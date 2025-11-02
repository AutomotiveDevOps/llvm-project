; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -Oz < %s | FileCheck %s
; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -O2 < %s | FileCheck %s --check-prefix=NOOPT

; Test E_SRAW (32-bit Shift Right Algebraic Word) instruction selection.
; E_SRAW performs arithmetic right shift by register: rD = rA >> rB[27:31] (arithmetic).
; Format: e_sraw rD, rA, rB. Supports all registers (not limited to R0-R7).
; Reference: VLEPEM Table B-3, VLEPIM Section 4.8.2

target datalayout = "E-p:32:32:32-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v128:128:128-n32"
target triple = "powerpc-none-eabivle"

; Test E_SRAW arithmetic shift right by register
define i32 @test_e_sraw(i32 %a, i32 %shift) optsize minsize {
entry:
; CHECK-LABEL: @test_e_sraw
; CHECK: e_sraw {{r[0-9]+}}, {{r[0-9]+}}, {{r[0-9]+}}
; Arithmetic shift right by register should use E_SRAW
  %result = ashr i32 %a, %shift
  ret i32 %result
}

attributes #0 = { minsize optsize "target-cpu"="e200z4" }

