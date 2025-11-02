; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -Oz < %s | FileCheck %s

; Test immediate value range constraints for VLE instructions.
; SE_* instructions use s6imm (-32 to 31), u4imm (0-15), u5imm (0-31).
; Large immediates should use 32-bit E_* forms or standard PowerPC instructions.
; Reference: VLEPEM Table B-3, VLEPIM Section 4.3.1

target datalayout = "E-p:32:32:32-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v128:128:128-n32"
target triple = "powerpc-none-eabivle"

; Test s6imm boundaries for arithmetic instructions
define i32 @test_s6imm_boundaries(i32 %a) optsize minsize {
entry:
; CHECK-LABEL: @test_s6imm_boundaries
; Minimum s6imm (-32) should use SE_ADDI
  %val1 = add i32 %a, -32
; CHECK: se_addi {{r[0-7]}}, {{r[0-7]}}, -32
; Maximum s6imm (31) should use SE_ADDI
  %val2 = add i32 %a, 31
; CHECK: se_addi {{r[0-7]}}, {{r[0-7]}}, 31
; Outside range should use E_ADDI or standard addi
  %val3 = add i32 %a, 32
; CHECK-NOT: se_addi {{r[0-7]}}, {{r[0-7]}}, 32
  %sum = add i32 %val1, %val2
  %result = add i32 %sum, %val3
  ret i32 %result
}

