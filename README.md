# Ratchet

Ratchet is a private, original C project for reading, writing, resolving, generating, and applying versioned binary diff streams. It provides a small library, a command line tool, a seed generator, a libFuzzer harness, and a ClusterFuzzLite build entrypoint.

The core idea is simple: a diff file describes how to transform one byte buffer into another byte buffer. Ratchet keeps that format explicit and inspectable. A diff has a fixed header, a checked operation stream, named base and target versions, optional chained intermediate versions, and CRC32 protection for both header and records.

This repository is intentionally self-contained. The version registry lives in memory. The fuzzer does not touch the filesystem or network. The normal build uses only a C compiler and `make`.

## Project Goals

Ratchet is built around five goals:

1. Provide a clear binary diff format with strict parsing and CRC validation.
2. Support version chains so a patch can depend on earlier named patches.
3. Generate diffs from two buffers using a deterministic greedy matcher.
4. Exercise the full patching pipeline from fuzz input, not only parser input.
5. Keep the project easy to build, test, inspect, and extend.

The codebase is split into focused modules under `src/`, with public headers under `include/ratchet/`.

## Repository Layout

```text
.
├── .clusterfuzzlite/
│   ├── build.sh
│   └── project.yaml
├── fuzz/
│   ├── corpus/
│   │   └── patch_fuzzer/
│   └── patch_fuzzer.c
├── include/
│   └── ratchet/
│       ├── cli.h
│       ├── compressor.h
│       ├── crc32.h
│       ├── differ.h
│       ├── parser.h
│       ├── patcher.h
│       ├── registry.h
│       ├── resolver.h
│       └── types.h
├── src/
│   ├── cli.c
│   ├── compressor.c
│   ├── crc32.c
│   ├── differ.c
│   ├── parser.c
│   ├── patcher.c
│   ├── registry.c
│   └── resolver.c
├── tests/
│   └── test_ratchet.c
├── tools/
│   └── generate_seeds.c
├── Makefile
└── README.md
```

## Components

### Parser

Parser code lives in `src/parser.c` and is exposed through `include/ratchet/parser.h`.

It handles:

- diff header parsing
- fixed magic validation
- format version validation
- base and target version name decoding
- operation count validation
- record parsing
- CRC32 verification
- in-memory operation list construction
- diff writing through the same format

The parser returns `RatchetStatus` values. It does not call `exit`, does not own global state, and keeps all parsed operation data in caller-managed structures.

### Registry

Registry code lives in `src/registry.c` and is exposed through `include/ratchet/registry.h`.

The registry maps a version name to a complete diff byte stream:

```c
RatchetRegistry registry;
ratchet_registry_init(&registry);
ratchet_registry_put(&registry, "v2", diff_bytes, diff_size);
ratchet_registry_free(&registry);
```

It is deliberately in-memory. This keeps fuzzing deterministic and avoids hidden filesystem or network dependencies.

### Resolver

Resolver code lives in `src/resolver.c` and is exposed through `include/ratchet/resolver.h`.

The resolver walks operation lists and expands version-chain records. For each chain record, it:

1. looks up the named version in the registry
2. parses that diff stream
3. resolves any nested chain operations
4. appends non-chain operations into one flat ordered list

The patcher consumes this flat operation list.

### Patcher

Patcher code lives in `src/patcher.c` and is exposed through `include/ratchet/patcher.h`.

It starts with a working buffer initialized from the base buffer. Then it applies operations in order:

- `COPY`: copy bytes from current working data and append them
- `INSERT`: append literal bytes
- `DELETE`: remove a range and shift later bytes down
- `CHAIN`: resolved before patch execution

Normal use is:

```c
RatchetBuffer out;
RatchetRegistry registry;

ratchet_registry_init(&registry);

if (ratchet_apply_diff_bytes(diff, diff_size,
                             &registry,
                             base, base_size,
                             &out) == RATCHET_OK) {
    /* out.data/out.size contain reconstructed target */
    ratchet_buffer_free(&out);
}

ratchet_registry_free(&registry);
```

### Differ

Differ code lives in `src/differ.c` and is exposed through `include/ratchet/differ.h`.

The differ compares base and target buffers and emits a deterministic operation list. It uses a simple greedy strategy:

1. scan target from left to right
2. find longest substring at current target position that appears in base
3. emit `COPY` for useful matches
4. collect unmatched bytes into `INSERT`
5. remove original base prefix after target reconstruction

This is intentionally simple. It is not a suffix-array differ or a full binary delta optimizer. It favors readability and deterministic behavior.

### Compressor

Compressor code lives in `src/compressor.c` and is exposed through `include/ratchet/compressor.h`.

It applies a lightweight entropy reduction pass to literal insert payloads:

- runs of identical bytes become RLE records
- repeated 4-byte patterns become back-references
- decompression round-trips back to original literal data

The compressor operates at operation-list level and at raw literal-buffer level.

### CRC32

CRC32 code lives in `src/crc32.c` and is exposed through `include/ratchet/crc32.h`.

The parser and writer use CRC32 for:

- header integrity
- copy record integrity
- insert record integrity
- delete record integrity
- version-chain record integrity

### CLI

CLI code lives in `src/cli.c`.

It provides four subcommands:

- `diff`
- `patch`
- `verify`
- `chain`

The CLI is a thin wrapper over the library.

## Binary Format

All multi-byte integers are 32-bit little-endian values.

### Header

Every diff begins with a fixed-size header:

| Field | Size | Meaning |
| --- | ---: | --- |
| magic | 8 bytes | fixed `RATCHET1` |
| format version | 4 bytes | current value `1` |
| flags | 4 bytes | reserved bitfield |
| base version | 65 bytes | null-terminated, max 64 bytes |
| target version | 65 bytes | null-terminated, max 64 bytes |
| operation count | 4 bytes | number of records following header |
| header CRC32 | 4 bytes | CRC over preceding header bytes |

Header size is `154` bytes.

### Operation Records

Ratchet supports four operation types.

#### Copy

Tag: `0x01`

| Field | Size |
| --- | ---: |
| type | 1 byte |
| source offset | 4 bytes |
| length | 4 bytes |
| record CRC32 | 4 bytes |

Copy appends bytes from the patcher's working data.

#### Insert

Tag: `0x02`

| Field | Size |
| --- | ---: |
| type | 1 byte |
| length | 4 bytes |
| literal data | `length` bytes |
| record CRC32 | 4 bytes |

Insert appends literal data.

#### Delete

Tag: `0x03`

| Field | Size |
| --- | ---: |
| type | 1 byte |
| offset | 4 bytes |
| length | 4 bytes |
| record CRC32 | 4 bytes |

Delete removes bytes from the current working buffer.

#### Version Chain

Tag: `0x04`

| Field | Size |
| --- | ---: |
| type | 1 byte |
| version name | 65 bytes |
| record CRC32 | 4 bytes |

Version-chain records name intermediate versions that must be resolved through the registry before the current diff continues.

## Build

Build everything:

```sh
make
```

The `Makefile` uses:

```text
gcc -Wall -Werror -Wextra -pedantic -std=c11
```

Produced binaries:

```text
ratchet
tests/test_ratchet
tools/generate_seeds
```

Clean build products:

```sh
make clean
```

## Test

Run the full test suite:

```sh
make test
```

Coverage includes:

- diff and patch round-trips
- varying buffer sizes
- corrupted header CRC rejection
- corrupted record CRC rejection
- valid copy operations
- insert operations that grow working data
- delete operations that shrink working data
- mixed insert/copy/delete sequences
- one-level version chains
- two-level version chains
- identical buffers
- no-common-substring buffers
- repeated runs
- compression/decompression round-trip
- invalid magic rejection
- truncated input rejection
- bounds rejection paths
- registry put/get behavior
- writer/parser round-trip

## CLI Usage

### Create Diff

```sh
./ratchet diff base.bin target.bin patch.ratchet
```

Reads `base.bin` and `target.bin`, compares them, and writes `patch.ratchet`.

### Apply Patch

```sh
./ratchet patch base.bin patch.ratchet reconstructed.bin
```

Reads base and diff bytes, applies the patch, and writes reconstructed output.

### Verify Diff

```sh
./ratchet verify patch.ratchet
```

Parses the diff and checks all CRC32 fields.

Exit code `0` means valid. Non-zero means parse failure, invalid format, or CRC failure.

### Chain Summary

```sh
./ratchet chain registry.diff target_version
```

Loads a registry diff byte stream and prints resolved operations in order.

## Library Usage

### Generate Diff Bytes

```c
#include "ratchet/differ.h"
#include "ratchet/parser.h"

RatchetBuffer diff;

if (ratchet_diff_to_bytes(base, base_size,
                          target, target_size,
                          "base-v1", "target-v2",
                          &diff) == RATCHET_OK) {
    /* diff.data/diff.size contain serialized diff */
    ratchet_buffer_free(&diff);
}
```

### Parse Diff Bytes

```c
#include "ratchet/parser.h"

RatchetOperationList ops;

if (ratchet_parse_diff(diff, diff_size, &ops) == RATCHET_OK) {
    /* inspect ops.items */
    ratchet_operation_list_free(&ops);
}
```

### Apply Parsed Operations

```c
#include "ratchet/patcher.h"
#include "ratchet/registry.h"

RatchetRegistry registry;
RatchetBuffer out;

ratchet_registry_init(&registry);

if (ratchet_apply_operations(&ops, &registry,
                             base, base_size,
                             &out) == RATCHET_OK) {
    ratchet_buffer_free(&out);
}

ratchet_registry_free(&registry);
```

### Register Version Bytes

```c
ratchet_registry_put(&registry, "intermediate-v2",
                     diff_bytes, diff_size);
```

### Resolve Chain Manually

```c
#include "ratchet/resolver.h"

RatchetOperationList flat;

if (ratchet_resolve_operations(&ops, &registry, &flat) == RATCHET_OK) {
    /* flat contains resolved non-chain operations */
    ratchet_operation_list_free(&flat);
}
```

## Memory Ownership

Ratchet uses explicit ownership:

- `RatchetBuffer` owns `data`
- `ratchet_buffer_free` releases buffer storage
- `RatchetOperationList` owns operation array and copied insert payloads
- `ratchet_operation_list_free` releases operation-list storage
- `RatchetRegistry` owns copied diff byte streams
- `ratchet_registry_free` releases registry storage

Callers should initialize structures before use:

```c
RatchetBuffer buf;
ratchet_buffer_init(&buf);
```

Most constructor-like API calls initialize their output object internally. If a function returns `RATCHET_OK`, caller owns returned data and must free it with matching free function.

## Error Handling

APIs return `RatchetStatus`:

| Status | Meaning |
| --- | --- |
| `RATCHET_OK` | success |
| `RATCHET_ERROR_INVALID` | invalid format or operation |
| `RATCHET_ERROR_CRC` | CRC mismatch |
| `RATCHET_ERROR_BOUNDS` | invalid offset/length for current buffer |
| `RATCHET_ERROR_NOMEM` | allocation failure |
| `RATCHET_ERROR_NOT_FOUND` | missing version in registry |
| `RATCHET_ERROR_DEPTH` | version-chain recursion depth exceeded |

The library does not print diagnostics from core APIs. CLI converts errors into non-zero exit codes.

## Fuzzing

Fuzz harness:

```text
fuzz/patch_fuzzer.c
```

The harness implements:

```c
int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size)
```

Pipeline:

1. parse raw input as a diff stream
2. initialize in-memory version registry
3. register embedded chain names against supplied input bytes
4. apply parsed operations to a fixed base buffer
5. ignore expected library errors
6. free all allocated memory

It does not:

- call `exit`
- write files
- open network connections
- depend on external registry state

### Seed Corpus

Seed corpus lives under:

```text
fuzz/corpus/patch_fuzzer/
```

Seed classes:

- minimal insert-only diffs
- valid copy-only diffs
- mixed insert-before-copy diffs
- one-level version-chain diffs
- two-level version-chain diffs

Regenerate seeds:

```sh
make seeds
```

### ClusterFuzzLite

Build script:

```text
.clusterfuzzlite/build.sh
```

It compiles with:

```sh
$CC $CFLAGS -Iinclude ... $LIB_FUZZING_ENGINE -o "$OUT/patch_fuzzer"
```

Metadata:

```text
.clusterfuzzlite/project.yaml
```

## Development Workflow

Common local loop:

```sh
make clean
make
make test
make seeds
```

Recommended checks before commit:

```sh
make clean && make && make test
```

For fuzz-oriented changes, also rebuild seed corpus:

```sh
make seeds
```

## Design Notes

### Why Fixed Header Fields?

Fixed header layout makes validation predictable and cheap. Version names are bounded to 64 bytes and stored as 65-byte null-terminated fields, avoiding unbounded string scans.

### Why CRC Per Record?

Per-record CRC lets `verify` reject corrupted operation streams without executing them. It also helps fuzzing explore parser and patcher paths separately.

### Why In-Memory Registry?

Version-chain resolution needs reproducibility. In-memory registry avoids filesystem ordering, path traversal concerns, network flakiness, and hidden external state.

### Why Greedy Differ?

Greedy differ is deterministic and easy to inspect. It is good enough for exercising copy/insert/delete semantics and writer correctness without adding a large algorithmic dependency.

### Why Separate Resolver?

Separating resolver from patcher means patch execution sees one ordered stream. This keeps patch operations simple while still supporting recursive version chains.

## Limitations

Ratchet is a compact research-oriented implementation, not a production package manager or archive format.

Current limitations:

- no streaming parser
- no mmap support
- no cryptographic authentication
- no filesystem-backed registry
- no optimal diff algorithm
- no ABI stability guarantee
- no package manager metadata
- CLI `chain` command is intentionally minimal

## Security Notes

Ratchet treats diff files as untrusted input. Parser and patcher paths return structured errors for invalid format, CRC mismatch, missing versions, recursion depth, and invalid bounds.

Fuzzing is part of the intended workflow. The harness intentionally drives beyond parsing into version resolution and patch application so stateful operation sequences are exercised.

Do not use Ratchet as a security boundary without adding:

- authenticated metadata
- stronger format version negotiation
- resource limits for large diffs
- policy for trusted version registries
- continuous fuzzing with sanitizers

## File Map

| File | Purpose |
| --- | --- |
| `src/parser.c` | binary reader/writer and operation-list utilities |
| `src/patcher.c` | patch execution |
| `src/differ.c` | greedy diff generation |
| `src/resolver.c` | version-chain flattening |
| `src/compressor.c` | literal compression/decompression |
| `src/registry.c` | in-memory version registry |
| `src/crc32.c` | CRC32 implementation |
| `src/cli.c` | command line interface |
| `tests/test_ratchet.c` | unit/integration tests |
| `tools/generate_seeds.c` | fuzz seed generator |
| `fuzz/patch_fuzzer.c` | libFuzzer entrypoint |

## Status

Ratchet builds with strict warnings as errors and includes an automated test suite plus fuzzing entrypoint.

Use:

```sh
make clean && make && make test
```

Expected result:

```text
25 tests passed
```
