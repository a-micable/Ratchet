package ratchet.metrics;

import java.util.*;
import java.util.concurrent.*;
import java.util.concurrent.atomic.*;
import java.time.Instant;

/**
 * Comprehensive metrics collection for performance monitoring.
 * Tracks latency, throughput, error rates, and resource usage.
 * Supports histograms, gauges, counters, and timers.
 */
public class MetricsCollector {
    private final ConcurrentHashMap<String, Counter> counters;
    private final ConcurrentHashMap<String, Gauge> gauges;
    private final ConcurrentHashMap<String, Histogram> histograms;
    private final ConcurrentHashMap<String, Timer> timers;
    private final String applicationName;

    public MetricsCollector(String applicationName) {
        this.applicationName = applicationName;
        this.counters = new ConcurrentHashMap<>();
        this.gauges = new ConcurrentHashMap<>();
        this.histograms = new ConcurrentHashMap<>();
        this.timers = new ConcurrentHashMap<>();
    }

    public static class Counter {
        private final AtomicLong value = new AtomicLong(0);
        public void increment() { value.incrementAndGet(); }
        public void increment(long delta) { value.addAndGet(delta); }
        public long getValue() { return value.get(); }
        public void reset() { value.set(0); }
    }

    public static class Gauge {
        private final AtomicLong value = new AtomicLong(0);
        public void setValue(long v) { value.set(v); }
        public long getValue() { return value.get(); }
    }

    public static class Histogram {
        private final long[] buckets;
        private final long[] thresholds;
        
        public Histogram(long... thresholds) {
            this.thresholds = thresholds;
            this.buckets = new long[thresholds.length + 1];
        }

        public synchronized void record(long value) {
            for (int i = 0; i < thresholds.length; i++) {
                if (value <= thresholds[i]) {
                    buckets[i]++;
                    return;
                }
            }
            buckets[thresholds.length]++;
        }

        public synchronized long[] getBuckets() {
            return Arrays.copyOf(buckets, buckets.length);
        }
    }

    public static class Timer {
        private final List<Long> measurements = Collections.synchronizedList(new ArrayList<>());
        private final int maxSize;

        public Timer(int maxSize) {
            this.maxSize = maxSize;
        }

        public long startTiming() {
            return System.nanoTime();
        }

        public void recordTiming(long startNanos) {
            long duration = (System.nanoTime() - startNanos) / 1_000_000;
            measurements.add(duration);
            if (measurements.size() > maxSize) {
                measurements.remove(0);
            }
        }

        public TimingStats getStats() {
            if (measurements.isEmpty()) {
                return new TimingStats(0, 0, 0, 0);
            }
            
            List<Long> sorted = new ArrayList<>(measurements);
            Collections.sort(sorted);
            
            long sum = sorted.stream().mapToLong(Long::longValue).sum();
            long avg = sum / sorted.size();
            long min = sorted.get(0);
            long max = sorted.get(sorted.size() - 1);
            
            return new TimingStats(avg, min, max, sorted.size());
        }
    }

    public static class TimingStats {
        public final long avgMs;
        public final long minMs;
        public final long maxMs;
        public final int sampleCount;

        public TimingStats(long avg, long min, long max, int count) {
            this.avgMs = avg;
            this.minMs = min;
            this.maxMs = max;
            this.sampleCount = count;
        }
    }

    public Counter getCounter(String name) {
        return counters.computeIfAbsent(name, k -> new Counter());
    }

    public Gauge getGauge(String name) {
        return gauges.computeIfAbsent(name, k -> new Gauge());
    }

    public Histogram getHistogram(String name, long... thresholds) {
        return histograms.computeIfAbsent(name, k -> new Histogram(thresholds));
    }

    public Timer getTimer(String name) {
        return timers.computeIfAbsent(name, k -> new Timer(10000));
    }

    public Map<String, Object> getMetricsSnapshot() {
        Map<String, Object> snapshot = new LinkedHashMap<>();
        snapshot.put("application", applicationName);
        snapshot.put("timestamp", Instant.now());
        
        Map<String, Long> counterValues = new LinkedHashMap<>();
        counters.forEach((k, v) -> counterValues.put(k, v.getValue()));
        snapshot.put("counters", counterValues);

        Map<String, Long> gaugeValues = new LinkedHashMap<>();
        gauges.forEach((k, v) -> gaugeValues.put(k, v.getValue()));
        snapshot.put("gauges", gaugeValues);

        return snapshot;
    }
}
