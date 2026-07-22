package ratchet;

public final class RatchetException extends Exception {
    private final RatchetStatus status;

    public RatchetException(RatchetStatus status, String message) {
        super(message);
        this.status = status;
    }

    public RatchetStatus status() {
        return status;
    }
}
