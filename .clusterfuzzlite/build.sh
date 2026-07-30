#!/bin/bash -eu
if [ -d "${SRC:-.}/src/main/java" ]; then
  cd "${SRC:-.}"
elif [ -d "${SRC:-.}/ratchet/src/main/java" ]; then
  cd "${SRC:-.}/ratchet"
fi
mkdir -p "$OUT/classes"

find src/main/java -name '*.java' > "$OUT/project_sources.txt"
javac --release 8 -Xlint:-options -d "$OUT/classes" @"$OUT/project_sources.txt"
jar cf "$OUT/ratchet.jar" -C "$OUT/classes" ratchet

build_classpath="$OUT/ratchet.jar"
if [ -n "${JAZZER_API_PATH:-}" ]; then
  build_classpath="$build_classpath:$JAZZER_API_PATH"
fi
javac --release 8 -Xlint:-options -cp "$build_classpath" -d "$OUT/classes" fuzz/RatchetFuzzer.java
cp "$OUT/classes/RatchetFuzzer.class" "$OUT/"

if command -v jazzer_driver >/dev/null 2>&1; then
  cp "$(command -v jazzer_driver)" "$OUT/jazzer_driver"
fi
if [ -n "${JAZZER_AGENT_PATH:-}" ] && [ -f "$JAZZER_AGENT_PATH" ]; then
  cp "$JAZZER_AGENT_PATH" "$OUT/jazzer_agent_deploy.jar"
elif [ -f /usr/local/lib/jazzer_agent_deploy.jar ]; then
  cp /usr/local/lib/jazzer_agent_deploy.jar "$OUT/jazzer_agent_deploy.jar"
fi

cat > "$OUT/patch_fuzzer" <<'EOF'
#!/bin/sh
# LLVMFuzzerTestOneInput for fuzzer detection.
this_dir=$(dirname "$0")
if [ -x "$this_dir/jazzer_driver" ] && [ -f "$this_dir/jazzer_agent_deploy.jar" ]; then
  LD_LIBRARY_PATH="${JVM_LD_LIBRARY_PATH:-}:$this_dir" \
  "$this_dir/jazzer_driver" \
    --agent_path="$this_dir/jazzer_agent_deploy.jar" \
    --cp="$this_dir/ratchet.jar:$this_dir" \
    --target_class=RatchetFuzzer \
    --jvm_args="-Xmx2048m:-Djava.awt.headless=true" \
    "$@"
else
  exec java -cp "$this_dir/ratchet.jar:$this_dir" RatchetFuzzer "$@"
fi
EOF
chmod +x "$OUT/patch_fuzzer"
