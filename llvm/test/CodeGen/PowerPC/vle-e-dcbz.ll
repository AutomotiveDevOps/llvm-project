; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -Oz < %s | FileCheck %s
; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -O2 < %s | FileCheck %s --check-prefix=NOOPT

; Test E_DCBZ (32-bit Data Cache Block Zero) instruction selection.
; E_DCBZ zeros a cache block: Mem[EA] = 0 for cache block.
; Format: e_dcbz rA, rB. This is a 32-bit VLE instruction.
; Reference: VLEPEM Table B-3, VLEPIM Section 4.10.1

target datalayout = "E-p:32:32:32-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v128:128:128-n32"
target triple = "powerpc-none-eabivle"

; Test E_DCBZ (cache block zero)
define void @test_e_dcbz(i8* %addr) optsize minsize {
entry:
; CHECK-LABEL: @test_e_dcbz
; CHECK: e_dcbz
; Cache block zero should use E_DCBZ
  call void @llvm.ppc.dcbz(i8* %addr)
  ret void
}

declare void @llvm.ppc.dcbz(i8*)

attributes #0 = { minsize optsize "target-cpu"="e200z4" }

