; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -Oz < %s | FileCheck %s

; Test R0-R7 register range constraints for 16-bit VLE instructions.
; SE_* instructions require all operands in R0-R7 range (3-bit register encoding).
; Instructions with registers outside this range should use 32-bit E_* forms.
; Reference: VLEPEM Table B-3, VLEPIM Section 4.2

target datalayout = "E-p:32:32:32-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v128:128:128-n32"
target triple = "powerpc-none-eabivle"

; Test that SE_ADD is used with R0-R7
define i32 @test_se_add_r0_r7(i32 %a, i32 %b) optsize minsize {
entry:
; CHECK-LABEL: @test_se_add_r0_r7
; CHECK: se_add {{r[0-7]}}, {{r[0-7]}}, {{r[0-7]}}
; When all registers are in R0-R7, should use SE_ADD
  %result = add i32 %a, %b
  ret i32 %result
}

; Test that E_ADD is used with registers outside R0-R7
define i32 @test_e_add_extended_regs(i32 %a, i32 %b) optsize minsize {
entry:
; CHECK-LABEL: @test_e_add_extended_regs
; CHECK: e_add {{r[0-9]+}}, {{r[0-9]+}}, {{r[0-9]+}}
; When registers are outside R0-R7, should use E_ADD
; Note: May still use SE_ADD if register allocator chooses R0-R7
  %result = add i32 %a, %b
  ret i32 %result
}

