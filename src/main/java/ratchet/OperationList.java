package ratchet;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public final class OperationList {
    private final ArrayList<Operation> operations = new ArrayList<Operation>();
    private String baseVersion = "";
    private String targetVersion = "";
    private int flags;

    public void setBaseVersion(String baseVersion) {
        this.baseVersion = sanitize(baseVersion);
    }

    public void setTargetVersion(String targetVersion) {
        this.targetVersion = sanitize(targetVersion);
    }

    public String baseVersion() { return baseVersion; }
    public String targetVersion() { return targetVersion; }
    public int flags() { return flags; }
    public void setFlags(int flags) { this.flags = flags; }

    public void add(Operation operation) {
        operations.add(operation);
    }

    public int size() { return operations.size(); }

    public Operation get(int index) { return operations.get(index); }

    public List<Operation> operations() {
        return Collections.unmodifiableList(operations);
    }

    private static String sanitize(String value) {
        if (value == null) {
            return "";
        }
        if (value.length() <= Format.NAME_MAX) {
            return value;
        }
        return value.substring(0, Format.NAME_MAX);
    }
}
