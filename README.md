# Ratchet

Ratchet is a private, original JVM/Java implementation of a versioned binary diff and patch format. It parses structured diff files, verifies CRC32 checksums, resolves named version chains through an in-memory registry, generates greedy binary diffs, applies patches, compresses literal insert data, and exposes a Java fuzz harness for ClusterFuzzLite/Jazzer-style JVM fuzzing.

## Why Java

Current submission platform accepts JVM, Rust, Swift, and Zig. C/C++ intake is closed, so Ratchet HEAD is Java-only. Historical commits remain in git history, but submitted source at HEAD uses JVM code and a JVM fuzz harness.

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
- `Differ`: deterministic greedy diff generator using longest base substring matches.
- `Compressor`: run-length and 4-byte back-reference compressor for insert literals.
- `RatchetCli`: local command line interface.
- `RatchetFuzzer`: JVM fuzz harness that parses input, populates registry entries from chain operations, and drives patch execution.

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

Seed corpus includes insert-only, copy-only, mixed sequence, one-level chain, and two-level chain examples. Mixed sequence seeds are intentionally stateful: they warm copy state, mutate working state, grow storage, then repeat copy.

## Fuzz Harness

`fuzz/RatchetFuzzer.java` exposes:

```java
public static void fuzzerTestOneInput(byte[] data)
```

Harness behavior:

1. parse raw input as Ratchet diff
2. ignore invalid parse/CRC errors
3. register chain operation names in in-memory registry
4. apply operations to fixed base buffer
5. ignore expected RatchetException failures
6. allow unexpected runtime failures to surface to fuzzer

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

## Error Model

Core library throws `RatchetException` with `RatchetStatus`:

- `INVALID`
- `CRC`
- `BOUNDS`
- `NOT_FOUND`
- `DEPTH`

Fuzz harness catches these expected domain failures and returns. Runtime exceptions remain visible to fuzzing.

## Security Notes

Ratchet treats diff bytes as untrusted. Parser checks structure and CRC before patching. Resolver caps recursion depth. Patcher validates normal operation bounds. Fuzzing exercises the full parse-resolve-patch lifecycle, not only record decoding.

## Current Validation

Local validation command:

```sh
make clean && make && make test
```

Current HEAD is Java/JVM source with ClusterFuzzLite JVM metadata.
