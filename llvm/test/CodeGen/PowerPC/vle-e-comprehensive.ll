; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -Oz < %s | FileCheck %s

; Comprehensive test for E_* (32-bit VLE) instruction variants.
; Test extended E instructions not covered in individual test files.
; Reference: VLEPEM Table B-4, VLEPIM Section 4.4

target datalayout = "E-p:32:32:32-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v128:128:128-n32"
target triple = "powerpc-none-eabivle"

; Test E_ADD (32-bit VLE add)
define i32 @test_e_add(i32 %a, i32 %b) optsize minsize {
entry:
; CHECK-LABEL: @test_e_add
; CHECK: e_add {{r[0-9]+}}, {{r[0-9]+}}, {{r[0-9]+}}
; E_ADD should be used when registers exceed R7 or immediate doesn't fit SE_ADD
  %result = add i32 %a, %b
  ret i32 %result
}

; Test E_ADDI (32-bit VLE add immediate)
define i32 @test_e_addi(i32 %a) optsize minsize {
entry:
; CHECK-LABEL: @test_e_addi
; CHECK: e_addi {{r[0-9]+}}, {{r[0-9]+}}, 128
; E_ADDI should be used for immediates outside SE_ADDI range
  %result = add i32 %a, 128
  ret i32 %result
}

; Test E_SUB (32-bit VLE subtract)
define i32 @test_e_sub(i32 %a, i32 %b) optsize minsize {
entry:
; CHECK-LABEL: @test_e_sub
; CHECK: e_sub {{r[0-9]+}}, {{r[0-9]+}}, {{r[0-9]+}}
  %result = sub i32 %a, %b
  ret i32 %result
}

; Test E_MULLW (32-bit VLE multiply)
define i32 @test_e_mullw(i32 %a, i32 %b) optsize minsize {
entry:
; CHECK-LABEL: @test_e_mullw
; CHECK: e_mullw {{r[0-9]+}}, {{r[0-9]+}}, {{r[0-9]+}}
  %result = mul i32 %a, %b
  ret i32 %result
}

; Test E_DIVW (32-bit VLE divide)
define i32 @test_e_divw(i32 %a, i32 %b) optsize minsize {
entry:
; CHECK-LABEL: @test_e_divw
; CHECK: e_divw {{r[0-9]+}}, {{r[0-9]+}}, {{r[0-9]+}}
  %result = sdiv i32 %a, %b
  ret i32 %result
}

; Test E_LWZ (32-bit VLE load word and zero)
define i32 @test_e_lwz(i32* %ptr) optsize minsize {
entry:
; CHECK-LABEL: @test_e_lwz
; CHECK: e_lwz {{r[0-9]+}}, 0({{r[0-9]+}})
  %val = load i32, i32* %ptr
  ret i32 %val
}

; Test E_STW (32-bit VLE store word)
define void @test_e_stw(i32* %ptr, i32 %val) optsize minsize {
entry:
; CHECK-LABEL: @test_e_stw
; CHECK: e_stw {{r[0-9]+}}, 0({{r[0-9]+}})
  store i32 %val, i32* %ptr
  ret void
}

; Test E_LMW (32-bit VLE load multiple)
define void @test_e_lmw(i32* %ptr, i32* %r14, i32* %r15, i32* %r16) optsize minsize {
entry:
; CHECK-LABEL: @test_e_lmw
; CHECK: e_lmw
; E_LMW loads multiple registers
  %v14 = load i32, i32* %r14
  %v15 = load i32, i32* %r15
  %v16 = load i32, i32* %r16
  store i32 %v14, i32* %ptr
  ret void
}

; Test E_STMW (32-bit VLE store multiple)
define void @test_e_stmw(i32* %ptr, i32* %r14, i32* %r15, i32* %r16) optsize minsize {
entry:
; CHECK-LABEL: @test_e_stmw
; CHECK: e_stmw
; E_STMW stores multiple registers
  store i32 1, i32* %r14
  store i32 2, i32* %r15
  store i32 3, i32* %r16
  ret void
}

; Test E_CMPWI (32-bit VLE compare word immediate)
define i32 @test_e_cmpwi(i32 %a) optsize minsize {
entry:
; CHECK-LABEL: @test_e_cmpwi
; CHECK: e_cmpwi {{r[0-9]+}}, 200
; E_CMPWI should be used for immediates outside SE_CMPI range
  %cmp = icmp eq i32 %a, 200
  %result = select i1 %cmp, i32 1, i32 0
  ret i32 %result
}

; Test E_B (32-bit VLE branch unconditional)
define void @test_e_b() optsize minsize {
entry:
; CHECK-LABEL: @test_e_b
; CHECK: e_b
; E_B for branches that exceed SE_B displacement range
  br label %label
label:
  ret void
}

; Test E_BL (32-bit VLE branch and link)
define void @test_e_bl() optsize minsize {
entry:
; CHECK-LABEL: @test_e_bl
; CHECK: e_bl
  call void @test_function()
  ret void
}

declare void @test_function()

; Test E_RFI (32-bit VLE return from interrupt)
define void @test_e_rfi() #0 {
entry:
; CHECK-LABEL: @test_e_rfi
; CHECK: e_rfi
; E_RFI for VLE mode interrupt return
  ret void
}

attributes #0 = { nounwind "interrupt" }

