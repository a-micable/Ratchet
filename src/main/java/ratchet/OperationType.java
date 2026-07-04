package ratchet;

public enum OperationType {
    COPY(0x01),
    INSERT(0x02),
    DELETE(0x03),
    CHAIN(0x04);

    private final int tag;

    OperationType(int tag) {
        this.tag = tag;
    }

    public int tag() {
        return tag;
    }

    public static OperationType fromTag(int tag) throws RatchetException {
        for (OperationType type : values()) {
            if (type.tag == tag) {
                return type;
            }
        }
        throw new RatchetException(RatchetStatus.INVALID, "unknown operation tag");
    }
}
