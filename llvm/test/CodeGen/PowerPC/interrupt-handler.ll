; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -mattr=+vle < %s | FileCheck %s --check-prefix=CHECK-VLE
; RUN: llc -mtriple=powerpc-none-unknown -mcpu=e500 < %s | FileCheck %s --check-prefix=CHECK-STD

; Test basic interrupt handler - should save LR, CR, and restore them before e_rfi/rfi
define void @test_interrupt() #0 {
; CHECK-VLE-LABEL: test_interrupt:
; CHECK-VLE: mflr r0
; CHECK-VLE: stw r0,
; CHECK-VLE: mfcr r0
; CHECK-VLE: stw r0,
; CHECK-VLE: lwz r0,
; CHECK-VLE: mtcr r0
; CHECK-VLE: lwz r0,
; CHECK-VLE: mtlr r0
; CHECK-VLE: e_rfi
; CHECK-STD-LABEL: test_interrupt:
; CHECK-STD: mflr r0
; CHECK-STD: stw r0,
; CHECK-STD: mfcr r0
; CHECK-STD: stw r0,
; CHECK-STD: lwz r0,
; CHECK-STD: mtcr r0
; CHECK-STD: lwz r0,
; CHECK-STD: mtlr r0
; CHECK-STD: rfi
  ret void
}

; Test interrupt handler with calls - should save all caller-saved registers
define void @test_interrupt_with_call() #0 {
; CHECK-VLE-LABEL: test_interrupt_with_call:
; CHECK-VLE: bl {{.*}}some_function
; CHECK-VLE: e_rfi
  call void @some_function()
  ret void
}

declare void @some_function()

; Test critical interrupt handler
define void @test_critical_interrupt() #1 {
; CHECK-VLE-LABEL: test_critical_interrupt:
; CHECK-VLE: e_rfi
  ret void
}

; Test external interrupt handler
define void @test_external_interrupt() #2 {
; CHECK-VLE-LABEL: test_external_interrupt:
; CHECK-VLE: e_rfi
  ret void
}

attributes #0 = { "interrupt"="standard" }
attributes #1 = { "interrupt"="critical" }
attributes #2 = { "interrupt"="external" }

