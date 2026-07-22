package ratchet.audit;

import java.time.Instant;
import java.util.*;
import java.util.concurrent.*;

/**
 * Comprehensive audit trail system for all operations.
 * Records who did what, when, and outcome.
 * Thread-safe with circular buffer for bounded memory.
 */
public class AuditTrail {
    private final ConcurrentLinkedQueue<AuditEvent> events;
    private final int maxEvents;
    private final String systemId;

    public static class AuditEvent {
        public final Instant timestamp;
        public final String userId;
        public final String operation;
        public final String resourceId;
        public final Map<String, String> metadata;
        public final AuditStatus status;
        public final long durationMs;

        public AuditEvent(String userId, String operation, String resourceId,
                         AuditStatus status, long durationMs) {
            this.timestamp = Instant.now();
            this.userId = userId;
            this.operation = operation;
            this.resourceId = resourceId;
            this.metadata = new ConcurrentHashMap<>();
            this.status = status;
            this.durationMs = durationMs;
        }
    }

    public enum AuditStatus {
        SUCCESS, FAILURE, PARTIAL, TIMEOUT
    }

    public AuditTrail(String systemId, int maxEvents) {
        this.systemId = systemId;
        this.maxEvents = maxEvents;
        this.events = new ConcurrentLinkedQueue<>();
    }

    public void record(AuditEvent event) {
        events.offer(event);
        while (events.size() > maxEvents) {
            events.poll();
        }
    }

    public void record(String userId, String operation, String resourceId, AuditStatus status) {
        record(new AuditEvent(userId, operation, resourceId, status, 0));
    }

    public List<AuditEvent> getEvents(String userId, String operation, int limit) {
        return events.stream()
            .filter(e -> (userId == null || e.userId.equals(userId)) &&
                        (operation == null || e.operation.equals(operation)))
            .limit(limit)
            .toList();
    }

    public List<AuditEvent> getEventsSince(Instant since) {
        return events.stream()
            .filter(e -> e.timestamp.isAfter(since))
            .toList();
    }

    public int eventCount() {
        return events.size();
    }

    public void clear() {
        events.clear();
    }
}
