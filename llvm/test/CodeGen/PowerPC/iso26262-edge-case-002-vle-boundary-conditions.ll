; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -Oz < %s | FileCheck %s
; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z6 -mvle -Oz < %s | FileCheck %s

; ISO 26262 Edge Case 002: VLE Instruction Encoding Boundary Condition Failures
; Test boundary values for immediate predicates: s6imm (-32 to 31), u5imm (0-31), u7imm (0-127), u4imm (0-15)
; Reference: PPCInstrVLE.td:22-50, PPCAsmParser.cpp:1190-1215

target datalayout = "E-p:32:32:32-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v128:128:128-n32"
target triple = "powerpc-none-eabivle"

; Test s6imm boundary: -32 (minimum valid)
define i32 @test_s6imm_min(i32 %a) optsize minsize {
; CHECK-LABEL: test_s6imm_min:
; CHECK: se_addi {{r[0-7]}}, {{r[0-7]}}, -32
entry:
  %result = add i32 %a, -32
  ret i32 %result
}

; Test s6imm boundary: -33 (should NOT use se_addi, must use E_ADDI or addi)
define i32 @test_s6imm_below_min(i32 %a) optsize minsize {
; CHECK-LABEL: test_s6imm_below_min:
; CHECK-NOT: se_addi {{r[0-7]}}, {{r[0-7]}}, -33
; CHECK: addi {{r[0-9]+}}, {{r[0-9]+}}, -33
entry:
  %result = add i32 %a, -33
  ret i32 %result
}

; Test s6imm boundary: 31 (maximum valid)
define i32 @test_s6imm_max(i32 %a) optsize minsize {
; CHECK-LABEL: test_s6imm_max:
; CHECK: se_addi {{r[0-7]}}, {{r[0-7]}}, 31
entry:
  %result = add i32 %a, 31
  ret i32 %result
}

; Test s6imm boundary: 32 (should NOT use se_addi)
define i32 @test_s6imm_above_max(i32 %a) optsize minsize {
; CHECK-LABEL: test_s6imm_above_max:
; CHECK-NOT: se_addi {{r[0-7]}}, {{r[0-7]}}, 32
; CHECK: addi {{r[0-9]+}}, {{r[0-9]+}}, 32
entry:
  %result = add i32 %a, 32
  ret i32 %result
}

; Test u5imm boundary: 0 (minimum valid for displacement)
define i32 @test_u5imm_min(i32* %ptr) optsize minsize {
; CHECK-LABEL: test_u5imm_min:
; CHECK: se_lwz {{r[0-7]}}, 0({{r[0-7]}})
entry:
  %val = load i32, i32* %ptr
  ret i32 %val
}

; Test u5imm boundary: 31 (maximum valid)
define i32 @test_u5imm_max(i32* %ptr) optsize minsize {
; CHECK-LABEL: test_u5imm_max:
; CHECK: se_lwz {{r[0-7]}}, 31({{r[0-7]}})
entry:
  %ptr_offset = getelementptr i32, i32* %ptr, i32 31
  %val = load i32, i32* %ptr_offset
  ret i32 %val
}

; Test u5imm boundary: 32 (should NOT use se_lwz with displacement)
define i32 @test_u5imm_above_max(i32* %ptr) optsize minsize {
; CHECK-LABEL: test_u5imm_above_max:
; CHECK-NOT: se_lwz {{r[0-7]}}, 32({{r[0-7]}})
; CHECK: lwz {{r[0-9]+}}, 32({{r[0-9]+}})
entry:
  %ptr_offset = getelementptr i32, i32* %ptr, i32 32
  %val = load i32, i32* %ptr_offset
  ret i32 %val
}

; Test u7imm boundary: 0 (minimum valid)
define i32 @test_u7imm_min(i32 %a) optsize minsize {
; CHECK-LABEL: test_u7imm_min:
entry:
  ; u7imm is used in specific VLE instructions
  ret i32 %a
}

; Test u7imm boundary: 127 (maximum valid)
define i32 @test_u7imm_max(i32 %a) optsize minsize {
; CHECK-LABEL: test_u7imm_max:
entry:
  ret i32 %a
}

; Test u4imm boundary: 0 (minimum valid for byte/halfword displacement)
define i8 @test_u4imm_min(i8* %ptr) optsize minsize {
; CHECK-LABEL: test_u4imm_min:
; CHECK: se_lbz {{r[0-7]}}, 0({{r[0-7]}})
entry:
  %val = load i8, i8* %ptr
  ret i8 %val
}

; Test u4imm boundary: 15 (maximum valid)
define i8 @test_u4imm_max(i8* %ptr) optsize minsize {
; CHECK-LABEL: test_u4imm_max:
; CHECK: se_lbz {{r[0-7]}}, 15({{r[0-7]}})
entry:
  %ptr_offset = getelementptr i8, i8* %ptr, i32 15
  %val = load i8, i8* %ptr_offset
  ret i8 %val
}

; Test u4imm boundary: 16 (should NOT use se_lbz with displacement)
define i8 @test_u4imm_above_max(i8* %ptr) optsize minsize {
; CHECK-LABEL: test_u4imm_above_max:
; CHECK-NOT: se_lbz {{r[0-7]}}, 16({{r[0-7]}})
; CHECK: lbz {{r[0-9]+}}, 16({{r[0-9]+}})
entry:
  %ptr_offset = getelementptr i8, i8* %ptr, i32 16
  %val = load i8, i8* %ptr_offset
  ret i8 %val
}

; Test boundary value -1 (should use se_addi with -1)
define i32 @test_boundary_minus_one(i32 %a) optsize minsize {
; CHECK-LABEL: test_boundary_minus_one:
; CHECK: se_addi {{r[0-7]}}, {{r[0-7]}}, -1
entry:
  %result = add i32 %a, -1
  ret i32 %result
}

