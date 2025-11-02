; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -Oz < %s | FileCheck %s
; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -O2 < %s | FileCheck %s --check-prefix=NOOPT

; Test E_ADD (32-bit VLE Add) instruction selection.
; E_ADD performs addition: rD = rA + rB.
; Format: e_add rD, rA, rB. Supports all registers (not limited to R0-R7).
; Reference: VLEPEM Table B-3, VLEPIM Section 4.3.1

target datalayout = "E-p:32:32:32-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v128:128:128-n32"
target triple = "powerpc-none-eabivle"

; Test E_ADD with registers outside R0-R7 range
define i32 @test_e_add_extended(i32 %a, i32 %b) optsize minsize {
entry:
; CHECK-LABEL: @test_e_add_extended
; CHECK: e_add {{r[0-9]+}}, {{r[0-9]+}}, {{r[0-9]+}}
; With registers outside R0-R7, should use E_ADD (32-bit)
  %result = add i32 %a, %b
  ret i32 %result
}

<<<<<<< HEAD
=======
attributes #0 = { minsize optsize "target-cpu"="e200z4" }

>>>>>>> master
