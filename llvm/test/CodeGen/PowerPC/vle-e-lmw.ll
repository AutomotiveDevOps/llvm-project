; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -Oz < %s | FileCheck %s
; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -O2 < %s | FileCheck %s --check-prefix=NOOPT

; Test E_LMW (32-bit VLE Load Multiple Words) instruction selection.
; E_LMW loads consecutive words starting from base address, updating registers rD through r31.
; Format: e_lmw rD, d(rA).
; Reference: VLEPEM Table B-3, VLEPIM Section 4.2.1

target datalayout = "E-p:32:32:32-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v128:128:128-n32"
target triple = "powerpc-none-eabivle"

; Test E_LMW loading multiple words
define void @test_e_lmw(i32* %base, i32* %out) optsize minsize {
entry:
; CHECK-LABEL: @test_e_lmw
; CHECK: e_lmw {{r[0-9]+}}, 0, {{r[0-9]+}}
; Multiple word loads should use E_LMW when beneficial
  %val1 = load i32, i32* %base, align 4
  %ptr2 = getelementptr inbounds i32, i32* %base, i32 1
  %val2 = load i32, i32* %ptr2, align 4
  %ptr3 = getelementptr inbounds i32, i32* %base, i32 2
  %val3 = load i32, i32* %ptr3, align 4
  store i32 %val1, i32* %out, align 4
  %out2 = getelementptr inbounds i32, i32* %out, i32 1
  store i32 %val2, i32* %out2, align 4
  %out3 = getelementptr inbounds i32, i32* %out, i32 2
  store i32 %val3, i32* %out3, align 4
  ret void
}

