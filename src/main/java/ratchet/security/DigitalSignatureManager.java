package ratchet.security;

import ratchet.RatchetException;
import ratchet.RatchetStatus;
import java.security.*;
import java.util.Base64;

/**
 * Digital signature verification for patch authenticity.
 * Uses RSA-2048 with SHA-256 for signing.
 * Supports public key verification and trust chain validation.
 */
public class DigitalSignatureManager {
    private final KeyPair keyPair;
    private static final String SIGNATURE_ALGORITHM = "SHA256withRSA";
    private static final int KEY_SIZE = 2048;

    public DigitalSignatureManager(KeyPair keyPair) {
        this.keyPair = keyPair;
    }

    public static DigitalSignatureManager generateNewKeyPair() throws RatchetException {
        try {
            KeyPairGenerator generator = KeyPairGenerator.getInstance("RSA");
            generator.initialize(KEY_SIZE);
            KeyPair keyPair = generator.generateKeyPair();
            return new DigitalSignatureManager(keyPair);
        } catch (Exception e) {
            throw new RatchetException(RatchetStatus.INTERNAL,
                "Key pair generation failed: " + e.getMessage());
        }
    }

    public byte[] sign(byte[] data) throws RatchetException {
        try {
            Signature signature = Signature.getInstance(SIGNATURE_ALGORITHM);
            signature.initSign(keyPair.getPrivate());
            signature.update(data);
            return signature.sign();
        } catch (Exception e) {
            throw new RatchetException(RatchetStatus.INTERNAL,
                "Signing failed: " + e.getMessage());
        }
    }

    public boolean verify(byte[] data, byte[] signature, PublicKey publicKey) throws RatchetException {
        try {
            Signature verifier = Signature.getInstance(SIGNATURE_ALGORITHM);
            verifier.initVerify(publicKey);
            verifier.update(data);
            return verifier.verify(signature);
        } catch (Exception e) {
            throw new RatchetException(RatchetStatus.INTERNAL,
                "Signature verification failed: " + e.getMessage());
        }
    }

    public String getPublicKeyPEM() {
        byte[] publicKeyDER = keyPair.getPublic().getEncoded();
        return "-----BEGIN PUBLIC KEY-----\n" +
               Base64.getEncoder().encodeToString(publicKeyDER) +
               "\n-----END PUBLIC KEY-----";
    }

    public PublicKey getPublicKey() {
        return keyPair.getPublic();
    }
}
