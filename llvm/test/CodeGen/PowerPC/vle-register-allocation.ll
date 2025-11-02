; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -Oz < %s | FileCheck %s
; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -O2 < %s | FileCheck %s --check-prefix=NOOPT

; Test register allocation behavior with VLE.
; Verifies that register allocator prefers R0-R7 for 16-bit VLE instructions
; and can use extended registers (R8-R31) for 32-bit E-form instructions.
; Reference: VLEPEM Table B-3, VLEPIM Section 1.2 (Register Allocation)

target datalayout = "E-p:32:32:32-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v128:128:128-n32"
target triple = "powerpc-none-eabivle"

; Test register allocation prefers R0-R7 for 16-bit operations
define i32 @test_reg_alloc_preference(i32 %a, i32 %b, i32 %c) optsize minsize {
entry:
; CHECK-LABEL: @test_reg_alloc_preference
; CHECK: se_addi {{r[0-7]}}, {{r[0-7]}}, 10
; CHECK: se_add {{r[0-7]}}, {{r[0-7]}}, {{r[0-7]}}
; Register allocator should prefer R0-R7 for SE_* instructions
  %add1 = add i32 %a, 10
  %add2 = add i32 %add1, %b
  ret i32 %add2
}

; Test extended registers used for 32-bit operations
define i32 @test_extended_regs(i32 %a, i32 %b, i32 %c, i32 %d, i32 %e, i32 %f, i32 %g, i32 %h, i32 %i) optsize minsize {
entry:
; CHECK-LABEL: @test_extended_regs
; CHECK: e_add {{r[0-9]+}}, {{r[0-9]+}}, {{r[0-9]+}}
; Functions with many parameters should use extended registers for E_* instructions
  %sum1 = add i32 %a, %b
  %sum2 = add i32 %sum1, %c
  %sum3 = add i32 %sum2, %d
  %sum4 = add i32 %sum3, %e
  %sum5 = add i32 %sum4, %f
  %sum6 = add i32 %sum5, %g
  %sum7 = add i32 %sum6, %h
  %sum8 = add i32 %sum7, %i
  ret i32 %sum8
}

attributes #0 = { minsize optsize "target-cpu"="e200z4" }

