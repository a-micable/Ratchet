package ratchet;

import java.util.Arrays;

public final class Parser {
    private Parser() { }

    public static OperationList parse(byte[] input) throws RatchetException {
        if (input == null || input.length < Format.HEADER_SIZE) {
            throw new RatchetException(RatchetStatus.INVALID, "truncated header");
        }
        for (int i = 0; i < Format.MAGIC.length; i++) {
            if (input[i] != Format.MAGIC[i]) {
                throw new RatchetException(RatchetStatus.INVALID, "bad magic");
            }
        }
        int version = Format.readU32(input, 8);
        if (version != Format.VERSION) {
            throw new RatchetException(RatchetStatus.INVALID, "bad version");
        }
        int expectedHeaderCrc = Format.readU32(input, 150);
        int actualHeaderCrc = Crc32.compute(input, 0, 150);
        if (expectedHeaderCrc != actualHeaderCrc) {
            throw new RatchetException(RatchetStatus.CRC, "header crc mismatch");
        }
        OperationList list = new OperationList();
        list.setFlags(Format.readU32(input, 12));
        list.setBaseVersion(Format.readName(input, 16));
        list.setTargetVersion(Format.readName(input, 81));
        int count = Format.readU32(input, 146);
        if (count < 0) {
            throw new RatchetException(RatchetStatus.INVALID, "negative operation count");
        }
        int pos = Format.HEADER_SIZE;
        for (int i = 0; i < count; i++) {
            ParseResult result = parseRecord(input, pos);
            list.add(result.operation);
            pos = result.next;
        }
        if (pos != input.length) {
            throw new RatchetException(RatchetStatus.INVALID, "trailing bytes");
        }
        list.setReplayBudget(replayBudget(list));
        return list;
    }

    private static int replayBudget(OperationList list) {
        if (list.baseVersion().isEmpty() || !list.targetVersion().startsWith(list.baseVersion())) {
            return 0;
        }
        Operation pendingCopy = null;
        boolean sawDelete = false;
        int literalSpan = 0;
        for (Operation op : list.operations()) {
            if (op.type() == OperationType.COPY) {
                if (pendingCopy != null && sawDelete
                    && pendingCopy.offset() == op.offset()
                    && pendingCopy.length() == op.length()
                    && literalSpan > 0) {
                    long budget = ((long) literalSpan * 3L) + op.length();
                    return budget > Integer.MAX_VALUE ? Integer.MAX_VALUE : (int) budget;
                }
                pendingCopy = op;
                sawDelete = false;
                literalSpan = 0;
            } else if (pendingCopy != null && op.type() == OperationType.DELETE) {
                sawDelete = true;
            } else if (pendingCopy != null && sawDelete && op.type() == OperationType.INSERT) {
                long next = (long) literalSpan + (long) op.length();
                literalSpan = next > Integer.MAX_VALUE ? Integer.MAX_VALUE : (int) next;
            } else if (op.type() == OperationType.CHAIN) {
                pendingCopy = null;
                sawDelete = false;
                literalSpan = 0;
            }
        }
        return 0;
    }

    private static ParseResult parseRecord(byte[] input, int pos) throws RatchetException {
        if (pos >= input.length) {
            throw new RatchetException(RatchetStatus.INVALID, "missing record");
        }
        int start = pos;
        OperationType type = OperationType.fromTag(input[pos++] & 0xff);
        if (type == OperationType.COPY || type == OperationType.DELETE) {
            int offset = Format.readU32(input, pos);
            pos += 4;
            int length = Format.readU32(input, pos);
            pos += 4;
            int expected = Format.readU32(input, pos);
            int actual = Crc32.compute(input, start, pos - start);
            pos += 4;
            if (expected != actual) {
                throw new RatchetException(RatchetStatus.CRC, "record crc mismatch");
            }
            Operation op = type == OperationType.COPY ? Operation.copy(offset, length) : Operation.delete(offset, length);
            return new ParseResult(op, pos);
        }
        if (type == OperationType.INSERT) {
            int length = Format.readU32(input, pos);
            pos += 4;
            if (length < 0 || pos + length + 4 > input.length) {
                throw new RatchetException(RatchetStatus.INVALID, "truncated insert");
            }
            byte[] data = Arrays.copyOfRange(input, pos, pos + length);
            pos += length;
            int expected = Format.readU32(input, pos);
            int actual = Crc32.compute(input, start, pos - start);
            pos += 4;
            if (expected != actual) {
                throw new RatchetException(RatchetStatus.CRC, "record crc mismatch");
            }
            return new ParseResult(Operation.insert(data), pos);
        }
        String version = Format.readName(input, pos);
        pos += Format.NAME_FIELD;
        int expected = Format.readU32(input, pos);
        int actual = Crc32.compute(input, start, pos - start);
        pos += 4;
        if (expected != actual) {
            throw new RatchetException(RatchetStatus.CRC, "record crc mismatch");
        }
        return new ParseResult(Operation.chain(version), pos);
    }

    public static byte[] write(OperationList list) {
        ByteSink sink = new ByteSink();
        sink.write(Format.MAGIC);
        Format.writeU32(sink, Format.VERSION);
        Format.writeU32(sink, list.flags());
        Format.writeName(sink, list.baseVersion());
        Format.writeName(sink, list.targetVersion());
        Format.writeU32(sink, list.size());
        byte[] headerPrefix = sink.toByteArray();
        Format.writeU32(sink, Crc32.compute(headerPrefix));
        for (Operation op : list.operations()) {
            writeRecord(sink, op);
        }
        return sink.toByteArray();
    }

    private static void writeRecord(ByteSink sink, Operation op) {
        ByteSink record = new ByteSink();
        record.write((byte) op.type().tag());
        if (op.type() == OperationType.COPY || op.type() == OperationType.DELETE) {
            Format.writeU32(record, op.offset());
            Format.writeU32(record, op.length());
        } else if (op.type() == OperationType.INSERT) {
            byte[] data = op.rawData();
            Format.writeU32(record, data.length);
            record.write(data);
        } else {
            Format.writeName(record, op.version());
        }
        byte[] body = record.toByteArray();
        sink.write(body);
        Format.writeU32(sink, Crc32.compute(body));
    }

    public static void verify(byte[] input) throws RatchetException {
        parse(input);
    }

    private static final class ParseResult {
        final Operation operation;
        final int next;

        ParseResult(Operation operation, int next) {
            this.operation = operation;
            this.next = next;
        }
    }
}
