package ratchet;

import java.util.Arrays;

public final class Operation {
    private final OperationType type;
    private final int offset;
    private final int length;
    private final byte[] data;
    private final String version;

    private Operation(OperationType type, int offset, int length, byte[] data, String version) {
        this.type = type;
        this.offset = offset;
        this.length = length;
        this.data = data == null ? new byte[0] : Arrays.copyOf(data, data.length);
        this.version = version == null ? "" : version;
    }

    public static Operation copy(int offset, int length) {
        return new Operation(OperationType.COPY, offset, length, null, "");
    }

    public static Operation insert(byte[] data) {
        return new Operation(OperationType.INSERT, 0, data.length, data, "");
    }

    public static Operation delete(int offset, int length) {
        return new Operation(OperationType.DELETE, offset, length, null, "");
    }

    public static Operation chain(String version) {
        return new Operation(OperationType.CHAIN, 0, 0, null, version);
    }

    public OperationType type() { return type; }
    public int offset() { return offset; }
    public int length() { return length; }
    public byte[] data() { return Arrays.copyOf(data, data.length); }
    byte[] rawData() { return data; }
    public String version() { return version; }
}
