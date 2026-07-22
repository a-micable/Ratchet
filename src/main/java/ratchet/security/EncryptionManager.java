package ratchet.security;

import ratchet.RatchetException;
import ratchet.RatchetStatus;
import javax.crypto.*;
import javax.crypto.spec.SecretKeySpec;
import javax.crypto.spec.GCMParameterSpec;
import java.security.*;

/**
 * AES-256-GCM encryption for patch data.
 * Provides authenticated encryption with associated data (AEAD).
 * Supports key derivation from master keys.
 */
public class EncryptionManager {
    private static final String ALGORITHM = "AES/GCM/NoPadding";
    private static final int GCM_TAG_LENGTH = 128;
    private static final int KEY_SIZE = 256;
    private static final String KEY_ALGORITHM = "AES";

    private final SecretKey masterKey;
    private final SecureRandom random;

    public EncryptionManager(byte[] masterKeyBytes) throws RatchetException {
        if (masterKeyBytes.length != 32) {
            throw new RatchetException(RatchetStatus.INVALID,
                "Master key must be 256 bits (32 bytes)");
        }
        this.masterKey = new SecretKeySpec(masterKeyBytes, 0, masterKeyBytes.length, KEY_ALGORITHM);
        this.random = new SecureRandom();
    }

    public EncryptedData encrypt(byte[] plaintext) throws RatchetException {
        try {
            Cipher cipher = Cipher.getInstance(ALGORITHM);
            byte[] iv = new byte[12];
            random.nextBytes(iv);

            GCMParameterSpec paramSpec = new GCMParameterSpec(GCM_TAG_LENGTH, iv);
            cipher.init(Cipher.ENCRYPT_MODE, masterKey, paramSpec);

            byte[] ciphertext = cipher.doFinal(plaintext);
            return new EncryptedData(iv, ciphertext);
        } catch (Exception e) {
            throw new RatchetException(RatchetStatus.INTERNAL,
                "Encryption failed: " + e.getMessage());
        }
    }

    public byte[] decrypt(EncryptedData data) throws RatchetException {
        try {
            Cipher cipher = Cipher.getInstance(ALGORITHM);
            GCMParameterSpec paramSpec = new GCMParameterSpec(GCM_TAG_LENGTH, data.iv);
            cipher.init(Cipher.DECRYPT_MODE, masterKey, paramSpec);

            return cipher.doFinal(data.ciphertext);
        } catch (Exception e) {
            throw new RatchetException(RatchetStatus.INTERNAL,
                "Decryption failed: " + e.getMessage());
        }
    }

    public static class EncryptedData {
        public final byte[] iv;
        public final byte[] ciphertext;

        public EncryptedData(byte[] iv, byte[] ciphertext) {
            this.iv = iv;
            this.ciphertext = ciphertext;
        }
    }

    public static byte[] deriveKey(String password, byte[] salt) throws RatchetException {
        try {
            javax.crypto.SecretKeyFactory factory = 
                javax.crypto.SecretKeyFactory.getInstance("PBKDF2WithHmacSHA256");
            javax.crypto.spec.PBEKeySpec spec = 
                new javax.crypto.spec.PBEKeySpec(password.toCharArray(), salt, 100000, 256);
            byte[] key = factory.generateSecret(spec).getEncoded();
            spec.clearPassword();
            return key;
        } catch (Exception e) {
            throw new RatchetException(RatchetStatus.INTERNAL,
                "Key derivation failed: " + e.getMessage());
        }
    }
}
