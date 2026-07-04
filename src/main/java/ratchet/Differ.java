package ratchet;

import java.util.Arrays;

public final class Differ {
    private Differ() { }

    public static OperationList diff(byte[] base, byte[] target, String baseName, String targetName) {
        OperationList out = new OperationList();
        out.setBaseVersion(baseName);
        out.setTargetVersion(targetName);
        int targetPos = 0;
        int insertStart = 0;
        while (targetPos < target.length) {
            Match match = longest(base, target, targetPos);
            if (match.length >= 4) {
                if (targetPos > insertStart) {
                    out.add(Operation.insert(Arrays.copyOfRange(target, insertStart, targetPos)));
                }
                out.add(Operation.copy(match.offset, match.length));
                targetPos += match.length;
                insertStart = targetPos;
            } else {
                targetPos++;
            }
        }
        if (targetPos > insertStart) {
            out.add(Operation.insert(Arrays.copyOfRange(target, insertStart, targetPos)));
        }
        if (base.length > 0) {
            out.add(Operation.delete(0, base.length));
        }
        return out;
    }

    public static byte[] diffBytes(byte[] base, byte[] target, String baseName, String targetName) {
        return Parser.write(diff(base, target, baseName, targetName));
    }

    private static Match longest(byte[] base, byte[] target, int targetPos) {
        Match best = new Match(0, 0);
        for (int basePos = 0; basePos < base.length; basePos++) {
            int length = 0;
            while (basePos + length < base.length
                    && targetPos + length < target.length
                    && base[basePos + length] == target[targetPos + length]) {
                length++;
            }
            if (length > best.length) {
                best = new Match(basePos, length);
            }
        }
        return best;
    }

    private static final class Match {
        final int offset;
        final int length;

        Match(int offset, int length) {
            this.offset = offset;
            this.length = length;
        }
    }
}
