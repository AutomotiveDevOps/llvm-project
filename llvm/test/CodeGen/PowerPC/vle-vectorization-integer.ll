; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -Oz < %s | FileCheck %s
; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -O2 < %s | FileCheck %s --check-prefix=NOOPT

; Test integer vectorization patterns optimized for VLE.
; Tests loop vectorization opportunities for integer arrays: element-wise operations,
; reductions, and transformations that can benefit from optimized instruction sequences.
; Note: VLE e200 cores do not have SIMD units, but loop optimizations still apply.
; Reference: VLEPEM Table B-3, VLEPIM Section 1.2 (Code Size Optimization)

target datalayout = "E-p:32:32:32-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v128:128:128-n32"
target triple = "powerpc-none-eabivle"

; Test element-wise addition (potential for loop unrolling/software pipelining)
define void @test_vector_add(i32* %a, i32* %b, i32* %c, i32 %n) optsize minsize {
entry:
; CHECK-LABEL: @test_vector_add
; CHECK-DAG: e_lwz
; CHECK-DAG: e_add
; CHECK-DAG: e_stw
; CHECK: e_blt
; Element-wise addition should optimize for code size
  br label %loop

loop:
  %i = phi i32 [ 0, %entry ], [ %next_i, %loop ]
  %cmp = icmp slt i32 %i, %n
  br i1 %cmp, label %loop_body, label %done

loop_body:
  %a_ptr = getelementptr i32, i32* %a, i32 %i
  %b_ptr = getelementptr i32, i32* %b, i32 %i
  %c_ptr = getelementptr i32, i32* %c, i32 %i
  %a_val = load i32, i32* %a_ptr, align 4
  %b_val = load i32, i32* %b_ptr, align 4
  %sum = add i32 %a_val, %b_val
  store i32 %sum, i32* %c_ptr, align 4
  %next_i = add i32 %i, 1
  br label %loop

done:
  ret void
}

; Test element-wise multiply
define void @test_vector_mul(i32* %a, i32* %b, i32* %c, i32 %n) optsize minsize {
entry:
; CHECK-LABEL: @test_vector_mul
; CHECK-DAG: e_lwz
; CHECK-DAG: e_mullw
; CHECK-DAG: e_stw
; Element-wise multiply should use E_MULLW
  br label %loop

loop:
  %i = phi i32 [ 0, %entry ], [ %next_i, %loop ]
  %cmp = icmp slt i32 %i, %n
  br i1 %cmp, label %loop_body, label %done

loop_body:
  %a_ptr = getelementptr i32, i32* %a, i32 %i
  %b_ptr = getelementptr i32, i32* %b, i32 %i
  %c_ptr = getelementptr i32, i32* %c, i32 %i
  %a_val = load i32, i32* %a_ptr, align 4
  %b_val = load i32, i32* %b_ptr, align 4
  %prod = mul i32 %a_val, %b_val
  store i32 %prod, i32* %c_ptr, align 4
  %next_i = add i32 %i, 1
  br label %loop

done:
  ret void
}

; Test max reduction
define i32 @test_max_reduction(i32* %arr, i32 %n) optsize minsize {
entry:
; CHECK-LABEL: @test_max_reduction
; CHECK-DAG: e_lwz
; CHECK-DAG: e_cmpw
; CHECK-DAG: e_bc
; Max reduction should optimize comparisons
  %first = load i32, i32* %arr, align 4
  br label %loop

loop:
  %i = phi i32 [ 1, %entry ], [ %next_i, %loop ]
  %max = phi i32 [ %first, %entry ], [ %next_max, %loop ]
  %cmp = icmp slt i32 %i, %n
  br i1 %cmp, label %loop_body, label %done

loop_body:
  %ptr = getelementptr i32, i32* %arr, i32 %i
  %val = load i32, i32* %ptr, align 4
  %cmp_max = icmp sgt i32 %val, %max
  %next_max = select i1 %cmp_max, i32 %val, i32 %max
  %next_i = add i32 %i, 1
  br label %loop

done:
  ret i32 %max
}

attributes #0 = { minsize optsize "target-cpu"="e200z4" }

