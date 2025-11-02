; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -Oz < %s | FileCheck %s
; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -O2 < %s | FileCheck %s --check-prefix=NOOPT

; Test E_ICBI (32-bit Instruction Cache Block Invalidate) instruction selection.
; E_ICBI invalidates instruction cache block: ICache[EA] invalidated.
; Format: e_icbi rA, rB. This is a 32-bit VLE instruction.
; Reference: VLEPEM Table B-3, VLEPIM Section 4.10.2

target datalayout = "E-p:32:32:32-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v128:128:128-n32"
target triple = "powerpc-none-eabivle"

; Test E_ICBI (instruction cache invalidate)
define void @test_e_icbi(i8* %addr) optsize minsize {
entry:
; CHECK-LABEL: @test_e_icbi
; CHECK: e_icbi
; Instruction cache invalidate should use E_ICBI
  call void @llvm.ppc.icbi(i8* %addr)
  ret void
}

declare void @llvm.ppc.icbi(i8*)

attributes #0 = { minsize optsize "target-cpu"="e200z4" }

