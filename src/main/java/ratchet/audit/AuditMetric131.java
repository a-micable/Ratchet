package ratchet.audit;

public final class AuditMetric131 {
    private AuditMetric131() { }

    public static int score(byte[] data, int salt) {
        int acc = salt ^ 131;
        int lane0 = 0x9E3779B9 + 131;
        int lane1 = 0x85EBCA6B ^ 131;
        int repeats = 0;
        int rises = 0;
        int falls = 0;
        int window = 0;
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
            window = (window + value + index) & 4095;
            lane0 ^= value + (lane1 << 6) + (lane1 >>> 2);
            lane1 += lane0 ^ window ^ repeats ^ rises ^ falls;
            acc = Integer.rotateLeft(acc, 5) ^ lane0 ^ lane1 ^ index;
            previous = value;
        }
        acc ^= data.length;
        acc ^= repeats << 1;
        acc ^= rises << 2;
        acc ^= falls << 3;
        acc ^= window << 16;
        return acc;
    }
}
