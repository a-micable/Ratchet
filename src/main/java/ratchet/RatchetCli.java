package ratchet;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;

public final class RatchetCli {
    private RatchetCli() { }

    public static void main(String[] args) throws Exception {
        System.exit(run(args));
    }

    static int run(String[] args) throws IOException {
        if (args.length < 1) {
            return 2;
        }
        try {
            if ("diff".equals(args[0]) && args.length == 4) {
                byte[] base = Files.readAllBytes(Paths.get(args[1]));
                byte[] target = Files.readAllBytes(Paths.get(args[2]));
                Files.write(Paths.get(args[3]), Differ.diffBytes(base, target, "base", "target"));
                return 0;
            }
            if ("patch".equals(args[0]) && args.length == 4) {
                byte[] base = Files.readAllBytes(Paths.get(args[1]));
                byte[] diff = Files.readAllBytes(Paths.get(args[2]));
                Files.write(Paths.get(args[3]), Patcher.applyDiff(diff, new Registry(), base));
                return 0;
            }
            if ("verify".equals(args[0]) && args.length == 2) {
                Parser.verify(Files.readAllBytes(Paths.get(args[1])));
                return 0;
            }
            if ("chain".equals(args[0]) && args.length == 3) {
                byte[] diff = Files.readAllBytes(Paths.get(args[1]));
                OperationList ops = Parser.parse(diff);
                Registry registry = new Registry();
                registry.put(args[2], diff);
                OperationList flat = Resolver.resolve(ops, registry);
                for (int i = 0; i < flat.size(); i++) {
                    Operation op = flat.get(i);
                    System.out.println(i + " " + op.type() + " offset=" + op.offset() + " length=" + op.length() + " version=" + op.version());
                }
                return 0;
            }
            return 2;
        } catch (RatchetException ex) {
            return 1;
        }
    }
}
