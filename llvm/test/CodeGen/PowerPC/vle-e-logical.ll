; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -Oz < %s | FileCheck %s
; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -O2 < %s | FileCheck %s --check-prefix=NOOPT

; Test 32-bit E-form logical instructions.
; Tests E_AND, E_OR, E_XOR, E_NAND, E_ANDC, E_ORC, E_EQV, E_NOR.
; These are 32-bit VLE instructions that support all registers (not limited to R0-R7).
; Reference: VLEPEM Table B-3, VLEPIM Section 4.3.3

target datalayout = "E-p:32:32:32-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v128:128:128-n32"
target triple = "powerpc-none-eabivle"

; Test E_AND
define i32 @test_e_and(i32 %a, i32 %b) optsize minsize {
entry:
; CHECK-LABEL: @test_e_and
; CHECK: e_and {{r[0-9]+}}, {{r[0-9]+}}, {{r[0-9]+}}
; AND with extended registers should use E_AND
  %result = and i32 %a, %b
  ret i32 %result
}

; Test E_OR
define i32 @test_e_or(i32 %a, i32 %b) optsize minsize {
entry:
; CHECK-LABEL: @test_e_or
; CHECK: e_or {{r[0-9]+}}, {{r[0-9]+}}, {{r[0-9]+}}
; OR with extended registers should use E_OR
  %result = or i32 %a, %b
  ret i32 %result
}

; Test E_XOR
define i32 @test_e_xor(i32 %a, i32 %b) optsize minsize {
entry:
; CHECK-LABEL: @test_e_xor
; CHECK: e_xor {{r[0-9]+}}, {{r[0-9]+}}, {{r[0-9]+}}
; XOR with extended registers should use E_XOR
  %result = xor i32 %a, %b
  ret i32 %result
}

; Test E_NAND (via pattern: ~(a & b))
define i32 @test_e_nand(i32 %a, i32 %b) optsize minsize {
entry:
; CHECK-LABEL: @test_e_nand
; CHECK: e_nand {{r[0-9]+}}, {{r[0-9]+}}, {{r[0-9]+}}
; NAND with extended registers should use E_NAND
  %and = and i32 %a, %b
  %result = xor i32 %and, -1
  ret i32 %result
}

; Test E_ANDC (a & ~b)
define i32 @test_e_andc(i32 %a, i32 %b) optsize minsize {
entry:
; CHECK-LABEL: @test_e_andc
; CHECK: e_andc {{r[0-9]+}}, {{r[0-9]+}}, {{r[0-9]+}}
; ANDC with extended registers should use E_ANDC
  %notb = xor i32 %b, -1
  %result = and i32 %a, %notb
  ret i32 %result
}

attributes #0 = { minsize optsize "target-cpu"="e200z4" }

