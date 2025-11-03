; RUN: llc -mtriple=powerpc-unknown-linux-gnu -mcpu=e200z4 < %s | FileCheck %s
; RUN: llc -mtriple=powerpc-unknown-linux-gnu -mcpu=e200z6 < %s | FileCheck %s

; Test FPU Register Handling in Interrupt Handlers
; Test that interrupt handlers properly save/restore Floating Point Registers (FPRs)
; when FPU operations are performed in interrupt handlers.
; Code location: PPCFrameLowering.cpp:1843-1913

target datalayout = "E-p:32:32:32-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:32:64-f32:32:32-f64:32:64-v128:128:128-a0:0:64-f128:64:128-n32"
target triple = "powerpc-unknown-linux-gnu"

; Test 1: Interrupt handler with FPU addition
; FPRs should be saved/restored if FPU is used
define void @test_interrupt_fpu_add() #0 {
; CHECK-LABEL: test_interrupt_fpu_add:
; CHECK:       # %bb.0:
; CHECK:        mflr 0
; CHECK:        mfcr
; CHECK:        stfd
; CHECK:        stfd
; Verify FPRs are saved when FPU operations are present
entry:
  %val1 = fadd float 1.0, 2.0
  %val2 = fadd float %val1, 3.0
  store float %val2, float* undef
  ret void
}

; Test 2: Interrupt handler with FPU multiply
define void @test_interrupt_fpu_multiply() #0 {
; CHECK-LABEL: test_interrupt_fpu_multiply:
; CHECK:       # %bb.0:
; CHECK:        mflr 0
; CHECK:        mfcr
; CHECK:        stfd
; CHECK:        e_fmuls
; Verify FPRs used in multiply are saved
entry:
  %prod = fmul float 2.0, 3.0
  store float %prod, float* undef
  ret void
}

; Test 3: Interrupt handler with multiple FPU operations
; All FPRs used should be saved
define void @test_interrupt_fpu_multiple() #0 {
; CHECK-LABEL: test_interrupt_fpu_multiple:
; CHECK:       # %bb.0:
; CHECK:        mflr 0
; CHECK:        mfcr
; CHECK-DAG:    stfd
; CHECK-DAG:    stfd
; CHECK-DAG:    stfd
; Multiple FPU operations should save all used FPRs
entry:
  %v1 = fadd float 1.0, 2.0
  %v2 = fadd float 3.0, 4.0
  %v3 = fmul float %v1, %v2
  store float %v3, float* undef
  ret void
}

; Test 4: Interrupt handler with FPU load/store
define void @test_interrupt_fpu_load_store(float* %ptr) #0 {
; CHECK-LABEL: test_interrupt_fpu_load_store:
; CHECK:       # %bb.0:
; CHECK:        mflr 0
; CHECK:        mfcr
; CHECK:        e_lfs
; CHECK:        stfd
; CHECK:        e_stfs
; FPU load/store operations should save FPRs
entry:
  %val = load float, float* %ptr
  %result = fadd float %val, 1.0
  store float %result, float* %ptr
  ret void
}

attributes #0 = { nounwind "interrupt" }

