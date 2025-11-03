; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -Oz < %s | FileCheck %s

; Test VLE optimization pass: logical operation conversion.
; PPCVLEOpt pass converts logical ops to 16-bit VLE forms when:
; - Immediate fits in u5imm range (0-31) for shift amounts
; - Registers are in R0-R7 range
; Reference: PPCVLEOpt.cpp:optimizeLogicalForVLE

target datalayout = "E-p:32:32:32-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v128:128:128-n32"
target triple = "powerpc-none-eabivle"

; Test andi with u5imm (0-31) should convert to se_andi
define i32 @test_andi_u5imm(i32 %a) optsize minsize {
entry:
; CHECK-LABEL: @test_andi_u5imm
; CHECK: se_andi {{r[0-7]}}, {{r[0-7]}}, 31
; And with immediate in u5imm range should use se_andi
  %result = and i32 %a, 31
  ret i32 %result
}

; Test ori with u5imm should convert to se_ori
define i32 @test_ori_u5imm(i32 %a) optsize minsize {
entry:
; CHECK-LABEL: @test_ori_u5imm
; CHECK: se_ori {{r[0-7]}}, {{r[0-7]}}, 15
; Or with immediate in u5imm range should use se_ori
  %result = or i32 %a, 15
  ret i32 %result
}

; Test xori with u5imm should convert to se_xori
define i32 @test_xori_u5imm(i32 %a) optsize minsize {
entry:
; CHECK-LABEL: @test_xori_u5imm
; CHECK: se_xori {{r[0-7]}}, {{r[0-7]}}, 10
; Xor with immediate in u5imm range should use se_xori
  %result = xor i32 %a, 10
  ret i32 %result
}

; Test andi with zero should optimize to clearing register
define i32 @test_andi_zero(i32 %a) optsize minsize {
entry:
; CHECK-LABEL: @test_andi_zero
; CHECK: se_li {{r[0-7]}}, 0
; And with zero should optimize to se_li 0
  %result = and i32 %a, 0
  ret i32 %result
}

; Test ori with immediate outside u5imm should NOT convert
define i32 @test_ori_large(i32 %a) optsize minsize {
entry:
; CHECK-LABEL: @test_ori_large
; CHECK: e_ori {{r[0-9]+}}, {{r[0-9]+}}, 32
; Or with immediate 32 (outside u5imm) should use e_ori (32-bit)
  %result = or i32 %a, 32
  ret i32 %result
}

