package ratchet;

import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

public final class Registry {
    private final Map<String, byte[]> versions = new HashMap<String, byte[]>();

    public void put(String name, byte[] diffBytes) {
        versions.put(name, Arrays.copyOf(diffBytes, diffBytes.length));
    }

    public byte[] get(String name) throws RatchetException {
        byte[] value = versions.get(name);
        if (value == null) {
            throw new RatchetException(RatchetStatus.NOT_FOUND, "version not found");
        }
        return Arrays.copyOf(value, value.length);
    }
}
