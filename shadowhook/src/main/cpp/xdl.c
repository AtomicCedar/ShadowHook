// clang-format off
#include "third_party/xdl/xdl/src/main/cpp/xdl.c"
// clang-format on

#include "sh_util.h"
#include "shadowhook.h"
#include "xdl_ext.h"

static void *xdl_any_sym_prefix(xdl_t *self, const char *prefix, size_t *symbol_size, ElfW(Sym) *symbols,
                                size_t symbols_cnt, const char *strtab, size_t strtab_sz) {
  if (NULL == prefix) return NULL;
  if (NULL != symbol_size) *symbol_size = 0;
  if (NULL == symbols) return NULL;

  for (size_t i = 0; i < symbols_cnt; i++) {
    ElfW(Sym) *sym = symbols + i;

    if (!XDL_SYMTAB_IS_EXPORT_SYM(sym->st_shndx)) continue;
    if (sym->st_name >= strtab_sz) continue;
    if (sh_util_starts_with(strtab + sym->st_name, prefix)) continue;

    return xdl_resolve_symbol_address(self, sym, symbol_size);
  }

  return NULL;
}

static size_t xdl_dynsym_count(const xdl_t *self) {
  if (self->sysv_hash.buckets_cnt > 0) {
    return self->sysv_hash.chains_cnt;
  }

  uintptr_t dynsym = (uintptr_t)self->dynsym;
  uintptr_t dynstr = (uintptr_t)self->dynstr;
  if (0 != dynsym && 0 != dynstr && dynstr > dynsym) {
    return (dynstr - dynsym) / sizeof(ElfW(Sym));
  }

  return 0;
}

void *xdl_sym_prefix(void *handle, const char *prefix, size_t *symbol_size) {
  if (NULL == handle) return NULL;

  xdl_t *self = (xdl_t *)handle;
  size_t dynsym_cnt = xdl_dynsym_count(self);

  return xdl_any_sym_prefix(self, prefix, symbol_size, self->dynsym, dynsym_cnt, self->dynstr,
                            self->dynstr_sz);
}

void *xdl_dsym_prefix(void *handle, const char *prefix, size_t *symbol_size) {
  if (NULL == handle) return NULL;

  xdl_t *self = (xdl_t *)handle;

  // load .symtab only once
  xdl_ensure_symtab_loaded(self);

  return xdl_any_sym_prefix(self, prefix, symbol_size, self->symtab, self->symtab_cnt, self->strtab,
                            self->strtab_sz);
}

static ElfW(Sym) *xdl_dynsym_find_symbol_use_custom_sysv_hash(xdl_t *self, const char *sym_name,
                                                              uint32_t hash) {
  for (uint32_t i = self->sysv_hash.buckets[hash % self->sysv_hash.buckets_cnt]; 0 != i;
       i = self->sysv_hash.chains[i]) {
    ElfW(Sym) *sym = self->dynsym + i;
    if (sym->st_name >= self->dynstr_sz) continue;
    if (0 != strcmp(self->dynstr + sym->st_name, sym_name)) continue;
    return sym;
  }

  return NULL;
}

static ElfW(Sym) *xdl_dynsym_find_symbol_use_custom_gnu_hash(xdl_t *self, const char *sym_name,
                                                             uint32_t hash) {
  static uint32_t elfclass_bits = sizeof(ElfW(Addr)) * 8;
  size_t word = self->gnu_hash.bloom[(hash / elfclass_bits) % self->gnu_hash.bloom_cnt];
  size_t mask = 0 | (size_t)1 << (hash % elfclass_bits) |
                (size_t)1 << ((hash >> self->gnu_hash.bloom_shift) % elfclass_bits);

  // if at least one bit is not set, this symbol is surely missing
  if ((word & mask) != mask) return NULL;

  // ignore STN_UNDEF
  uint32_t i = self->gnu_hash.buckets[hash % self->gnu_hash.buckets_cnt];
  if (i < self->gnu_hash.symoffset) return NULL;

  // loop through the chain
  while (1) {
    ElfW(Sym) *sym = self->dynsym + i;
    uint32_t sym_hash = self->gnu_hash.chains[i - self->gnu_hash.symoffset];

    if ((hash | (uint32_t)1) == (sym_hash | (uint32_t)1)) {
      if (sym->st_name < self->dynstr_sz && 0 == strcmp(self->dynstr + sym->st_name, sym_name)) {
        return sym;
      }
    }

    // chain ends with an element with the lowest bit set to 1
    if (sym_hash & (uint32_t)1) break;

    i++;
  }

  return NULL;
}

void *xdl_sym_hash(void *handle, const char *symbol, uint32_t sysv_hash, uint32_t gnu_hash,
                   size_t *symbol_size) {
  if (NULL == handle || NULL == symbol) return NULL;
  if (NULL != symbol_size) *symbol_size = 0;

  xdl_t *self = (xdl_t *)handle;

  // load .dynsym only once
  xdl_ensure_dynsym_loaded(self);
  if (NULL == self->dynsym) return NULL;

  // find symbol
  ElfW(Sym) *sym = NULL;
  if (self->gnu_hash.buckets_cnt > 0) {
    // use GNU hash (.gnu.hash -> .dynsym -> .dynstr), O(x) + O(1) + O(1)
    sym = xdl_dynsym_find_symbol_use_custom_gnu_hash(self, symbol, gnu_hash);
  }
  if (NULL == sym && self->sysv_hash.buckets_cnt > 0) {
    // use SYSV hash (.hash -> .dynsym -> .dynstr), O(x) + O(1) + O(1)
    sym = xdl_dynsym_find_symbol_use_custom_sysv_hash(self, symbol, sysv_hash);
  }
  if (NULL == sym || !XDL_DYNSYM_IS_EXPORT_SYM(sym->st_shndx)) return NULL;

  return xdl_resolve_symbol_address(self, sym, symbol_size);
}
