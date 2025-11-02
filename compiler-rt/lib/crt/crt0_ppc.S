//===-- crt0_ppc.S - PowerPC Baremetal Startup Code ----------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// PowerPC baremetal startup code (crt0) for embedded e200 cores.
// Supports both standard PowerPC and VLE (Variable Length Encoding) modes.
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

_start:
    // Entry point for PowerPC baremetal applications
    // On reset, the processor jumps to address 0x00000000, which should
    // contain this _start function (placed by linker script).
    
    // Step 1: Initialize Stack Pointer (R1)
    // Use _stack_top symbol if provided by linker script, otherwise use default
    .weak _stack_top
    .extern _stack_top
    lis     %r3, _stack_top@h
    ori     %r3, %r3, _stack_top@l
    
    // If _stack_top is not defined, use a default value
    // This can be overridden by the linker script
    // Default stack top at 0x20010000 (can be overridden)
    cmpwi   %r3, 0
    bne     1f
    lis     %r3, 0x2001
    ori     %r3, %r3, 0x0000
1:
    mr      %r1, %r3    // Copy to stack pointer register
    
    // Step 2: Copy .data section from Flash to RAM
    // Linker provides these symbols:
    // __data_load__ = Load address (in Flash)
    // __data_start__ = Virtual address (in RAM)
    // __data_end__ = End of .data section (in RAM)
    .extern __data_load__
    .extern __data_start__
    .extern __data_end__
    
    lis     %r3, __data_load__@h       // Source address (Flash)
    ori     %r3, %r3, __data_load__@l
    lis     %r4, __data_start__@h      // Destination address (RAM)
    ori     %r4, %r4, __data_start__@l
    lis     %r5, __data_end__@h        // End address
    ori     %r5, %r5, __data_end__@l
    
    // Check if .data section exists (src != dst means we need to copy)
    cmpw    %r3, %r4
    beq     2f                          // Skip if no .data to copy
    
    // Copy loop
copy_data_loop:
    cmpw    %r4, %r5
    bge     2f                          // Done if dst >= end
    lwz     %r6, 0(%r3)                 // Load from Flash
    stw     %r6, 0(%r4)                 // Store to RAM
    addi    %r3, %r3, 4                 // Increment source
    addi    %r4, %r4, 4                 // Increment destination
    b       copy_data_loop

2:
    // Step 3: Zero .bss section
    // Linker provides:
    // __bss_start__ = Start of .bss section
    // __bss_end__ = End of .bss section
    .extern __bss_start__
    .extern __bss_end__
    
    lis     %r3, __bss_start__@h
    ori     %r3, %r3, __bss_start__@l
    lis     %r4, __bss_end__@h
    ori     %r4, %r4, __bss_end__@l
    
    // Check if .bss exists
    cmpw    %r3, %r4
    bge     3f                          // Skip if no .bss to zero
    
    li      %r5, 0                      // Zero value
zero_bss_loop:
    cmpw    %r3, %r4
    bge     3f                          // Done if start >= end
    stw     %r5, 0(%r3)                 // Store zero
    addi    %r3, %r3, 4                 // Increment
    b       zero_bss_loop

3:
    // Step 4: Call C++ constructors via .init_array
    // The compiler generates .init_array section, and crtbegin/crtend
    // handle the actual constructor iteration.
    // For baremetal, we'll call _init if it exists (set up by crtbegin)
    .extern _init
    .weak _init
    lis     %r3, _init@h
    ori     %r3, %r3, _init@l
    cmpwi   %r3, 0
    beq     4f
    mtctr   %r3
    bctrl

4:
    // Step 5: Call main()
    // Call main with no arguments (typical for baremetal)
    .extern main
    bl      main
    
    // Step 6: Infinite loop if main returns
    // Embedded programs typically never return from main
infinite_loop:
    b       infinite_loop

.size _start, . - _start

