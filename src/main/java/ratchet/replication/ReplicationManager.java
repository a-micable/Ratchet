package ratchet.replication;

import ratchet.RatchetException;
import ratchet.RatchetStatus;
import java.util.*;
import java.util.concurrent.*;
import java.util.stream.Collectors;

/**
 * Distributed replication system for consistency across nodes.
 * Implements leader-based replication with quorum write support.
 */
public class ReplicationManager {
    private final String nodeId;
    private final List<ReplicationPeer> peers;
    private final BlockingQueue<ReplicationEvent> eventQueue;
    private final ConcurrentHashMap<String, VersionMetadata> versionLog;
    private volatile boolean isLeader = false;

    public static class ReplicationPeer {
        public final String nodeId;
        public final String address;
        public final int port;
        public volatile long lastHeartbeat;

        public ReplicationPeer(String nodeId, String address, int port) {
            this.nodeId = nodeId;
            this.address = address;
            this.port = port;
            this.lastHeartbeat = System.currentTimeMillis();
        }
    }

    public static class ReplicationEvent {
        public final String versionName;
        public final byte[] patchData;
        public final long sequenceNumber;
        public final long timestamp;

        public ReplicationEvent(String versionName, byte[] patchData, long sequenceNumber) {
            this.versionName = versionName;
            this.patchData = patchData;
            this.sequenceNumber = sequenceNumber;
            this.timestamp = System.currentTimeMillis();
        }
    }

    public static class VersionMetadata {
        public final String versionName;
        public final long sequenceNumber;
        public final String checksum;
        public final long timestamp;
        public final ReplicationState state;

        public VersionMetadata(String versionName, long seqNum, String checksum) {
            this.versionName = versionName;
            this.sequenceNumber = seqNum;
            this.checksum = checksum;
            this.timestamp = System.currentTimeMillis();
            this.state = ReplicationState.PENDING;
        }
    }

    public enum ReplicationState {
        PENDING, REPLICATED, COMMITTED, FAILED
    }

    public ReplicationManager(String nodeId) {
        this.nodeId = nodeId;
        this.peers = Collections.synchronizedList(new ArrayList<>());
        this.eventQueue = new LinkedBlockingQueue<>(10000);
        this.versionLog = new ConcurrentHashMap<>();
    }

    public void addPeer(ReplicationPeer peer) {
        peers.add(peer);
    }

    public void queueReplication(ReplicationEvent event) throws RatchetException {
        try {
            if (!eventQueue.offer(event, 5, TimeUnit.SECONDS)) {
                throw new RatchetException(RatchetStatus.TIMEOUT,
                    "Replication queue full");
            }
        } catch (InterruptedException e) {
            throw new RatchetException(RatchetStatus.TIMEOUT,
                "Replication interrupted");
        }
    }

    public boolean performLeaderElection() {
        List<ReplicationPeer> activePeers = peers.stream()
            .filter(p -> System.currentTimeMillis() - p.lastHeartbeat < 5000)
            .collect(Collectors.toList());

        String maxNodeId = nodeId;
        for (ReplicationPeer peer : activePeers) {
            if (peer.nodeId.compareTo(maxNodeId) > 0) {
                maxNodeId = peer.nodeId;
            }
        }

        this.isLeader = maxNodeId.equals(nodeId);
        return isLeader;
    }

    public List<VersionMetadata> getReplicationLog() {
        return new ArrayList<>(versionLog.values());
    }

    public void recordVersion(String versionName, String checksum, long sequenceNumber) {
        versionLog.put(versionName, new VersionMetadata(versionName, sequenceNumber, checksum));
    }

    public int getPeerCount() {
        return peers.size();
    }

    public boolean isLeader() {
        return isLeader;
    }
}
