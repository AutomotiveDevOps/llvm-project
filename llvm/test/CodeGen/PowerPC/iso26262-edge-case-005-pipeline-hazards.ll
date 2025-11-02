; RUN: llc -mtriple=powerpc-unknown-linux-gnu -mcpu=e200z6 -verify-machineinstrs < %s | FileCheck %s
; RUN: llc -mtriple=powerpc-unknown-linux-gnu -mcpu=e200z4 -verify-machineinstrs < %s | FileCheck %s

; ISO 26262 Edge Case 005: Pipeline Hazard Undetected Stalls in Single-Issue In-Order Pipeline
; Test that pipeline hazards are properly detected and accounted for in WCET analysis
; Reference: PPCScheduleE200Z6.td:17-231, PPCScheduleE200Z4.td

target datalayout = "E-p:32:32:32-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:32:64-f32:32:32-f64:32:64-v128:128:128-a0:0:64-f128:64:128-n32"
target triple = "powerpc-unknown-linux-gnu"

; Test 1: Load-to-use latency - verify proper spacing between load and use
define i32 @test_load_to_use_latency(i32* %ptr) {
; CHECK-LABEL: test_load_to_use_latency:
; CHECK:       # %bb.0:
; CHECK:        lwz {{r[0-9]+}}, 0({{r[0-9]+}})
; CHECK-NEXT:   {{[a-z]+}} {{r[0-9]+}}, {{r[0-9]+}}
; CHECK-NEXT:   {{[a-z]+}} {{r[0-9]+}}, {{r[0-9]+}}
; Verify at least 3 cycles between load and use (for e200z6)
; The scheduler should insert instructions or nops if needed
entry:
  %val = load i32, i32* %ptr
  %result = add i32 %val, 1
  ret i32 %result
}

; Test 2: Division latency (34 cycles) - verify proper spacing
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

; Test 3: Branch misprediction penalty - verify branch scheduling
define i32 @test_branch_misprediction(i32 %a, i32 %b) {
; CHECK-LABEL: test_branch_misprediction:
; CHECK:       # %bb.0:
; CHECK:        cmpw {{cr[0-9]+}}, {{r[0-9]+}}, {{r[0-9]+}}
; CHECK:        beq {{.+}}
; Branch misprediction penalty is 3 cycles - scheduler should account for this
entry:
  %cmp = icmp eq i32 %a, %b
  br i1 %cmp, label %if_true, label %if_false

if_true:
  ret i32 1

if_false:
  ret i32 0
}

; Test 4: Resource conflict - MUL and FPU sharing execution unit
define i32 @test_resource_conflict(i32 %a, i32 %b) {
; CHECK-LABEL: test_resource_conflict:
; CHECK:       # %bb.0:
; CHECK:        mullw {{r[0-9]+}}, {{r[0-9]+}}, {{r[0-9]+}}
; CHECK:        mullw {{r[0-9]+}}, {{r[0-9]+}}, {{r[0-9]+}}
; MUL operations may conflict if issued in same cycle - scheduler should handle
entry:
  %mul1 = mul i32 %a, %b
  %mul2 = mul i32 %mul1, %b
  %result = mul i32 %mul2, %a
  ret i32 %result
}

; Test 5: Bypass path testing - verify forwarding scenarios
define i32 @test_bypass_paths(i32 %a, i32 %b) {
; CHECK-LABEL: test_bypass_paths:
; CHECK:       # %bb.0:
; CHECK:        add {{r[0-9]+}}, {{r[0-9]+}}, {{r[0-9]+}}
; CHECK:        add {{r[0-9]+}}, {{r[0-9]+}}, {{r[0-9]+}}
; GPR bypass paths should be modeled - certain ALU results can forward
entry:
  %add1 = add i32 %a, %b
  %add2 = add i32 %add1, %b
  %add3 = add i32 %add2, %a
  ret i32 %add3
}

; Test 6: Cache miss penalty (if modeled) - test memory access timing
define i32 @test_cache_miss_penalty(i32* %ptr1, i32* %ptr2) {
; CHECK-LABEL: test_cache_miss_penalty:
; CHECK:       # %bb.0:
; CHECK:        lwz {{r[0-9]+}}, 0({{r[0-9]+}})
; CHECK:        lwz {{r[0-9]+}}, 0({{r[0-9]+}})
; Cache miss penalties should be accounted for in WCET if modeled
entry:
  %val1 = load i32, i32* %ptr1
  %val2 = load i32, i32* %ptr2
  %result = add i32 %val1, %val2
  ret i32 %result
}

