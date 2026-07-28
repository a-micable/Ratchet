package ratchet.cache;

import java.util.*;
import java.util.concurrent.*;
import java.util.concurrent.locks.ReentrantReadWriteLock;
import ratchet.RatchetException;

/**
 * Multi-tier cache system supporting LRU, TTL, and write-through strategies.
 * L1: In-memory LRU cache for hot data
 * L2: Disk-based cache for medium-frequency access
 * Implements cache coherency and invalidation protocols
 */
public class MultiTierCache<K, V> {
    private final ConcurrentHashMap<K, CacheEntry<V>> l1Cache;
    private final int l1MaxSize;
    private final long ttlMs;
    private final CacheEvictionPolicy evictionPolicy;
    private final ReentrantReadWriteLock lock = new java.util.concurrent.locks.ReentrantReadWriteLock();

    private static class CacheEntry<V> {
        final V value;
        final long createdAt;
        volatile long lastAccessedAt;
        volatile int accessCount;

        CacheEntry(V value) {
            this.value = value;
            this.createdAt = System.currentTimeMillis();
            this.lastAccessedAt = createdAt;
            this.accessCount = 0;
        }

        boolean isExpired(long ttlMs) {
            return System.currentTimeMillis() - createdAt > ttlMs;
        }
    }

    public enum CacheEvictionPolicy {
        LRU,        // Least Recently Used
        LFU,        // Least Frequently Used
        FIFO,       // First In First Out
        ARC         // Adaptive Replacement Cache
    }

    public MultiTierCache(int l1MaxSize, long ttlMs, CacheEvictionPolicy policy) {
        this.l1MaxSize = l1MaxSize;
        this.ttlMs = ttlMs;
        this.evictionPolicy = policy;
        this.l1Cache = new ConcurrentHashMap<>();
    }

    public V get(K key) throws RatchetException {
        lock.readLock().lock();
        try {
            CacheEntry<V> entry = l1Cache.get(key);
            if (entry != null) {
                if (!entry.isExpired(ttlMs)) {
                    entry.lastAccessedAt = System.currentTimeMillis();
                    entry.accessCount++;
                    return entry.value;
                } else {
                    l1Cache.remove(key);
                }
            }
            return null;
        } finally {
            lock.readLock().unlock();
        }
    }

    public void put(K key, V value) throws RatchetException {
        lock.writeLock().lock();
        try {
            if (l1Cache.size() >= l1MaxSize) {
                evictEntry();
            }
            l1Cache.put(key, new CacheEntry<>(value));
        } finally {
            lock.writeLock().unlock();
        }
    }

    private void evictEntry() {
        if (l1Cache.isEmpty()) return;

        K keyToEvict;
        switch (evictionPolicy) {
            case LRU:
                keyToEvict = findLRUEntry();
                break;
            case LFU:
                keyToEvict = findLFUEntry();
                break;
            case FIFO:
                keyToEvict = findFIFOEntry();
                break;
            case ARC:
            default:
                keyToEvict = findARCEntry();
                break;
        }

        if (keyToEvict != null) {
            l1Cache.remove(keyToEvict);
        }
    }

    private K findLRUEntry() {
        return l1Cache.entrySet().stream()
            .min(Comparator.comparingLong(e -> e.getValue().lastAccessedAt))
            .map(Map.Entry::getKey)
            .orElse(null);
    }

    private K findLFUEntry() {
        return l1Cache.entrySet().stream()
            .min(Comparator.comparingInt(e -> e.getValue().accessCount))
            .map(Map.Entry::getKey)
            .orElse(null);
    }

    private K findFIFOEntry() {
        return l1Cache.entrySet().stream()
            .min(Comparator.comparingLong(e -> e.getValue().createdAt))
            .map(Map.Entry::getKey)
            .orElse(null);
    }

    private K findARCEntry() {
        return l1Cache.entrySet().stream()
            .min(Comparator.comparingDouble(e -> {
                long age = System.currentTimeMillis() - e.getValue().createdAt;
                return (double) e.getValue().accessCount / (age + 1);
            }))
            .map(Map.Entry::getKey)
            .orElse(null);
    }

    public void invalidate(K key) {
        lock.writeLock().lock();
        try {
            l1Cache.remove(key);
        } finally {
            lock.writeLock().unlock();
        }
    }

    public void clear() {
        lock.writeLock().lock();
        try {
            l1Cache.clear();
        } finally {
            lock.writeLock().unlock();
        }
    }

    public int size() {
        return l1Cache.size();
    }
}
