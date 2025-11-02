; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -Oz < %s | FileCheck %s
; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -O2 < %s | FileCheck %s --check-prefix=NOOPT

; Test 32-bit E-form logical immediate instructions.
; Tests E_ORI, E_ORIS, E_ANDI, E_ANDIS, E_XORI, E_XORIS.
; These instructions support 16-bit immediates with optional shift.
; Reference: VLEPEM Table B-3, VLEPIM Section 4.3.3

target datalayout = "E-p:32:32:32-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v128:128:128-n32"
target triple = "powerpc-none-eabivle"

; Test E_ORI (OR immediate, lower 16 bits)
define i32 @test_e_ori(i32 %a) optsize minsize {
entry:
; CHECK-LABEL: @test_e_ori
; CHECK: e_ori {{r[0-9]+}}, {{r[0-9]+}}, 100
; OR with immediate should use E_ORI
  %result = or i32 %a, 100
  ret i32 %result
}

; Test E_ORIS (OR immediate shifted, upper 16 bits)
define i32 @test_e_oris(i32 %a) optsize minsize {
entry:
; CHECK-LABEL: @test_e_oris
; CHECK: e_oris {{r[0-9]+}}, {{r[0-9]+}}, 100
; OR with shifted immediate should use E_ORIS
  %result = or i32 %a, 6553600
  ret i32 %result
}

; Test E_ANDI (AND immediate, lower 16 bits)
define i32 @test_e_andi(i32 %a) optsize minsize {
entry:
; CHECK-LABEL: @test_e_andi
; CHECK: e_andi {{r[0-9]+}}, {{r[0-9]+}}, 255
; AND with immediate should use E_ANDI
  %result = and i32 %a, 255
  ret i32 %result
}

; Test E_ANDIS (AND immediate shifted, upper 16 bits)
define i32 @test_e_andis(i32 %a) optsize minsize {
entry:
; CHECK-LABEL: @test_e_andis
; CHECK: e_andis {{r[0-9]+}}, {{r[0-9]+}}, 100
; AND with shifted immediate should use E_ANDIS
  %result = and i32 %a, 6553600
  ret i32 %result
}

; Test E_XORI (XOR immediate, lower 16 bits)
define i32 @test_e_xori(i32 %a) optsize minsize {
entry:
; CHECK-LABEL: @test_e_xori
; CHECK: e_xori {{r[0-9]+}}, {{r[0-9]+}}, 50
; XOR with immediate should use E_XORI
  %result = xor i32 %a, 50
  ret i32 %result
}

; Test E_XORIS (XOR immediate shifted, upper 16 bits)
define i32 @test_e_xoris(i32 %a) optsize minsize {
entry:
; CHECK-LABEL: @test_e_xoris
; CHECK: e_xoris {{r[0-9]+}}, {{r[0-9]+}}, 50
; XOR with shifted immediate should use E_XORIS
  %result = xor i32 %a, 3276800
  ret i32 %result
}

attributes #0 = { minsize optsize "target-cpu"="e200z4" }

