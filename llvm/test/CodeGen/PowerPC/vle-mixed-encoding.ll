; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -Oz < %s | FileCheck %s

; Test mixed 16-bit and 32-bit VLE instruction sequences.
; Verify that sequences mixing se_* (16-bit) and e_* (32-bit) instructions
; are generated correctly based on immediate values and register constraints.
; Reference: VLEPIM Section 4.3

target datalayout = "E-p:32:32:32-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v128:128:128-n32"
target triple = "powerpc-none-eabivle"

; Test mixed sequence: some operations fit 16-bit, others need 32-bit
define i32 @test_mixed_sequence(i32 %a, i32* %ptr) optsize minsize {
entry:
; CHECK-LABEL: @test_mixed_sequence
; 16-bit addi (fits s6imm)
  %v1 = add i32 %a, 15
; CHECK: se_addi {{r[0-7]}}, {{r[0-7]}}, 15
; 32-bit addi (immediate too large)
  %v2 = add i32 %v1, 128
; CHECK: e_addi {{r[0-9]+}}, {{r[0-9]+}}, 128
; 16-bit shift (fits u5imm)
  %v3 = shl i32 %v2, 10
; CHECK: se_slwi {{r[0-7]}}, {{r[0-7]}}, 10
; 32-bit load (may need large offset)
  %val = load i32, i32* %ptr
; 16-bit add (registers in R0-R7)
  %result = add i32 %v3, %val
; CHECK: se_add {{r[0-7]}}, {{r[0-7]}}, {{r[0-7]}}
  ret i32 %result
}

; Test alternating 16-bit and 32-bit instructions
define i32 @test_alternating_encoding(i32 %a) optsize minsize {
entry:
; CHECK-LABEL: @test_alternating_encoding
; 16-bit
  %v1 = add i32 %a, 10
; CHECK: se_addi {{r[0-7]}}, {{r[0-7]}}, 10
; 32-bit
  %v2 = add i32 %v1, 200
; CHECK: e_addi {{r[0-9]+}}, {{r[0-9]+}}, 200
; 16-bit
  %v3 = shl i32 %v2, 5
; CHECK: se_slwi {{r[0-7]}}, {{r[0-7]}}, 5
; 32-bit
  %v4 = add i32 %v3, 256
; CHECK: e_addi {{r[0-9]+}}, {{r[0-9]+}}, 256
  ret i32 %v4
}

; Test that register allocation affects encoding choice
define i32 @test_register_affects_encoding(i32 %a, i32 %b, i32 %c, i32 %d, i32 %e, i32 %f, i32 %g, i32 %h, i32 %i) optsize minsize {
entry:
; CHECK-LABEL: @test_register_affects_encoding
; High register pressure may force R8+ usage, affecting encoding
  %v1 = add i32 %a, %b
  %v2 = add i32 %c, %d
  %v3 = add i32 %e, %f
  %v4 = add i32 %g, %h
  %s1 = add i32 %v1, %v2
  %s2 = add i32 %v3, %v4
  %s3 = add i32 %s1, %s2
  %result = add i32 %s3, %i
; When registers exceed R7, may need e_* instead of se_*
  ret i32 %result
}

