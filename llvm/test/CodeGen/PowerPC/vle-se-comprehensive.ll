; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -Oz < %s | FileCheck %s

; Comprehensive test for SE_* (16-bit VLE) instruction forms.
; Test various SE instructions not covered in individual test files.
; Reference: VLEPEM Table B-3, VLEPIM Section 4.3

target datalayout = "E-p:32:32:32-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v128:128:128-n32"
target triple = "powerpc-none-eabivle"

; Test SE_SUB (16-bit subtract)
define i32 @test_se_sub(i32 %a, i32 %b) optsize minsize {
entry:
; CHECK-LABEL: @test_se_sub
; CHECK: se_sub {{r[0-7]}}, {{r[0-7]}}, {{r[0-7]}}
  %result = sub i32 %a, %b
  ret i32 %result
}

; Test SE_MR (16-bit move register)
define i32 @test_se_mr(i32 %a) optsize minsize {
entry:
; CHECK-LABEL: @test_se_mr
; CHECK: se_mr {{r[0-7]}}, {{r[0-7]}}
  ret i32 %a
}

; Test SE_OR (16-bit logical or)
define i32 @test_se_or(i32 %a, i32 %b) optsize minsize {
entry:
; CHECK-LABEL: @test_se_or
; CHECK: se_or {{r[0-7]}}, {{r[0-7]}}, {{r[0-7]}}
  %result = or i32 %a, %b
  ret i32 %result
}

; Test SE_AND (16-bit logical and)
define i32 @test_se_and(i32 %a, i32 %b) optsize minsize {
entry:
; CHECK-LABEL: @test_se_and
; CHECK: se_and {{r[0-7]}}, {{r[0-7]}}, {{r[0-7]}}
  %result = and i32 %a, %b
  ret i32 %result
}

; Test SE_XOR (16-bit logical xor)
define i32 @test_se_xor(i32 %a, i32 %b) optsize minsize {
entry:
; CHECK-LABEL: @test_se_xor
; CHECK: se_xor {{r[0-7]}}, {{r[0-7]}}, {{r[0-7]}}
  %result = xor i32 %a, %b
  ret i32 %result
}

; Test SE_SLWI (16-bit shift left word immediate)
define i32 @test_se_slwi(i32 %a) optsize minsize {
entry:
; CHECK-LABEL: @test_se_slwi
; CHECK: se_slwi {{r[0-7]}}, {{r[0-7]}}, 10
  %result = shl i32 %a, 10
  ret i32 %result
}

; Test SE_SRWI (16-bit shift right word immediate)
define i32 @test_se_srwi(i32 %a) optsize minsize {
entry:
; CHECK-LABEL: @test_se_srwi
; CHECK: se_srwi {{r[0-7]}}, {{r[0-7]}}, 10
  %result = lshr i32 %a, 10
  ret i32 %result
}

; Test SE_SRAWI (16-bit shift right arithmetic word immediate)
define i32 @test_se_srawi(i32 %a) optsize minsize {
entry:
; CHECK-LABEL: @test_se_srawi
; CHECK: se_srawi {{r[0-7]}}, {{r[0-7]}}, 10
  %result = ashr i32 %a, 10
  ret i32 %result
}

; Test SE_CMP (16-bit compare)
define i32 @test_se_cmp(i32 %a, i32 %b) optsize minsize {
entry:
; CHECK-LABEL: @test_se_cmp
; CHECK: se_cmp {{r[0-7]}}, {{r[0-7]}}
  %cmp = icmp eq i32 %a, %b
  %result = select i1 %cmp, i32 1, i32 0
  ret i32 %result
}

; Test SE_CMPI (16-bit compare immediate)
define i32 @test_se_cmpi(i32 %a) optsize minsize {
entry:
; CHECK-LABEL: @test_se_cmpi
; CHECK: se_cmpi {{r[0-7]}}, 15
  %cmp = icmp eq i32 %a, 15
  %result = select i1 %cmp, i32 1, i32 0
  ret i32 %result
}

; Test SE_B (16-bit branch unconditional)
define void @test_se_b() optsize minsize {
entry:
; CHECK-LABEL: @test_se_b
; CHECK: se_b
  br label %label
label:
  ret void
}

; Test SE_BC (16-bit branch conditional)
define void @test_se_bc(i32 %a) optsize minsize {
entry:
; CHECK-LABEL: @test_se_bc
; CHECK: se_cmpi {{r[0-7]}}, 0
; CHECK: se_bc
  %cmp = icmp eq i32 %a, 0
  br i1 %cmp, label %if, label %end
if:
  ret void
end:
  ret void
}

; Test SE_LBZ (16-bit load byte and zero)
define i32 @test_se_lbz(i8* %ptr) optsize minsize {
entry:
; CHECK-LABEL: @test_se_lbz
; CHECK: se_lbz {{r[0-7]}}, 0({{r[0-7]}})
  %val = load i8, i8* %ptr
  %result = zext i8 %val to i32
  ret i32 %result
}

; Test SE_STB (16-bit store byte)
define void @test_se_stb(i8* %ptr, i8 %val) optsize minsize {
entry:
; CHECK-LABEL: @test_se_stb
; CHECK: se_stb {{r[0-7]}}, 0({{r[0-7]}})
  store i8 %val, i8* %ptr
  ret void
}

