; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -Oz < %s | FileCheck %s

; Test VLE Instruction Encoding Boundary Conditions
; Test all immediate boundary values for VLE instruction encoding to ensure
; correct handling at exact boundaries and prevent silent truncation.
; Code location: PPCInstrVLE.td:22-50, PPCAsmParser.cpp:1190-1215

target datalayout = "E-p:32:32:32-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v128:128:128-n32"
target triple = "powerpc-none-eabivle"

; Test s6imm minimum boundary: -32
define i32 @test_boundary_s6imm_min(i32 %a) optsize minsize {
entry:
; CHECK-LABEL: @test_boundary_s6imm_min
; CHECK: se_addi {{r[0-7]}}, {{r[0-7]}}, -32
; Boundary value -32 should fit in s6imm and use se_addi
  %result = add i32 %a, -32
  ret i32 %result
}

; Test s6imm maximum boundary: 31
define i32 @test_boundary_s6imm_max(i32 %a) optsize minsize {
entry:
; CHECK-LABEL: @test_boundary_s6imm_max
; CHECK: se_addi {{r[0-7]}}, {{r[0-7]}}, 31
; Boundary value 31 should fit in s6imm and use se_addi
  %result = add i32 %a, 31
  ret i32 %result
}

; Test s6imm below minimum: -33 (should NOT fit, use 32-bit)
define i32 @test_boundary_s6imm_below_min(i32 %a) optsize minsize {
entry:
; CHECK-LABEL: @test_boundary_s6imm_below_min
; CHECK: e_addi {{r[0-9]+}}, {{r[0-9]+}}, -33
; Value -33 below s6imm minimum should use e_addi (32-bit), not truncate
  %result = add i32 %a, -33
  ret i32 %result
}

; Test s6imm above maximum: 32 (may fit in u7imm for addi)
define i32 @test_boundary_s6imm_above_max(i32 %a) optsize minsize {
entry:
; CHECK-LABEL: @test_boundary_s6imm_above_max
; Value 32 above s6imm max may fit in u7imm range for addi
  %result = add i32 %a, 32
  ret i32 %result
}

; Test u5imm minimum boundary: 0
define i32 @test_boundary_u5imm_min(i32 %a) optsize minsize {
entry:
; CHECK-LABEL: @test_boundary_u5imm_min
; Boundary value 0 should fit in u5imm
  %result = and i32 %a, 0
  ret i32 %result
}

; Test u5imm maximum boundary: 31
define i32 @test_boundary_u5imm_max(i32 %a) optsize minsize {
entry:
; CHECK-LABEL: @test_boundary_u5imm_max
; CHECK: se_andi {{r[0-7]}}, {{r[0-7]}}, 31
; Boundary value 31 should fit in u5imm and use se_andi
  %result = and i32 %a, 31
  ret i32 %result
}

; Test u5imm above maximum: 32 (should NOT fit, use 32-bit)
define i32 @test_boundary_u5imm_above_max(i32 %a) optsize minsize {
entry:
; CHECK-LABEL: @test_boundary_u5imm_above_max
; CHECK: e_andi {{r[0-9]+}}, {{r[0-9]+}}, 32
; Value 32 above u5imm max should use e_andi (32-bit), not truncate
  %result = and i32 %a, 32
  ret i32 %result
}

; Test u7imm minimum boundary: 0
define i32 @test_boundary_u7imm_min(i32 %a) optsize minsize {
entry:
; CHECK-LABEL: @test_boundary_u7imm_min
; Boundary value 0 should fit in u7imm
  %result = add i32 %a, 0
  ret i32 %result
}

; Test u7imm maximum boundary: 127
define i32 @test_boundary_u7imm_max(i32 %a) optsize minsize {
entry:
; CHECK-LABEL: @test_boundary_u7imm_max
; CHECK: se_addi {{r[0-7]}}, {{r[0-7]}}, 127
; Boundary value 127 should fit in u7imm and use se_addi
  %result = add i32 %a, 127
  ret i32 %result
}

; Test u7imm above maximum: 128 (should NOT fit, use 32-bit)
define i32 @test_boundary_u7imm_above_max(i32 %a) optsize minsize {
entry:
; CHECK-LABEL: @test_boundary_u7imm_above_max
; CHECK: e_addi {{r[0-9]+}}, {{r[0-9]+}}, 128
; Value 128 above u7imm max should use e_addi (32-bit), not truncate
  %result = add i32 %a, 128
  ret i32 %result
}

; Test -1 (special case: should fit in s6imm)
define i32 @test_boundary_minus_one(i32 %a) optsize minsize {
entry:
; CHECK-LABEL: @test_boundary_minus_one
; CHECK: se_addi {{r[0-7]}}, {{r[0-7]}}, -1
; Value -1 should fit in s6imm and use se_addi
  %result = add i32 %a, -1
  ret i32 %result
}

; Test 15 (common boundary value)
define i32 @test_boundary_fifteen(i32 %a) optsize minsize {
entry:
; CHECK-LABEL: @test_boundary_fifteen
; CHECK: se_addi {{r[0-7]}}, {{r[0-7]}}, 15
; Value 15 should fit in all ranges
  %result = add i32 %a, 15
  ret i32 %result
}

