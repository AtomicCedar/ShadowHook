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
// systest targets for intercept at an arbitrary in-symbol instruction offset.
// Every instruction is 4-byte aligned; all offsets used by unittest are
// multiples of 4.

#include "asm.h"

// arm64: covers PC-relative ADRP+ADD, LDR literal, LDR X17 + BR X17 patterns.
// x0 = x0 + x1 on success (returns to caller via test_a64_helper_global).
// Offsets (bytes from start):
//   0   adrp x9        (ADRP)
//   4   add  x9        (ADD lo12)
//   8   ldr  x10, lit  (LDR literal)
//   12  ldr  x17, tgt  (LDR X17)
//   16  br   x17       (BR X17)
//   20  literal pool   (DATA - must NOT be hookable)
ENTRY_GLOBAL_ARM(test_a64_sym_offset)
    adrp     x9, test_a64_helper_hidden_tail
    add      x9, x9, :lo12:test_a64_helper_hidden_tail
    ldr      x10, .L_a64_sym_offset_lit
    ldr      x17, .L_a64_sym_offset_tgt
    br       x17
.L_a64_sym_offset_lit:
    .xword   0x123456789ABCDEF
.L_a64_sym_offset_tgt:
    .xword   test_a64_helper_hidden_tail
END(test_a64_sym_offset)

// arm64: a small straight-line function for negative tests (bad offsets).
//   0   add x0, x0, x1
//   4   add x0, x0, x1
//   8   ret
ENTRY_GLOBAL_ARM(test_a64_sym_offset_neg)
    add      x0, x0, x1
    add      x0, x0, x1
    ret
END(test_a64_sym_offset_neg)
