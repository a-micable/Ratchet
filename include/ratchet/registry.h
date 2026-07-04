#ifndef RATCHET_REGISTRY_H
#define RATCHET_REGISTRY_H
#include "ratchet/types.h"
typedef struct RatchetRegistryEntry {
    char name[RATCHET_NAME_FIELD];
    uint8_t *data;
    size_t size;
} RatchetRegistryEntry;
typedef struct RatchetRegistry {
    RatchetRegistryEntry *items;
    size_t count;
    size_t capacity;
} RatchetRegistry;
void ratchet_registry_init(RatchetRegistry *registry);
void ratchet_registry_free(RatchetRegistry *registry);
RatchetStatus ratchet_registry_put(RatchetRegistry *registry, const char *name, const uint8_t *data, size_t size);
RatchetStatus ratchet_registry_get(const RatchetRegistry *registry, const char *name, const uint8_t **data, size_t *size);
#endif
