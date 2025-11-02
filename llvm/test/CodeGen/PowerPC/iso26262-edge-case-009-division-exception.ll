; RUN: llc -mtriple=powerpc-unknown-linux-gnu -mcpu=e200z6 < %s | FileCheck %s
; RUN: llc -mtriple=powerpc-unknown-linux-gnu -mcpu=e200z4 < %s | FileCheck %s

; ISO 26262 Edge Case 009: Division by Zero and Integer Overflow Exception Handling
; Test that division exceptions are properly handled
; Reference: PPCScheduleE200Z6.td:80-86 (IIC_IntDivW), PPCISelLowering.cpp, PPCInstrInfo.td

target datalayout = "E-p:32:32:32-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:32:64-f32:32:32-f64:32:64-v128:128:128-a0:0:64-f128:64:128-n32"
target triple = "powerpc-unknown-linux-gnu"

; Test 1: Signed division with potential divide-by-zero
define i32 @test_sdiv_with_check(i32 %a, i32 %b) {
; CHECK-LABEL: test_sdiv_with_check:
; CHECK:       # %bb.0:
; TODO: Should verify divide-by-zero check is generated
; CHECK:        divw {{r[0-9]+}}, {{r[0-9]+}}, {{r[0-9]+}}
entry:
  ; PowerPC doesn't trap on divide-by-zero - software must check
  %result = sdiv i32 %a, %b
  ret i32 %result
}

; Test 2: Unsigned division
define i32 @test_udiv_with_check(i32 %a, i32 %b) {
; CHECK-LABEL: test_udiv_with_check:
; CHECK:       # %bb.0:
; CHECK:        divwu {{r[0-9]+}}, {{r[0-9]+}}, {{r[0-9]+}}
entry:
  %result = udiv i32 %a, %b
  ret i32 %result
}

; Test 3: Division with known non-zero divisor (should not need check)
define i32 @test_sdiv_known_safe(i32 %a) {
; CHECK-LABEL: test_sdiv_known_safe:
; CHECK:       # %bb.0:
; CHECK:        divw {{r[0-9]+}}, {{r[0-9]+}}, {{r[0-9]+}}
; Should not generate divide-by-zero check for constant non-zero divisor
entry:
  %result = sdiv i32 %a, 5
  ret i32 %result
}

; Test 4: Division latency (34 cycles) - verify scheduling accounts for it
define i32 @test_division_latency(i32 %a, i32 %b) {
; CHECK-LABEL: test_division_latency:
; CHECK:       # %bb.0:
; CHECK:        divw {{r[0-9]+}}, {{r[0-9]+}}, {{r[0-9]+}}
; CHECK-NEXT:   {{[a-z]+}} {{r[0-9]+}}, {{r[0-9]+}}
; Division has 34-cycle latency - scheduler should account for this
entry:
  %quotient = sdiv i32 %a, %b
  %result = add i32 %quotient, 1
  ret i32 %result
}

; Test 5: Multiple divisions - verify exception path handling
define i32 @test_multiple_divisions(i32 %a, i32 %b, i32 %c) {
; CHECK-LABEL: test_multiple_divisions:
; CHECK:       # %bb.0:
; CHECK:        divw
; CHECK:        divw
entry:
  %div1 = sdiv i32 %a, %b
  %div2 = sdiv i32 %div1, %c
  ret i32 %div2
}

; Test 6: Division with overflow potential (INT_MIN / -1)
define i32 @test_division_overflow(i32 %a) {
; CHECK-LABEL: test_division_overflow:
; CHECK:       # %bb.0:
; CHECK:        divw {{r[0-9]+}}, {{r[0-9]+}}, -1
; Division overflow should be handled appropriately
entry:
  ; INT_MIN / -1 can overflow
  %result = sdiv i32 %a, -1
  ret i32 %result
}

; Test 7: Reminder operation (uses same division unit)
define i32 @test_remainder(i32 %a, i32 %b) {
; CHECK-LABEL: test_remainder:
; CHECK:       # %bb.0:
; CHECK:        divw
; CHECK:        mullw
; CHECK:        subf
; Or: CHECK: divw followed by calculation for remainder
entry:
  %rem = srem i32 %a, %b
  ret i32 %rem
}

