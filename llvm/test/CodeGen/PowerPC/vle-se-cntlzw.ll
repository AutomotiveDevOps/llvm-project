; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -Oz < %s | FileCheck %s
; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -O2 < %s | FileCheck %s --check-prefix=NOOPT

; Test SE_CNTLZW (16-bit Count Leading Zeros Word) instruction selection.
; SE_CNTLZW counts leading zeros: rD = count_leading_zeros(rA).
; Format: se_cntlzw rD, rA. Requires all registers in R0-R7 range.
; Reference: VLEPEM Table B-3, VLEPIM Section 4.7.2

target datalayout = "E-p:32:32:32-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v128:128:128-n32"
target triple = "powerpc-none-eabivle"

; Test SE_CNTLZW count leading zeros
define i32 @test_se_cntlzw(i32 %a) optsize minsize {
entry:
; CHECK-LABEL: @test_se_cntlzw
; CHECK: se_cntlzw {{r[0-7]}}, {{r[0-7]}}
; Count leading zeros should use SE_CNTLZW
  %count = call i32 @llvm.ctlz.i32(i32 %a, i1 false)
  ret i32 %count
}

declare i32 @llvm.ctlz.i32(i32, i1)

attributes #0 = { minsize optsize "target-cpu"="e200z4" }

