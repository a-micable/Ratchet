#!/bin/bash -eu
cd "${SRC:-.}"
mkdir -p "$OUT/classes"
find src/main/java fuzz -name '*.java' > "$OUT/java_sources.txt"
javac --release 8 -Xlint:-options -d "$OUT/classes" @"$OUT/java_sources.txt"
jar cf "$OUT/patch_fuzzer.jar" -C "$OUT/classes" .
cat > "$OUT/patch_fuzzer" <<'EOF'
#!/bin/bash -eu
exec java -cp "$(dirname "$0")/patch_fuzzer.jar" RatchetFuzzer "$@"
EOF
chmod +x "$OUT/patch_fuzzer"
