; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -Oz < %s | FileCheck %s
; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -O2 < %s | FileCheck %s --check-prefix=NOOPT

; Test VLE optimization pass: 32-bit to 16-bit add/sub conversion.
; PPCVLEOpt pass converts addi/subi to se_addi/se_subi when:
; - Immediate fits in s6imm range (-32 to 31) or u7imm range (0-127)
; - Registers are in R0-R7 range (for 16-bit encoding)
; Reference: PPCVLEOpt.cpp:optimizeAddSubForVLE

target datalayout = "E-p:32:32:32-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v128:128:128-n32"
target triple = "powerpc-none-eabivle"

; Test addi with s6imm (-32 to 31) should convert to se_addi
define i32 @test_addi_s6imm(i32 %a) optsize minsize {
entry:
; CHECK-LABEL: @test_addi_s6imm
; CHECK: se_addi {{r[0-7]}}, {{r[0-7]}}, -32
; Add with immediate -32 (s6imm minimum) should use se_addi
  %result = add i32 %a, -32
  ret i32 %result
}

; Test addi with s6imm maximum (31)
define i32 @test_addi_s6imm_max(i32 %a) optsize minsize {
entry:
; CHECK-LABEL: @test_addi_s6imm_max
; CHECK: se_addi {{r[0-7]}}, {{r[0-7]}}, 31
; Add with immediate 31 (s6imm maximum) should use se_addi
  %result = add i32 %a, 31
  ret i32 %result
}

; Test addi with u7imm (0-127) should convert to se_addi
define i32 @test_addi_u7imm(i32 %a) optsize minsize {
entry:
; CHECK-LABEL: @test_addi_u7imm
; CHECK: se_addi {{r[0-7]}}, {{r[0-7]}}, 127
; Add with immediate 127 (u7imm maximum) should use se_addi
  %result = add i32 %a, 127
  ret i32 %result
}

; Test addi with zero should convert to se_addi
define i32 @test_addi_zero(i32 %a) optsize minsize {
entry:
; CHECK-LABEL: @test_addi_zero
; CHECK: se_addi {{r[0-7]}}, {{r[0-7]}}, 0
; Add with immediate 0 should use se_addi (or se_mr for identity)
  %result = add i32 %a, 0
  ret i32 %result
}

; Test subi with s6imm should convert to se_subi
define i32 @test_subi_s6imm(i32 %a) optsize minsize {
entry:
; CHECK-LABEL: @test_subi_s6imm
; CHECK: se_subi {{r[0-7]}}, {{r[0-7]}}, 15
; Subtract with immediate in s6imm range should use se_subi
  %result = sub i32 %a, 15
  ret i32 %result
}

; Test addi with immediate outside VLE range should NOT convert
define i32 @test_addi_large(i32 %a) optsize minsize {
entry:
; CHECK-LABEL: @test_addi_large
; NOOPT-LABEL: @test_addi_large
; CHECK: e_addi {{r[0-9]+}}, {{r[0-9]+}}, 128
; Add with immediate 128 (outside u7imm) should use e_addi (32-bit)
  %result = add i32 %a, 128
  ret i32 %result
}

; Test multiple addi operations
define i32 @test_addi_multiple(i32 %a) optsize minsize {
entry:
; CHECK-LABEL: @test_addi_multiple
; CHECK-DAG: se_addi {{r[0-7]}}, {{r[0-7]}}, 10
; CHECK-DAG: se_addi {{r[0-7]}}, {{r[0-7]}}, 20
; Multiple addi operations should each convert if possible
  %v1 = add i32 %a, 10
  %v2 = add i32 %v1, 20
  ret i32 %v2
}

