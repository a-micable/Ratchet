package ratchet.health;

import java.util.*;
import java.time.Instant;
import java.util.concurrent.*;

/**
 * Health check framework for monitoring system status.
 * Supports periodic health checks with circuit breaker pattern.
 */
public class HealthCheckManager {
    private final Map<String, HealthCheck> checks = new ConcurrentHashMap<>();
    private final Map<String, HealthStatus> statuses = new ConcurrentHashMap<>();
    private final ScheduledExecutorService scheduler;

    public enum HealthStatus {
        UP, DOWN, DEGRADED, UNKNOWN
    }

    public interface HealthCheck {
        HealthCheckResult performCheck() throws Exception;
    }

    public static class HealthCheckResult {
        public final HealthStatus status;
        public final String message;
        public final Map<String, Object> details;
        public final long checkedAt;

        public HealthCheckResult(HealthStatus status, String message) {
            this.status = status;
            this.message = message;
            this.details = new HashMap<>();
            this.checkedAt = System.currentTimeMillis();
        }
    }

    public HealthCheckManager() {
        this.scheduler = Executors.newScheduledThreadPool(4);
    }

    public void registerCheck(String name, HealthCheck check, long intervalSeconds) {
        checks.put(name, check);
        statuses.put(name, new HealthStatus[]{HealthStatus.UNKNOWN}[0]);
        
        scheduler.scheduleAtFixedRate(() -> {
            try {
                HealthCheckResult result = check.performCheck();
                statuses.put(name, result.status);
            } catch (Exception e) {
                statuses.put(name, HealthStatus.DOWN);
            }
        }, 0, intervalSeconds, TimeUnit.SECONDS);
    }

    public HealthStatus getStatus(String name) {
        return statuses.getOrDefault(name, HealthStatus.UNKNOWN);
    }

    public HealthStatus getOverallStatus() {
        if (statuses.isEmpty()) return HealthStatus.UNKNOWN;
        
        boolean hasDown = statuses.containsValue(HealthStatus.DOWN);
        if (hasDown) return HealthStatus.DOWN;
        
        boolean hasDegraded = statuses.containsValue(HealthStatus.DEGRADED);
        if (hasDegraded) return HealthStatus.DEGRADED;
        
        return HealthStatus.UP;
    }

    public Map<String, HealthStatus> getAllStatuses() {
        return new HashMap<>(statuses);
    }

    public void shutdown() {
        scheduler.shutdown();
        try {
            if (!scheduler.awaitTermination(5, TimeUnit.SECONDS)) {
                scheduler.shutdownNow();
            }
        } catch (InterruptedException e) {
            scheduler.shutdownNow();
        }
    }
}
