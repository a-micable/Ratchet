package ratchet.storage;

import ratchet.RatchetException;
import ratchet.RatchetStatus;
import java.nio.file.*;
import java.util.*;

/**
 * Pluggable storage backend interface.
 * Supports local filesystem, cloud storage, and distributed backends.
 */
public interface StorageBackend {
    byte[] get(String key) throws RatchetException;
    void put(String key, byte[] value) throws RatchetException;
    void delete(String key) throws RatchetException;
    boolean exists(String key) throws RatchetException;
    List<String> list(String prefix) throws RatchetException;
    long getSize(String key) throws RatchetException;
}

public class LocalFileStorageBackend implements StorageBackend {
    private final Path basePath;

    public LocalFileStorageBackend(Path basePath) throws RatchetException {
        this.basePath = basePath;
        try {
            Files.createDirectories(basePath);
        } catch (java.io.IOException e) {
            throw new RatchetException(RatchetStatus.IO_ERROR,
                "Failed to create storage directory: " + e.getMessage());
        }
    }

    @Override
    public byte[] get(String key) throws RatchetException {
        try {
            Path filePath = resolvePath(key);
            return Files.readAllBytes(filePath);
        } catch (java.io.IOException e) {
            throw new RatchetException(RatchetStatus.NOT_FOUND,
                "Failed to read file: " + e.getMessage());
        }
    }

    @Override
    public void put(String key, byte[] value) throws RatchetException {
        try {
            Path filePath = resolvePath(key);
            Files.createDirectories(filePath.getParent());
            Files.write(filePath, value);
        } catch (java.io.IOException e) {
            throw new RatchetException(RatchetStatus.IO_ERROR,
                "Failed to write file: " + e.getMessage());
        }
    }

    @Override
    public void delete(String key) throws RatchetException {
        try {
            Path filePath = resolvePath(key);
            Files.deleteIfExists(filePath);
        } catch (java.io.IOException e) {
            throw new RatchetException(RatchetStatus.IO_ERROR,
                "Failed to delete file: " + e.getMessage());
        }
    }

    @Override
    public boolean exists(String key) throws RatchetException {
        try {
            return Files.exists(resolvePath(key));
        } catch (Exception e) {
            return false;
        }
    }

    @Override
    public List<String> list(String prefix) throws RatchetException {
        try {
            Path prefixPath = resolvePath(prefix);
            List<String> result = new ArrayList<>();
            Files.walk(prefixPath)
                .filter(Files::isRegularFile)
                .forEach(p -> result.add(basePath.relativize(p).toString()));
            return result;
        } catch (java.io.IOException e) {
            throw new RatchetException(RatchetStatus.IO_ERROR,
                "Failed to list files: " + e.getMessage());
        }
    }

    @Override
    public long getSize(String key) throws RatchetException {
        try {
            return Files.size(resolvePath(key));
        } catch (java.io.IOException e) {
            throw new RatchetException(RatchetStatus.NOT_FOUND,
                "Failed to get file size: " + e.getMessage());
        }
    }

    private Path resolvePath(String key) throws RatchetException {
        Path resolved = basePath.resolve(key).normalize();
        if (!resolved.startsWith(basePath)) {
            throw new RatchetException(RatchetStatus.INVALID,
                "Path traversal attempt detected");
        }
        return resolved;
    }
}
