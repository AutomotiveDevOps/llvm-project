//===-- crt0_ppc_vle.S - PowerPC VLE Baremetal Startup Code --------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// PowerPC VLE (Variable Length Encoding) baremetal startup code (crt0) for
// embedded e200 cores. Uses 16-bit and 32-bit VLE instructions for smaller
// code size.
//
// This startup code performs:
// 1. Stack pointer initialization (from linker symbol _stack_top or default)
// 2. .data section initialization (copy from Flash to RAM)
// 3. .bss section zeroing
// 4. C++ constructor array iteration (.init_array)
// 5. Call to main()
// 6. Infinite loop if main returns
//
//===----------------------------------------------------------------------===//

.section .text.start, "ax", @progbits
.global _start
.type _start, @function

// Enable VLE mode for this file
.machine ppc

_start:
    // Entry point for PowerPC VLE baremetal applications
    // On reset, the processor jumps to address 0x00000000
    
    // Step 1: Initialize Stack Pointer (R1)
    // Use _stack_top symbol if provided by linker script
    .extern _stack_top
    // VLE: Use se_li + se_add for small values, e_add for large
    // Load _stack_top address (linker will resolve)
    e_lis     %r3, _stack_top@h
    e_or2i    %r3, _stack_top@l
    
    // If _stack_top is not defined, use a default value
    .weak _stack_top
    e_cmplwi  %r3, 0
    se_beq    1f
    se_mr     %r1, %r3
    se_b      2f
1:
    // Default stack top at 0x20010000
    e_lis     %r1, 0x2001
    e_or2i    %r1, 0x0000
2:
    
    // Step 2: Copy .data section from Flash to RAM
    .extern __data_load__
    .extern __data_start__
    .extern __data_end__
    
    e_lis     %r3, __data_load__@h       // Source (Flash)
    e_or2i    %r3, __data_load__@l
    e_lis     %r4, __data_start__@h      // Destination (RAM)
    e_or2i    %r4, __data_start__@l
    e_lis     %r5, __data_end__@h        // End
    e_or2i    %r5, __data_end__@l
    
    // Check if .data section exists
    e_cmp     %r3, %r4, 0
    se_beq    copy_data_done
    
    // Copy loop (use VLE instructions)
copy_data_loop:
    e_cmp     %r4, %r5, 0
    se_bge    copy_data_done
    e_lwz     %r6, 0(%r3)                 // Load from Flash
    e_stw     %r6, 0(%r4)                 // Store to RAM
    se_addi   %r3, %r3, 4
    se_addi   %r4, %r4, 4
    se_b      copy_data_loop
copy_data_done:

    // Step 3: Zero .bss section
    .extern __bss_start__
    .extern __bss_end__
    
    e_lis     %r3, __bss_start__@h
    e_or2i    %r3, __bss_start__@l
    e_lis     %r4, __bss_end__@h
    e_or2i    %r4, __bss_end__@l
    
    // Check if .bss exists
    e_cmp     %r3, %r4, 0
    se_bge    zero_bss_done
    
    se_li     %r5, 0                      // Zero value
zero_bss_loop:
    e_cmp     %r3, %r4, 0
    se_bge    zero_bss_done
    e_stw     %r5, 0(%r3)
    se_addi   %r3, %r3, 4
    se_b      zero_bss_loop
zero_bss_done:

    // Step 4: Call C++ constructors
    .extern _init
    .weak _init
    e_lis     %r3, _init@h
    e_or2i    %r3, _init@l
    e_cmplwi  %r3, 0
    se_beq    skip_init
    e_mtctr   %r3
    e_bctrl
skip_init:

    // Step 5: Call main()
    .extern main
    e_bl      main
    
    // Step 6: Infinite loop
infinite_loop:
    se_b      infinite_loop

.size _start, . - _start

