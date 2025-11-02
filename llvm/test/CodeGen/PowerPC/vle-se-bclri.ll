; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -Oz < %s | FileCheck %s
; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -O2 < %s | FileCheck %s --check-prefix=NOOPT

; Test SE_BCLRI (16-bit Bit Clear Immediate) instruction selection.
; SE_BCLRI clears a bit: rD = rA & ~(1 << UIMM).
; Format: se_bclri rD, rA, UIMM. Requires registers in R0-R7, immediate 0-31 (u5imm).
; Reference: VLEPEM Table B-3, VLEPIM Section 4.3.3

target datalayout = "E-p:32:32:32-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v128:128:128-n32"
target triple = "powerpc-none-eabivle"

; Test SE_BCLRI clearing bit 5
define i32 @test_se_bclri(i32 %a) optsize minsize {
entry:
; CHECK-LABEL: @test_se_bclri
; CHECK: se_bclri {{r[0-7]}}, {{r[0-7]}}, 5
; Bit clear immediate should use SE_BCLRI
  %mask = shl i32 1, 5
  %notmask = xor i32 %mask, -1
  %result = and i32 %a, %notmask
  ret i32 %result
}

; Test SE_BCLRI with different bit positions
define i32 @test_se_bclri_bit0(i32 %a) optsize minsize {
entry:
; CHECK-LABEL: @test_se_bclri_bit0
; CHECK: se_bclri {{r[0-7]}}, {{r[0-7]}}, 0
; Clearing bit 0 should use SE_BCLRI
  %mask = shl i32 1, 0
  %notmask = xor i32 %mask, -1
  %result = and i32 %a, %notmask
  ret i32 %result
}

attributes #0 = { minsize optsize "target-cpu"="e200z4" }

