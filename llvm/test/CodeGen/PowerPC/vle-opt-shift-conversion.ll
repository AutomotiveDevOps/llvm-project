; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -Oz < %s | FileCheck %s

; Test VLE optimization pass: shift instruction conversion.
; PPCVLEOpt pass converts shift instructions to 16-bit VLE forms when:
; - Shift amount fits in u5imm range (0-31)
; - Registers are in R0-R7 range
; Reference: PPCVLEOpt.cpp:optimizeShiftForVLE

target datalayout = "E-p:32:32:32-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v128:128:128-n32"
target triple = "powerpc-none-eabivle"

; Test shift left with u5imm should convert to se_slwi
define i32 @test_slwi_u5imm(i32 %a) optsize minsize {
entry:
; CHECK-LABEL: @test_slwi_u5imm
; CHECK: se_slwi {{r[0-7]}}, {{r[0-7]}}, 15
; Shift left with immediate in u5imm range should use se_slwi
  %result = shl i32 %a, 15
  ret i32 %result
}

; Test shift right logical with u5imm should convert to se_srwi
define i32 @test_srwi_u5imm(i32 %a) optsize minsize {
entry:
; CHECK-LABEL: @test_srwi_u5imm
; CHECK: se_srwi {{r[0-7]}}, {{r[0-7]}}, 10
; Shift right logical with immediate in u5imm range should use se_srwi
  %result = lshr i32 %a, 10
  ret i32 %result
}

; Test shift right arithmetic with u5imm should convert to se_srawi
define i32 @test_srawi_u5imm(i32 %a) optsize minsize {
entry:
; CHECK-LABEL: @test_srawi_u5imm
; CHECK: se_srawi {{r[0-7]}}, {{r[0-7]}}, 5
; Shift right arithmetic with immediate in u5imm range should use se_srawi
  %result = ashr i32 %a, 5
  ret i32 %result
}

; Test shift with zero should optimize (no-op or identity)
define i32 @test_slwi_zero(i32 %a) optsize minsize {
entry:
; CHECK-LABEL: @test_slwi_zero
; Shift by zero should be optimized away
  %result = shl i32 %a, 0
  ret i32 %result
}

; Test shift with maximum u5imm (31)
define i32 @test_slwi_max(i32 %a) optsize minsize {
entry:
; CHECK-LABEL: @test_slwi_max
; CHECK: se_slwi {{r[0-7]}}, {{r[0-7]}}, 31
; Shift left with immediate 31 (u5imm maximum) should use se_slwi
  %result = shl i32 %a, 31
  ret i32 %result
}

; Test shift with amount outside u5imm should NOT convert
define i32 @test_slwi_large(i32 %a) optsize minsize {
entry:
; CHECK-LABEL: @test_slwi_large
; CHECK: e_slwi {{r[0-9]+}}, {{r[0-9]+}}, 32
; Shift left with immediate 32 (outside u5imm) should use e_slwi (32-bit)
  %result = shl i32 %a, 32
  ret i32 %result
}

