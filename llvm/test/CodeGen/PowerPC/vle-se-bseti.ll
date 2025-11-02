; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -Oz < %s | FileCheck %s
; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -O2 < %s | FileCheck %s --check-prefix=NOOPT

; Test SE_BSETI (16-bit Bit Set Immediate) instruction selection.
; SE_BSETI sets a bit: rD = rA | (1 << UIMM).
; Format: se_bseti rD, rA, UIMM. Requires registers in R0-R7, immediate 0-31 (u5imm).
; Reference: VLEPEM Table B-3, VLEPIM Section 4.3.3

target datalayout = "E-p:32:32:32-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v128:128:128-n32"
target triple = "powerpc-none-eabivle"

; Test SE_BSETI setting bit 7
define i32 @test_se_bseti(i32 %a) optsize minsize {
entry:
; CHECK-LABEL: @test_se_bseti
; CHECK: se_bseti {{r[0-7]}}, {{r[0-7]}}, 7
; Bit set immediate should use SE_BSETI
  %mask = shl i32 1, 7
  %result = or i32 %a, %mask
  ret i32 %result
}

; Test SE_BSETI with different bit positions
define i32 @test_se_bseti_bit15(i32 %a) optsize minsize {
entry:
; CHECK-LABEL: @test_se_bseti_bit15
; CHECK: se_bseti {{r[0-7]}}, {{r[0-7]}}, 15
; Setting bit 15 should use SE_BSETI
  %mask = shl i32 1, 15
  %result = or i32 %a, %mask
  ret i32 %result
}

attributes #0 = { minsize optsize "target-cpu"="e200z4" }

