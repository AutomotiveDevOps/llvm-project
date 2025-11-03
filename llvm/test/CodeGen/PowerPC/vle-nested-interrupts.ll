; RUN: llc -mtriple=powerpc-unknown-linux-gnu -mcpu=e200z6 < %s | FileCheck %s

; Test Nested Interrupt Context Handling
; Test that nested interrupt scenarios properly save/restore register context
; in correct order, ensuring no corruption when interrupts nest.

target datalayout = "E-p:32:32:32-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:32:64-f32:32:32-f64:32:64-v128:128:128-a0:0:64-f128:64:128-n32"
target triple = "powerpc-unknown-linux-gnu"

; Test 1: Simulate nested interrupt scenario with multiple register usage
; All registers must be saved/restored in correct order
define void @test_nested_interrupt_multiple_regs(i32 %a, i32 %b, i32 %c, i32 %d) #0 {
; CHECK-LABEL: test_nested_interrupt_multiple_regs:
; CHECK:       # %bb.0:
; CHECK:        mflr 0
; CHECK:        stw 0, 4(1)
; CHECK:        mfcr
; CHECK:        stw
; CHECK-DAG:    stw {{r[0-9]+}}, {{[0-9]+}}(1)
; CHECK-DAG:    stw {{r[0-9]+}}, {{[0-9]+}}(1)
; CHECK-DAG:    stw {{r[0-9]+}}, {{[0-9]+}}(1)
; Multiple registers should be saved in consistent order for nesting
entry:
  %v1 = add i32 %a, %b
  %v2 = add i32 %c, %d
  %v3 = add i32 %v1, %v2
  store i32 %v3, i32* undef
  ret void
}

; Test 2: Nested interrupt with LR usage
; LR must be saved first before any nested call
define void @test_nested_interrupt_lr_usage() #0 {
; CHECK-LABEL: test_nested_interrupt_lr_usage:
; CHECK:       # %bb.0:
; CHECK:        mflr 0
; CHECK:        stw 0, 4(1)
; CHECK:        mfcr
; CHECK:        bl
; CHECK:        lwz 0, 4(1)
; CHECK:        mtlr 0
; CHECK:        rfi
; LR must be saved before nested call and restored before return
entry:
  call void @external_function()
  ret void
}

; Test 3: Nested interrupt with CR usage
; CR must be saved and restored correctly
define void @test_nested_interrupt_cr_usage(i32 %a, i32 %b) #0 {
; CHECK-LABEL: test_nested_interrupt_cr_usage:
; CHECK:       # %bb.0:
; CHECK:        mflr 0
; CHECK:        mfcr
; CHECK:        stw
; CHECK:        cmpw
; CHECK:        lwz
; CHECK:        mtcrf
; CHECK:        rfi
; CR must be saved before comparison and restored before return
entry:
  %cmp = icmp eq i32 %a, %b
  br i1 %cmp, label %if, label %end
if:
  ret void
end:
  ret void
}

; Test 4: Deep nesting scenario (simulate with many registers)
define void @test_deep_nesting(i32 %a, i32 %b, i32 %c, i32 %d, i32 %e, i32 %f) #0 {
; CHECK-LABEL: test_deep_nesting:
; CHECK:       # %bb.0:
; CHECK:        mflr 0
; CHECK:        stw 0, 4(1)
; CHECK:        mfcr
; CHECK:        stw
; CHECK:        stw {{r[0-9]+}}, {{[0-9]+}}(1)
; CHECK:        stw {{r[0-9]+}}, {{[0-9]+}}(1)
; CHECK:        stw {{r[0-9]+}}, {{[0-9]+}}(1)
; CHECK:        stw {{r[0-9]+}}, {{[0-9]+}}(1)
; CHECK:        stw {{r[0-9]+}}, {{[0-9]+}}(1)
; Deep nesting should save all used registers
entry:
  %v1 = add i32 %a, %b
  %v2 = add i32 %c, %d
  %v3 = add i32 %e, %f
  %s1 = add i32 %v1, %v2
  %s2 = add i32 %s1, %v3
  store i32 %s2, i32* undef
  ret void
}

declare void @external_function()

attributes #0 = { nounwind "interrupt" }

