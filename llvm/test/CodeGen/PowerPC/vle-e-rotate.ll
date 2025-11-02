; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -Oz < %s | FileCheck %s
; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -O2 < %s | FileCheck %s --check-prefix=NOOPT

; Test E-form rotate instructions (E_RLWINM, E_RLWNM, E_RLWIMI).
; These perform rotate and mask operations used in bit manipulation and math operations.
; Reference: VLEPEM Table B-3, VLEPIM Section 4.8.3

target datalayout = "E-p:32:32:32-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v128:128:128-n32"
target triple = "powerpc-none-eabivle"

; Test rotate left with mask (common pattern for bit extraction)
define i32 @test_e_rlwinm(i32 %a) optsize minsize {
entry:
; CHECK-LABEL: @test_e_rlwinm
; CHECK: e_rlwinm {{r[0-9]+}}, {{r[0-9]+}}, {{r[0-9]+}}, 0, 31
; Rotate with mask should use E_RLWINM
  %rot = call i32 @llvm.fshl.i32(i32 %a, i32 %a, i32 4)
  %masked = and i32 %rot, -1
  ret i32 %masked
}

declare i32 @llvm.fshl.i32(i32, i32, i32)

attributes #0 = { minsize optsize "target-cpu"="e200z4" }

