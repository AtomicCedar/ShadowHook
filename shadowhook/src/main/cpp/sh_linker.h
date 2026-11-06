// Copyright (c) 2021-2025 ByteDance Inc.
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//

// Created by Kelun Cai (caikelun@bytedance.com) on 2021-04-11.

#pragma once
#include <link.h>
#include <stdbool.h>
#include <stdint.h>

#include "sh_config.h"
#include "sh_util.h"
#include "shadowhook.h"

#ifdef __cplusplus
extern "C" {
#endif

// linker utils
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wpadded"
typedef struct {
  void *dli_fbase;              // ELF load_bias
  char *dli_fname;              // pathname or basename of ELF
  void *dli_saddr;              // symbol address
  size_t dli_ssize;             // symbol size
  const ElfW(Phdr) *dlpi_phdr;  // ELF program headers
  size_t dlpi_phnum;            // number of items in dlpi_phdr
  bool is_sym_addr;
  bool is_proc_start;
} sh_addr_info_t;
#pragma clang diagnostic pop
int sh_linker_get_addr_info_by_addr(sh_addr_info_t *addr_info, void *addr, bool is_sym_addr,
                                    bool is_proc_start, bool ignore_sym_info);
int sh_linker_get_addr_info_by_name(sh_addr_info_t *addr_info, const char *lib_name, const char *sym_name);

void sh_linker_free_addr_info(sh_addr_info_t *addr_info);
int sh_linker_copy_addr_info(sh_addr_info_t *addr_info, sh_addr_info_t *copy);

bool sh_linker_is_addr_in_elf_pt_load(uintptr_t addr, void *dli_fbase, const ElfW(Phdr) *dlpi_phdr,
                                      size_t dlpi_phnum);

#ifdef __cplusplus
}
#endif
