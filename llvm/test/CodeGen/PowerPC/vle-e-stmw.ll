; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -Oz < %s | FileCheck %s
; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -O2 < %s | FileCheck %s --check-prefix=NOOPT

; Test E_STMW (32-bit VLE Store Multiple Words) instruction selection.
; E_STMW stores consecutive words starting from base address, from registers rS through r31.
; Format: e_stmw rS, d(rA).
; Reference: VLEPEM Table B-3, VLEPIM Section 4.2.2

target datalayout = "E-p:32:32:32-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v128:128:128-n32"
target triple = "powerpc-none-eabivle"

; Test E_STMW storing multiple words
define void @test_e_stmw(i32* %base, i32 %val1, i32 %val2, i32 %val3) optsize minsize {
entry:
; CHECK-LABEL: @test_e_stmw
; CHECK: e_stmw {{r[0-9]+}}, 0, {{r[0-9]+}}
; Multiple word stores should use E_STMW when beneficial
  store i32 %val1, i32* %base, align 4
  %ptr2 = getelementptr inbounds i32, i32* %base, i32 1
  store i32 %val2, i32* %ptr2, align 4
  %ptr3 = getelementptr inbounds i32, i32* %base, i32 2
  store i32 %val3, i32* %ptr3, align 4
  ret void
}

