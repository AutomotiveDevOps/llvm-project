; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -Oz < %s | FileCheck %s

; Test E_ADDI (32-bit VLE Add Immediate) instruction selection.
; E_ADDI performs addition with immediate: rD = rA + imm.
; Format: e_addi rD, rA, SIMM where SIMM is 16-bit signed immediate.
; Supports all registers and larger immediates than SE_ADDI.
; Reference: VLEPEM Table B-3, VLEPIM Section 4.3.1

target datalayout = "E-p:32:32:32-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v128:128:128-n32"
target triple = "powerpc-none-eabivle"

; Test E_ADDI with large immediate (outside s6imm range)
define i32 @test_e_addi_large(i32 %a) optsize minsize {
entry:
; CHECK-LABEL: @test_e_addi_large
; CHECK: e_addi {{r[0-9]+}}, {{r[0-9]+}}, 1000
; Immediate 1000 (outside s6imm range) should use E_ADDI
  %result = add i32 %a, 1000
  ret i32 %result
}

