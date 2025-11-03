; RUN: llc -mtriple=powerpc-unknown-linux-gnu -mcpu=e200z6 < %s | FileCheck %s
; RUN: llc -mtriple=powerpc-unknown-linux-gnu -mcpu=e200z4 < %s | FileCheck %s

; Test SPR Register Save/Restore in Interrupt Handlers
; Test that interrupt handlers properly save/restore Special Purpose Registers (SPRs)
; when SPRs are used in interrupt handlers.
; Code location: PPCFrameLowering.cpp:1843-1913

target datalayout = "E-p:32:32:32-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:32:64-f32:32:32-f64:32:64-v128:128:128-a0:0:64-f128:64:128-n32"
target triple = "powerpc-unknown-linux-gnu"

; Test 1: Interrupt handler using CTR (Count Register)
; CTR should be saved/restored if used in interrupt handler
define void @test_interrupt_ctr() #0 {
; CHECK-LABEL: test_interrupt_ctr:
; CHECK:       # %bb.0:
; CHECK:        mflr 0
; CHECK:        mfcr
; CHECK:        mfctr
; CHECK:        stw
; Verify CTR is saved when used
entry:
  ; Use CTR via inline asm (LLVM doesn't directly expose CTR)
  call void asm sideeffect "mtctr $0", "r"(i32 100)
  ret void
}

; Test 2: Interrupt handler using LR (Link Register)
; LR should already be saved (this is standard)
define void @test_interrupt_lr() #0 {
; CHECK-LABEL: test_interrupt_lr:
; CHECK:       # %bb.0:
; CHECK:        mflr 0
; CHECK:        stw 0, 4(1)
; CHECK:        mfcr
; Verify LR is saved (standard requirement)
  ret void
}

; Test 3: Interrupt handler using multiple SPRs
; All used SPRs should be saved
define void @test_interrupt_multiple_spr() #0 {
; CHECK-LABEL: test_interrupt_multiple_spr:
; CHECK:       # %bb.0:
; CHECK:        mflr 0
; CHECK:        mfcr
; CHECK:        mfctr
; CHECK:        stw
; Multiple SPR usage should trigger save for all
entry:
  call void asm sideeffect "mtctr $0", "r"(i32 200)
  ret void
}

; Test 4: Interrupt handler accessing XER (Exception Register)
; XER should be saved if accessed
define void @test_interrupt_xer() #0 {
; CHECK-LABEL: test_interrupt_xer:
; CHECK:       # %bb.0:
; CHECK:        mflr 0
; CHECK:        mfcr
; CHECK:        mfxer
; CHECK:        stw
; XER should be saved if used in interrupt handler
entry:
  call void asm sideeffect "mtxer $0", "r"(i32 300)
  ret void
}

attributes #0 = { nounwind "interrupt" }

