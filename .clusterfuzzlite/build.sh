#!/bin/bash -eu
cd "${SRC:-.}"
mkdir -p "$OUT"
$CC $CFLAGS -Iinclude src/parser.c src/patcher.c src/differ.c src/resolver.c src/compressor.c src/registry.c src/crc32.c fuzz/patch_fuzzer.c $LIB_FUZZING_ENGINE -o "$OUT/patch_fuzzer"
