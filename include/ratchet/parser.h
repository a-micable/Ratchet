#ifndef RATCHET_PARSER_H
#define RATCHET_PARSER_H
#include "ratchet/types.h"
RatchetStatus ratchet_parse_diff(const uint8_t *data, size_t size, RatchetOperationList *out);
RatchetStatus ratchet_write_diff(const RatchetOperationList *ops, RatchetBuffer *out);
RatchetStatus ratchet_verify_diff(const uint8_t *data, size_t size);
void ratchet_operation_list_init(RatchetOperationList *list);
void ratchet_operation_list_free(RatchetOperationList *list);
RatchetStatus ratchet_operation_list_push(RatchetOperationList *list, const RatchetOperation *op);
void ratchet_buffer_init(RatchetBuffer *buf);
void ratchet_buffer_free(RatchetBuffer *buf);
RatchetStatus ratchet_buffer_reserve(RatchetBuffer *buf, size_t need);
RatchetStatus ratchet_buffer_append(RatchetBuffer *buf, const uint8_t *data, size_t size);
#endif
