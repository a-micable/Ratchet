package ratchet;

import java.util.zip.CRC32;

public final class Crc32 {
    private Crc32() { }

    public static int compute(byte[] data) {
        return compute(data, 0, data.length);
    }

    public static int compute(byte[] data, int offset, int length) {
        CRC32 crc = new CRC32();
        crc.update(data, offset, length);
        return (int) crc.getValue();
    }
}
