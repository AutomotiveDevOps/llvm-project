; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -Oz < %s | FileCheck %s
; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -O2 < %s | FileCheck %s --check-prefix=NOOPT

; Test SE_ADDI (16-bit Add Immediate) instruction selection.
; SE_ADDI performs addition with immediate: rD = rA + imm.
; Format: se_addi rD, rA, SIMM where SIMM is 6-bit signed immediate (-32 to 31).
; Requires registers in R0-R7 range and immediate in s6imm range.
; Reference: VLEPEM Table B-3, VLEPIM Section 4.3.1

target datalayout = "E-p:32:32:32-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v128:128:128-n32"
target triple = "powerpc-none-eabivle"

; Test SE_ADDI with small positive immediate
define i32 @test_se_addi_positive(i32 %a) optsize minsize {
entry:
; CHECK-LABEL: @test_se_addi_positive
; CHECK: se_addi {{r[0-7]}}, {{r[0-7]}}, 15
; Immediate 15 (within s6imm range -32 to 31) should use SE_ADDI
  %result = add i32 %a, 15
  ret i32 %result
}

; Test SE_ADDI with negative immediate
define i32 @test_se_addi_negative(i32 %a) optsize minsize {
entry:
; CHECK-LABEL: @test_se_addi_negative
; CHECK: se_addi {{r[0-7]}}, {{r[0-7]}}, -10
; Immediate -10 (within s6imm range) should use SE_ADDI
  %result = add i32 %a, -10
  ret i32 %result
}

; Test SE_ADDI with minimum immediate (-32)
define i32 @test_se_addi_min(i32 %a) optsize minsize {
entry:
; CHECK-LABEL: @test_se_addi_min
; CHECK: se_addi {{r[0-7]}}, {{r[0-7]}}, -32
; Minimum immediate -32 should use SE_ADDI
  %result = add i32 %a, -32
  ret i32 %result
}

; Test SE_ADDI with maximum immediate (31)
define i32 @test_se_addi_max(i32 %a) optsize minsize {
entry:
; CHECK-LABEL: @test_se_addi_max
; CHECK: se_addi {{r[0-7]}}, {{r[0-7]}}, 31
; Maximum immediate 31 should use SE_ADDI
  %result = add i32 %a, 31
  ret i32 %result
}

; Test that immediate outside range falls back to standard instruction
define i32 @test_se_addi_large_imm(i32 %a) optsize minsize {
entry:
; CHECK-LABEL: @test_se_addi_large_imm
; CHECK-NOT: se_addi {{r[0-7]}}, {{r[0-7]}}, 32
; Immediate 32 (outside s6imm range) should use standard addi or e_addi
; NOOPT-LABEL: @test_se_addi_large_imm
; NOOPT: addi
  %result = add i32 %a, 32
  ret i32 %result
}

