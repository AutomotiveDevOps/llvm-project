; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -Oz < %s | FileCheck %s
; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -O2 < %s | FileCheck %s --check-prefix=NOOPT

; Test E_TW, E_TWI (32-bit Trap Word) instruction selection.
; E_TW/E_TWI generate traps for debugging and error handling.
; Format: e_tw TO, rA, rB; e_twi TO, rA, SIMM.
; Reference: VLEPEM Table B-3, VLEPIM Section 4.9.1

target datalayout = "E-p:32:32:32-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v128:128:128-n32"
target triple = "powerpc-none-eabivle"

; Test E_TW trap word
define void @test_e_tw(i32 %a, i32 %b) optsize minsize {
entry:
; CHECK-LABEL: @test_e_tw
; CHECK: e_tw
; Trap word should use E_TW
  call void @llvm.ppc.tw(i32 0, i32 %a, i32 %b)
  ret void
}

; Test E_TWI trap word immediate
define void @test_e_twi(i32 %a) optsize minsize {
entry:
; CHECK-LABEL: @test_e_twi
; CHECK: e_twi
; Trap word immediate should use E_TWI
  call void @llvm.ppc.twi(i32 0, i32 %a, i32 100)
  ret void
}

declare void @llvm.ppc.tw(i32, i32, i32)
declare void @llvm.ppc.twi(i32, i32, i32)

attributes #0 = { minsize optsize "target-cpu"="e200z4" }

