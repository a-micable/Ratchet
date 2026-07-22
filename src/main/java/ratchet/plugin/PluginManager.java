package ratchet.plugin;

import java.util.*;
import ratchet.RatchetException;

/**
 * Plugin architecture for extensible functionality.
 * Supports dynamic loading of plugins with lifecycle management.
 */
public interface RatchetPlugin {
    String getName();
    String getVersion();
    void initialize(PluginContext context) throws RatchetException;
    void shutdown() throws RatchetException;
}

public class PluginManager {
    private final Map<String, RatchetPlugin> plugins = new HashMap<>();
    private final PluginClassLoader classLoader;

    public PluginManager(java.nio.file.Path pluginDirectory) {
        this.classLoader = new PluginClassLoader(pluginDirectory);
    }

    public void loadPlugin(String pluginName, String pluginPath) throws RatchetException {
        try {
            Class<?> pluginClass = classLoader.loadClass(pluginPath);
            RatchetPlugin plugin = (RatchetPlugin) pluginClass.getDeclaredConstructor().newInstance();
            plugin.initialize(new PluginContext() {
                @Override
                public String getPluginDirectory() { return pluginPath; }
            });
            plugins.put(pluginName, plugin);
        } catch (Exception e) {
            throw new RatchetException(ratchet.RatchetStatus.INTERNAL,
                "Failed to load plugin: " + e.getMessage());
        }
    }

    public <T> Optional<T> getPluginService(String pluginName, Class<T> serviceClass) {
        RatchetPlugin plugin = plugins.get(pluginName);
        if (plugin instanceof PluginService && serviceClass.isInstance(plugin)) {
            return Optional.of(serviceClass.cast(plugin));
        }
        return Optional.empty();
    }

    public void unloadPlugin(String pluginName) throws RatchetException {
        RatchetPlugin plugin = plugins.remove(pluginName);
        if (plugin != null) {
            plugin.shutdown();
        }
    }

    public interface PluginContext {
        String getPluginDirectory();
    }

    public interface PluginService {
    }

    private static class PluginClassLoader extends ClassLoader {
        private final java.nio.file.Path pluginDir;

        public PluginClassLoader(java.nio.file.Path pluginDir) {
            this.pluginDir = pluginDir;
        }

        @Override
        protected Class<?> findClass(String name) throws ClassNotFoundException {
            try {
                String path = name.replace('.', '/') + ".class";
                java.nio.file.Path classFile = pluginDir.resolve(path);
                if (java.nio.file.Files.exists(classFile)) {
                    byte[] classData = java.nio.file.Files.readAllBytes(classFile);
                    return defineClass(name, classData, 0, classData.length);
                }
            } catch (java.io.IOException e) {
                // Fall through
            }
            throw new ClassNotFoundException(name);
        }
    }
}
