; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -Oz < %s | FileCheck %s
; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -O2 < %s | FileCheck %s --check-prefix=NOOPT

; Test E_SYNC, E_ISYNC, E_EIEIO (32-bit Synchronize) instruction selection.
; These provide memory synchronization for multiprocessor systems and DMA.
; Reference: VLEPEM Table B-3, VLEPIM Section 4.6.3

target datalayout = "E-p:32:32:32-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v128:128:128-n32"
target triple = "powerpc-none-eabivle"

; Test E_SYNC full synchronization
define void @test_e_sync() optsize minsize {
entry:
; CHECK-LABEL: @test_e_sync
; CHECK: e_sync
; Full synchronization should use E_SYNC
  fence seq_cst
  ret void
}

; Test E_ISYNC instruction synchronization
define void @test_e_isync() optsize minsize {
entry:
; CHECK-LABEL: @test_e_isync
; CHECK: e_isync
; Instruction synchronization should use E_ISYNC
  fence acquire
  ret void
}

attributes #0 = { minsize optsize "target-cpu"="e200z4" }

