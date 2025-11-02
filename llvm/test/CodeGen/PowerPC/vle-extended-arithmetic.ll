; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -Oz < %s | FileCheck %s
; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -O2 < %s | FileCheck %s --check-prefix=NOOPT

; Test extended arithmetic operations (carry/borrow propagation).
; Tests E_ADDC, E_ADDE, E_SUBFC, E_SUBFE for multi-word arithmetic.
; These instructions are used for 64-bit and larger arithmetic on 32-bit processors.
; Reference: VLEPEM Table B-3, VLEPIM Section 4.3.2-4.3.3

target datalayout = "E-p:32:32:32-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v128:128:128-n32"
target triple = "powerpc-none-eabivle"

; Test extended add with carry propagation
; This pattern would use E_ADDC followed by E_ADDE for multi-word addition
define i64 @test_extended_add(i64 %a, i64 %b) optsize minsize {
entry:
; CHECK-LABEL: @test_extended_add
; CHECK-DAG: e_addc
; CHECK-DAG: e_adde
; Extended 64-bit addition should use E_ADDC/E_ADDE sequence
  %result = add i64 %a, %b
  ret i64 %result
}

; Test extended subtract with borrow propagation
; This pattern would use E_SUBFC followed by E_SUBFE for multi-word subtraction
define i64 @test_extended_sub(i64 %a, i64 %b) optsize minsize {
entry:
; CHECK-LABEL: @test_extended_sub
; CHECK-DAG: e_subfc
; CHECK-DAG: e_subfe
; Extended 64-bit subtraction should use E_SUBFC/E_SUBFE sequence
  %result = sub i64 %a, %b
  ret i64 %result
}

attributes #0 = { minsize optsize "target-cpu"="e200z4" }

