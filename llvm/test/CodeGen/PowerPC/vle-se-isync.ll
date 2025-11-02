; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -Oz < %s | FileCheck %s
; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -O2 < %s | FileCheck %s --check-prefix=NOOPT

; Test SE_ISYNC (16-bit Instruction Synchronize) instruction selection.
; SE_ISYNC ensures instruction synchronization: ensures previous instructions complete.
; Format: se_isync. Used for memory barrier and code modification scenarios.
; Reference: VLEPEM Table B-3, VLEPIM Section 4.6.3

target datalayout = "E-p:32:32:32-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v128:128:128-n32"
target triple = "powerpc-none-eabivle"

; Test SE_ISYNC instruction synchronize
define void @test_se_isync() optsize minsize {
entry:
; CHECK-LABEL: @test_se_isync
; CHECK: se_isync
; Instruction synchronize should use SE_ISYNC
  fence acquire
  ret void
}

attributes #0 = { minsize optsize "target-cpu"="e200z4" }

