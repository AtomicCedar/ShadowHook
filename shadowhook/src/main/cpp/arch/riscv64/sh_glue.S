// Copyright (c) 2021-2026 ByteDance Inc.
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

// Created by Eirv (loveirv@outlook.com) on 2026-10-10.

#include "sh_config.h"

#define ENTRY(f)      \
  .globl f;           \
  .balign 4;          \
  .text;              \
  .type f, %function; \
f:                    \
  .cfi_startproc

#define END(f)   \
  .cfi_endproc;  \
  .size f, .- f

#ifdef SH_CONFIG_CORRUPT_IP_REGS
#define IP_0 t3
#define IP_1 t4
#else
#define IP_0 a0
#define IP_1 a1
#endif

ENTRY(shadowhook_interceptor_glue)
#if 0
  // set fp-chain entry
  sub  sp, sp, #0x340
  .cfi_def_cfa_offset 0x340
  stp  x29, x30, [sp]
  .cfi_rel_offset x29, 0x0
  .cfi_rel_offset x30, 0x8

  // save pstate
  mrs  IP_0, nzcv
  str  IP_0, [sp, #0x118]

  // temporary save context-pointer to stack
  str  IP_1, [sp, #-0x8]

  // Do we need to save fpsimd registers?
  ldr  IP_1, [IP_1]             // get sh_switch_t.flags_union
  tbnz IP_1, #0, .L_save_vregs  // test read_vregs bit and branch

.L_save_vregs_continue:
  // restore IP_0 and IP_1 !!!
  ldr  IP_0, [sp, #0x330]
  str  IP_1, [sp, #0x330]  // save sh_switch_t.flags_union !!!
  ldr  IP_1, [sp, #0x338]

  // save x0-x30, sp
  stp x0,  x1,  [sp, #0x10]
  stp x2,  x3,  [sp, #0x20]
  stp x4,  x5,  [sp, #0x30]
  stp x6,  x7,  [sp, #0x40]
  stp x8,  x9,  [sp, #0x50]
  stp x10, x11, [sp, #0x60]
  stp x12, x13, [sp, #0x70]
  stp x14, x15, [sp, #0x80]
  stp x16, x17, [sp, #0x90]
  stp x18, x19, [sp, #0xa0]
  stp x20, x21, [sp, #0xb0]
  stp x22, x23, [sp, #0xc0]
  stp x24, x25, [sp, #0xd0]
  stp x26, x27, [sp, #0xe0]
  stp x28, x29, [sp, #0xf0]
  add IP_0, sp, #0x340          // get sp
  stp x30, IP_0, [sp, #0x100]   // save lr, sp

  // upgrade fp for fp-chain
  mov x29, sp

  // call shadowhook_interceptor_caller
  ldr x0, [sp, #-0x8]  // get context-pointer from stack
  add x1, sp, #0x10    // CPU context
  add x2, sp, #0x338   // next_hop
  bl  shadowhook_interceptor_caller

  // Do we need to restore fpsimd registers?
  ldr  IP_0, [sp, #0x330]          // get sh_switch_t.flags_union !!!
  tbnz IP_0, #1, .L_restore_vregs  // test write_vregs bit and branch

.L_restore_vregs_continue:
  // restore pstate
  ldr IP_0, [sp, #0x118]
  msr nzcv, IP_0

  // restore x0-x30
  ldp x0,  x1,  [sp, #0x10]
  ldp x2,  x3,  [sp, #0x20]
  ldp x4,  x5,  [sp, #0x30]
  ldp x6,  x7,  [sp, #0x40]
  ldp x8,  x9,  [sp, #0x50]
  ldp x10, x11, [sp, #0x60]
  ldp x12, x13, [sp, #0x70]
  ldp x14, x15, [sp, #0x80]
  ldp x16, x17, [sp, #0x90]
  ldp x18, x19, [sp, #0xa0]
  ldp x20, x21, [sp, #0xb0]
  ldp x22, x23, [sp, #0xc0]
  ldp x24, x25, [sp, #0xd0]
  ldp x26, x27, [sp, #0xe0]
  ldp x28, x29, [sp, #0xf0]
  ldr x30,      [sp, #0x100]

  // Always use x16 and x17 registers, because the target address of
  // the subsequent jump may be a proxy function written in C language.
  str x16, [sp, #0x330]  // save x16 for "is_proc_start == false" !!!
  ldr x16, [sp, #0x338]  // get next_hop
  str x17, [sp, #0x338]  // save x17 for "is_proc_start == false" !!!

  // skip fp-chain entry
  .cfi_restore x29
  .cfi_restore x30
  // restore fp, lr, sp
  add sp,  sp,  #0x340
  .cfi_def_cfa_offset 0

  // jump to next_hop
  br x16

.L_save_vregs:
  // save q0-q31
  stp  q0,  q1,  [sp, #0x120]
  stp  q2,  q3,  [sp, #0x140]
  stp  q4,  q5,  [sp, #0x160]
  stp  q6,  q7,  [sp, #0x180]
  stp  q8,  q9,  [sp, #0x1a0]
  stp  q10, q11, [sp, #0x1c0]
  stp  q12, q13, [sp, #0x1e0]
  stp  q14, q15, [sp, #0x200]
  stp  q16, q17, [sp, #0x220]
  stp  q18, q19, [sp, #0x240]
  stp  q20, q21, [sp, #0x260]
  stp  q22, q23, [sp, #0x280]
  stp  q24, q25, [sp, #0x2a0]
  stp  q26, q27, [sp, #0x2c0]
  stp  q28, q29, [sp, #0x2e0]
  stp  q30, q31, [sp, #0x300]

  // save fpsr, fpcr
  mrs  IP_0, fpsr
  str  IP_0, [sp, #0x320]
  mrs  IP_0, fpcr
  str  IP_0, [sp, #0x328]

  b    .L_save_vregs_continue

.L_restore_vregs:
  // restore q0-q31
  ldp  q0,  q1,  [sp, #0x120]
  ldp  q2,  q3,  [sp, #0x140]
  ldp  q4,  q5,  [sp, #0x160]
  ldp  q6,  q7,  [sp, #0x180]
  ldp  q8,  q9,  [sp, #0x1a0]
  ldp  q10, q11, [sp, #0x1c0]
  ldp  q12, q13, [sp, #0x1e0]
  ldp  q14, q15, [sp, #0x200]
  ldp  q16, q17, [sp, #0x220]
  ldp  q18, q19, [sp, #0x240]
  ldp  q20, q21, [sp, #0x260]
  ldp  q22, q23, [sp, #0x280]
  ldp  q24, q25, [sp, #0x2a0]
  ldp  q26, q27, [sp, #0x2c0]
  ldp  q28, q29, [sp, #0x2e0]
  ldp  q30, q31, [sp, #0x300]

  // restore fpsr, fpcr
  ldr  IP_0, [sp, #0x320]
  msr  fpsr, IP_0
  ldr  IP_0, [sp, #0x328]
  msr  fpcr, IP_0

  b    .L_restore_vregs_continue
#endif
END(shadowhook_interceptor_glue)
