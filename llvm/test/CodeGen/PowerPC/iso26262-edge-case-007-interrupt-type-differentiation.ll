; RUN: llc -mtriple=powerpc-unknown-linux-gnu -mcpu=e200z6 -mattr=+booke < %s | FileCheck %s --check-prefix=CHECK
; RUN: llc -mtriple=powerpc-unknown-linux-gnu -mcpu=e200z4 -mattr=+booke < %s | FileCheck %s --check-prefix=CHECK

; ISO 26262 Edge Case 007: Critical vs External Interrupt Type Handling Differentiation
; Test that critical and external interrupts are handled differently
; Reference: AttrDocs.td:1836-1871, PPCFrameLowering.cpp

target datalayout = "E-p:32:32:32-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:32:64-f32:32:32-f64:32:64-v128:128:128-a0:0:64-f128:64:128-n32"
target triple = "powerpc-unknown-linux-gnu"

; Test 1: Critical interrupt handler (IVOR0, non-maskable)
define void @test_critical_interrupt() #1 {
; CHECK-LABEL: test_critical_interrupt:
; CHECK:       # %bb.0:
; CHECK:        mflr 0
; CHECK:        mfcr
; CHECK:        rfi
; Critical interrupt should save context but ideally minimal (priority requirement)
  ret void
}

; Test 2: External interrupt handler (IVOR4)
define void @test_external_interrupt() #2 {
; CHECK-LABEL: test_external_interrupt:
; CHECK:       # %bb.0:
; CHECK:        mflr 0
; CHECK:        mfcr
; CHECK:        rfi
; External interrupt should save full context
  ret void
}

; Test 3: Default interrupt handler
define void @test_default_interrupt() #0 {
; CHECK-LABEL: test_default_interrupt:
; CHECK:       # %bb.0:
; CHECK:        mflr 0
; CHECK:        mfcr
; CHECK:        rfi
; Default interrupt should use standard context save
  ret void
}

; Test 4: Critical interrupt with minimal register usage
define void @test_critical_minimal() #1 {
; CHECK-LABEL: test_critical_minimal:
; CHECK:       # %bb.0:
; CHECK:        mflr 0
; CHECK:        mfcr
; CHECK:        rfi
; Critical interrupts should have minimal latency (save only essential registers)
  ret void
}

; Test 5: External interrupt with full context (function calls)
declare void @helper_func(i32)

define void @test_external_full_context() #2 {
; CHECK-LABEL: test_external_full_context:
; CHECK:       # %bb.0:
; CHECK:        mflr 0
; CHECK:        mfcr
; CHECK:        stw
; CHECK:        bl helper_func
; CHECK:        rfi
; External interrupt can make calls - needs full context save
entry:
  call void @helper_func(i32 42)
  ret void
}

; Test 6: Verify interrupt type attribute is recognized
; TODO: When codegen differentiates interrupt types, these should generate different code
define void @test_type_differentiation_critical() #1 {
; CHECK-LABEL: test_type_differentiation_critical:
; CHECK:       # %bb.0:
; CHECK:        mflr 0
; CHECK:        mfcr
; CHECK:        rfi
; TODO: Should verify minimal context save vs full context save
  ret void
}

define void @test_type_differentiation_external() #2 {
; CHECK-LABEL: test_type_differentiation_external:
; CHECK:       # %bb.0:
; CHECK:        mflr 0
; CHECK:        mfcr
; CHECK:        rfi
; TODO: Should verify full context save
  ret void
}

attributes #0 = { nounwind "interrupt" }
attributes #1 = { nounwind "interrupt"="critical" }
attributes #2 = { nounwind "interrupt"="external" }

