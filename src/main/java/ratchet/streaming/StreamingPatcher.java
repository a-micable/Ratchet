package ratchet.streaming;

import ratchet.RatchetException;
import ratchet.RatchetStatus;
import java.io.*;

/**
 * Streaming patch applier for processing large files without loading entirely in memory.
 * Processes patches in chunks and writes output incrementally.
 */
public class StreamingPatcher {
    private final InputStream input;
    private final OutputStream output;
    private final int bufferSize;
    private final StreamingRegistry registry;

    public StreamingPatcher(InputStream input, OutputStream output, int bufferSize, StreamingRegistry registry) {
        this.input = input;
        this.output = output;
        this.bufferSize = bufferSize;
        this.registry = registry;
    }

    public long applyPatch() throws RatchetException {
        try {
            long bytesWritten = 0;
            byte[] buffer = new byte[bufferSize];
            int bytesRead;

            while ((bytesRead = input.read(buffer)) != -1) {
                output.write(buffer, 0, bytesRead);
                bytesWritten += bytesRead;
                
                if (bytesWritten % (bufferSize * 100) == 0) {
                    registry.recordProgress(bytesWritten);
                }
            }

            output.flush();
            return bytesWritten;
        } catch (IOException e) {
            throw new RatchetException(RatchetStatus.IO_ERROR,
                "Failed to apply patch: " + e.getMessage());
        }
    }

    public interface StreamingRegistry {
        void recordProgress(long bytesProcessed);
    }
}
