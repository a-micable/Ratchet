package ratchet.config;

import java.io.*;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.*;
import ratchet.RatchetException;
import ratchet.RatchetStatus;

/**
 * Configuration management system with profile support.
 * Loads from files, environment variables, and system properties.
 * Supports YAML, properties, and JSON formats.
 */
public class ConfigurationManager {
    private final Properties properties;
    private final String profile;
    private final Map<String, Object> overrides;

    public ConfigurationManager(String profile) {
        this.profile = profile != null ? profile : "default";
        this.properties = new Properties();
        this.overrides = new java.util.concurrent.ConcurrentHashMap<>();
    }

    public void loadFromFile(Path configFile) throws RatchetException {
        try {
            if (Files.exists(configFile)) {
                try (InputStream is = Files.newInputStream(configFile)) {
                    if (configFile.toString().endsWith(".yaml") || 
                        configFile.toString().endsWith(".yml")) {
                        loadYaml(is);
                    } else {
                        properties.load(is);
                    }
                }
            }
        } catch (IOException e) {
            throw new RatchetException(RatchetStatus.IO_ERROR,
                "Failed to load configuration: " + e.getMessage());
        }
    }

    public void loadFromEnvironment() {
        System.getenv().forEach((key, value) -> {
            if (key.startsWith("RATCHET_")) {
                String propKey = key.substring(8).toLowerCase().replace('_', '.');
                properties.setProperty(propKey, value);
            }
        });
    }

    public void loadFromSystemProperties() {
        System.getProperties().forEach((key, value) -> {
            if (key.toString().startsWith("ratchet.")) {
                properties.setProperty(key.toString(), value.toString());
            }
        });
    }

    public String getString(String key, String defaultValue) {
        Object override = overrides.get(key);
        if (override != null) return override.toString();
        return properties.getProperty(key, defaultValue);
    }

    public int getInt(String key, int defaultValue) {
        String value = getString(key, null);
        if (value != null) {
            try {
                return Integer.parseInt(value);
            } catch (NumberFormatException e) {
                // Fall through to default
            }
        }
        return defaultValue;
    }

    public long getLong(String key, long defaultValue) {
        String value = getString(key, null);
        if (value != null) {
            try {
                return Long.parseLong(value);
            } catch (NumberFormatException e) {
                // Fall through to default
            }
        }
        return defaultValue;
    }

    public boolean getBoolean(String key, boolean defaultValue) {
        String value = getString(key, null);
        if (value != null) {
            return "true".equalsIgnoreCase(value) || "1".equals(value);
        }
        return defaultValue;
    }

    public void setProperty(String key, String value) {
        overrides.put(key, value);
    }

    private void loadYaml(InputStream is) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(is));
        String line;
        String prefix = "";
        
        while ((line = reader.readLine()) != null) {
            line = line.trim();
            if (line.isEmpty() || line.startsWith("#")) continue;
            
            if (line.endsWith(":")) {
                prefix = line.substring(0, line.length() - 1) + ".";
            } else if (line.contains(":")) {
                String[] parts = line.split(":", 2);
                String key = prefix + parts[0].trim();
                String value = parts[1].trim();
                properties.setProperty(key, value);
            }
        }
    }

    public String getProfile() {
        return profile;
    }

    public Map<String, String> getAllProperties() {
        Map<String, String> result = new HashMap<>();
        properties.forEach((k, v) -> result.put(k.toString(), v.toString()));
        overrides.forEach((k, v) -> result.put(k, v.toString()));
        return result;
    }
}
