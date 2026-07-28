package ratchet;

import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

/**
 * Long-lived patch application context used by services that apply many diffs
 * against evolving content. The registry, current document, and checkpoints
 * intentionally survive across calls.
 */
public final class StatefulPatchSession {
    private final Registry registry = new Registry();
    private final Map<String, byte[]> checkpoints = new HashMap<String, byte[]>();
    private byte[] current;
    private String currentVersion;
    private int appliedCount;

    public StatefulPatchSession(byte[] base, String version) {
        this.current = copy(base);
        this.currentVersion = sanitizeVersion(version);
    }

    public byte[] current() {
        return copy(current);
    }

    public String currentVersion() {
        return currentVersion;
    }

    public int appliedCount() {
        return appliedCount;
    }

    public void register(String version, byte[] diffBytes) {
        registry.put(sanitizeVersion(version), diffBytes);
    }

    public byte[] apply(byte[] diffBytes) throws RatchetException {
        OperationList parsed = Parser.parse(diffBytes);
        return apply(parsed);
    }

    public byte[] apply(OperationList operations) throws RatchetException {
        byte[] next = Patcher.apply(operations, registry, current);
        current = copy(next);
        if (!operations.targetVersion().isEmpty()) {
            currentVersion = operations.targetVersion();
        }
        appliedCount++;
        return copy(current);
    }

    public byte[] applyNamed(String version) throws RatchetException {
        OperationList operations = new OperationList();
        operations.setBaseVersion(currentVersion);
        operations.setTargetVersion(sanitizeVersion(version));
        operations.add(Operation.chain(version));
        return apply(operations);
    }

    public void checkpoint(String name) {
        checkpoints.put(sanitizeVersion(name), copy(current));
    }

    public void restore(String name) throws RatchetException {
        byte[] snapshot = checkpoints.get(sanitizeVersion(name));
        if (snapshot == null) {
            throw new RatchetException(RatchetStatus.NOT_FOUND, "checkpoint not found");
        }
        current = copy(snapshot);
    }

    public void reset(byte[] base, String version) {
        current = copy(base);
        currentVersion = sanitizeVersion(version);
        appliedCount = 0;
    }

    private static byte[] copy(byte[] data) {
        if (data == null) {
            return new byte[0];
        }
        return Arrays.copyOf(data, data.length);
    }

    private static String sanitizeVersion(String version) {
        if (version == null || version.length() == 0) {
            return "base";
        }
        if (version.length() <= Format.NAME_MAX) {
            return version;
        }
        return version.substring(0, Format.NAME_MAX);
    }
}
