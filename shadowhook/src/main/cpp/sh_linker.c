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

#include "sh_linker.h"

#include <dlfcn.h>
#include <pthread.h>
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <sys/system_properties.h>

#include "queue.h"
#include "sh_log.h"
#include "sh_recorder.h"
#include "sh_sig.h"
#include "sh_switch.h"
#include "sh_util.h"
#include "sh_xdl.h"
#include "shadowhook.h"
#include "xdl.h"

static void *sh_linker_get_base_addr(xdl_info_t *dlinfo) {
  uintptr_t vaddr_min = UINTPTR_MAX;
  for (size_t i = 0; i < dlinfo->dlpi_phnum; i++) {
    const ElfW(Phdr) *phdr = &(dlinfo->dlpi_phdr[i]);
    if (PT_LOAD == phdr->p_type && vaddr_min > phdr->p_vaddr) vaddr_min = phdr->p_vaddr;
  }

  if (UINTPTR_MAX == vaddr_min)
    return dlinfo->dli_fbase;  // should not happen
  else
    return (void *)((uintptr_t)dlinfo->dli_fbase + sh_util_page_start(vaddr_min));
}

static bool sh_linker_check_arch(xdl_info_t *dlinfo) {
  ElfW(Ehdr) *ehdr = (ElfW(Ehdr) *)sh_linker_get_base_addr(dlinfo);

#if defined(__LP64__)
#define SH_LINKER_ELF_CLASS   ELFCLASS64
#define SH_LINKER_ELF_MACHINE EM_AARCH64
#else
#define SH_LINKER_ELF_CLASS   ELFCLASS32
#define SH_LINKER_ELF_MACHINE EM_ARM
#endif

  if (0 != memcmp(ehdr->e_ident, ELFMAG, SELFMAG)) return false;
  if (SH_LINKER_ELF_CLASS != ehdr->e_ident[EI_CLASS]) return false;
  if (SH_LINKER_ELF_MACHINE != ehdr->e_machine) return false;

  return true;
}

int sh_linker_get_addr_info_by_addr(sh_addr_info_t *addr_info, void *addr, bool is_sym_addr,
                                    bool is_proc_start, bool ignore_sym_info) {
  sh_linker_free_addr_info(addr_info);
  memset(addr_info, 0, sizeof(sh_addr_info_t));

  // dladdr()
  int r = 0;
  void *dlcache = NULL;
  bool crashed = false;
  xdl_info_t dlinfo;
  memset(&dlinfo, 0, sizeof(xdl_info_t));
  if (sh_util_get_api_level() >= __ANDROID_API_L__) {
    r = xdl_addr4(addr, &dlinfo, &dlcache, ignore_sym_info ? XDL_NON_SYM : XDL_DEFAULT);
  } else {
    SH_SIG_TRY(SIGSEGV, SIGBUS) {
      r = xdl_addr4(addr, &dlinfo, &dlcache, ignore_sym_info ? XDL_NON_SYM : XDL_DEFAULT);
    }
    SH_SIG_CATCH() {
      crashed = true;
    }
    SH_SIG_EXIT
  }
  SH_LOG_INFO(
      "linker: get dlinfo by target addr: target_addr %p, sym_name %s, sym_sz %zu, load_bias %" PRIxPTR
      ", pathname %s",
      addr, NULL == dlinfo.dli_sname ? "(NULL)" : dlinfo.dli_sname, dlinfo.dli_ssize,
      (uintptr_t)dlinfo.dli_fbase, NULL == dlinfo.dli_fname ? "(NULL)" : dlinfo.dli_fname);

  // check error
  if (crashed) {
    r = SHADOWHOOK_ERRNO_HOOK_DLADDR_CRASH;
    goto end;
  }
  if (0 == r || NULL == dlinfo.dli_fbase) {
    r = SHADOWHOOK_ERRNO_HOOK_DLINFO;
    goto end;
  }
  if (!sh_linker_check_arch(&dlinfo)) {
    r = SHADOWHOOK_ERRNO_ELF_ARCH_MISMATCH;
    goto end;
  }

  if (!ignore_sym_info && 0 == dlinfo.dli_saddr) {
    r = SHADOWHOOK_ERRNO_HOOK_DLINFO;
    goto end;
  }

  // OK
  if (NULL != dlinfo.dli_fname) {
    if (NULL == (addr_info->dli_fname = strdup(dlinfo.dli_fname))) return SHADOWHOOK_ERRNO_OOM;
  }
  addr_info->dli_fbase = dlinfo.dli_fbase;
  addr_info->dli_saddr = dlinfo.dli_saddr;
  addr_info->dli_ssize = dlinfo.dli_ssize;
  addr_info->dlpi_phdr = dlinfo.dlpi_phdr;
  addr_info->dlpi_phnum = dlinfo.dlpi_phnum;
  addr_info->is_sym_addr = is_sym_addr;
  addr_info->is_proc_start = is_proc_start;
  r = 0;

end:
  xdl_addr_clean(&dlcache);
  return r;
}

int sh_linker_get_addr_info_by_name(sh_addr_info_t *addr_info, const char *lib_name, const char *sym_name) {
  sh_linker_free_addr_info(addr_info);
  memset(addr_info, 0, sizeof(sh_addr_info_t));

  // open library
  void *handle = sh_xdl_open(lib_name);
  if (SH_XDL_CRASH == handle) return SHADOWHOOK_ERRNO_HOOK_DLOPEN_CRASH;
  if (NULL == handle) return SHADOWHOOK_ERRNO_HOOK_DLOPEN;

  // get dlinfo
  xdl_info_t dlinfo;
  xdl_info(handle, XDL_DI_DLINFO, (void *)&dlinfo);

  // check error
  if (!sh_linker_check_arch(&dlinfo)) {
    xdl_close(handle);
    return SHADOWHOOK_ERRNO_ELF_ARCH_MISMATCH;
  }

  // lookup symbol address
  size_t sym_size = 0;
  void *sym_addr = sh_xdl_sym(handle, sym_name, &sym_size);

  // close library
  xdl_close(handle);

  if (SH_XDL_CRASH == sym_addr) return SHADOWHOOK_ERRNO_HOOK_DLSYM_CRASH;
  if (NULL == sym_addr) return SHADOWHOOK_ERRNO_HOOK_DLSYM;

  if (NULL == (addr_info->dli_fname = strdup(lib_name))) return SHADOWHOOK_ERRNO_OOM;
  addr_info->dli_fbase = dlinfo.dli_fbase;
  addr_info->dli_saddr = sym_addr;
  addr_info->dli_ssize = sym_size;
  addr_info->dlpi_phdr = dlinfo.dlpi_phdr;
  addr_info->dlpi_phnum = dlinfo.dlpi_phnum;
  addr_info->is_sym_addr = true;
  addr_info->is_proc_start = true;
  return 0;
}

void sh_linker_free_addr_info(sh_addr_info_t *addr_info) {
  if (NULL != addr_info->dli_fname) {
    free(addr_info->dli_fname);
    addr_info->dli_fname = NULL;
  }
}

int sh_linker_copy_addr_info(sh_addr_info_t *addr_info, sh_addr_info_t *copy) {
  memcpy(copy, addr_info, sizeof(sh_addr_info_t));
  if (NULL != addr_info->dli_fname) {
    copy->dli_fname = strdup(addr_info->dli_fname);
    if (NULL == copy->dli_fname) return SHADOWHOOK_ERRNO_OOM;
  }
  return 0;
}

bool sh_linker_is_addr_in_elf_pt_load(uintptr_t addr, void *dli_fbase, const ElfW(Phdr) *dlpi_phdr,
                                      size_t dlpi_phnum) {
  if (addr < (uintptr_t)dli_fbase) return false;

  uintptr_t vaddr = addr - (uintptr_t)dli_fbase;
  for (size_t i = 0; i < dlpi_phnum; i++) {
    const ElfW(Phdr) *phdr = &dlpi_phdr[i];
    if (PT_LOAD != phdr->p_type) continue;

    if (phdr->p_vaddr <= vaddr && vaddr < phdr->p_vaddr + phdr->p_memsz) return true;
  }

  return false;
}
