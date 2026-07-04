#ifndef RATCHET_COMPRESSOR_H
#define RATCHET_COMPRESSOR_H
#include "ratchet/types.h"
RatchetStatus ratchet_compress_literal(const uint8_t *data, size_t size, RatchetBuffer *out);
RatchetStatus ratchet_decompress_literal(const uint8_t *data, size_t size, RatchetBuffer *out);
RatchetStatus ratchet_compress_operations(RatchetOperationList *ops);
RatchetStatus ratchet_decompress_operations(RatchetOperationList *ops);
#endif
