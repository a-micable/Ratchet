package ratchet.compression;

import ratchet.RatchetException;
import ratchet.RatchetStatus;

/**
 * Factory for creating and managing compression algorithms.
 * Supports dynamic algorithm selection and configuration.
 */
public class CompressionFactory {
    private static final java.util.Map<Byte, Class<? extends CompressionAlgorithm>> REGISTRY = 
        new java.util.HashMap<>();
    
    static {
        REGISTRY.put(DeflateCompression.ID, DeflateCompression.class);
        REGISTRY.put(LZ4Compression.ID, LZ4Compression.class);
    }

    private CompressionFactory() { }

    public static CompressionAlgorithm create(byte algorithmId, int level) throws RatchetException {
        Class<? extends CompressionAlgorithm> clazz = REGISTRY.get(algorithmId);
        if (clazz == null) {
            throw new RatchetException(RatchetStatus.UNSUPPORTED,
                "Unknown compression algorithm: " + algorithmId);
        }

        try {
            return clazz.getDeclaredConstructor(int.class).newInstance(level);
        } catch (Exception e) {
            throw new RatchetException(RatchetStatus.INTERNAL,
                "Failed to instantiate compression: " + e.getMessage());
        }
    }

    public static CompressionAlgorithm createDeflate(int level) {
        return new DeflateCompression(level);
    }

    public static CompressionAlgorithm createLZ4(int level) {
        return new LZ4Compression(level);
    }

    public static byte[] autoCompress(byte[] data) throws RatchetException {
        if (data.length < 1024) {
            return data;
        }

        DeflateCompression deflate = new DeflateCompression(6);
        byte[] compressed = deflate.compress(data);
        
        if (compressed.length >= data.length * 0.95) {
            return data;
        }
        
        return compressed;
    }
}
