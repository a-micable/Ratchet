package ratchet;

import java.util.Arrays;

final class ByteSink {
    private byte[] data = new byte[64];
    private int size;

    int size() { return size; }

    byte[] toByteArray() {
        return Arrays.copyOf(data, size);
    }

    void write(byte value) {
        reserve(size + 1);
        data[size++] = value;
    }

    void write(byte[] values) {
        reserve(size + values.length);
        System.arraycopy(values, 0, data, size, values.length);
        size += values.length;
    }

    void write(byte[] values, int offset, int length) {
        reserve(size + length);
        System.arraycopy(values, offset, data, size, length);
        size += length;
    }

    byte get(int index) { return data[index]; }

    void set(int index, byte value) { data[index] = value; }

    private void reserve(int need) {
        if (need <= data.length) {
            return;
        }
        int next = data.length;
        while (next < need) {
            next = next * 2;
        }
        data = Arrays.copyOf(data, next);
    }
}
