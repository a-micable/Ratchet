package ratchet.compression;

import java.io.ByteArrayOutputStream;
import ratchet.RatchetException;
import ratchet.RatchetStatus;

/**
 * LZ4 compression for ultra-fast compression/decompression.
 * Excellent for real-time patching with moderate compression ratios.
 * Reference implementation based on LZ4 framing format.
 */
public class LZ4Compression extends CompressionAlgorithm {
    public static final byte ID = 0x02;
    private static final int BLOCK_SIZE = 1 << 16;
    private static final int HASH_SIZE = 1 << 16;

    public LZ4Compression(int level) {
        super("LZ4", ID, Math.min(level, 1));
    }

    @Override
    public byte[] compress(byte[] data) throws RatchetException {
        if (data == null || data.length == 0) {
            return new byte[0];
        }

        try {
            ByteArrayOutputStream output = new ByteArrayOutputStream();
            int offset = 0;
            
            while (offset < data.length) {
                int blockLen = Math.min(BLOCK_SIZE, data.length - offset);
                byte[] compressedBlock = compressBlock(data, offset, blockLen);
                
                output.write(compressedBlock.length >> 8 & 0xFF);
                output.write(compressedBlock.length & 0xFF);
                output.write(blockLen >> 8 & 0xFF);
                output.write(blockLen & 0xFF);
                output.write(compressedBlock);
                
                offset += blockLen;
            }
            
            return output.toByteArray();
        } catch (Exception e) {
            throw new RatchetException(RatchetStatus.COMPRESSION_ERROR,
                "LZ4 compression failed: " + e.getMessage());
        }
    }

    @Override
    public byte[] decompress(byte[] data, int maxSize) throws RatchetException {
        if (data == null || data.length == 0) {
            return new byte[0];
        }

        try {
            ByteArrayOutputStream output = new ByteArrayOutputStream();
            int pos = 0;
            
            while (pos < data.length) {
                if (pos + 4 > data.length) break;
                
                int compLen = ((data[pos] & 0xFF) << 8) | (data[pos + 1] & 0xFF);
                int uncompLen = ((data[pos + 2] & 0xFF) << 8) | (data[pos + 3] & 0xFF);
                pos += 4;
                
                if (pos + compLen > data.length) {
                    throw new RatchetException(RatchetStatus.INVALID,
                        "Corrupted LZ4 stream");
                }
                
                byte[] block = decompressBlock(data, pos, compLen, uncompLen);
                if (output.size() + block.length > maxSize) {
                    throw new RatchetException(RatchetStatus.SIZE_EXCEEDED,
                        "Decompressed size exceeds limit");
                }
                output.write(block);
                pos += compLen;
            }
            
            return output.toByteArray();
        } catch (RatchetException e) {
            throw e;
        } catch (Exception e) {
            throw new RatchetException(RatchetStatus.COMPRESSION_ERROR,
                "LZ4 decompression failed: " + e.getMessage());
        }
    }

    private byte[] compressBlock(byte[] data, int offset, int length) {
        int[] hashTable = new int[HASH_SIZE];
        byte[] output = new byte[length + length / 255 + 16];
        int outPos = 0;

        int pos = 0;
        int matchStart = 0;
        
        while (pos < length) {
            int hash = hash24(data, offset + pos);
            int ref = hashTable[hash];
            hashTable[hash] = pos;
            
            int matchLen = 0;
            if (ref > 0 && pos - ref < 65535) {
                matchLen = countMatch(data, offset + ref, offset + pos, length - pos);
            }

            if (matchLen >= 4) {
                int litLen = pos - matchStart;
                outPos = encodeLitRun(output, outPos, data, offset + matchStart, litLen);
                outPos = encodeMatch(output, outPos, pos - ref, matchLen);
                pos += matchLen;
                matchStart = pos;
            } else {
                pos++;
            }
        }

        int litLen = length - matchStart;
        if (litLen > 0) {
            outPos = encodeLitRun(output, outPos, data, offset + matchStart, litLen);
        }

        byte[] result = new byte[outPos];
        System.arraycopy(output, 0, result, 0, outPos);
        return result;
    }

    private byte[] decompressBlock(byte[] data, int offset, int compLen, int uncompLen) {
        byte[] output = new byte[uncompLen];
        int inPos = offset;
        int outPos = 0;

        while (inPos < offset + compLen && outPos < uncompLen) {
            int token = data[inPos++] & 0xFF;
            int litLen = token >> 4;
            int matchLen = (token & 0x0F) + 4;

            if (litLen == 15) {
                while (inPos < offset + compLen) {
                    int b = data[inPos++] & 0xFF;
                    litLen += b;
                    if (b != 255) break;
                }
            }

            System.arraycopy(data, inPos, output, outPos, litLen);
            inPos += litLen;
            outPos += litLen;

            if (outPos >= uncompLen) break;

            int offset16 = ((data[inPos] & 0xFF) | ((data[inPos + 1] & 0xFF) << 8));
            inPos += 2;

            if (matchLen == 19) {
                while (inPos < offset + compLen) {
                    int b = data[inPos++] & 0xFF;
                    matchLen += b;
                    if (b != 255) break;
                }
            }

            int copyPos = outPos - offset16;
            for (int i = 0; i < matchLen; i++) {
                output[outPos++] = output[copyPos++];
            }
        }

        return output;
    }

    private int hash24(byte[] data, int offset) {
        if (offset + 3 > data.length) return 0;
        return ((data[offset] << 16) ^ (data[offset + 1] << 8) ^ data[offset + 2]) & 0xFFFF;
    }

    private int countMatch(byte[] data, int ref, int pos, int max) {
        int len = 0;
        while (len < max && data[ref + len] == data[pos + len]) {
            len++;
        }
        return len;
    }

    private int encodeLitRun(byte[] output, int pos, byte[] data, int offset, int length) {
        while (length > 0) {
            int run = Math.min(length, 255);
            output[pos++] = (byte) (run << 4);
            System.arraycopy(data, offset, output, pos, run);
            pos += run;
            offset += run;
            length -= run;
        }
        return pos;
    }

    private int encodeMatch(byte[] output, int pos, int distance, int length) {
        output[pos++] = (byte) (((length - 4) & 0x0F) | 0xF0);
        output[pos++] = (byte) (distance & 0xFF);
        output[pos++] = (byte) ((distance >> 8) & 0xFF);
        return pos;
    }
}
