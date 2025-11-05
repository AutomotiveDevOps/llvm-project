# Startup Code Requirements for e200 Cores

## Overview

Startup code for e200 cores uses VLE instructions extensively. This document identifies which VLE instructions are required for startup code compilation.

## Location

Startup code is located at:
- `/projects/vle/DEVKIT-Makefile/MPC5744P/Startup_Code/startup.S`
- `/projects/vle/DEVKIT-Makefile/MPC5748G/e200z2_3/Startup_Code/startup.S`
- `/projects/vle/DEVKIT-Makefile/MPC5748G/e200z4_1/startup.S`
- `/projects/vle/DEVKIT-Makefile/MPC5748G/e200z4_2/startup.S`

## VLE Instructions Used in Startup Code

### Critical Instructions (Must Implement First)

1. **e_li** - Load Immediate
   - Used extensively: `e_li r0, 0` through `e_li r31, 0` (register initialization)
   - Used for constants: `e_li r3, 0xC520`, `e_li r3, 0xD928`, `e_li r3, 0x201`
   - **Status**: ❌ Not implemented yet
   - **Priority**: 🔴 CRITICAL

2. **e_lis** - Load Immediate Shifted
   - Used for high 16 bits: `e_lis r4, 0xFC05`, `e_lis r3, 0xFF00`, `e_lis r3, 0x7F00`
   - **Status**: ❌ Not implemented yet
   - **Priority**: 🔴 CRITICAL

3. **e_or2i** - OR 2-Operand Immediate
   - Used to complete 32-bit values: `e_or2i r4, 0x0000`, `e_or2i r3, 0x010A`
   - **Status**: ❌ Not implemented yet
   - **Priority**: 🔴 CRITICAL

4. **e_stw** - Store Word
   - Used for memory writes: `e_stw r3, 0x10(r4)`, `e_stw r3, 0(r4)`
   - **Status**: ❌ Not implemented yet
   - **Priority**: 🔴 CRITICAL

5. **e_lbzu** - Load Byte and Zero with Update
   - Used in data copy loops: `e_lbzu r4, 1(r10)`
   - **Status**: ✅ Implemented
   - **Priority**: ✅ Complete

6. **e_bdnz** - Branch Decrement CTR if Not Zero
   - Used in loops: `e_bdnz sram_loop`, `e_bdnz ldmem_loop`, `e_bdnz DATACPYLOOP`
   - **Status**: ❌ Not implemented yet (needs e_bc with BO=2)
   - **Priority**: 🔴 CRITICAL

7. **e_beq** - Branch if Equal
   - Used for conditionals: `e_beq SDATACOPY`, `e_beq ROMCPYEND`, `e_beq __icache_no_abort`
   - **Status**: ❌ Not implemented yet (simplified mnemonic for e_bc)
   - **Priority**: 🔴 CRITICAL

8. **e_bne** - Branch if Not Equal
   - Used for conditionals: `e_bne __icache_inv`, `e_bne __dcache_inv`
   - **Status**: ❌ Not implemented yet (simplified mnemonic for e_bc)
   - **Priority**: 🔴 CRITICAL

9. **e_b** - Unconditional Branch
   - Used for jumps: `e_b __icache_cfg`, `e_b __dcache_cfg`, `e_b .` (infinite loop)
   - **Status**: ✅ Implemented
   - **Priority**: ✅ Complete

10. **e_bl** - Branch and Link
    - Used for function calls: `e_bl main`
    - **Status**: ✅ Implemented
    - **Priority**: ✅ Complete

11. **e_addi** - Add Immediate
    - Used in loops: `e_addi r5,r5,128`
    - **Status**: ✅ Implemented
    - **Priority**: ✅ Complete

12. **e_stmw** - Store Multiple Word
    - Used for SRAM initialization: `e_stmw r0,0(r5)`
    - **Status**: ❌ Not implemented yet
    - **Priority**: 🔴 CRITICAL

13. **e_stbu** - Store Byte with Update
    - Used in data copy loops: `e_stbu r4, 1(r5)`
    - **Status**: ✅ Implemented
    - **Priority**: ✅ Complete

14. **e_stwu** - Store Word with Update
    - Used for stack termination: `e_stwu r0,-64(r1)`
    - **Status**: ✅ Implemented
    - **Priority**: ✅ Complete

15. **e_subi** - Subtract Immediate
    - Used for address adjustment: `e_subi r10,r10, 1`, `e_subi r5, r5, 1`
    - **Status**: ❌ Not implemented yet
    - **Priority**: 🔴 CRITICAL

16. **e_srwi** - Shift Right Word Immediate
    - Used for division: `e_srwi r5, r5, 0x7` (divide by 128)
    - **Status**: ❌ Not implemented yet
    - **Priority**: 🔴 CRITICAL

17. **e_cmp16i** - Compare 16-bit Immediate
    - Used for conditionals: `e_cmp16i r9,0`
    - **Status**: ❌ Not implemented yet
    - **Priority**: 🔴 CRITICAL

18. **e_ori** - OR Immediate
    - Used for bit manipulation: `e_ori r5, r5, 0x0001`
    - **Status**: ✅ Implemented (E_ORI)
    - **Priority**: ✅ Complete (verify format matches)

## Assembly Directives Used

1. **`.vle`** - VLE mode directive
   - Used in GreenHills assembler: `.vle`
   - **Status**: Need to verify LLVM assembler support

2. **`.section .startup, "ax"`** - Startup section
   - Standard ELF section directive
   - **Status**: Should work, but need to verify VLE section flag

## Implementation Priority for Startup Code

### Phase 1: Minimum for Startup Code Compilation
1. ✅ E_B (unconditional branch)
2. ✅ E_BL (branch and link)
3. ✅ E_LBZU (load byte with update)
4. ❌ E_LI (load immediate) - **CRITICAL**
5. ❌ E_LIS (load immediate shifted) - **CRITICAL**
6. ❌ E_OR2I (OR 2-operand immediate) - **CRITICAL**
7. ❌ E_STW (store word) - **CRITICAL**

### Phase 2: For Startup Code Loops
8. ❌ E_BDNZ (branch decrement CTR if not zero) - **CRITICAL**
9. ❌ E_BEQ (branch if equal) - **CRITICAL**
10. ❌ E_BNE (branch if not equal) - **CRITICAL**
11. ❌ E_STMW (store multiple word) - **CRITICAL**
12. ❌ E_SUBI (subtract immediate) - **CRITICAL**
13. ❌ E_SRWI (shift right word immediate) - **CRITICAL**
14. ❌ E_CMP16I (compare 16-bit immediate) - **CRITICAL**

## Example Usage from startup.S

```assembly
# Register initialization
e_li	r0, 0
e_li	r1, 0
# ... (all 32 registers)

# Memory writes
e_lis	r4, 0xFC05
e_or2i	r4, 0x0000
e_li	r3, 0xC520
e_stw	r3, 0x10(r4)

# Loops
sram_loop:
    e_addi      r5,r5,128
    e_bdnz      sram_loop

# Conditionals
e_beq       SDATACOPY
e_bne       __icache_inv

# Function call
e_bl	main

# Infinite loop
e_b .
```

## Notes

- Startup code is in pure assembly, so instruction selection patterns are not critical initially
- However, assembler must be able to parse and encode these instructions
- Linker must handle VLE sections correctly
- Object files must have correct VLE section flags

## References

- Startup code: `/projects/vle/DEVKIT-Makefile/MPC5744P/Startup_Code/startup.S`
- Linker scripts: `/projects/vle/DEVKIT-Makefile/MPC5744P/Linker_Files/`
- LLVM integration notes: `/projects/vle/DEVKIT-Makefile/LLVM_INTEGRATION_ISSUES.md`

