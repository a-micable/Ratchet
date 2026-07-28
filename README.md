# Ratchet

Ratchet is a private, original JVM/Java implementation of a versioned binary diff and patch format. It parses structured diff files, verifies CRC32 checksums, resolves named version chains through in-memory registries, generates greedy binary diffs, applies patches, compresses literal insert data, and exposes JVM fuzzing surfaces for both one-shot parsing and longer lifecycle/stateful patch sessions.

## Layout

```text
src/main/java/ratchet/        core library and CLI
src/main/java/ratchet/audit/  deterministic byte audit utilities
src/test/java/ratchet/        test suite
fuzz/RatchetFuzzer.java       JVM fuzz entrypoint
fuzz/corpus/patch_fuzzer/     binary seed corpus
.clusterfuzzlite/build.sh     ClusterFuzzLite JVM build script
.clusterfuzzlite/project.yaml metadata
Makefile                      local javac build
```

## Format

Header fields are fixed width: 8-byte magic `RATCHET1`, 4-byte format version, 4-byte flags, 65-byte base version name, 65-byte target version name, 4-byte operation count, and 4-byte CRC32 over the header prefix.

Operation tags:

- `0x01` copy: offset, length, CRC32
- `0x02` insert: length, literal bytes, CRC32
- `0x03` delete: offset, length, CRC32
- `0x04` version chain: 65-byte version name, CRC32

All integers are little-endian 32-bit values.

## Components

- `Parser`: reads and writes diff streams, validates magic/version/name fields, checks CRC32, constructs operation lists.
- `Registry`: maps version names to diff byte streams, entirely in memory.
- `Resolver`: recursively expands chain operations into flat ordered patch operations.
- `Patcher`: applies copy, insert, and delete operations to a working buffer after resolver flattening.
- `StatefulPatchSession`: keeps an evolving current document, named registry entries, checkpoints, and version metadata across multiple patch calls.
- `Differ`: deterministic greedy diff generator using longest base substring matches.
- `Compressor`: run-length and 4-byte back-reference compressor for insert literals.
- `RatchetCli`: local command line interface.
- `RatchetFuzzer`: JVM fuzz harness that either parses raw diffs or interprets command streams that mutate a long-lived patch session.

## Stateful Bug Model

Ratchet intentionally favors bugs that require lifecycle context rather than isolated malformed records. The most interesting paths now involve sequences such as:

- register a named diff, apply it through a chain, checkpoint the result, mutate again, then restore
- reuse a warmed copy cursor after deletes and inserts have changed the working buffer
- resolve nested chains whose registry entries were installed by earlier operations
- reset a session while keeping enough registry/checkpoint history to exercise stale-state assumptions
- query current state repeatedly between mutations to expose defensive-copy and aliasing mistakes

This gives fuzzing and review more room to find ordering bugs, stale snapshots, bad lifecycle transitions, and state aliasing issues.

## Build

```sh
make clean
make
```

Requires `javac` and `jar`. No network and no external dependencies required for local build.

## Test

```sh
make test
```

Expected output:

```text
Java Ratchet tests passed
```

Tests cover round trips, CRC rejection, copy/insert/delete operations, mixed operation sequences, version chains, compression, registry behavior, and writer/parser round trips.

## Seeds

```sh
make seeds
```

Seed corpus includes insert-only, copy-only, mixed sequence, one-level chain, two-level chain, and command-stream stateful session examples. Mixed sequence seeds are intentionally stateful: they warm copy state, mutate working state, grow storage, then repeat copy.

## Fuzz Harness

`fuzz/RatchetFuzzer.java` exposes:

```java
public static void fuzzerTestOneInput(byte[] data)
```

Raw diff behavior:

1. parse raw input as Ratchet diff
2. ignore invalid parse/CRC errors
3. register chain operation names in in-memory registry
4. apply operations to fixed base buffer
5. ignore expected RatchetException failures
6. allow unexpected runtime failures to surface to fuzzer

Inputs that do not start with the Ratchet magic header are treated as command streams. Those commands register generated patches, apply named versions, apply direct operation lists, checkpoint and restore session state, reset the current document, and query session metadata. This path is intentionally lifecycle-heavy.

The harness does not write files, open sockets, or call process exit.

## CLI

```sh
java -cp build/classes ratchet.RatchetCli diff base.bin target.bin patch.ratchet
java -cp build/classes ratchet.RatchetCli patch base.bin patch.ratchet out.bin
java -cp build/classes ratchet.RatchetCli verify patch.ratchet
java -cp build/classes ratchet.RatchetCli chain registry.diff target_version
```

## API Sketch

```java
byte[] diff = Differ.diffBytes(base, target, "base", "target");
Registry registry = new Registry();
byte[] output = Patcher.applyDiff(diff, registry, base);
```

Manual parse/resolve:

```java
OperationList parsed = Parser.parse(diff);
OperationList flat = Resolver.resolve(parsed, registry);
```

Stateful session:

```java
StatefulPatchSession session = new StatefulPatchSession(base, "base");
session.register("v1", diff);
byte[] current = session.applyNamed("v1");
session.checkpoint("stable");
```

## Error Model

Core library throws `RatchetException` with `RatchetStatus`:

- `INVALID`
- `CRC`
- `BOUNDS`
- `NOT_FOUND`
- `DEPTH`
- `COMPRESSION_ERROR`
- `SIZE_EXCEEDED`
- `UNSUPPORTED`
- `INTERNAL`
- `IO_ERROR`
- `AUTHENTICATION_FAILED`
- `AUTHORIZATION_FAILED`
- `TIMEOUT`
- `CONCURRENT_MODIFICATION`

Fuzz harness catches these expected domain failures and returns. Runtime exceptions remain visible to fuzzing.

## Security Notes

Ratchet treats diff bytes and command streams as untrusted. Parser checks structure and CRC before patching. Resolver caps recursion depth. Patcher validates normal operation bounds. Stateful session APIs defensively copy stored and returned byte arrays. Fuzzing exercises parse-resolve-patch lifecycle and cross-call state transitions, not only record decoding.

## Current Validation

Local validation command:

```sh
make clean && make && make test
```

Current HEAD is Java/JVM source with ClusterFuzzLite JVM metadata.
