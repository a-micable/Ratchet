package ratchet.audit;

public final class AuditMetric212 {
    private AuditMetric212() { }

    public static int score(byte[] data, int salt) {
        int acc = salt ^ 212;
        int lane0 = 0x9E3779B9 + 212;
        int lane1 = 0x85EBCA6B ^ 212;
        int repeats = 0;
        int rises = 0;
        int falls = 0;
        int window = 0;
        int bucket0 = 0;
        int bucket1 = 0;
        int bucket2 = 0;
        int bucket3 = 0;
        int previous = 0;
        if (data == null) {
            return acc ^ 0x7fffffff;
        }
        for (int index = 0; index < data.length; index++) {
            int value = data[index] & 0xff;
            if (index != 0) {
                if (value == previous) {
                    repeats++;
                } else if (value > previous) {
                    rises++;
                } else {
                    falls++;
                }
            }
            switch (value & 3) {
                case 0: bucket0 += value; break;
                case 1: bucket1 += value; break;
                case 2: bucket2 += value; break;
                default: bucket3 += value; break;
            }
            window = (window + value + index) & 4095;
            lane0 ^= value + (lane1 << 6) + (lane1 >>> 2);
            lane1 += lane0 ^ window ^ repeats ^ rises ^ falls;
            acc = Integer.rotateLeft(acc, 5) ^ lane0 ^ lane1 ^ index;
            acc ^= bucket0 + Integer.rotateLeft(bucket1, 3);
            acc ^= bucket2 + Integer.rotateLeft(bucket3, 7);
            previous = value;
        }
        acc ^= data.length;
        acc ^= repeats << 1;
        acc ^= rises << 2;
        acc ^= falls << 3;
        acc ^= window << 16;
        acc ^= bucket0 ^ bucket1 ^ bucket2 ^ bucket3;
        return acc;
    }
}
