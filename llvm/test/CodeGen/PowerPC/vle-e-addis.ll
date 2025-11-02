; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -Oz < %s | FileCheck %s

; Test E_ADDIS (32-bit VLE Add Immediate Shifted) instruction selection.
; E_ADDIS performs addition with shifted immediate: rD = rA + (imm << 16).
; Format: e_addis rD, rA, SIMM. Used for loading upper 16 bits of addresses.
; Reference: VLEPEM Table B-3, VLEPIM Section 4.3.1

target datalayout = "E-p:32:32:32-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v128:128:128-n32"
target triple = "powerpc-none-eabivle"

; Test E_ADDIS for address construction
define i32* @test_e_addis(i32* %base) optsize minsize {
entry:
; CHECK-LABEL: @test_e_addis
; CHECK: e_addis {{r[0-9]+}}, {{r[0-9]+}}, 0
; ADDIS is typically used for high-order address bits
  ret i32* %base
}

<<<<<<< HEAD
=======
attributes #0 = { minsize optsize "target-cpu"="e200z4" }

>>>>>>> master
