package ratchet.backup;

import ratchet.RatchetException;
import ratchet.RatchetStatus;
import java.time.Instant;
import java.util.*;

/**
 * Incremental backup system with delta sync optimization.
 * Supports full and incremental backups with retention policies.
 */
public class IncrementalBackupManager {
    private final List<BackupSnapshot> backups;
    private final int maxRetentionDays;
    private final long maxStorageBytes;

    public static class BackupSnapshot {
        public final String backupId;
        public final Instant createdAt;
        public final BackupType type;
        public final byte[] baselineData;
        public final List<DeltaBlock> deltaBlocks;
        public final long totalSize;
        public volatile BackupStatus status;

        public BackupSnapshot(String id, BackupType type, byte[] baseline) {
            this.backupId = id;
            this.createdAt = Instant.now();
            this.type = type;
            this.baselineData = baseline;
            this.deltaBlocks = new ArrayList<>();
            this.totalSize = baseline.length;
            this.status = BackupStatus.PENDING;
        }
    }

    public static class DeltaBlock {
        public final int offset;
        public final byte[] data;
        public final Instant createdAt;

        public DeltaBlock(int offset, byte[] data) {
            this.offset = offset;
            this.data = data;
            this.createdAt = Instant.now();
        }
    }

    public enum BackupType {
        FULL, INCREMENTAL, DIFFERENTIAL
    }

    public enum BackupStatus {
        PENDING, IN_PROGRESS, COMPLETED, FAILED
    }

    public IncrementalBackupManager(int maxRetentionDays, long maxStorageBytes) {
        this.backups = Collections.synchronizedList(new ArrayList<>());
        this.maxRetentionDays = maxRetentionDays;
        this.maxStorageBytes = maxStorageBytes;
    }

    public BackupSnapshot createFullBackup(byte[] data) throws RatchetException {
        String backupId = UUID.randomUUID().toString();
        BackupSnapshot snapshot = new BackupSnapshot(backupId, BackupType.FULL, data);
        backups.add(snapshot);
        snapshot.status = BackupStatus.COMPLETED;
        enforceRetentionPolicy();
        return snapshot;
    }

    public BackupSnapshot createIncrementalBackup(byte[] currentData, BackupSnapshot baseline) 
            throws RatchetException {
        String backupId = UUID.randomUUID().toString();
        BackupSnapshot snapshot = new BackupSnapshot(backupId, BackupType.INCREMENTAL, new byte[0]);
        
        List<DeltaBlock> deltas = computeDeltas(baseline.baselineData, currentData);
        snapshot.deltaBlocks.addAll(deltas);
        backups.add(snapshot);
        snapshot.status = BackupStatus.COMPLETED;
        enforceRetentionPolicy();
        return snapshot;
    }

    public byte[] restoreFromBackup(BackupSnapshot snapshot) throws RatchetException {
        if (snapshot.type == BackupType.FULL) {
            return snapshot.baselineData.clone();
        }

        byte[] result = Arrays.copyOf(snapshot.baselineData, snapshot.baselineData.length);
        for (DeltaBlock delta : snapshot.deltaBlocks) {
            System.arraycopy(delta.data, 0, result, delta.offset, delta.data.length);
        }
        return result;
    }

    private List<DeltaBlock> computeDeltas(byte[] baseline, byte[] current) {
        List<DeltaBlock> deltas = new ArrayList<>();
        int maxLen = Math.max(baseline.length, current.length);
        
        for (int i = 0; i < maxLen; i += 4096) {
            int end = Math.min(i + 4096, maxLen);
            byte[] currentBlock = end <= current.length ? 
                Arrays.copyOfRange(current, i, end) : new byte[0];
            byte[] baselineBlock = end <= baseline.length ? 
                Arrays.copyOfRange(baseline, i, end) : new byte[0];
            
            if (!Arrays.equals(currentBlock, baselineBlock)) {
                deltas.add(new DeltaBlock(i, currentBlock));
            }
        }
        return deltas;
    }

    private void enforceRetentionPolicy() {
        Instant cutoff = Instant.now().minusSeconds(maxRetentionDays * 86400L);
        backups.removeIf(b -> b.createdAt.isBefore(cutoff));
        
        long totalSize = backups.stream().mapToLong(b -> b.totalSize).sum();
        while (totalSize > maxStorageBytes && !backups.isEmpty()) {
            BackupSnapshot oldest = backups.stream()
                .min(Comparator.comparing(b -> b.createdAt))
                .orElse(null);
            if (oldest != null) {
                backups.remove(oldest);
                totalSize -= oldest.totalSize;
            }
        }
    }

    public List<BackupSnapshot> listBackups() {
        return new ArrayList<>(backups);
    }

    public long getTotalBackupSize() {
        return backups.stream().mapToLong(b -> b.totalSize).sum();
    }
}
