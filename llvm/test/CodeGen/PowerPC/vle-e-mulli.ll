; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -Oz < %s | FileCheck %s
; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -O2 < %s | FileCheck %s --check-prefix=NOOPT

; Test E_MULLI (32-bit Multiply Immediate) instruction selection.
; E_MULLI performs signed multiplication with immediate: rD = (rA * SIMM)[31:0].
; Format: e_mulli rD, rA, SIMM. This is a 32-bit VLE instruction.
; Immediate range: -32768 to 32767 (16-bit signed).
; Reference: VLEPEM Table B-3, VLEPIM Section 4.3.4

target datalayout = "E-p:32:32:32-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v128:128:128-n32"
target triple = "powerpc-none-eabivle"

; Test E_MULLI with small immediate
define i32 @test_e_mulli_small(i32 %a) optsize minsize {
entry:
; CHECK-LABEL: @test_e_mulli_small
; CHECK: e_mulli {{r[0-9]+}}, {{r[0-9]+}}, 5
; Multiply with immediate should use E_MULLI
  %result = mul i32 %a, 5
  ret i32 %result
}

; Test E_MULLI with negative immediate
define i32 @test_e_mulli_neg(i32 %a) optsize minsize {
entry:
; CHECK-LABEL: @test_e_mulli_neg
; CHECK: e_mulli {{r[0-9]+}}, {{r[0-9]+}}, -10
; Negative immediate should use E_MULLI
  %result = mul i32 %a, -10
  ret i32 %result
}

; Test E_MULLI with larger immediate (within 16-bit signed range)
define i32 @test_e_mulli_large(i32 %a) optsize minsize {
entry:
; CHECK-LABEL: @test_e_mulli_large
; CHECK: e_mulli {{r[0-9]+}}, {{r[0-9]+}}, 32767
; Large immediate within range should use E_MULLI
  %result = mul i32 %a, 32767
  ret i32 %result
}

attributes #0 = { minsize optsize "target-cpu"="e200z4" }

