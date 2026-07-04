import ratchet.Operation;
import ratchet.OperationList;
import ratchet.OperationType;
import ratchet.Parser;
import ratchet.Patcher;
import ratchet.RatchetException;
import ratchet.Registry;

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
}
