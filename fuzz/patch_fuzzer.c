#include "ratchet/parser.h"
#include "ratchet/patcher.h"
#include "ratchet/registry.h"
#include <stdint.h>
#include <string.h>
int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size) { RatchetOperationList ops; RatchetRegistry reg; RatchetBuffer out; static const uint8_t base[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ012345"; size_t i; if (ratchet_parse_diff(data, size, &ops) != RATCHET_OK) return 0; ratchet_registry_init(&reg); for (i = 0; i < ops.count; i++) { if (ops.items[i].type == RATCHET_OP_CHAIN && ops.items[i].version[0] != '\0') { (void)ratchet_registry_put(&reg, ops.items[i].version, data, size); } }
    (void)ratchet_apply_operations(&ops, &reg, base, sizeof(base) - 1u, &out);
    if (out.data) ratchet_buffer_free(&out);
    ratchet_registry_free(&reg);
    ratchet_operation_list_free(&ops);
    return 0;
}
