package ratchet.profiling;

import java.util.*;
import java.util.concurrent.*;
import java.time.Instant;

/**
 * CPU and memory profiling for performance optimization.
 * Records execution time, memory usage, and GC statistics.
 */
public class PerformanceProfiler {
    private final String name;
    private final Map<String, ExecutionProfile> profiles;
    private final MemoryMonitor memoryMonitor;

    public static class ExecutionProfile {
        public final String operationName;
        public final List<Long> executionTimes;
        public final long startTime;
        public volatile long endTime;
        public final List<MemorySnapshot> memorySnapshots;

        public ExecutionProfile(String operationName) {
            this.operationName = operationName;
            this.executionTimes = Collections.synchronizedList(new ArrayList<>());
            this.memorySnapshots = Collections.synchronizedList(new ArrayList<>());
            this.startTime = System.nanoTime();
            this.endTime = -1;
        }
    }

    public static class MemorySnapshot {
        public final long timestamp;
        public final long heapUsed;
        public final long heapMax;
        public final long nonHeapUsed;

        public MemorySnapshot() {
            this.timestamp = System.currentTimeMillis();
            java.lang.management.MemoryMXBean memBean = 
                java.lang.management.ManagementFactory.getMemoryMXBean();
            this.heapUsed = memBean.getHeapMemoryUsage().getUsed();
            this.heapMax = memBean.getHeapMemoryUsage().getMax();
            this.nonHeapUsed = memBean.getNonHeapMemoryUsage().getUsed();
        }
    }

    public static class ProfileStats {
        public final long avgTimeMs;
        public final long minTimeMs;
        public final long maxTimeMs;
        public final long totalTimeMs;
        public final int sampleCount;
        public final double throughputOpsPerSec;
        public final MemorySnapshot peakMemory;

        public ProfileStats(ExecutionProfile profile) {
            List<Long> times = new ArrayList<>(profile.executionTimes);
            
            if (times.isEmpty()) {
                this.avgTimeMs = 0;
                this.minTimeMs = 0;
                this.maxTimeMs = 0;
                this.totalTimeMs = 0;
                this.sampleCount = 0;
                this.throughputOpsPerSec = 0;
                this.peakMemory = null;
            } else {
                Collections.sort(times);
                this.minTimeMs = times.get(0) / 1_000_000;
                this.maxTimeMs = times.get(times.size() - 1) / 1_000_000;
                this.totalTimeMs = times.stream().mapToLong(t -> t / 1_000_000).sum();
                this.avgTimeMs = this.totalTimeMs / times.size();
                this.sampleCount = times.size();
                this.throughputOpsPerSec = (double) sampleCount / (totalTimeMs / 1000.0);
                this.peakMemory = profile.memorySnapshots.stream()
                    .max(Comparator.comparingLong(m -> m.heapUsed))
                    .orElse(null);
            }
        }
    }

    public PerformanceProfiler(String name) {
        this.name = name;
        this.profiles = new ConcurrentHashMap<>();
        this.memoryMonitor = new MemoryMonitor();
    }

    public ExecutionProfile startProfiling(String operationName) {
        ExecutionProfile profile = new ExecutionProfile(operationName);
        profiles.put(operationName, profile);
        memoryMonitor.captureSnapshot(profile);
        return profile;
    }

    public void recordExecution(ExecutionProfile profile, long startNanos) {
        long duration = System.nanoTime() - startNanos;
        profile.executionTimes.add(duration);
        memoryMonitor.captureSnapshot(profile);
    }

    public void stopProfiling(ExecutionProfile profile) {
        profile.endTime = System.nanoTime();
    }

    public ProfileStats getStatistics(String operationName) {
        ExecutionProfile profile = profiles.get(operationName);
        if (profile == null) return null;
        return new ProfileStats(profile);
    }

    public Map<String, ProfileStats> getAllStatistics() {
        Map<String, ProfileStats> stats = new LinkedHashMap<>();
        profiles.forEach((name, profile) -> stats.put(name, new ProfileStats(profile)));
        return stats;
    }

    private static class MemoryMonitor {
        void captureSnapshot(ExecutionProfile profile) {
            if (profile.memorySnapshots.size() < 100) {
                profile.memorySnapshots.add(new MemorySnapshot());
            }
        }
    }
}
