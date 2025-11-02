; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -Oz < %s | FileCheck %s
; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -O2 < %s | FileCheck %s --check-prefix=NOOPT

; Test E_SUBFC (32-bit Subtract From with Carry) instruction selection.
; E_SUBFC performs subtract from with carry: rD = rB - rA + CA - 1.
; Format: e_subfc rD, rA, rB. This is a 32-bit VLE instruction.
; Reference: VLEPEM Table B-3, VLEPIM Section 4.3.3

target datalayout = "E-p:32:32:32-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v128:128:128-n32"
target triple = "powerpc-none-eabivle"

; Test E_SUBFC with carry
define i32 @test_e_subfc(i32 %a, i32 %b) optsize minsize {
entry:
; CHECK-LABEL: @test_e_subfc
; CHECK: e_subfc {{r[0-9]+}}, {{r[0-9]+}}, {{r[0-9]+}}
; Subtract from with carry should use E_SUBFC
  %result = sub i32 %b, %a
  ret i32 %result
}

attributes #0 = { minsize optsize "target-cpu"="e200z4" }

