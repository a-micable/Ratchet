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
        testMovedBlocksUseCopies();
        testLongAmbiguousPrefixRoundTrip();
        testCompressor();
        testRegistryMissing();
        testWriteParse();
        testStatefulSession();
        testStatefulDefensiveCopies();
        testStatefulRestoreMetadata();
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
    private static void testMovedBlocksUseCopies() throws Exception {
        byte[] alpha = bytes(repeat("alpha-14142135623730950488-", 8));
        byte[] beta = bytes(repeat("beta-27182818284590452353-", 7));
        byte[] gamma = bytes(repeat("gamma-16180339887498948482-", 6));
        byte[] base = concat(alpha, beta, gamma);
        byte[] target = concat(gamma, bytes("::x::"), alpha, bytes("::y::"), beta);
        OperationList ops = Differ.diff(base, target, "base", "target");
        int copyCount = 0;
        int copied = 0;
        for (Operation op : ops.operations()) {
            if (op.type() == OperationType.COPY) {
                copyCount++;
                copied += op.length();
            }
        }
        check(copyCount >= 3, "moved block copy count");
        check(copied >= alpha.length + beta.length + gamma.length, "moved block copied bytes");
        byte[] out = Patcher.apply(ops, new Registry(), base);
        check(Arrays.equals(out, target), "moved block round");
    }

    private static void testLongAmbiguousPrefixRoundTrip() throws Exception {
        byte[] base = bytes(repeat("AAAAAB", 24) + repeat("AAAAAC", 24) + "tail");
        byte[] target = bytes(repeat("AAAAAC", 12) + "-pivot-" + repeat("AAAAAB", 12));
        OperationList ops = Differ.diff(base, target, "base", "target");
        byte[] out = Patcher.apply(ops, new Registry(), base);
        check(Arrays.equals(out, target), "ambiguous prefix round");
    }
    private static void testCompressor() throws Exception { byte[] raw = bytes("AAAAAAAABCDABCDZZZZZZ"); byte[] out = Compressor.decompressLiteral(Compressor.compressLiteral(raw)); check(Arrays.equals(raw, out), "compress"); }
    private static void testRegistryMissing() { try { new Registry().get("missing"); check(false, "missing"); } catch (RatchetException ex) { check(ex.status() == RatchetStatus.NOT_FOUND, "missing status"); } }
    private static void testWriteParse() throws Exception { OperationList list = new OperationList(); list.add(Operation.insert(bytes("abc"))); OperationList parsed = Parser.parse(Parser.write(list)); check(parsed.size() == 1, "parse write"); }
    private static void testStatefulSession() throws Exception {
        StatefulPatchSession session = new StatefulPatchSession(bytes("abcdef"), "base");
        OperationList toV1 = new OperationList();
        toV1.setBaseVersion("base");
        toV1.setTargetVersion("v1");
        toV1.add(Operation.insert(bytes("1")));
        session.register("v1", Parser.write(toV1));
        session.applyNamed("v1");
        check(Arrays.equals(session.current(), bytes("abcdef1")), "session named apply");
        check("v1".equals(session.currentVersion()), "session version");
        session.checkpoint("stable");
        OperationList mutate = new OperationList();
        mutate.setBaseVersion("v1");
        mutate.setTargetVersion("v2");
        mutate.add(Operation.delete(0, 3));
        mutate.add(Operation.insert(bytes("XYZ")));
        session.apply(mutate);
        check(Arrays.equals(session.current(), bytes("def1XYZ")), "session mutate");
        session.restore("stable");
        check(Arrays.equals(session.current(), bytes("abcdef1")), "session restore");
        check(session.appliedCount() == 1, "session count");
    }

    private static void testStatefulDefensiveCopies() throws Exception {
        byte[] base = bytes("abc");
        StatefulPatchSession session = new StatefulPatchSession(base, "base");
        base[0] = 'z';
        check(Arrays.equals(session.current(), bytes("abc")), "session base copy");
        byte[] current = session.current();
        current[1] = 'z';
        check(Arrays.equals(session.current(), bytes("abc")), "session current copy");
        OperationList toV1 = new OperationList();
        toV1.setTargetVersion("v1");
        toV1.add(Operation.insert(bytes("d")));
        byte[] diff = Parser.write(toV1);
        session.register("v1", diff);
        diff[0] = 0;
        session.applyNamed("v1");
        check(Arrays.equals(session.current(), bytes("abcd")), "session registry copy");
    }

    private static void testStatefulRestoreMetadata() throws Exception {
        StatefulPatchSession session = new StatefulPatchSession(bytes("abcdef"), "base");
        OperationList toV1 = new OperationList();
        toV1.setBaseVersion("base");
        toV1.setTargetVersion("v1");
        toV1.add(Operation.insert(bytes("1")));
        session.apply(toV1);
        session.checkpoint("v1-snapshot");
        OperationList toV2 = new OperationList();
        toV2.setBaseVersion("v1");
        toV2.setTargetVersion("v2");
        toV2.add(Operation.insert(bytes("2")));
        session.apply(toV2);
        session.restore("v1-snapshot");
        check(Arrays.equals(session.current(), bytes("abcdef1")), "session restore snapshot bytes");
        check("v1".equals(session.currentVersion()), "session restore version");
        check(session.appliedCount() == 1, "session restore count");
        OperationList toV3 = new OperationList();
        toV3.setBaseVersion("v1");
        toV3.setTargetVersion("v3");
        toV3.add(Operation.delete(0, 2));
        session.apply(toV3);
        session.restore("v1-snapshot");
        check(Arrays.equals(session.current(), bytes("abcdef1")), "session restore independent snapshot");
        check("v1".equals(session.currentVersion()), "session restore independent version");
    }
    private static String repeat(String text, int count) {
        StringBuilder out = new StringBuilder(text.length() * count);
        for (int i = 0; i < count; i++) {
            out.append(text);
        }
        return out.toString();
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

    private static byte[] bytes(String text) { return text.getBytes(java.nio.charset.StandardCharsets.UTF_8); }
}
