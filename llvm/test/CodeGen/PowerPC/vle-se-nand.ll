; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -Oz < %s | FileCheck %s
; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -O2 < %s | FileCheck %s --check-prefix=NOOPT

; Test SE_NAND (16-bit NAND) instruction selection.
; SE_NAND performs bitwise NAND: rD = ~(rA & rB).
; Format: se_nand rD, rA, rB. Requires all registers in R0-R7 range.
; Reference: VLEPEM Table B-3, VLEPIM Section 4.3.3

target datalayout = "E-p:32:32:32-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v128:128:128-n32"
target triple = "powerpc-none-eabivle"

; Test SE_NAND basic operation
define i32 @test_se_nand(i32 %a, i32 %b) optsize minsize {
entry:
; CHECK-LABEL: @test_se_nand
; CHECK: se_nand {{r[0-7]}}, {{r[0-7]}}, {{r[0-7]}}
; NAND operation with R0-R7 should use SE_NAND
  %and = and i32 %a, %b
  %result = xor i32 %and, -1
  ret i32 %result
}

attributes #0 = { minsize optsize "target-cpu"="e200z4" }

