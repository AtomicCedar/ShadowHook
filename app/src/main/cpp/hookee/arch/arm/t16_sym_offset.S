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

// Created by AtomicCedar on 2026-11-07.
// systest targets for intercept at an arbitrary in-symbol instruction offset
// (thumb). Offsets are counted from the symbol address (even, without the
// thumb bit).

#include "asm.h"

// thumb: straight-line T16 function for positive tests.
//   0   nop                 (T16, 2B)
//   2   add  r0, r0, r1     (T16, 2B)
//   4   ldr  r2, [pc, #8]   (T16, 2B, literal load - pool below)
//   6   nop                 (T16, 2B)
//   8   bx   lr             (T16, 2B)
//   10  pool                (DATA - must NOT be hookable)
ENTRY_GLOBAL_THUMB(test_t16_sym_offset)
    nop
    add      r0, r0, r1
    ldr      r2, .L_t16_sym_offset_lit
    nop
    bx       lr
.L_t16_sym_offset_lit:
    .word    0x12345678
END(test_t16_sym_offset)

// thumb: IT block function for boundary/negative tests.
//   0   cmp  r0, r0         (T16, 2B)
//   2   it   eq             (T16, 2B, IT block start: 1 member)
//   4   addeq r0, r0, #1    (T16, 2B, inside IT block - must NOT be hookable)
//   6   b    helper         (T16, 2B)
ENTRY_GLOBAL_THUMB(test_t16_sym_offset_it)
    cmp      r0, r0
    it       eq
    addeq    r0, r0, #1
    b        test_t16_helper_global
END(test_t16_sym_offset_it)

// thumb: T32 (4-byte) instruction function for split/negative tests.
//   0   nop                 (T16, 2B)
//   2   ldr.w r2, [r3]      (T32, 4B: offset 4 splits it)
//   6   bx   lr             (T16, 2B)
ENTRY_GLOBAL_THUMB(test_t16_sym_offset_t32)
    nop
    ldr.w    r2, [r3]
    bx       lr
END(test_t16_sym_offset_t32)
