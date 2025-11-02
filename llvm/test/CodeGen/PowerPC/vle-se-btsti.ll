; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -Oz < %s | FileCheck %s
; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -O2 < %s | FileCheck %s --check-prefix=NOOPT

; Test SE_BTSTI (16-bit Bit Test Immediate) instruction selection.
; SE_BTSTI tests a bit and sets condition codes: tests (rA & (1 << UIMM)) != 0.
; Format: se_btsti rA, UIMM. Requires registers in R0-R7, immediate 0-31 (u5imm).
; Reference: VLEPEM Table B-3, VLEPIM Section 4.3.3

target datalayout = "E-p:32:32:32-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v128:128:128-n32"
target triple = "powerpc-none-eabivle"

; Test SE_BTSTI testing bit 3
define i1 @test_se_btsti(i32 %a) optsize minsize {
entry:
; CHECK-LABEL: @test_se_btsti
; CHECK: se_btsti {{r[0-7]}}, 3
; CHECK: bc
; Bit test immediate should use SE_BTSTI
  %mask = shl i32 1, 3
  %and = and i32 %a, %mask
  %result = icmp ne i32 %and, 0
  ret i1 %result
}

; Test SE_BTSTI with different bit positions
define i1 @test_se_btsti_bit10(i32 %a) optsize minsize {
entry:
; CHECK-LABEL: @test_se_btsti_bit10
; CHECK: se_btsti {{r[0-7]}}, 10
; CHECK: bc
; Testing bit 10 should use SE_BTSTI
  %mask = shl i32 1, 10
  %and = and i32 %a, %mask
  %result = icmp ne i32 %and, 0
  ret i1 %result
}

attributes #0 = { minsize optsize "target-cpu"="e200z4" }

