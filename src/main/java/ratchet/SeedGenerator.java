package ratchet;

import java.io.File;
import java.nio.file.Files;

public final class SeedGenerator {
    private SeedGenerator() { }

    public static void main(String[] args) throws Exception {
        File dir = new File("fuzz/corpus/patch_fuzzer");
        dir.mkdirs();
        byte[] base = "ABCDEFGHIJKLMNOPQRSTUVWXYZ012345".getBytes("UTF-8");
        write(dir, "insert_min_1.bin", Differ.diffBytes(new byte[0], "hello".getBytes("UTF-8"), "base", "target"));
        write(dir, "insert_min_2.bin", Differ.diffBytes(new byte[0], "worldworld".getBytes("UTF-8"), "base", "target"));
        write(dir, "copy_only_1.bin", Differ.diffBytes(base, java.util.Arrays.copyOfRange(base, 0, 8), "base", "target"));
        write(dir, "copy_only_2.bin", Differ.diffBytes(base, java.util.Arrays.copyOfRange(base, 4, 16), "base", "target"));
        OperationList mixedOne = new OperationList();
        mixedOne.add(Operation.copy(2, 6));
        mixedOne.add(Operation.delete(0, 20));
        mixedOne.add(Operation.insert(repeat((byte) 'A', 128)));
        mixedOne.add(Operation.copy(2, 6));
        write(dir, "mixed_insert_copy_1.bin", Parser.write(mixedOne));
        OperationList mixedTwo = new OperationList();
        mixedTwo.add(Operation.copy(4, 8));
        mixedTwo.add(Operation.delete(0, 24));
        mixedTwo.add(Operation.insert(repeat((byte) 'B', 256)));
        mixedTwo.add(Operation.copy(4, 8));
        write(dir, "mixed_insert_copy_2.bin", Parser.write(mixedTwo));
        OperationList childOne = new OperationList();
        childOne.add(Operation.insert("ONE".getBytes("UTF-8")));
        write(dir, "chain_child_one.bin", Parser.write(childOne));
        OperationList chainOne = new OperationList();
        chainOne.add(Operation.chain("chain_child_one"));
        chainOne.add(Operation.insert("X".getBytes("UTF-8")));
        write(dir, "chain_one.bin", Parser.write(chainOne));
        OperationList childTwoA = new OperationList();
        childTwoA.add(Operation.insert("TWO".getBytes("UTF-8")));
        write(dir, "chain_child_two_a.bin", Parser.write(childTwoA));
        OperationList childTwoB = new OperationList();
        childTwoB.add(Operation.chain("chain_child_two_a"));
        childTwoB.add(Operation.insert("MID".getBytes("UTF-8")));
        write(dir, "chain_child_two_b.bin", Parser.write(childTwoB));
        OperationList chainTwo = new OperationList();
        chainTwo.add(Operation.chain("chain_child_two_b"));
        chainTwo.add(Operation.insert("END".getBytes("UTF-8")));
        write(dir, "chain_two.bin", Parser.write(chainTwo));
        write(dir, "stateful_register_apply_checkpoint.bin", new byte[] {
            0x00, 0x03, 'a', 'b', 'c',
            0x08,
            0x18,
            0x11, 0x02, 'x', 'y',
            0x19,
            0x20
        });
        write(dir, "stateful_chain_restore_reset.bin", new byte[] {
            0x3f,
            0x3e,
            0x16,
            0x18,
            0x26,
            0x2d,
            0x08
        });
    }

    private static byte[] repeat(byte value, int count) {
        byte[] out = new byte[count];
        java.util.Arrays.fill(out, value);
        return out;
    }

    private static void write(File dir, String name, byte[] data) throws Exception {
        Files.write(new File(dir, name).toPath(), data);
    }
}
