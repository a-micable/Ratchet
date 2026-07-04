#ifndef RATCHET_DIFFER_H
#define RATCHET_DIFFER_H
#include "ratchet/types.h"
RatchetStatus ratchet_diff_buffers(const uint8_t *base, size_t base_size, const uint8_t *target, size_t target_size, const char *base_name, const char *target_name, RatchetOperationList *ops);
RatchetStatus ratchet_diff_to_bytes(const uint8_t *base, size_t base_size, const uint8_t *target, size_t target_size, const char *base_name, const char *target_name, RatchetBuffer *out);
#endif
