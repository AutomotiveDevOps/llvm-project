===================================================================
PowerPC Embedded Quick Start Guide
===================================================================

This guide provides a minimal example of compiling a simple embedded program
for PowerPC e200 cores with VLE support.

Prerequisites
==============

* Clang configured with PowerPC backend
* LLVM linker (lld) or compatible linker
* Basic understanding of embedded systems

Minimal Example
===============

Step 1: Create a Simple Program
-------------------------------

Create ``main.c``:

.. code-block:: c

   void _start(void);
   void main(void);

   void _start(void) {
     // Minimal startup: initialize stack
     asm volatile ("lis %r1, 0x2000");
     asm volatile ("ori %r1, %r1, 0x10000");
     
     main();
     
     // Halt
     while (1) { }
   }

   void main(void) {
     // Your code here
     volatile int *led = (volatile int *)0x40000000;
     *led = 1;
   }

Step 2: Create a Linker Script
-------------------------------

Create ``memory.ld``:

.. code-block:: ld

   MEMORY
   {
     FLASH (rx) : ORIGIN = 0x00000000, LENGTH = 512K
     RAM (rwx)  : ORIGIN = 0x20000000, LENGTH = 64K
   }

   ENTRY(_start)

   SECTIONS
   {
     .text : {
       *(.text.start)
       *(.text*)
     } > FLASH

     .data : {
       *(.data*)
     } > RAM AT > FLASH

     .bss : {
       *(.bss*)
     } > RAM

     .stack : {
       . = ALIGN(8);
       . += 0x1000;  /* 4KB stack */
       _stack_top = .;
     } > RAM
   }

Step 3: Compile and Link
-------------------------

Compile:

.. code-block:: bash

   clang -target powerpc-none-eabivle \
         -mcpu=e200z4 \
         -mvle \
         -Os \
         -ffreestanding \
         -nostdlib \
         -c main.c -o main.o

Link:

.. code-block:: bash

   clang -target powerpc-none-eabivle \
         -mcpu=e200z4 \
         -mvle \
         -T memory.ld \
         -nostartfiles \
         -nostdlib \
         -o firmware.elf main.o

Step 4: Verify
--------------

Check the output:

.. code-block:: bash

   file firmware.elf
   # Should show: ELF 32-bit MSB executable, PowerPC...

Disassemble to verify VLE instructions:

.. code-block:: bash

   llvm-objdump -d firmware.elf
   # Look for 16-bit VLE instructions (se_* prefix)

Complete Makefile Example
==========================

.. code-block:: makefile

   TARGET = powerpc-none-eabivle
   CPU = e200z4
   OPT = -Os
   
   CC = clang
   LD = clang
   
   CFLAGS = -target $(TARGET) -mcpu=$(CPU) -mvle $(OPT) \
            -ffreestanding -nostdlib -Wall
   
   LDFLAGS = -target $(TARGET) -mcpu=$(CPU) -mvle \
             -T memory.ld -nostartfiles -nostdlib
   
   OBJS = main.o
   
   firmware.elf: $(OBJS)
   	$(LD) $(LDFLAGS) -o $@ $^
   
   %.o: %.c
   	$(CC) $(CFLAGS) -c $< -o $@
   
   clean:
   	rm -f $(OBJS) firmware.elf

Next Steps
==========

* See :doc:`EmbeddedPowerPC` for detailed documentation
* Add runtime library support (compiler-rt)
* Implement proper startup code with data/bss initialization
* Add linker script for your specific hardware

Troubleshooting
===============

**Error**: ``unknown target triple``

**Solution**: Ensure you have PowerPC backend enabled in your Clang build.

**Error**: ``undefined reference to '__*'``

**Solution**: Link compiler-rt builtins library. See :doc:`EmbeddedPowerPC`.

**Warning**: ``VLE instructions not generated``

**Solution**: Verify ``-mvle`` flag and ``powerpc-none-eabivle`` target triple.

