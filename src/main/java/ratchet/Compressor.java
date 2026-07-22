package ratchet;

import java.util.Arrays;

public final class Compressor {
    private Compressor() { }

    public static byte[] compressLiteral(byte[] input) {
        ByteSink sink = new ByteSink();
        sink.write(new byte[] { 'R', 'C', 'M', 'P' });
        Format.writeU32(sink, input.length);
        int pos = 0;
        while (pos < input.length) {
            int run = 1;
            while (pos + run < input.length && input[pos + run] == input[pos] && run < 255) {
                run++;
            }
            if (run >= 4) {
                sink.write((byte) 1);
                sink.write((byte) run);
                sink.write(input[pos]);
                pos += run;
                continue;
            }
            int back = findBackReference(input, pos);
            if (back >= 0) {
                sink.write((byte) 2);
                Format.writeU32(sink, back);
                pos += 4;
                continue;
            }
            sink.write((byte) 0);
            sink.write(input[pos]);
            pos++;
        }
        return sink.toByteArray();
    }

    public static byte[] decompressLiteral(byte[] input) throws RatchetException {
        if (input.length < 8 || input[0] != 'R' || input[1] != 'C' || input[2] != 'M' || input[3] != 'P') {
            return Arrays.copyOf(input, input.length);
        }
        int expected = Format.readU32(input, 4);
        ByteSink sink = new ByteSink();
        int pos = 8;
        while (pos < input.length) {
            int tag = input[pos++] & 0xff;
            if (tag == 0) {
                if (pos >= input.length) {
                    throw new RatchetException(RatchetStatus.INVALID, "truncated literal");
                }
                sink.write(input[pos++]);
            } else if (tag == 1) {
                if (pos + 2 > input.length) {
                    throw new RatchetException(RatchetStatus.INVALID, "truncated run");
                }
                int count = input[pos++] & 0xff;
                byte value = input[pos++];
                for (int i = 0; i < count; i++) {
                    sink.write(value);
                }
            } else if (tag == 2) {
                int back = Format.readU32(input, pos);
                pos += 4;
                byte[] soFar = sink.toByteArray();
                if (back < 0 || back + 4 > soFar.length) {
                    throw new RatchetException(RatchetStatus.BOUNDS, "bad back reference");
                }
                sink.write(soFar, back, 4);
            } else {
                throw new RatchetException(RatchetStatus.INVALID, "bad compression tag");
            }
        }
        byte[] out = sink.toByteArray();
        if (out.length != expected) {
            throw new RatchetException(RatchetStatus.INVALID, "bad decompressed length");
        }
        return out;
    }

    private static int findBackReference(byte[] input, int pos) {
        if (pos < 4 || pos + 4 > input.length) {
            return -1;
        }
        for (int i = 0; i + 4 <= pos; i++) {
            if (input[i] == input[pos]
                    && input[i + 1] == input[pos + 1]
                    && input[i + 2] == input[pos + 2]
                    && input[i + 3] == input[pos + 3]) {
                return i;
            }
        }
        return -1;
    }
}
