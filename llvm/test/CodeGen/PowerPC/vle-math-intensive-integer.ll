; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -Oz < %s | FileCheck %s
; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -O2 < %s | FileCheck %s --check-prefix=NOOPT

; Test integer math-intensive operations optimized for VLE.
; Tests patterns common in mathematical computations: multiply-accumulate,
; division/modulo, bit manipulation, and extended precision arithmetic.
; Optimizes for code size while maintaining performance for math applications.
; Reference: VLEPEM Table B-3, VLEPIM Section 4.3 (Arithmetic Instructions)

target datalayout = "E-p:32:32:32-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v128:128:128-n32"
target triple = "powerpc-none-eabivle"

; Test multiply-accumulate pattern (common in DSP and signal processing)
define i32 @test_mul_acc(i32 %a, i32 %b, i32 %c) optsize minsize {
entry:
; CHECK-LABEL: @test_mul_acc
; CHECK-DAG: e_mullw
; CHECK-DAG: e_add
; Multiply-accumulate should use E_MULLW + E_ADD
  %mul = mul i32 %a, %b
  %acc = add i32 %mul, %c
  ret i32 %acc
}

; Test division with remainder (common in cryptography and hashing)
define { i32, i32 } @test_div_rem(i32 %a, i32 %b) optsize minsize {
entry:
; CHECK-LABEL: @test_div_rem
; CHECK: e_divw
; CHECK: e_mullw
; CHECK: e_subf
; Division and remainder should use E_DIVW and related operations
  %quot = sdiv i32 %a, %b
  %mul = mul i32 %quot, %b
  %rem = sub i32 %a, %mul
  %result = insertvalue { i32, i32 } undef, i32 %quot, 0
  %result2 = insertvalue { i32, i32 } %result, i32 %rem, 1
  ret { i32, i32 } %result2
}

; Test bit manipulation patterns (common in encoding/decoding)
define i32 @test_bit_manip(i32 %a, i32 %mask) optsize minsize {
entry:
; CHECK-LABEL: @test_bit_manip
; CHECK-DAG: e_and
; CHECK-DAG: e_or
; CHECK-DAG: e_xor
; Bit manipulation should use efficient logical operations
  %and = and i32 %a, %mask
  %or = or i32 %a, %mask
  %xor = xor i32 %and, %or
  ret i32 %xor
}

; Test extended precision addition (64-bit on 32-bit processor)
define i64 @test_extended_add(i64 %a, i64 %b) optsize minsize {
entry:
; CHECK-LABEL: @test_extended_add
; CHECK-DAG: e_addc
; CHECK-DAG: e_adde
; Extended precision should use E_ADDC/E_ADDE sequence
  %sum = add i64 %a, %b
  ret i64 %sum
}

attributes #0 = { minsize optsize "target-cpu"="e200z4" }

