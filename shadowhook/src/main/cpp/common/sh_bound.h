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
// Instruction-boundary validation for intercepting at an arbitrary offset
// inside a symbol (function), for both arm64 and thumb.

#pragma once
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Check whether `offset` is a valid hookable instruction position within the
// symbol at `sym_addr` with size `sym_size`.
//
// Checks:
// - offset is within the symbol range [0, sym_size)
// - offset falls on an instruction boundary when decoding linearly from sym_addr
// - the instruction at the offset is safe to relocate:
//   - arm64: always safe if boundary-aligned (rewrite engine handles PC-relative)
//   - thumb: not inside an IT block (except at the IT block start),
//            not BL/BLX/SVC, not in a detected literal pool
//
// Returns 0 on success, or SHADOWHOOK_ERRNO_* on failure.
int sh_bound_check(uintptr_t sym_addr, size_t sym_size, size_t offset);
