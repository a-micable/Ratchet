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
        write(dir, "moved_blocks_suffix_automaton.bin",
            Differ.diffBytes(base, concat(slice(base, 16, 32), "::".getBytes("UTF-8"), slice(base, 0, 16)), "base", "target"));
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
        write(dir, "stateful_restore_metadata.bin", new byte[] {
            0x01, 0x03, 'v', 'o', 'n',
            0x09,
            0x19,
            0x42, 0x04, 'n', 'e', 'x', 't',
            0x18,
            0x21,
            0x12, 0x02, 'z', 'z'
        });
        write(dir, "stateful_recover_after_errors.bin", new byte[] {
            0x08,
            0x00, 0x02, 'o', 'k',
            0x08,
            0x38,
            0x47,
            0x10, 0x03, 'm', 'u', 't',
            0x30,
            0x28,
            0x18
        });
        write(dir, "stateful_variant_reset_alias.bin", new byte[] {
            (byte) 0xad,
            (byte) 0xc3, 0x04, 'd', 'a', 't', 'a',
            (byte) 0xca,
            (byte) 0x92, 0x03, 'x', 'y', 'z',
            (byte) 0xd9,
            0x22,
            (byte) 0xbe
        });
    }

    private static byte[] repeat(byte value, int count) {
        byte[] out = new byte[count];
        java.util.Arrays.fill(out, value);
        return out;
    }

    private static byte[] slice(byte[] data, int start, int end) {
        return java.util.Arrays.copyOfRange(data, start, end);
    }

    private static byte[] concat(byte[]... arrays) {
        int length = 0;
        for (byte[] array : arrays) {
            length += array.length;
        }
        byte[] out = new byte[length];
        int pos = 0;
        for (byte[] array : arrays) {
            System.arraycopy(array, 0, out, pos, array.length);
            pos += array.length;
        }
        return out;
    }

    private static void write(File dir, String name, byte[] data) throws Exception {
        Files.write(new File(dir, name).toPath(), data);
    }
}
