#ifndef RATCHET_PATCHER_H
#define RATCHET_PATCHER_H
#include "ratchet/types.h"
#include "ratchet/registry.h"
RatchetStatus ratchet_apply_operations(const RatchetOperationList *ops, const RatchetRegistry *registry, const uint8_t *base, size_t base_size, RatchetBuffer *out);
RatchetStatus ratchet_apply_diff_bytes(const uint8_t *diff, size_t diff_size, const RatchetRegistry *registry, const uint8_t *base, size_t base_size, RatchetBuffer *out);
#endif
