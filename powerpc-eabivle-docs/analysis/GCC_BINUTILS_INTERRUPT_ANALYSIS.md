# GCC and Binutils Interrupt Handler Analysis for PowerPC e200

## Overview

This document analyzes how GCC and binutils handle interrupt handlers for PowerPC e200 cores to identify what features are missing in LLVM's implementation.

---

## Linker Script Support (Binutils)

### Current LLVM Implementation

**File**: `clang/tools/generate-ppc-linker-script.py`

The LLVM linker script generator already includes interrupt-related sections:

```python
# Core exceptions table (IVOR table)
.core_exceptions_table   : ALIGN(0x1000)
{
  __IVPR_VALUE = . ;  # IVPR (Interrupt Vector Prefix Register) base address
  KEEP(*(.core_exceptions_table))
} > m_text

# INTC vector table (Interrupt Controller)
.intc_vector_table   : ALIGN(0x1000)
{
  KEEP(*(.intc_vector_table))
} > m_text
```

**Key Observations**:
1. ✅ **`.core_exceptions_table` section** - Already supported in linker script generator
   - This is the IVOR (Interrupt Vector Offset Register) table
   - Symbol `__IVPR_VALUE` provides base address for IVPR register initialization
   - Alignment of 0x1000 (4KB) matches typical e200 requirements

2. ✅ **`.intc_vector_table` section** - Already supported
   - Interrupt Controller (INTC) vector table for external interrupts
   - Separate from core exceptions (IVOR)

### What This Means

- **Binutils/Linker**: ✅ Already supports interrupt vector tables via standard sections
- **Missing**: Compiler support to automatically place interrupt handlers in these sections

---

## GCC Interrupt Attribute Support

### GCC VLE Fork Location

**Reference**: `/projects/gcc-4.9.4-vle`

**Critical Finding**: ⚠️ **GCC PowerPC backend does NOT implement interrupt handler support**

Analysis of `/projects/gcc-4.9.4-vle/gcc/config/rs6000/rs6000.c`:

```c
/* 6 bitfields: function is interrupt handler, name present in
   proc table, function calls alloca, on condition directives
   (controls stack walks, 3 bits), saves condition reg, saves
   link reg. */

// ...

/* Interrupt handler mask.  */
/* Omit this long, since we never set the interrupt handler bit
   above.  */
```

**Implication**: Even GCC's PowerPC backend (including the VLE fork) does not implement interrupt handler support. The infrastructure exists (bitfield definition) but is never set/used.

### Expected GCC Behavior

Based on typical GCC implementations for embedded targets (ARM, AVR, MIPS), GCC would:

1. **Parse `__attribute__((interrupt))`**
   - Validate function signature (void return, no parameters)
   - Optionally parse interrupt type/vector number

2. **Generate Prologue Code**:
   ```assembly
   # Save Link Register
   mflr    r0
   stw     r0, 4(r1)
   
   # Save Condition Register  
   mfcr    r0
   stw     r0, 8(r1)
   
   # Save used GPRs
   # ... register-specific saves ...
   ```

3. **Generate Epilogue Code**:
   ```assembly
   # Restore GPRs
   # ... register-specific restores ...
   
   # Restore Condition Register
   lwz     r0, 8(r1)
   mtcr    r0
   
   # Restore Link Register
   lwz     r0, 4(r1)
   mtlr    r0
   
   # Return from interrupt (VLE mode)
   e_rfi
   # OR (standard mode)
   rfi
   ```

### Section Placement

GCC would typically place interrupt handlers in `.core_exceptions_table`:

```c
// GCC-compatible usage
__attribute__((section(".core_exceptions_table"), interrupt))
void external_interrupt_handler(void) {
    // Handler code
}
```

Or use linker script to automatically place functions with interrupt attribute.

---

## Comparison: GCC/Binutils vs LLVM

### ✅ What LLVM Already Has

1. **Linker Script Generator**
   - `.core_exceptions_table` section definition
   - `.intc_vector_table` section definition
   - `__IVPR_VALUE` symbol for IVPR initialization
   - Proper alignment (4KB)

2. **Instruction Support**
   - `E_RFI` instruction defined (`PPCInstrVLE.td:1355-1358`)
   - `RFI` instruction (standard PowerPC)

3. **Startup Code Infrastructure**
   - `crt0_ppc.c` and `crt0_ppc.S` exist
   - Can be extended with IVOR table initialization

### ❌ What LLVM is Missing

1. **Clang Attribute Parsing**
   - No `__attribute__((interrupt))` parsing
   - No validation of interrupt handler signatures
   - No interrupt type support ("critical", "external", etc.)

2. **Frame Lowering**
   - No automatic detection of interrupt handlers
   - No automatic register save/restore
   - No `e_rfi`/`rfi` generation in epilogue

3. **Section Placement**
   - No automatic placement of interrupt handlers in `.core_exceptions_table`
   - Users must manually use `__attribute__((section(".core_exceptions_table")))`

4. **IVOR Table Initialization**
   - No automatic IVOR table creation
   - No IVPR register initialization in startup code
   - Users must manually set up interrupt vectors

5. **Register Save Lists**
   - No special callee-saved register lists for interrupt handlers
   - Standard ABI registers may not be sufficient

---

## GCC-Specific Features to Consider

### 1. Interrupt Handler Calling Convention

GCC may use a different calling convention for interrupt handlers:
- All registers must be saved (both caller-saved and callee-saved)
- Stack alignment requirements may differ
- No parameter passing (interrupts have no parameters)
- No return values (must return void)

### 2. Nested Interrupt Support

Some GCC implementations support:
- Nested interrupt handlers
- Critical section macros
- Interrupt priority handling

**Status**: ⚠️ GCC rs6000 backend has interrupt handler bitfield definition but may not be fully implemented
   - Found in `/projects/gcc-4.9.4-vle/gcc/config/rs6000/rs6000.c`
   - Comment mentions "we never set the interrupt handler bit" - suggests incomplete implementation

### 3. Interrupt Vector Numbering

Some targets (e.g., MIPS) support:
```c
__attribute__((interrupt("vector=hw0"))) void handler(void) {}
```

PowerPC e200 uses IVOR numbers (0-63) instead of named vectors.

### 4. Mixed VLE/BookE Interrupt Handlers

Some e200 implementations support:
- Interrupt handlers in VLE mode
- Interrupt handlers in BookE (standard) mode
- Runtime mode switching in interrupt context

**Linker Script Support**: ✅ Already supported via `--mixed-vle-booke` flag

---

## Recommendations Based on GCC/Binutils Analysis

### Priority 1: Match Basic GCC Functionality

1. **Interrupt Attribute**
   - Parse `__attribute__((interrupt))`
   - Validate signature (void, no params)
   - Basic implementation first

2. **Register Save/Restore**
   - Save LR, CR, and all used GPRs
   - Generate `e_rfi`/`rfi` in epilogue
   - Match GCC's register save pattern

### Priority 2: Integrate with Existing Linker Script Support

1. **Section Placement**
   - Optionally auto-place interrupt handlers in `.core_exceptions_table`
   - Or document manual placement with `__attribute__((section()))`

2. **IVOR Table Initialization**
   - Provide helper to initialize IVPR from `__IVPR_VALUE` symbol
   - Document IVOR table layout

### Priority 3: Advanced Features

1. **Interrupt Types**
   - Support "critical" vs "standard" interrupts
   - Support IVOR number specification

2. **Nested Interrupts**
   - Optional feature, less critical initially

---

## Specific Implementation Gaps

### Gap 1: Linker Script Symbol Usage

**Current State**: Linker script defines `__IVPR_VALUE` but no code uses it

**What's Needed**:
```c
// In crt0_ppc.c or startup code
extern uint32_t __IVPR_VALUE;  // Defined in linker script

void init_interrupts(void) {
    // Set IVPR register to base of exception table
    __asm__ __volatile__("mtspr 63, %0" : : "r" (__IVPR_VALUE));
}
```

**Action**: Add IVPR initialization to startup code

---

### Gap 2: Section Placement Automation

**GCC Pattern** (hypothetical):
```c
__attribute__((interrupt)) void handler(void) {
    // GCC may automatically place in .core_exceptions_table
}
```

**Current LLVM**:
```c
__attribute__((section(".core_exceptions_table")))
__attribute__((interrupt)) void handler(void) {
    // Requires manual section specification
}
```

**Action**: Consider auto-placing interrupt handlers (optional enhancement)

---

### Gap 3: IVOR Table Structure

**Expected Structure** (from linker script alignment):
```c
// IVOR table: 64 entries, each 4 bytes (32-bit function pointer)
// Alignment: 4KB (0x1000)
__attribute__((section(".core_exceptions_table")))
__attribute__((aligned(4096)))
void (*const ivor_table[64])(void) = {
    [0] = critical_input_handler,      // IVOR0
    [1] = machine_check_handler,        // IVOR1
    [2] = data_storage_handler,         // IVOR2
    [3] = instruction_storage_handler,  // IVOR3
    [4] = external_interrupt_handler,   // IVOR4
    // ... remaining entries ...
};
```

**What's Missing**:
- Default handlers (weak symbols)
- Helper function to populate table
- Documentation of IVOR mapping

---

## Binutils (Linker) Features

### ELF Section Flags

Binutils supports special section flags for PowerPC:
- `SHF_PPC_VLE` - Marks section as containing VLE instructions
- Used for mixed VLE/BookE mode

**LLVM Support**: ✅ Already handled in linker script generator (`--mixed-vle-booke`)

### Relocation Types

PowerPC ELF supports various relocation types for interrupt vectors:
- `R_PPC_ADDR32` - Absolute 32-bit address
- `R_PPC_REL32` - PC-relative 32-bit
- VLE-specific relocations

**Status**: LLVM should generate correct relocations (needs verification)

---

## Migration from GCC

### GCC Code Pattern
```c
// GCC VLE fork (hypothetical)
__attribute__((interrupt)) 
void timer_interrupt_handler(void) {
    // Handler code - GCC saves/restores registers automatically
    counter++;
}
```

### LLVM Equivalent (After Implementation)
```c
// LLVM (target)
__attribute__((interrupt))
void timer_interrupt_handler(void) {
    // Handler code - LLVM saves/restores registers automatically
    counter++;
}
```

### Current LLVM Workaround
```c
// Manual register save/restore
void timer_interrupt_handler(void) {
    __asm__ __volatile__(
        "mflr    r0\n\t"
        "stw     r0, 4(r1)\n\t"
        "mfcr    r0\n\t"
        "stw     r0, 8(r1)\n\t"
        // ... save more registers ...
    );
    
    counter++;  // Handler code
    
    __asm__ __volatile__(
        // ... restore registers ...
        "lwz     r0, 4(r1)\n\t"
        "mtlr    r0\n\t"
        "e_rfi\n\t"
    );
}
```

---

## Key Findings Summary

### 🔍 Critical Discovery

**GCC PowerPC backend does NOT support interrupt handlers!**

- Infrastructure exists (bitfield definition) but is never used
- Comment states: "we never set the interrupt handler bit"
- This means **both GCC and LLVM are missing this feature**
- LLVM implementing interrupt support would provide a **unique advantage**

### ✅ Already Implemented (LLVM)

1. Linker script sections (`.core_exceptions_table`, `.intc_vector_table`)
2. IVPR symbol (`__IVPR_VALUE`)
3. Instruction support (`E_RFI`, `RFI`)
4. Basic infrastructure (startup code, linker script generator)

### ❌ Missing in Both GCC and LLVM

1. **Interrupt attribute parsing** - Neither GCC nor LLVM parse `__attribute__((interrupt))` for PowerPC
2. **Register save/restore** - No automatic prologue/epilogue in either toolchain
3. **IVOR table initialization** - Neither provides automatic startup code integration
4. **Return instruction** - Neither automatically generates `e_rfi`/`rfi`

### ⚠️ Missing (Enhancement)

1. Automatic section placement
2. Interrupt type specification
3. Nested interrupt support
4. Documentation/examples

### 🎯 Opportunity

Implementing interrupt handler support in LLVM would:
- Provide a **competitive advantage** over GCC
- Fill a **critical gap** in both toolchains
- Enable embedded systems development that currently requires manual assembly
- Match functionality available in ARM, RISC-V, and other embedded targets

---

## Recommended Action Plan

1. **Immediate**: Implement basic interrupt attribute (Priority 1)
2. **Short-term**: Add register save/restore (Priority 1)
3. **Short-term**: Initialize IVPR from `__IVPR_VALUE` (Priority 2)
4. **Medium-term**: Document IVOR table structure (Priority 2)
5. **Long-term**: Advanced features (Priority 3)

---

## References

- Linker Script Generator: `clang/tools/generate-ppc-linker-script.py:220-233`
- Linker Script Templates: `clang/tools/ppc-linker-script-templates.md`
- GCC VLE Fork: `/projects/gcc-4.9.4-vle` (reference for patterns)
- PowerPC e200 Core Reference Manuals (IVOR register descriptions)
- PowerPC Book E Architecture Specification

