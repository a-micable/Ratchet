package ratchet;

final class Format {
    static final byte[] MAGIC = new byte[] { 'R', 'A', 'T', 'C', 'H', 'E', 'T', '1' };
    static final int VERSION = 1;
    static final int NAME_MAX = 64;
    static final int NAME_FIELD = 65;
    static final int HEADER_SIZE = 154;

    private Format() { }

    static int readU32(byte[] data, int offset) throws RatchetException {
        if (offset < 0 || offset + 4 > data.length) {
            throw new RatchetException(RatchetStatus.INVALID, "truncated u32");
        }
        return (data[offset] & 0xff)
            | ((data[offset + 1] & 0xff) << 8)
            | ((data[offset + 2] & 0xff) << 16)
            | ((data[offset + 3] & 0xff) << 24);
    }

    static void writeU32(ByteSink sink, int value) {
        sink.write((byte) value);
        sink.write((byte) (value >>> 8));
        sink.write((byte) (value >>> 16));
        sink.write((byte) (value >>> 24));
    }

    static String readName(byte[] data, int offset) throws RatchetException {
        if (offset < 0 || offset + NAME_FIELD > data.length) {
            throw new RatchetException(RatchetStatus.INVALID, "truncated name");
        }
        int end = offset;
        while (end < offset + NAME_FIELD && data[end] != 0) {
            end++;
        }
        if (end == offset + NAME_FIELD) {
            throw new RatchetException(RatchetStatus.INVALID, "unterminated name");
        }
        return new String(data, offset, end - offset, java.nio.charset.StandardCharsets.UTF_8);
    }

    static void writeName(ByteSink sink, String name) {
        byte[] field = new byte[NAME_FIELD];
        byte[] raw = (name == null ? "" : name).getBytes(java.nio.charset.StandardCharsets.UTF_8);
        int n = Math.min(NAME_MAX, raw.length);
        System.arraycopy(raw, 0, field, 0, n);
        sink.write(field);
    }
}
