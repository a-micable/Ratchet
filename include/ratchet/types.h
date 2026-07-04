#ifndef RATCHET_TYPES_H
#define RATCHET_TYPES_H
#include <stddef.h>
#include <stdint.h>
#define RATCHET_MAGIC "RATCHET1"
#define RATCHET_MAGIC_SIZE 8
#define RATCHET_VERSION 1u
#define RATCHET_NAME_MAX 64u
#define RATCHET_NAME_FIELD 65u
#define RATCHET_HEADER_SIZE 154u
#define RATCHET_OP_COPY 0x01u
#define RATCHET_OP_INSERT 0x02u
#define RATCHET_OP_DELETE 0x03u
#define RATCHET_OP_CHAIN 0x04u
typedef enum RatchetStatus {
    RATCHET_OK = 0,
    RATCHET_ERROR_INVALID = 1,
    RATCHET_ERROR_CRC = 2,
    RATCHET_ERROR_BOUNDS = 3,
    RATCHET_ERROR_NOMEM = 4,
    RATCHET_ERROR_NOT_FOUND = 5,
    RATCHET_ERROR_DEPTH = 6
} RatchetStatus;
typedef struct RatchetBuffer {
    uint8_t *data;
    size_t size;
    size_t capacity;
} RatchetBuffer;
typedef struct RatchetOperation {
    uint8_t type;
    uint32_t offset;
    uint32_t length;
    uint8_t *data;
    char version[RATCHET_NAME_FIELD];
} RatchetOperation;
typedef struct RatchetOperationList {
    RatchetOperation *items;
    size_t count;
    size_t capacity;
    char base_version[RATCHET_NAME_FIELD];
    char target_version[RATCHET_NAME_FIELD];
    uint32_t flags;
} RatchetOperationList;
#endif
