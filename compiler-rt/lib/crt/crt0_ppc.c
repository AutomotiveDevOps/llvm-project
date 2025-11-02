//===-- crt0_ppc.c - PowerPC Baremetal Startup Code (C) ------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// PowerPC baremetal startup code (crt0) in C for embedded e200 cores.
// This version uses C code and will be compiled with VLE support if available.
//
// This startup code performs:
// 1. Stack pointer initialization
// 2. .data section initialization (copy from Flash to RAM)
// 3. .bss section zeroing
// 4. C++ constructor array iteration
// 5. Call to main()
// 6. Infinite loop if main returns
//
//===----------------------------------------------------------------------===//

#include <stddef.h>
#include <stdint.h>

// Linker-provided symbols for memory layout
extern char __data_start__[];
extern char __data_end__[];
extern char __data_load__[];
extern char __bss_start__[];
extern char __bss_end__[];
extern char _stack_top[];

// C++ constructor support (provided by crtbegin)
extern void _init(void) __attribute__((weak));

// Main function declaration
extern int main(void);

// Stack pointer initialization
// For PowerPC, R1 is the stack pointer
// We initialize it from _stack_top symbol or use a default
__attribute__((section(".text.start")))
__attribute__((weak)) extern char _stack_top[];

__attribute__((section(".text.start")))
void _start(void) {
    // Initialize stack pointer
    // If _stack_top is provided by linker script, use it
    // Otherwise, use a default value (0x20010000)
    uintptr_t stack_top = (uintptr_t)&_stack_top;
    if (stack_top == 0) {
        stack_top = 0x20010000U;  // Default stack top
    }
    
    // Set stack pointer using inline assembly
    __asm__ volatile (
        "mr %%r1, %0"
        :
        : "r" (stack_top)
        : "r1"
    );
    
    // Copy .data section from Flash to RAM
    // This is needed when .data is in RAM but initialized data is in Flash
    char *src = &__data_load__[0];
    char *dst = &__data_start__[0];
    char *end = &__data_end__[0];
    
    // Only copy if source and destination differ (data is in Flash)
    if (src != dst) {
        while (dst < end) {
            *dst++ = *src++;
        }
    }
    
    // Zero .bss section
    char *bss_start = &__bss_start__[0];
    char *bss_end = &__bss_end__[0];
    
    while (bss_start < bss_end) {
        *bss_start++ = 0;
    }
    
    // Call C++ constructors if _init exists
    // The _init function is provided by crtbegin and iterates .init_array
    if ((uintptr_t)&_init != 0) {
        _init();
    }
    
    // Call main()
    (void)main();
    
    // Infinite loop if main returns (should not happen in embedded systems)
    while (1) {
        // Halt or enter low-power mode
        __asm__ volatile ("nop");
    }
}

