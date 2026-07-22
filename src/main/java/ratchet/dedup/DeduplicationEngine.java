package ratchet.dedup;

import ratchet.RatchetException;
import java.util.*;
import java.security.MessageDigest;

/**
 * Content-addressable deduplication system using SHA-256 hashing.
 * Reduces storage by identifying and eliminating duplicate chunks.
 */
public class DeduplicationEngine {
    private final Map<String, ChunkMetadata> chunkIndex;
    private final int chunkSize;

    public static class ChunkMetadata {
        public final String sha256;
        public final long size;
        public volatile long referenceCount;
        public final long createdAt;

        public ChunkMetadata(String sha256, long size) {
            this.sha256 = sha256;
            this.size = size;
            this.referenceCount = 1;
            this.createdAt = System.currentTimeMillis();
        }
    }

    public DeduplicationEngine(int chunkSize) {
        this.chunkSize = chunkSize;
        this.chunkIndex = Collections.synchronizedMap(new HashMap<>());
    }

    public List<String> deduplicateContent(byte[] data) throws RatchetException {
        List<String> chunkHashes = new ArrayList<>();
        
        for (int i = 0; i < data.length; i += chunkSize) {
            int end = Math.min(i + chunkSize, data.length);
            byte[] chunk = Arrays.copyOfRange(data, i, end);
            String hash = hashChunk(chunk);
            chunkHashes.add(hash);

            ChunkMetadata metadata = chunkIndex.get(hash);
            if (metadata != null) {
                metadata.referenceCount++;
            } else {
                chunkIndex.put(hash, new ChunkMetadata(hash, chunk.length));
            }
        }

        return chunkHashes;
    }

    public byte[] reconstructContent(List<String> chunkHashes, java.util.Map<String, byte[]> chunkStore) 
            throws RatchetException {
        java.io.ByteArrayOutputStream output = new java.io.ByteArrayOutputStream();
        
        for (String hash : chunkHashes) {
            byte[] chunk = chunkStore.get(hash);
            if (chunk == null) {
                throw new RatchetException(ratchet.RatchetStatus.NOT_FOUND,
                    "Chunk not found: " + hash);
            }
            try {
                output.write(chunk);
            } catch (java.io.IOException e) {
                throw new RatchetException(ratchet.RatchetStatus.IO_ERROR,
                    "Failed to reconstruct content");
            }
        }

        return output.toByteArray();
    }

    private String hashChunk(byte[] chunk) throws RatchetException {
        try {
            MessageDigest digest = MessageDigest.getInstance("SHA-256");
            byte[] hash = digest.digest(chunk);
            return bytesToHex(hash);
        } catch (java.security.NoSuchAlgorithmException e) {
            throw new RatchetException(ratchet.RatchetStatus.INTERNAL,
                "SHA-256 not available");
        }
    }

    private String bytesToHex(byte[] bytes) {
        StringBuilder sb = new StringBuilder();
        for (byte b : bytes) {
            sb.append(String.format("%02x", b));
        }
        return sb.toString();
    }

    public Map<String, ChunkMetadata> getChunkIndex() {
        return Collections.unmodifiableMap(chunkIndex);
    }

    public long getTotalStorageSize() {
        return chunkIndex.values().stream()
            .mapToLong(m -> m.size)
            .sum();
    }

    public long getDeduplicationRatio() {
        long logicalSize = chunkIndex.values().stream()
            .mapToLong(m -> m.size * m.referenceCount)
            .sum();
        long physicalSize = getTotalStorageSize();
        
        return physicalSize > 0 ? (logicalSize * 100) / physicalSize : 0;
    }
}
