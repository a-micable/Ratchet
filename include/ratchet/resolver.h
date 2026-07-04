#ifndef RATCHET_RESOLVER_H
#define RATCHET_RESOLVER_H
#include "ratchet/types.h"
#include "ratchet/registry.h"
RatchetStatus ratchet_resolve_operations(const RatchetOperationList *ops, const RatchetRegistry *registry, RatchetOperationList *out);
#endif
