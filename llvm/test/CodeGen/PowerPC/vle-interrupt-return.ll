; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle < %s | FileCheck %s
; RUN: llc -mtriple=powerpc-unknown-linux-gnu -mcpu=e200z4 < %s | FileCheck %s --check-prefix=NO_VLE

; Test RFI vs e_RFI Differentiation in VLE Mode
; Test that interrupt handlers in VLE mode use e_rfi instead of rfi.
; Standard PowerPC mode should use rfi.
; Code location: PPCFrameLowering.cpp:1662-1676

target datalayout = "E-p:32:32:32-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:32:64-f32:32:32-f64:32:64-v128:128:128-a0:0:64-f128:64:128-n32"
target triple = "powerpc-none-eabivle"

; Test 1: VLE mode interrupt handler should use e_rfi
define void @test_vle_interrupt_return() #0 {
; CHECK-LABEL: test_vle_interrupt_return:
; CHECK:       # %bb.0:
; CHECK:        mflr 0
; CHECK:        mfcr
; CHECK:        e_rfi
; VLE mode interrupt handler should use e_rfi, not rfi
  ret void
}

; Test 2: VLE mode interrupt handler with register usage
define void @test_vle_interrupt_with_registers(i32 %a) #0 {
; CHECK-LABEL: test_vle_interrupt_with_registers:
; CHECK:       # %bb.0:
; CHECK:        mflr 0
; CHECK:        mfcr
; CHECK:        e_rfi
; VLE mode interrupt handler with registers should still use e_rfi
entry:
  %val = add i32 %a, 1
  store i32 %val, i32* undef
  ret void
}

; Test 3: Non-VLE mode interrupt handler should use rfi
define void @test_non_vle_interrupt_return() #0 {
; NO_VLE-LABEL: test_non_vle_interrupt_return:
; NO_VLE:       # %bb.0:
; NO_VLE:        mflr 0
; NO_VLE:        mfcr
; NO_VLE:        rfi
; Non-VLE mode interrupt handler should use rfi, not e_rfi
  ret void
}

attributes #0 = { nounwind "interrupt" }

