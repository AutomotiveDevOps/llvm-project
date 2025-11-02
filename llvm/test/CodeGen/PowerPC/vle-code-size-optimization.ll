; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -Oz < %s | FileCheck %s
; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -O2 < %s | FileCheck %s --check-prefix=NOOPT

; Test code size optimization patterns with VLE.
; Verifies that -Oz optimization level selects 16-bit VLE instructions (se_*)
; when register constraints (R0-R7) and immediate constraints are met.
; Tests preference for smaller instruction encodings for code size reduction.
; Reference: VLEPEM Table B-3, VLEPIM Section 1.2 (Code Size Optimization)

target datalayout = "E-p:32:32:32-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v128:128:128-n32"
target triple = "powerpc-none-eabivle"

; Test that -Oz prefers SE_ADDI over E_ADDI for small immediates
define i32 @test_code_size_addi(i32 %a) optsize minsize {
entry:
; CHECK-LABEL: @test_code_size_addi
; CHECK: se_addi {{r[0-7]}}, {{r[0-7]}}, 10
; With -Oz and small immediate, should use 16-bit SE_ADDI
  %result = add i32 %a, 10
  ret i32 %result
}

; Test that -Oz prefers SE_LWZ for small displacements
define i32 @test_code_size_load(i32* %ptr) optsize minsize {
entry:
; CHECK-LABEL: @test_code_size_load
; CHECK: se_lwz {{r[0-7]}}, 0, {{r[0-7]}}
; With -Oz and zero displacement, should use 16-bit SE_LWZ
  %val = load i32, i32* %ptr, align 4
  ret i32 %val
}

; Test that -O2 may use 32-bit instructions for flexibility
define i32 @test_performance_mode(i32 %a) {
entry:
; NOOPT-LABEL: @test_performance_mode
; NOOPT-NOT: se_addi
; With -O2, may use 32-bit instructions for performance
  %result = add i32 %a, 10
  ret i32 %result
}

attributes #0 = { minsize optsize "target-cpu"="e200z4" }

