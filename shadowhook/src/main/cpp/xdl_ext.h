#pragma once

#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

void *xdl_sym_prefix(void *handle, const char *prefix, size_t *symbol_size);

void *xdl_dsym_prefix(void *handle, const char *prefix, size_t *symbol_size);

void *xdl_sym_hash(void *handle, const char *symbol, uint32_t sysv_hash, uint32_t gnu_hash,
                   size_t *symbol_size);

#ifdef __cplusplus
}
#endif
