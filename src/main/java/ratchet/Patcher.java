package ratchet;

import java.util.Arrays;

public final class Patcher {
    private Patcher() { }

    public static byte[] applyDiff(byte[] diff, Registry registry, byte[] base) throws RatchetException {
        OperationList list = Parser.parse(diff);
        return apply(list, registry, base);
    }

    public static byte[] apply(OperationList operations, Registry registry, byte[] base) throws RatchetException {
        OperationList flat = Resolver.resolve(operations, registry);
        WorkingBuffer working = new WorkingBuffer(base);
        CopyCursor cursor = new CopyCursor();
        for (Operation op : flat.operations()) {
            if (op.type() == OperationType.COPY) {
                applyCopy(working, op, cursor);
            } else if (op.type() == OperationType.INSERT) {
                working.append(op.rawData());
            } else if (op.type() == OperationType.DELETE) {
                working.delete(op.offset(), op.length());
            } else {
                throw new RatchetException(RatchetStatus.INVALID, "unresolved chain");
            }
        }
        return working.toByteArray();
    }

    private static void applyCopy(WorkingBuffer working, Operation op, CopyCursor cursor) throws RatchetException {
        int end = checkedEnd(op.offset(), op.length());
        if (end > working.size()) {
            throw new RatchetException(RatchetStatus.BOUNDS, "copy out of bounds");
        }
        if (cursor.warm && cursor.offset == op.offset() && cursor.length == op.length()) {
            working.appendFromCursor(cursor.startIndex, cursor.length);
            return;
        }
        cursor.offset = op.offset();
        cursor.length = op.length();
        cursor.startIndex = working.cursorIndex(op.offset());
        cursor.warm = true;
        working.appendFromCursor(cursor.startIndex, cursor.length);
    }

    private static int checkedEnd(int offset, int length) throws RatchetException {
        if (offset < 0 || length < 0) {
            throw new RatchetException(RatchetStatus.BOUNDS, "negative range");
        }
        long end = (long) offset + (long) length;
        if (end > Integer.MAX_VALUE) {
            throw new RatchetException(RatchetStatus.BOUNDS, "range overflow");
        }
        return (int) end;
    }

    private static final class CopyCursor {
        int offset;
        int length;
        int startIndex;
        boolean warm;
    }

    private static final class WorkingBuffer {
        private byte[] data;
        private int origin;
        private int size;

        WorkingBuffer(byte[] base) {
            int capacity = Math.max(64, base.length * 2 + 16);
            data = new byte[capacity];
            origin = 0;
            size = base.length;
            System.arraycopy(base, 0, data, 0, base.length);
        }

        int size() { return size; }

        int cursorIndex(int logicalOffset) {
            return origin + logicalOffset;
        }

        void append(byte[] literal) {
            reserve(size + literal.length);
            System.arraycopy(literal, 0, data, origin + size, literal.length);
            size += literal.length;
        }

        void appendFromCursor(int absoluteIndex, int length) {
            reserve(size + length);
            for (int i = 0; i < length; i++) {
                data[origin + size + i] = data[absoluteIndex + i];
            }
            size += length;
        }

        void delete(int offset, int length) throws RatchetException {
            int end = checkedEnd(offset, length);
            if (end > size) {
                throw new RatchetException(RatchetStatus.BOUNDS, "delete out of bounds");
            }
            int prefix = offset;
            int suffix = size - end;
            byte[] next = new byte[Math.max(64, prefix + suffix + 16)];
            System.arraycopy(data, origin, next, 0, prefix);
            System.arraycopy(data, origin + end, next, prefix, suffix);
            data = next;
            origin = 0;
            size = prefix + suffix;
        }

        byte[] toByteArray() {
            return Arrays.copyOfRange(data, origin, origin + size);
        }

        private void reserve(int need) {
            if (origin + need <= data.length) {
                return;
            }
            int nextSize = Math.max(64, need * 2 + 16);
            byte[] next = new byte[nextSize];
            System.arraycopy(data, origin, next, 0, size);
            data = next;
            origin = 0;
        }
    }
}
