; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -Oz < %s | FileCheck %s
; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -O2 < %s | FileCheck %s --check-prefix=NOOPT

; Test SE_EXTSH (16-bit Extend Sign Halfword) instruction selection.
; SE_EXTSH sign-extends halfword to word: rD = SignExtend(rA[15:0]).
; Format: se_extsh rD, rA. Requires all registers in R0-R7 range.
; Reference: VLEPEM Table B-3, VLEPIM Section 4.7.1

target datalayout = "E-p:32:32:32-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v128:128:128-n32"
target triple = "powerpc-none-eabivle"

; Test SE_EXTSH sign extension
define i32 @test_se_extsh(i16 %val) optsize minsize {
entry:
; CHECK-LABEL: @test_se_extsh
; CHECK: se_extsh {{r[0-7]}}, {{r[0-7]}}
; Sign extend halfword should use SE_EXTSH
  %ext = sext i16 %val to i32
  ret i32 %ext
}

attributes #0 = { minsize optsize "target-cpu"="e200z4" }

