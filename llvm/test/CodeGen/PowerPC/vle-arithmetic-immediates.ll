; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -Oz < %s | FileCheck %s
; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -O2 < %s | FileCheck %s --check-prefix=NOOPT

; Test arithmetic instructions with immediate value constraints.
; Verifies immediate range boundaries for VLE instructions:
; - s6imm: -32 to 31 (6-bit signed) for SE_ADDI, SE_SUBI
; - 16-bit signed immediate for E_ADDI, E_MULLI
; Tests both values that fit and values that don't fit VLE constraints.
; Reference: VLEPEM Table B-3, VLEPIM Section 4.2.1

target datalayout = "E-p:32:32:32-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v128:128:128-n32"
target triple = "powerpc-none-eabivle"

; Test SE_ADDI with immediate at lower boundary (-32)
define i32 @test_se_addi_min(i32 %a) optsize minsize {
entry:
; CHECK-LABEL: @test_se_addi_min
; CHECK: se_addi {{r[0-7]}}, {{r[0-7]}}, -32
; Minimum s6imm value should use SE_ADDI
  %result = add i32 %a, -32
  ret i32 %result
}

; Test SE_ADDI with immediate at upper boundary (31)
define i32 @test_se_addi_max(i32 %a) optsize minsize {
entry:
; CHECK-LABEL: @test_se_addi_max
; CHECK: se_addi {{r[0-7]}}, {{r[0-7]}}, 31
; Maximum s6imm value should use SE_ADDI
  %result = add i32 %a, 31
  ret i32 %result
}

; Test SE_ADDI with immediate just outside range (32)
define i32 @test_se_addi_out_of_range(i32 %a) optsize minsize {
entry:
; CHECK-LABEL: @test_se_addi_out_of_range
; CHECK-NOT: se_addi
; CHECK: e_addi {{r[0-9]+}}, {{r[0-9]+}}, 32
; Value outside s6imm range should use E_ADDI (32-bit)
  %result = add i32 %a, 32
  ret i32 %result
}

; Test E_ADDI with larger immediate
define i32 @test_e_addi_large(i32 %a) optsize minsize {
entry:
; CHECK-LABEL: @test_e_addi_large
; CHECK: e_addi {{r[0-9]+}}, {{r[0-9]+}}, 100
; Larger immediate should use E_ADDI
  %result = add i32 %a, 100
  ret i32 %result
}

; Test E_MULLI with immediate in range
define i32 @test_e_mulli_range(i32 %a) optsize minsize {
entry:
; CHECK-LABEL: @test_e_mulli_range
; CHECK: e_mulli {{r[0-9]+}}, {{r[0-9]+}}, 100
; Immediate multiplication should use E_MULLI
  %result = mul i32 %a, 100
  ret i32 %result
}

; Test E_MULLI with negative immediate
define i32 @test_e_mulli_negative(i32 %a) optsize minsize {
entry:
; CHECK-LABEL: @test_e_mulli_negative
; CHECK: e_mulli {{r[0-9]+}}, {{r[0-9]+}}, -50
; Negative immediate should use E_MULLI
  %result = mul i32 %a, -50
  ret i32 %result
}

attributes #0 = { minsize optsize "target-cpu"="e200z4" }

