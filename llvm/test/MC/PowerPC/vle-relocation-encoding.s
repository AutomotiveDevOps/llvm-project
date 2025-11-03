# RUN: llvm-mc -triple=powerpc-none-eabivle -mcpu=e200z4 -mvle -filetype=obj -o %t.o %s
# RUN: llvm-readobj -r %t.o | FileCheck %s

# Test VLE relocation encoding.
# Verify that relocations are correctly emitted for VLE instructions.
# Reference: VLEPIM Chapter 2, COMPREHENSIVE_GCC_PATCHES_ANALYSIS.md

        .text
        .globl  test_function
        .type   test_function,@function
test_function:
# CHECK: Relocations [
# CHECK:   Relocation {
# CHECK:     Type: R_PPC_VLE_REL24
# CHECK:   }
        e_bl    external_function
        se_blr
        .size   test_function, .-test_function

        .globl  external_function
        .type   external_function,@function
external_function:
        se_blr
        .size   external_function, .-external_function

        .data
        .globl  test_data
test_data:
# CHECK: Relocation {
# CHECK:   Type: R_PPC_VLE_ADDR16_HA
# CHECK: }
        .long   test_data@ha
        .size   test_data, 4

