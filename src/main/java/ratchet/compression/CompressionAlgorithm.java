package ratchet.compression;

import ratchet.RatchetException;
import ratchet.RatchetStatus;

/**
 * Abstract base for compression algorithms.
 * Supports multiple compression backends (LZMA, Brotli, DEFLATE, LZ4).
 * Compression is applied to literal insert data to reduce size.
 */
public abstract class CompressionAlgorithm {
    protected final int level;
    protected final String name;
    protected final byte algorithmId;

    protected CompressionAlgorithm(String name, byte algorithmId, int level) {
        if (level < 0 || level > 11) {
            throw new IllegalArgumentException("Level must be 0-11");
        }
        this.name = name;
        this.algorithmId = algorithmId;
        this.level = level;
    }

    public abstract byte[] compress(byte[] data) throws RatchetException;
    public abstract byte[] decompress(byte[] data, int maxSize) throws RatchetException;
    
    public String getName() { return name; }
    public byte getAlgorithmId() { return algorithmId; }
    public int getLevel() { return level; }
    
    public CompressionStats estimateCompression(byte[] data) {
        try {
            byte[] compressed = compress(data);
            return new CompressionStats(data.length, compressed.length, getLevel());
        } catch (RatchetException e) {
            return new CompressionStats(data.length, data.length, getLevel());
        }
    }

    public static class CompressionStats {
        public final long originalSize;
        public final long compressedSize;
        public final int compressionLevel;
        public final double ratio;

        public CompressionStats(long original, long compressed, int level) {
            this.originalSize = original;
            this.compressedSize = compressed;
            this.compressionLevel = level;
            this.ratio = original > 0 ? (double) compressed / original : 1.0;
        }
    }
}
