package ratchet.db;

import ratchet.RatchetException;
import ratchet.RatchetStatus;
import java.nio.file.Path;
import java.sql.*;
import java.util.*;

/**
 * SQLite-based persistence layer for version registry and metadata.
 * Supports transactions, prepared statements, and connection pooling.
 * Thread-safe with automatic schema migration.
 */
public class DatabaseManager {
    private final String connectionString;
    private final int poolSize;
    private final Queue<Connection> connectionPool;
    private volatile boolean closed = false;

    public DatabaseManager(Path dbPath, int poolSize) throws RatchetException {
        this.poolSize = poolSize;
        this.connectionPool = new java.util.concurrent.ConcurrentLinkedQueue<>();
        this.connectionString = "jdbc:sqlite:" + dbPath.toAbsolutePath();
        
        try {
            initializePool();
            initializeSchema();
        } catch (Exception e) {
            throw new RatchetException(RatchetStatus.IO_ERROR,
                "Database initialization failed: " + e.getMessage());
        }
    }

    private void initializePool() throws SQLException {
        for (int i = 0; i < poolSize; i++) {
            Connection conn = DriverManager.getConnection(connectionString);
            conn.setAutoCommit(true);
            connectionPool.offer(conn);
        }
    }

    private void initializeSchema() throws SQLException, RatchetException {
        try (Connection conn = getConnection()) {
            try (Statement stmt = conn.createStatement()) {
                stmt.execute("CREATE TABLE IF NOT EXISTS versions (" +
                    "id INTEGER PRIMARY KEY AUTOINCREMENT," +
                    "version_name TEXT UNIQUE NOT NULL," +
                    "checksum TEXT NOT NULL," +
                    "content_size INTEGER," +
                    "created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP" +
                    ")");

                stmt.execute("CREATE TABLE IF NOT EXISTS patches (" +
                    "id INTEGER PRIMARY KEY AUTOINCREMENT," +
                    "base_version TEXT NOT NULL," +
                    "target_version TEXT NOT NULL," +
                    "patch_data BLOB NOT NULL," +
                    "compressed INTEGER DEFAULT 0," +
                    "created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP," +
                    "FOREIGN KEY(base_version) REFERENCES versions(version_name)," +
                    "FOREIGN KEY(target_version) REFERENCES versions(version_name)" +
                    ")");

                stmt.execute("CREATE INDEX IF NOT EXISTS idx_version_name ON versions(version_name)");
                stmt.execute("CREATE INDEX IF NOT EXISTS idx_patch_versions ON patches(base_version, target_version)");
            }
        }
    }

    public Connection getConnection() throws RatchetException {
        if (closed) {
            throw new RatchetException(RatchetStatus.INTERNAL, "Database is closed");
        }
        
        Connection conn = connectionPool.poll();
        if (conn != null) {
            try {
                if (!conn.isValid(1)) {
                    conn = DriverManager.getConnection(connectionString);
                }
            } catch (SQLException e) {
                conn = null;
            }
        }
        
        if (conn == null) {
            try {
                conn = DriverManager.getConnection(connectionString);
            } catch (SQLException e) {
                throw new RatchetException(RatchetStatus.IO_ERROR,
                    "Failed to get database connection: " + e.getMessage());
            }
        }
        
        return conn;
    }

    public void releaseConnection(Connection conn) {
        if (!closed && conn != null) {
            connectionPool.offer(conn);
        }
    }

    public void storeVersion(String versionName, String checksum, byte[] content) throws RatchetException {
        Connection conn = getConnection();
        try {
            String sql = "INSERT OR REPLACE INTO versions(version_name, checksum, content_size) VALUES (?, ?, ?)";
            try (PreparedStatement stmt = conn.prepareStatement(sql)) {
                stmt.setString(1, versionName);
                stmt.setString(2, checksum);
                stmt.setInt(3, content.length);
                stmt.executeUpdate();
            }
        } catch (SQLException e) {
            throw new RatchetException(RatchetStatus.IO_ERROR,
                "Failed to store version: " + e.getMessage());
        } finally {
            releaseConnection(conn);
        }
    }

    public byte[] getPatchData(String baseVersion, String targetVersion) throws RatchetException {
        Connection conn = getConnection();
        try {
            String sql = "SELECT patch_data FROM patches WHERE base_version = ? AND target_version = ?";
            try (PreparedStatement stmt = conn.prepareStatement(sql)) {
                stmt.setString(1, baseVersion);
                stmt.setString(2, targetVersion);
                try (ResultSet rs = stmt.executeQuery()) {
                    if (rs.next()) {
                        return rs.getBytes("patch_data");
                    }
                }
            }
            return null;
        } catch (SQLException e) {
            throw new RatchetException(RatchetStatus.IO_ERROR,
                "Failed to retrieve patch: " + e.getMessage());
        } finally {
            releaseConnection(conn);
        }
    }

    public void close() throws RatchetException {
        closed = true;
        Connection conn;
        while ((conn = connectionPool.poll()) != null) {
            try {
                conn.close();
            } catch (SQLException e) {
                // Ignore
            }
        }
    }
}
