import ratchet.Operation;
import ratchet.OperationList;
import ratchet.OperationType;
import ratchet.Parser;
import ratchet.Patcher;
import ratchet.RatchetException;
import ratchet.Registry;
import ratchet.StatefulPatchSession;

public final class RatchetFuzzer {
    private static final byte[] BASE = "ABCDEFGHIJKLMNOPQRSTUVWXYZ012345".getBytes(java.nio.charset.StandardCharsets.UTF_8);

    public static void main(String[] args) throws Exception {
        if (args.length == 0) {
            fuzzerTestOneInput(new byte[0]);
            return;
        }
        for (String path : args) {
            fuzzerTestOneInput(java.nio.file.Files.readAllBytes(java.nio.file.Paths.get(path)));
        }
    }

    public static void fuzzerTestOneInput(byte[] data) {
        if (!looksLikeDiff(data)) {
            exerciseStatefulSession(data);
            return;
        }
        OperationList list;
        try {
            list = Parser.parse(data);
        } catch (RatchetException ex) {
            return;
        }
        Registry registry = new Registry();
        for (Operation op : list.operations()) {
            if (op.type() == OperationType.CHAIN && !op.version().isEmpty()) {
                registry.put(op.version(), data);
            }
        }
        try {
            Patcher.apply(list, registry, BASE);
        } catch (RatchetException ex) {
            return;
        }
    }

    private static boolean looksLikeDiff(byte[] data) {
        byte[] magic = new byte[] { 'R', 'A', 'T', 'C', 'H', 'E', 'T', '1' };
        if (data == null || data.length < magic.length) {
            return false;
        }
        for (int i = 0; i < magic.length; i++) {
            if (data[i] != magic[i]) {
                return false;
            }
        }
        return true;
    }

    private static void exerciseStatefulSession(byte[] data) {
        StatefulPatchSession session = new StatefulPatchSession(BASE, "base");
        int pos = 0;
        while (pos < data.length) {
            int op = data[pos++] & 0xff;
            int slot = op & 0x07;
            try {
                switch ((op >>> 3) & 0x07) {
                    case 0:
                        session.register(name(slot), Parser.write(generatedPatch(data, pos, slot, (op >>> 6) & 0x03)));
                        pos = skipLiteral(data, pos);
                        break;
                    case 1:
                        session.applyNamed(name(slot));
                        break;
                    case 2:
                        OperationList direct = generatedPatch(data, pos, slot, (op >>> 6) & 0x03);
                        pos = skipLiteral(data, pos);
                        session.apply(direct);
                        break;
                    case 3:
                        session.checkpoint(name(slot));
                        break;
                    case 4:
                        session.restore(name(slot));
                        break;
                    case 5:
                        session.reset(resetBase(slot, (op >>> 6) & 0x03), "base");
                        break;
                    case 6:
                        byte[] current = session.current();
                        if (current.length > 0) {
                            current[0] ^= (byte) op;
                        }
                        session.currentVersion();
                        session.appliedCount();
                        break;
                    default:
                        session.register(name(slot), Parser.write(chainPatch(slot, (op >>> 6) & 0x03)));
                        break;
                }
            } catch (RatchetException ex) {
                continue;
            }
        }
    }

    private static OperationList generatedPatch(byte[] data, int pos, int slot, int variant) {
        OperationList list = new OperationList();
        list.setBaseVersion(variant == 0 ? "base" : name(Math.max(0, slot - 1)));
        list.setTargetVersion(name(slot));
        int length = pos < data.length ? ((data[pos] & 0x0f) + 1) : 1;
        byte[] literal = new byte[length];
        for (int i = 0; i < literal.length; i++) {
            int source = pos + 1 + i;
            literal[i] = source < data.length ? data[source] : (byte) ('A' + slot);
        }
        if ((slot & 1) == 0) {
            list.add(Operation.insert(literal));
            list.add(Operation.copy(0, Math.min(4, BASE.length)));
        } else if (variant == 0) {
            list.add(Operation.copy(slot, Math.min(4 + slot, BASE.length - slot)));
            list.add(Operation.insert(literal));
            list.add(Operation.delete(0, Math.min(slot, BASE.length)));
        } else {
            int copyLength = Math.min(3 + slot, BASE.length - slot);
            list.add(Operation.copy(slot, copyLength));
            list.add(Operation.delete(0, Math.min(2 + variant, BASE.length)));
            list.add(Operation.insert(literal));
            list.add(Operation.copy(slot, copyLength));
        }
        return list;
    }

    private static OperationList chainPatch(int slot, int variant) {
        OperationList list = new OperationList();
        list.setBaseVersion(variant == 0 ? "base" : name(Math.max(0, slot - 1)));
        list.setTargetVersion(name(slot));
        if (slot > 0) {
            list.add(Operation.chain(name(slot - 1)));
        }
        if (variant > 1) {
            list.add(Operation.chain(name((slot + 1) & 0x07)));
        }
        list.add(Operation.insert(new byte[] { (byte) ('0' + slot) }));
        return list;
    }

    private static byte[] resetBase(int slot, int variant) {
        if (variant == 0) {
            return BASE;
        }
        int length = Math.min(BASE.length, 4 + slot + variant);
        byte[] out = new byte[length];
        for (int i = 0; i < out.length; i++) {
            out[i] = BASE[(slot + i) % BASE.length];
        }
        return out;
    }

    private static int skipLiteral(byte[] data, int pos) {
        if (pos >= data.length) {
            return pos;
        }
        int length = (data[pos] & 0x0f) + 1;
        long next = (long) pos + 1L + (long) length;
        return next > data.length ? data.length : (int) next;
    }

    private static String name(int slot) {
        return "v" + slot;
    }
}
