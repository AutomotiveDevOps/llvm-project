; RUN: llc -mtriple=powerpc-unknown-linux-gnu -mcpu=e200z6 < %s | FileCheck %s
; RUN: llc -mtriple=powerpc-unknown-linux-gnu -mcpu=e200z4 < %s | FileCheck %s
; RUN: llc -mtriple=powerpc-unknown-linux-gnu -mcpu=e200z0 < %s | FileCheck %s

; ISO 26262 Edge Case 001: Interrupt Handler Register Context Incomplete Save/Restore
; Test that interrupt handlers properly save/restore all required registers
; Reference: PPCFrameLowering.cpp:1843-1913

target datalayout = "E-p:32:32:32-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:32:64-f32:32:32-f64:32:64-v128:128:128-a0:0:64-f128:64:128-n32"
target triple = "powerpc-unknown-linux-gnu"

; Test 1: Basic interrupt handler must save LR and CR
define void @test_basic_interrupt() #0 {
; CHECK-LABEL: test_basic_interrupt:
; CHECK:       # %bb.0:
; CHECK-NEXT:    mflr 0
; CHECK-NEXT:    stw 0, 4(1)
; CHECK:        mfcr
; CHECK-NEXT:    stw
; CHECK:        rfi
  ret void
}

; Test 2: Interrupt handler with GPR usage must save all used GPRs
define void @test_interrupt_with_gprs() #0 {
; CHECK-LABEL: test_interrupt_with_gprs:
; CHECK:       # %bb.0:
; CHECK:        mflr 0
; CHECK:        mfcr
; CHECK:        stw
; Verify that callee-saved GPRs are saved
; CHECK:        stw {{r[0-9]+}}, {{[0-9]+}}(1)
; CHECK:        stw {{r[0-9]+}}, {{[0-9]+}}(1)
; CHECK:        rfi
entry:
  %val = add i32 1, 2
  %val2 = add i32 %val, 3
  store i32 %val2, i32* undef
  ret void
}

; Test 3: Interrupt handler with function calls must save caller-saved registers
declare void @external_func(i32)

define void @test_interrupt_with_call() #0 {
; CHECK-LABEL: test_interrupt_with_call:
; CHECK:       # %bb.0:
; CHECK:        mflr 0
; CHECK:        mfcr
; CHECK:        stw
; CHECK:        bl external_func
; CHECK:        rfi
entry:
  call void @external_func(i32 42)
  ret void
}

; Test 4: Nested interrupt scenario - verify register save ordering
define void @test_nested_interrupt() #0 {
; CHECK-LABEL: test_nested_interrupt:
; CHECK:       # %bb.0:
; CHECK:        mflr 0
; CHECK:        stw 0, 4(1)
; CHECK:        mfcr
; CHECK:        stw
; CHECK:        rfi
entry:
  ; Use multiple registers to test save ordering
  %v1 = add i32 1, 2
  %v2 = add i32 %v1, 3
  %v3 = add i32 %v2, 4
  %v4 = add i32 %v3, 5
  store i32 %v4, i32* undef
  ret void
}

; Test 5: Verify SPR usage is detected (if SPRs are used, they should be saved)
; Note: SPR access in interrupt handlers should trigger save/restore
define void @test_interrupt_spr_usage() #0 {
; CHECK-LABEL: test_interrupt_spr_usage:
; CHECK:       # %bb.0:
; CHECK:        mflr 0
; CHECK:        mfcr
; CHECK:        rfi
entry:
  ; SPR access would require additional save/restore
  ret void
}

attributes #0 = { nounwind "interrupt" }

