; RUN: llc -mtriple=powerpc-unknown-linux-gnu -mcpu=e200z6 -mattr=+booke < %s | FileCheck %s --check-prefix=CHECK-BOOKE
; RUN: llc -mtriple=powerpc-unknown-linux-gnu -mcpu=e200z4 -mattr=+booke < %s | FileCheck %s --check-prefix=CHECK-BOOKE
; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z6 -mvle -mattr=+booke < %s | FileCheck %s --check-prefix=CHECK-VLE

; ISO 26262 Edge Case 003: RFI vs BLR Instruction Misuse in Interrupt Handlers
; Test that interrupt handlers use RFI (or e_rfi for VLE) instead of BLR
; Reference: PPCFrameLowering.cpp:1662-1676

target datalayout = "E-p:32:32:32-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:32:64-f32:32:32-f64:32:64-v128:128:128-a0:0:64-f128:64:128-n32"
target triple = "powerpc-unknown-linux-gnu"

; Test 1: Standard PowerPC interrupt handler must use RFI (not BLR)
define void @test_standard_interrupt_rfi() #0 {
; CHECK-BOOKE-LABEL: test_standard_interrupt_rfi:
; CHECK-BOOKE:       # %bb.0:
; CHECK-BOOKE:        mflr 0
; CHECK-BOOKE:        mfcr
; CHECK-BOOKE-NOT:    blr
; CHECK-BOOKE:        rfi
  ret void
}

; Test 2: VLE mode interrupt handler should use e_rfi (currently uses RFI)
; TODO: When e_rfi is implemented, this should check for e_rfi
define void @test_vle_interrupt_rfi() #0 {
; CHECK-VLE-LABEL: test_vle_interrupt_rfi:
; CHECK-VLE:       # %bb.0:
; CHECK-VLE:        e_mflr
; CHECK-VLE:        e_mfcr
; CHECK-VLE-NOT:    e_blr
; CHECK-VLE:        rfi
; TODO-VLE: Should use e_rfi when implemented
  ret void
}

; Test 3: Non-interrupt function should use BLR (not RFI)
define void @test_normal_function_blr() {
; CHECK-BOOKE-LABEL: test_normal_function_blr:
; CHECK-BOOKE:       # %bb.0:
; CHECK-BOOKE:        blr
; CHECK-BOOKE-NOT:    rfi
  ret void
}

; Test 4: Verify RFI is not generated for non-interrupt handlers
define void @test_no_rfi_in_normal() {
; CHECK-BOOKE-LABEL: test_no_rfi_in_normal:
; CHECK-BOOKE-NOT:   rfi
  ret void
}

; Test 5: Critical interrupt should also use RFI
define void @test_critical_interrupt_rfi() #1 {
; CHECK-BOOKE-LABEL: test_critical_interrupt_rfi:
; CHECK-BOOKE:       # %bb.0:
; CHECK-BOOKE:        mflr 0
; CHECK-BOOKE:        mfcr
; CHECK-BOOKE-NOT:    blr
; CHECK-BOOKE:        rfi
  ret void
}

; Test 6: External interrupt should also use RFI
define void @test_external_interrupt_rfi() #2 {
; CHECK-BOOKE-LABEL: test_external_interrupt_rfi:
; CHECK-BOOKE:       # %bb.0:
; CHECK-BOOKE:        mflr 0
; CHECK-BOOKE:        mfcr
; CHECK-BOOKE-NOT:    blr
; CHECK-BOOKE:        rfi
  ret void
}

attributes #0 = { nounwind "interrupt" }
attributes #1 = { nounwind "interrupt"="critical" }
attributes #2 = { nounwind "interrupt"="external" }

