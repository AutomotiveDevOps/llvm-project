; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -Oz < %s | FileCheck %s
; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -O2 < %s | FileCheck %s --check-prefix=NOOPT

; Test E_MULHW (32-bit Multiply High Word Signed) instruction selection.
; E_MULHW computes high 32 bits of signed multiplication: rD = (rA * rB)[63:32].
; Format: e_mulhw rD, rA, rB. This is a 32-bit VLE instruction.
; Reference: VLEPEM Table B-3, VLEPIM Section 4.3.4

target datalayout = "E-p:32:32:32-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v128:128:128-n32"
target triple = "powerpc-none-eabivle"

; Test E_MULHW for high word extraction
; Note: LLVM uses mulhs intrinsic for high bits
define i32 @test_e_mulhw(i32 %a, i32 %b) optsize minsize {
entry:
; CHECK-LABEL: @test_e_mulhw
; CHECK: e_mulhw {{r[0-9]+}}, {{r[0-9]+}}, {{r[0-9]+}}
; Multiply high signed should use E_MULHW
  %result = call i32 @llvm.ppc.mulhw.i32(i32 %a, i32 %b)
  ret i32 %result
}

declare i32 @llvm.ppc.mulhw.i32(i32, i32)

attributes #0 = { minsize optsize "target-cpu"="e200z4" }

