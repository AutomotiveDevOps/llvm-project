; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -Oz < %s | FileCheck %s
; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -O2 < %s | FileCheck %s --check-prefix=NOOPT

; Test SE_CNTLZB (16-bit Count Leading Zeros Byte) instruction selection.
; SE_CNTLZB counts leading zeros in byte: rD = count_leading_zeros(rA[7:0]).
; Format: se_cntlzb rD, rA. Requires all registers in R0-R7 range.
; Reference: VLEPEM Table B-3, VLEPIM Section 4.7.2

target datalayout = "E-p:32:32:32-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v128:128:128-n32"
target triple = "powerpc-none-eabivle"

; Test SE_CNTLZB count leading zeros in byte
define i32 @test_se_cntlzb(i8 %val) optsize minsize {
entry:
; CHECK-LABEL: @test_se_cntlzb
; CHECK: se_cntlzb {{r[0-7]}}, {{r[0-7]}}
; Count leading zeros byte should use SE_CNTLZB
  %ext = zext i8 %val to i32
  %count = call i32 @llvm.ctlz.i32(i32 %ext, i1 false)
  ret i32 %count
}

declare i32 @llvm.ctlz.i32(i32, i1)

attributes #0 = { minsize optsize "target-cpu"="e200z4" }

