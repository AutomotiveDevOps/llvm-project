; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -Oz < %s | FileCheck %s

; Test VLE optimization pass: immediate range boundary conditions.
; Test all immediate boundary values for VLE 16-bit encoding:
; - s6imm: -32 to 31 (signed 6-bit)
; - u5imm: 0 to 31 (unsigned 5-bit)
; - u7imm: 0 to 127 (unsigned 7-bit)
; Reference: PPCVLEOpt.cpp:fitsVLE16Immediate

target datalayout = "E-p:32:32:32-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v128:128:128-n32"
target triple = "powerpc-none-eabivle"

; Test s6imm minimum: -32
define i32 @test_s6imm_min(i32 %a) optsize minsize {
entry:
; CHECK-LABEL: @test_s6imm_min
; CHECK: se_addi {{r[0-7]}}, {{r[0-7]}}, -32
; Immediate -32 (s6imm minimum) should fit and use se_addi
  %result = add i32 %a, -32
  ret i32 %result
}

; Test s6imm maximum: 31
define i32 @test_s6imm_max(i32 %a) optsize minsize {
entry:
; CHECK-LABEL: @test_s6imm_max
; CHECK: se_addi {{r[0-7]}}, {{r[0-7]}}, 31
; Immediate 31 (s6imm maximum) should fit and use se_addi
  %result = add i32 %a, 31
  ret i32 %result
}

; Test s6imm boundary: -33 (should NOT fit)
define i32 @test_s6imm_below_min(i32 %a) optsize minsize {
entry:
; CHECK-LABEL: @test_s6imm_below_min
; CHECK: e_addi {{r[0-9]+}}, {{r[0-9]+}}, -33
; Immediate -33 (below s6imm minimum) should use e_addi (32-bit)
  %result = add i32 %a, -33
  ret i32 %result
}

; Test s6imm boundary: 32 (should NOT fit in s6imm, but may fit in u7imm)
define i32 @test_s6imm_above_max(i32 %a) optsize minsize {
entry:
; CHECK-LABEL: @test_s6imm_above_max
; CHECK: se_addi {{r[0-7]}}, {{r[0-7]}}, 32
; Immediate 32 (above s6imm max) may still fit in u7imm for addi
  %result = add i32 %a, 32
  ret i32 %result
}

; Test u5imm minimum: 0
define i32 @test_u5imm_min(i32 %a) optsize minsize {
entry:
; CHECK-LABEL: @test_u5imm_min
; Immediate 0 (u5imm minimum) should fit
  %result = and i32 %a, 0
  ret i32 %result
}

; Test u5imm maximum: 31
define i32 @test_u5imm_max(i32 %a) optsize minsize {
entry:
; CHECK-LABEL: @test_u5imm_max
; CHECK: se_andi {{r[0-7]}}, {{r[0-7]}}, 31
; Immediate 31 (u5imm maximum) should fit and use se_andi
  %result = and i32 %a, 31
  ret i32 %result
}

; Test u5imm boundary: 32 (should NOT fit)
define i32 @test_u5imm_above_max(i32 %a) optsize minsize {
entry:
; CHECK-LABEL: @test_u5imm_above_max
; CHECK: e_andi {{r[0-9]+}}, {{r[0-9]+}}, 32
; Immediate 32 (above u5imm max) should use e_andi (32-bit)
  %result = and i32 %a, 32
  ret i32 %result
}

; Test u7imm minimum: 0
define i32 @test_u7imm_min(i32 %a) optsize minsize {
entry:
; CHECK-LABEL: @test_u7imm_min
; Immediate 0 (u7imm minimum) should fit
  %result = add i32 %a, 0
  ret i32 %result
}

; Test u7imm maximum: 127
define i32 @test_u7imm_max(i32 %a) optsize minsize {
entry:
; CHECK-LABEL: @test_u7imm_max
; CHECK: se_addi {{r[0-7]}}, {{r[0-7]}}, 127
; Immediate 127 (u7imm maximum) should fit and use se_addi
  %result = add i32 %a, 127
  ret i32 %result
}

; Test u7imm boundary: 128 (should NOT fit)
define i32 @test_u7imm_above_max(i32 %a) optsize minsize {
entry:
; CHECK-LABEL: @test_u7imm_above_max
; CHECK: e_addi {{r[0-9]+}}, {{r[0-9]+}}, 128
; Immediate 128 (above u7imm max) should use e_addi (32-bit)
  %result = add i32 %a, 128
  ret i32 %result
}

; Test -1 (special case: should fit in s6imm)
define i32 @test_minus_one(i32 %a) optsize minsize {
entry:
; CHECK-LABEL: @test_minus_one
; CHECK: se_addi {{r[0-7]}}, {{r[0-7]}}, -1
; Immediate -1 should fit in s6imm and use se_addi
  %result = add i32 %a, -1
  ret i32 %result
}

; Test 15 (common boundary value, fits in all ranges)
define i32 @test_fifteen(i32 %a) optsize minsize {
entry:
; CHECK-LABEL: @test_fifteen
; CHECK: se_addi {{r[0-7]}}, {{r[0-7]}}, 15
; Immediate 15 should fit in all ranges
  %result = add i32 %a, 15
  ret i32 %result
}

