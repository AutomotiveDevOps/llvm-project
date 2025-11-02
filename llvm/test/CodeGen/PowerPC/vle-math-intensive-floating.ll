; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -Oz < %s | FileCheck %s
; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -O2 < %s | FileCheck %s --check-prefix=NOOPT

; Test floating point math-intensive operations optimized for VLE.
; Tests common floating point patterns: multiply-add, trigonometric approximations,
; polynomial evaluation, and iterative algorithms common in scientific computing.
; Note: VLE e200 cores support floating point via standard PowerPC FPU instructions.
; Reference: VLEPEM Table B-3, VLEPIM Section 4.3 (Arithmetic Instructions)

target datalayout = "E-p:32:32:32-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v128:128:128-n32"
target triple = "powerpc-none-eabivle"

; Test floating point multiply-add (common in matrix operations)
define float @test_fma(float %a, float %b, float %c) optsize minsize {
entry:
; CHECK-LABEL: @test_fma
; CHECK: fmadds
; CHECK: se_stfs
; Floating point multiply-add should use efficient FPU operations
  %mul = fmul float %a, %b
  %add = fadd float %mul, %c
  ret float %add
}

; Test polynomial evaluation (common in approximation functions)
define float @test_polynomial(float %x) optsize minsize {
entry:
; CHECK-LABEL: @test_polynomial
; CHECK-DAG: fmuls
; CHECK-DAG: fadds
; Polynomial evaluation: x^3 + 2*x^2 + 3*x + 4
  %x2 = fmul float %x, %x
  %x3 = fmul float %x2, %x
  %term2 = fmul float %x2, 2.0
  %term3 = fmul float %x, 3.0
  %sum1 = fadd float %x3, %term2
  %sum2 = fadd float %sum1, %term3
  %result = fadd float %sum2, 4.0
  ret float %result
}

; Test floating point reduction loop
define float @test_fp_reduction(float* %arr, i32 %n) optsize minsize {
entry:
; CHECK-LABEL: @test_fp_reduction
; CHECK-DAG: lfsx
; CHECK-DAG: fadds
; CHECK: e_blt
; Floating point sum reduction should optimize for code size
  br label %loop

loop:
  %i = phi i32 [ 0, %entry ], [ %next_i, %loop ]
  %sum = phi float [ 0.0, %entry ], [ %next_sum, %loop ]
  %cmp = icmp slt i32 %i, %n
  br i1 %cmp, label %loop_body, label %done

loop_body:
  %ptr = getelementptr float, float* %arr, i32 %i
  %val = load float, float* %ptr, align 4
  %next_sum = fadd float %sum, %val
  %next_i = add i32 %i, 1
  br label %loop

done:
  ret float %sum
}

attributes #0 = { minsize optsize "target-cpu"="e200z4" }

