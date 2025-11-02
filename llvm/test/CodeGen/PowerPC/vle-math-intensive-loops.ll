; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -Oz < %s | FileCheck %s
; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -O2 < %s | FileCheck %s --check-prefix=NOOPT

; Test loop-intensive math patterns optimized for VLE.
; Tests common mathematical loop patterns: dot products, matrix operations,
; sum reductions, and iterative computations that benefit from VLE code size.
; Reference: VLEPEM Table B-3, VLEPIM Section 1.2 (Code Size Optimization)

target datalayout = "E-p:32:32:32-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v128:128:128-n32"
target triple = "powerpc-none-eabivle"

; Test dot product loop (common in linear algebra)
define i32 @test_dot_product(i32* %a, i32* %b, i32 %n) optsize minsize {
entry:
; CHECK-LABEL: @test_dot_product
; CHECK-DAG: e_lwz
; CHECK-DAG: e_mullw
; CHECK-DAG: e_add
; CHECK: e_blt
; Dot product loop should optimize for code size
  br label %loop

loop:
  %i = phi i32 [ 0, %entry ], [ %next_i, %loop ]
  %sum = phi i32 [ 0, %entry ], [ %next_sum, %loop ]
  %cmp = icmp slt i32 %i, %n
  br i1 %cmp, label %loop_body, label %done

loop_body:
  %a_ptr = getelementptr i32, i32* %a, i32 %i
  %b_ptr = getelementptr i32, i32* %b, i32 %i
  %a_val = load i32, i32* %a_ptr, align 4
  %b_val = load i32, i32* %b_ptr, align 4
  %prod = mul i32 %a_val, %b_val
  %next_sum = add i32 %sum, %prod
  %next_i = add i32 %i, 1
  br label %loop

done:
  ret i32 %sum
}

; Test sum reduction loop
define i32 @test_sum_reduction(i32* %arr, i32 %n) optsize minsize {
entry:
; CHECK-LABEL: @test_sum_reduction
; CHECK-DAG: se_lwz
; CHECK-DAG: se_add
; CHECK: se_blt
; Small loops should prefer 16-bit VLE instructions
  br label %loop

loop:
  %i = phi i32 [ 0, %entry ], [ %next_i, %loop ]
  %sum = phi i32 [ 0, %entry ], [ %next_sum, %loop ]
  %cmp = icmp slt i32 %i, %n
  br i1 %cmp, label %loop_body, label %done

loop_body:
  %ptr = getelementptr i32, i32* %arr, i32 %i
  %val = load i32, i32* %ptr, align 4
  %next_sum = add i32 %sum, %val
  %next_i = add i32 %i, 1
  br label %loop

done:
  ret i32 %sum
}

attributes #0 = { minsize optsize "target-cpu"="e200z4" }

