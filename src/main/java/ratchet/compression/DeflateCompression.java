package ratchet.compression;

import ratchet.RatchetException;
import ratchet.RatchetStatus;
import java.io.*;
import java.util.zip.Deflater;
import java.util.zip.Inflater;

/**
 * DEFLATE compression using built-in Java compression.
 * Fast, universally supported compression suitable for most use cases.
 */
public class DeflateCompression extends CompressionAlgorithm {
    public static final byte ID = 0x01;
    
    public DeflateCompression(int level) {
        super("DEFLATE", ID, level);
    }

    @Override
    public byte[] compress(byte[] data) throws RatchetException {
        if (data == null || data.length == 0) {
            return new byte[0];
        }
        
        try {
            Deflater deflater = new Deflater(level, true);
            deflater.setInput(data);
            deflater.finish();
            
            byte[] buffer = new byte[Math.max(1024, data.length / 4)];
            ByteArrayOutputStream output = new ByteArrayOutputStream();
            
            while (!deflater.finished()) {
                int count = deflater.deflate(buffer);
                output.write(buffer, 0, count);
            }
            
            deflater.end();
            return output.toByteArray();
        } catch (Exception e) {
            throw new RatchetException(RatchetStatus.COMPRESSION_ERROR, 
                "DEFLATE compression failed: " + e.getMessage());
        }
    }

    @Override
    public byte[] decompress(byte[] data, int maxSize) throws RatchetException {
        if (data == null || data.length == 0) {
            return new byte[0];
        }
        
        try {
            Inflater inflater = new Inflater(true);
            inflater.setInput(data);
            
            byte[] buffer = new byte[Math.min(maxSize, 65536)];
            ByteArrayOutputStream output = new ByteArrayOutputStream();
            
            while (!inflater.finished()) {
                int count = inflater.inflate(buffer);
                if (output.size() + count > maxSize) {
                    throw new RatchetException(RatchetStatus.SIZE_EXCEEDED,
                        "Decompressed size exceeds limit: " + maxSize);
                }
                output.write(buffer, 0, count);
            }
            
            inflater.end();
            return output.toByteArray();
        } catch (Exception e) {
            throw new RatchetException(RatchetStatus.COMPRESSION_ERROR,
                "DEFLATE decompression failed: " + e.getMessage());
        }
    }
}
