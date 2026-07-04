package ratchet;

import java.util.Arrays;

public final class RatchetTest {
    private static int failures;

    public static void main(String[] args) throws Exception {
        testRoundTrip();
        testEmptyBase();
        testEmptyTarget();
        testCrcReject();
        testCopy();
        testInsert();
        testDelete();
        testMixed();
        testChainOne();
        testChainTwo();
        testIdentical();
        testNoCommon();
        testCompressor();
        testRegistryMissing();
        testWriteParse();
        if (failures != 0) {
            throw new AssertionError(failures + " failures");
        }
        System.out.println("Java Ratchet tests passed");
    }

    private static void check(boolean condition, String name) {
        if (!condition) {
            failures++;
            System.out.println("FAIL " + name);
        }
    }

    private static void round(byte[] base, byte[] target) throws Exception {
        byte[] diff = Differ.diffBytes(base, target, "b", "t");
        byte[] out = Patcher.applyDiff(diff, new Registry(), base);
        check(Arrays.equals(out, target), "round");
    }

    private static void testRoundTrip() throws Exception { round(bytes("abcd"), bytes("abXYcd")); }
    private static void testEmptyBase() throws Exception { round(new byte[0], bytes("hello")); }
    private static void testEmptyTarget() throws Exception { round(bytes("hello"), new byte[0]); }
    private static void testCrcReject() throws Exception { byte[] diff = Differ.diffBytes(bytes("abc"), bytes("xyz"), "b", "t"); diff[20] ^= 1; try { Parser.verify(diff); check(false, "crc"); } catch (RatchetException ex) { check(ex.status() == RatchetStatus.CRC, "crc status"); } }
    private static void testCopy() throws Exception { OperationList list = new OperationList(); list.add(Operation.copy(1, 3)); byte[] out = Patcher.apply(list, new Registry(), bytes("abcdef")); check(out.length == 9, "copy size"); }
    private static void testInsert() throws Exception { OperationList list = new OperationList(); list.add(Operation.insert(bytes("ZZ"))); byte[] out = Patcher.apply(list, new Registry(), bytes("abc")); check(out.length == 5, "insert size"); }
    private static void testDelete() throws Exception { OperationList list = new OperationList(); list.add(Operation.delete(2, 2)); byte[] out = Patcher.apply(list, new Registry(), bytes("abcdef")); check(Arrays.equals(out, bytes("abef")), "delete"); }
    private static void testMixed() throws Exception { OperationList list = new OperationList(); list.add(Operation.insert(bytes("XY"))); list.add(Operation.copy(0, 2)); list.add(Operation.delete(1, 1)); byte[] out = Patcher.apply(list, new Registry(), bytes("abcdef")); check(out.length == 9, "mixed"); }
    private static void testChainOne() throws Exception { OperationList child = new OperationList(); child.add(Operation.insert(bytes("D"))); byte[] childBytes = Parser.write(child); OperationList parent = new OperationList(); parent.add(Operation.chain("v1")); Registry registry = new Registry(); registry.put("v1", childBytes); byte[] out = Patcher.apply(parent, registry, bytes("abc")); check(out.length == 4, "chain one"); }
    private static void testChainTwo() throws Exception { OperationList one = new OperationList(); one.add(Operation.insert(bytes("D"))); OperationList two = new OperationList(); two.add(Operation.chain("v1")); two.add(Operation.insert(bytes("E"))); OperationList root = new OperationList(); root.add(Operation.chain("v2")); Registry registry = new Registry(); registry.put("v1", Parser.write(one)); registry.put("v2", Parser.write(two)); byte[] out = Patcher.apply(root, registry, bytes("abc")); check(out.length == 5, "chain two"); }
    private static void testIdentical() throws Exception { OperationList ops = Differ.diff(bytes("same same"), bytes("same same"), "b", "t"); check(ops.size() == 2 && ops.get(0).type() == OperationType.COPY, "identical"); }
    private static void testNoCommon() throws Exception { OperationList ops = Differ.diff(bytes("abcd"), bytes("WXYZ"), "b", "t"); check(ops.size() == 2 && ops.get(0).type() == OperationType.INSERT, "no common"); }
    private static void testCompressor() throws Exception { byte[] raw = bytes("AAAAAAAABCDABCDZZZZZZ"); byte[] out = Compressor.decompressLiteral(Compressor.compressLiteral(raw)); check(Arrays.equals(raw, out), "compress"); }
    private static void testRegistryMissing() { try { new Registry().get("missing"); check(false, "missing"); } catch (RatchetException ex) { check(ex.status() == RatchetStatus.NOT_FOUND, "missing status"); } }
    private static void testWriteParse() throws Exception { OperationList list = new OperationList(); list.add(Operation.insert(bytes("abc"))); OperationList parsed = Parser.parse(Parser.write(list)); check(parsed.size() == 1, "parse write"); }
    private static byte[] bytes(String text) { return text.getBytes(java.nio.charset.StandardCharsets.UTF_8); }
}
