; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -Oz < %s | FileCheck %s
; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -O2 < %s | FileCheck %s --check-prefix=NOOPT

; Test E_ADDC (32-bit Add with Carry) instruction selection.
; E_ADDC performs addition with carry: rD = rA + rB + CA (carry bit from XER).
; Format: e_addc rD, rA, rB. This is a 32-bit VLE instruction.
; Reference: VLEPEM Table B-3, VLEPIM Section 4.3.2

target datalayout = "E-p:32:32:32-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v128:128:128-n32"
target triple = "powerpc-none-eabivle"

; Test E_ADDC with explicit carry addition
; Note: LLVM IR doesn't have direct carry support, so we test via patterns
; that would generate addc when carry propagation is needed
define i32 @test_e_addc(i32 %a, i32 %b) optsize minsize {
entry:
; CHECK-LABEL: @test_e_addc
; CHECK: e_addc {{r[0-9]+}}, {{r[0-9]+}}, {{r[0-9]+}}
; With VLE enabled, extended add with carry should use E_ADDC
  %result = add i32 %a, %b
  ret i32 %result
}

attributes #0 = { minsize optsize "target-cpu"="e200z4" }

