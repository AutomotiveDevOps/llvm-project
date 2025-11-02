===================================================================
Migrating from GCC to Clang for PowerPC VLE
===================================================================

Introduction
============

This guide helps users migrate from GCC 4.9.4 VLE fork (or similar) to Clang
for PowerPC e200/VLE embedded projects.

Command-Line Option Mappings
=============================

Basic Compilation
-----------------

**GCC:**
.. code-block:: bash

   powerpc-eabivle-gcc -mcpu=e200z4 -mvle -Os -c main.c -o main.o

**Clang:**
.. code-block:: bash

   clang -target powerpc-none-eabivle -mcpu=e200z4 -mvle -Os -c main.c -o main.o

Key differences:
* GCC uses prefixed toolchain name; Clang uses ``-target`` flag
* Triple format is similar but Clang uses ``powerpc-none-eabivle``

Linking
-------

**GCC:**
.. code-block:: bash

   powerpc-eabivle-gcc -T linker.ld -o firmware.elf main.o startup.o

**Clang:**
.. code-block:: bash

   clang -target powerpc-none-eabivle -T linker.ld -o firmware.elf main.o startup.o

Runtime Libraries
-----------------

**GCC:**
.. code-block:: bash

   powerpc-eabivle-gcc ... -lgcc -lc

**Clang:**
.. code-block:: bash

   clang ... -lclang_rt.builtins-powerpc -lc

Note: Clang uses compiler-rt builtins instead of libgcc.

Code Compatibility
===================

C Standard Compliance
---------------------

Clang generally follows the C standard more strictly than GCC. Common issues:

1. **Variable-length arrays in structs**: Not supported in C99, but GCC allows it.

2. **Zero-length arrays**: GCC extension; use flexible array members in Clang:
   ```c
   // GCC:  int array[0];
   // Clang: int array[];  (flexible array member)
   ```

3. **Nested functions**: GCC extension not supported by Clang.

Inline Assembly
---------------

Clang's inline assembly syntax is compatible with GCC for PowerPC, but there
are some differences:

**GCC:**
.. code-block:: c

   asm volatile ("se_addi %0, %1, %2" : "=r"(out) : "r"(in1), "i"(imm));

**Clang:**
.. code-block:: c

   __asm__ volatile ("se_addi %0, %1, %2" : "=r"(out) : "r"(in1), "i"(imm));

Both syntaxes work in Clang, but ``__asm__`` is preferred for compatibility.

VLE Instruction Syntax
---------------------

**GCC:**
.. code-block:: c

   asm volatile ("se_addi %r3, %r1, 42");

**Clang:**
.. code-block:: c

   __asm__ volatile ("se_addi %r3, %r1, 42");

Behavior Differences
====================

Optimization Levels
-------------------

Clang and GCC may produce different code sizes and performance characteristics:

* **Code Size**: Clang with ``-Oz -mvle`` typically matches or exceeds GCC code
  size optimization
* **Performance**: Similar performance, but some code patterns may differ

Floating-Point
--------------

* Default float ABI may differ between GCC and Clang
* Use explicit flags: ``-mhard-float`` or ``-msoft-float``
* Check your target's default with: ``clang -target powerpc-none-eabivle --help``

Link-Time Optimization
---------------------

**GCC:**
.. code-block:: bash

   powerpc-eabivle-gcc -flto -fuse-linker-plugin ...

**Clang:**
.. code-block:: bash

   clang -flto=thin ...  # or -flto=full
   # Uses lld by default for LTO

Feature Parity Matrix
=====================

| Feature | GCC 4.9.4 VLE | Clang | Notes |
|---------|---------------|-------|-------|
| VLE 16-bit instructions | ✅ | ✅ | Complete |
| VLE 32-bit instructions | ✅ | ✅ | Complete |
| e200z0 support | ✅ | ✅ | 4-stage pipeline |
| e200z4 support | ✅ | ✅ | 5-stage dual-issue |
| e200z6 support | ✅ | ✅ | 7-stage single-issue |
| Linker scripts | ✅ | ✅ | Full support |
| Startup code | ✅ | ✅ | User-provided |
| compiler-rt builtins | N/A | ✅ | Clang-specific |
| libgcc compatibility | ✅ | ⚠️ | Use compiler-rt instead |
| Extended inline asm | ✅ | ⚠️ | Some differences |
| Nested functions | ✅ | ❌ | GCC extension |
| Zero-length arrays | ✅ | ⚠️ | Use flexible arrays |

Common Migration Issues
=======================

Issue: Undefined References to __* Functions
---------------------------------------------

**Problem:**
.. code-block:: bash

   undefined reference to '__divsi3'
   undefined reference to '__fixunsdfdi'

**Solution:**

Link compiler-rt builtins:

.. code-block:: bash

   clang ... -L/path/to/compiler-rt/lib/baremetal \
             -lclang_rt.builtins-powerpc

Issue: VLE Instructions Not Generated
--------------------------------------

**Problem:** Generated code uses standard PowerPC instructions instead of VLE.

**Solution:**

1. Verify target triple: ``-target powerpc-none-eabivle``
2. Enable VLE explicitly: ``-mvle``
3. Check optimization level: ``-Oz`` helps with code size

Issue: Linker Errors with Startup Code
---------------------------------------

**Problem:** Startup code doesn't link correctly.

**Solution:**

1. Ensure startup code uses compatible calling conventions
2. Check linker script entry point matches startup function
3. Use ``-nostartfiles`` if providing custom startup

Issue: Different Code Size
---------------------------

**Problem:** Clang produces larger code than GCC.

**Solution:**

1. Use ``-Oz`` for maximum code size optimization
2. Ensure ``-mvle`` is enabled
3. Review optimization flags and disable size-increasing opts

Best Practices for Migration
=============================

1. **Start Small**: Migrate one module at a time
2. **Test Thoroughly**: Validate on target hardware
3. **Compare Binaries**: Check code size and performance
4. **Update Build System**: Adjust flags and library paths
5. **Document Differences**: Note any behavioral changes

Testing Checklist
=================

- [ ] Compilation succeeds with Clang
- [ ] VLE instructions generated (check with objdump)
- [ ] Object file format correct (ELF 32-bit MSB PowerPC)
- [ ] Linking succeeds
- [ ] Binary size acceptable (compare with GCC)
- [ ] Functionality verified on hardware
- [ ] Performance acceptable
- [ ] No undefined references

Additional Resources
=====================

* :doc:`EmbeddedPowerPC` - Clang embedded PowerPC guide
* :doc:`EmbeddedPowerPCQuickStart` - Quick start examples
* :doc:`Toolchain` - Complete toolchain documentation
* GCC to Clang migration guide (general)

See Also
========

For issues not covered here, see:
* :doc:`EmbeddedPowerPC` - Troubleshooting section
* LLVM bug tracker for known issues
* Clang documentation for general migration guidance

