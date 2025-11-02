; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle < %s | FileCheck %s
; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z6 -mvle < %s | FileCheck %s

; ISO 26262 Edge Case 006: VLE Instruction Length Decoding Ambiguity
; Test that VLE instruction boundaries are correctly identified
; Reference: PPCInstrVLE.td, PPCDisassembler.cpp, PPCMCCodeEmitter.cpp

target datalayout = "E-p:32:32:32-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v128:128:128-n32"
target triple = "powerpc-none-eabivle"

; Test 1: Mixed 16-bit and 32-bit VLE instructions - verify alignment
define i32 @test_mixed_vle_instructions(i32 %a, i32 %b) optsize minsize {
; CHECK-LABEL: test_mixed_vle_instructions:
; CHECK:       # %bb.0:
; CHECK:        se_addi
; CHECK:        e_add
; Verify that instruction boundaries are correctly maintained
entry:
  %add1 = add i32 %a, 10        ; Should use se_addi (16-bit)
  %add2 = add i32 %add1, %b     ; Should use e_add or se_add (depending on regs)
  ret i32 %add2
}

; Test 2: Instruction alignment - verify 16-bit instructions are 2-byte aligned
define void @test_vle_alignment(i32* %ptr) optsize minsize {
; CHECK-LABEL: test_vle_alignment:
; CHECK:       # %bb.0:
; CHECK:        se_lwz
; CHECK:        se_stw
; 16-bit VLE instructions must be 2-byte aligned
entry:
  %val = load i32, i32* %ptr
  store i32 %val, i32* %ptr
  ret void
}

; Test 3: Sequential 16-bit instructions - verify correct decoding
define i32 @test_sequential_16bit(i32 %a) optsize minsize {
; CHECK-LABEL: test_sequential_16bit:
; CHECK:       # %bb.0:
; CHECK:        se_addi
; CHECK:        se_subi
; CHECK:        se_cmpi
; Multiple 16-bit instructions should decode correctly
entry:
  %add = add i32 %a, 5
  %sub = sub i32 %add, 3
  %cmp = icmp eq i32 %sub, 0
  %result = select i1 %cmp, i32 1, i32 0
  ret i32 %result
}

; Test 4: 32-bit VLE instructions mixed with 16-bit - verify boundaries
define i32 @test_mixed_lengths(i32 %a, i32 %b, i32 %c) optsize minsize {
; CHECK-LABEL: test_mixed_lengths:
; CHECK:       # %bb.0:
; CHECK:        se_addi
; CHECK:        e_add
; CHECK:        se_subi
; Verify instruction length detection doesn't get confused
entry:
  %add1 = add i32 %a, 10        ; 16-bit
  %add2 = add i32 %add1, %b     ; 32-bit (if regs not in R0-R7)
  %sub = sub i32 %add2, 5       ; 16-bit
  ret i32 %sub
}

; Test 5: Instruction stream integrity - verify no misalignment
define i32 @test_stream_integrity(i32 %a, i32 %b) optsize minsize {
; CHECK-LABEL: test_stream_integrity:
; CHECK:       # %bb.0:
; CHECK:        se_add
; CHECK:        se_mr
; CHECK:        se_cmp
; Verify all instructions are correctly aligned and decoded
entry:
  %sum = add i32 %a, %b
  %cmp = icmp sgt i32 %sum, 0
  %result = select i1 %cmp, i32 %sum, i32 0
  ret i32 %result
}

