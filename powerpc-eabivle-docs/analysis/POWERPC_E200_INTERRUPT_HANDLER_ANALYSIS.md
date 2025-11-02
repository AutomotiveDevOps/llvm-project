# PowerPC e200 Interrupt Handler Support - Detailed Analysis

## Overview

This document provides a detailed analysis of missing interrupt handler support for PowerPC e200 cores and outlines a comprehensive implementation plan based on patterns from other LLVM targets (RISC-V, ARM, AVR).

---

## Current Status

**Status**: ❌ Completely Missing  
**Impact**: Critical for embedded systems development

### What's Missing

1. No `__attribute__((interrupt))` parsing in Clang
2. No interrupt handler detection in frame lowering
3. No automatic register save/restore
4. No IVOR table initialization in startup code
5. No `e_rfi` instruction generation for interrupt returns

---

## PowerPC e200 Interrupt Architecture

### IVOR (Interrupt Vector Offset Register) System

PowerPC e200 cores use the Book E architecture interrupt model with IVOR (Interrupt Vector Offset Register) table instead of standard PowerPC exception vectors.

**Key Registers**:
- **IVPR** (Interrupt Vector Prefix Register): Base address for interrupt vectors
- **IVORx** registers: Offset registers for different exception types
  - IVOR0: Critical Input
  - IVOR1: Machine Check
  - IVOR2: Data Storage
  - IVOR3: Instruction Storage
  - IVOR4: External Input
  - ... (up to IVOR63)
- **SRR0/SRR1**: Save/Restore Registers (return address and MSR)
- **MCSRR0/MCSRR1**: Machine Check Save/Restore Registers

### Interrupt Handler Requirements

For PowerPC e200 interrupt handlers, the following registers must be saved/restored:

1. **Link Register (LR)** - Always required
2. **Condition Register (CR)** - Always required  
3. **General Purpose Registers (GPRs)** - All registers used by the handler
4. **MSR bits** - Saved automatically by hardware in SRR1/MCSRR1

### Return from Interrupt

- **Standard PowerPC**: Uses `rfi` (Return From Interrupt) instruction
- **VLE Mode**: Uses `e_rfi` instruction (defined in `PPCInstrVLE.td:1355-1358`)

---

## Implementation Plan

### Phase 1: Clang Attribute Support

#### 1.1 Define PowerPC Interrupt Attribute

**File**: `clang/include/clang/Basic/Attr.td`

Add a new attribute definition following the pattern of RISC-V:

```tablegen
def PowerPCInterrupt : InheritableAttr {
  let Spellings = [GCC<"interrupt">];
  let Subjects = SubjectList<[Function]>;
  let Args = [OptionalStringArgument<"InterruptType">];
  let Documentation = [PowerPCInterruptDocs];
  let HasCustomParsing = 1;
}
```

**Interrupt Types** (optional):
- `"critical"` - Critical interrupt (non-maskable)
- `"external"` - External interrupt (IVOR4)
- Default: Standard interrupt

#### 1.2 Implement Attribute Parser

**File**: `clang/lib/Sema/SemaDeclAttr.cpp`

Add handler function:

```cpp
static void handlePowerPCInterruptAttr(Sema &S, Decl *D,
                                       const ParsedAttr &AL) {
  if (!isa<FunctionDecl>(D)) {
    S.Diag(AL.getLoc(), diag::warn_attribute_wrong_decl_type)
        << AL << ExpectedFunction;
    return;
  }
  
  FunctionDecl *FD = cast<FunctionDecl>(D);
  
  // Validate function signature
  if (!FD->getReturnType()->isVoidType()) {
    S.Diag(AL.getLoc(), diag::err_interrupt_not_void);
    return;
  }
  
  if (!FD->param_empty()) {
    S.Diag(AL.getLoc(), diag::err_interrupt_has_params);
    return;
  }
  
  // Parse optional interrupt type
  StringRef Kind = "standard";
  if (AL.hasArg(0)) {
    Kind = AL.getArgAsString(0);
    if (!(Kind == "critical" || Kind == "external")) {
      S.Diag(AL.getLoc(), diag::err_interrupt_unknown_kind) << Kind;
      return;
    }
  }
  
  D->addAttr(::new (S.Context) PowerPCInterruptAttr(S.Context, AL, Kind));
}
```

#### 1.3 Add Attribute Documentation

**File**: `clang/include/clang/Basic/AttrDocs.td`

```tablegen
def PowerPCInterruptDocs : Documentation {
  let Category = DocCatFunction;
  let Heading = "interrupt";
  let Content = [{
The ``interrupt`` attribute indicates that the function is an interrupt handler.
The compiler generates appropriate prologue/epilogue code to save and restore
all registers used by the function.

For PowerPC e200 cores, this attribute:
- Saves/restores Link Register (LR)
- Saves/restores Condition Register (CR)  
- Saves/restores all General Purpose Registers used by the handler
- Generates ``e_rfi`` instruction for return (VLE mode) or ``rfi`` (standard mode)

The attribute accepts an optional argument specifying the interrupt type:
- ``"critical"`` - Critical interrupt (non-maskable)
- ``"external"`` - External interrupt handler
- Default - Standard interrupt handler

Example:
\code
__attribute__((interrupt)) void timer_handler(void) {
    // Interrupt handler code
}

__attribute__((interrupt("external"))) void uart_handler(void) {
    // External interrupt handler
}
\endcode
  }];
}
```

---

### Phase 2: LLVM Backend Support

#### 2.1 Register Save Lists for Interrupt Handlers

**File**: `llvm/lib/Target/PowerPC/PPCCallingConv.td` (or create new file)

Define interrupt handler callee-saved register lists:

```tablegen
// Standard interrupt handler - save all GPRs, LR, CR
def CSR_PPC32_Interrupt : CalleeSavedRegs<(add
  LR,           // Link Register
  CTR,          // Count Register
  CR2, CR3, CR4, CR5, CR6, CR7,  // Condition Register fields
  R14, R15, R16, R17, R18, R19, R20, R21, R22, R23,
  R24, R25, R26, R27, R28, R29, R30, R31
)>;

// VLE interrupt handler - same but note VLE-specific constraints
def CSR_PPC32_VLE_Interrupt : CalleeSavedRegs<(add CSR_PPC32_Interrupt)>;
```

**File**: `llvm/lib/Target/PowerPC/PPCRegisterInfo.cpp`

Modify `getCalleeSavedRegs()`:

```cpp
const MCPhysReg *
PPCRegisterInfo::getCalleeSavedRegs(const MachineFunction *MF) const {
  const PPCSubtarget &Subtarget = MF->getSubtarget<PPCSubtarget>();
  
  // Check if this is an interrupt handler
  if (MF->getFunction().hasFnAttribute("interrupt")) {
    if (Subtarget.hasVLE())
      return CSR_PPC32_VLE_Interrupt_SaveList;
    return CSR_PPC32_Interrupt_SaveList;
  }
  
  // ... existing callee-saved register logic ...
}
```

#### 2.2 Frame Lowering - Prologue/Epilogue

**File**: `llvm/lib/Target/PowerPC/PPCFrameLowering.cpp`

**Modify `determineCalleeSaves()`**:

```cpp
void PPCFrameLowering::determineCalleeSaves(MachineFunction &MF,
                                            BitVector &SavedRegs,
                                            RegScavenger *RS) const {
  TargetFrameLowering::determineCalleeSaves(MF, SavedRegs, RS);
  
  // Interrupt handlers must save all used registers
  if (MF.getFunction().hasFnAttribute("interrupt")) {
    const PPCSubtarget &STI = MF.getSubtarget<PPCSubtarget>();
    
    // Always save LR and CR
    SavedRegs.set(PPC::LR);
    SavedRegs.set(PPC::CR0);  // Save entire CR (all fields)
    SavedRegs.set(PPC::CR1);
    SavedRegs.set(PPC::CR2);
    SavedRegs.set(PPC::CR3);
    SavedRegs.set(PPC::CR4);
    SavedRegs.set(PPC::CR5);
    SavedRegs.set(PPC::CR6);
    SavedRegs.set(PPC::CR7);
    
    // Save all GPRs that might be used
    // In practice, register allocator will determine which are actually used
    // but for interrupt handlers, we're conservative and save all
    if (MF.getFrameInfo().hasCalls()) {
      // If handler makes calls, must save all caller-saved registers
      for (unsigned Reg = PPC::R14; Reg <= PPC::R31; ++Reg)
        SavedRegs.set(Reg);
    }
    
    // TODO: Save floating-point registers if FPU present and used
  }
}
```

**Modify `emitEpilogue()`** to generate `e_rfi` or `rfi`:

```cpp
MachineBasicBlock::iterator
PPCFrameLowering::emitEpilogue(MachineFunction &MF,
                               MachineBasicBlock &MBB) const {
  // ... existing epilogue code ...
  
  // Check if this is an interrupt handler
  if (MF.getFunction().hasFnAttribute("interrupt")) {
    const PPCInstrInfo &TII = *STI.getInstrInfo();
    const PPCSubtarget &Subtarget = MF.getSubtarget<PPCSubtarget>();
    
    // Generate return from interrupt instruction
    if (Subtarget.hasVLE()) {
      // VLE mode: use e_rfi
      BuildMI(MBB, MBBI, DL, TII.get(PPC::E_RFI))
        .addReg(PPC::LR, RegState::Implicit);
    } else {
      // Standard mode: use rfi
      BuildMI(MBB, MBBI, DL, TII.get(PPC::RFI))
        .addReg(PPC::LR, RegState::Implicit);
    }
    
    // Don't generate normal return
    return MBBI;
  }
  
  // ... existing return logic ...
}
```

#### 2.3 Instruction Selection - Validate Interrupt Handlers

**File**: `llvm/lib/Target/PowerPC/PPCISelLowering.cpp`

Add validation in `LowerFormalArguments()`:

```cpp
const Function &Func = MF.getFunction();
if (Func.hasFnAttribute("interrupt")) {
  if (!Func.arg_empty()) {
    report_fatal_error(
      "Functions with the interrupt attribute cannot have arguments!");
  }
  
  if (!Func.getReturnType()->isVoidTy()) {
    report_fatal_error(
      "Functions with the interrupt attribute must have void return type!");
  }
  
  StringRef Kind = 
    MF.getFunction().getFnAttribute("interrupt").getValueAsString();
  
  // Validate interrupt type
  if (!Kind.empty() && 
      !(Kind == "critical" || Kind == "external" || Kind == "standard")) {
    report_fatal_error(
      "PowerPC interrupt attribute argument not supported: " + Kind);
  }
}
```

---

### Phase 3: Startup Code - IVOR Table Initialization

#### 3.1 IVOR Table Structure

The IVOR table must be initialized with interrupt handler function pointers. The table structure depends on which IVORs are used.

**Example IVOR table layout**:
```c
// IVOR table - interrupt vector addresses
// Base address set in IVPR register
typedef void (*interrupt_handler_t)(void);

__attribute__((section(".ivor_table")))
interrupt_handler_t ivor_table[64] = {
  [0] = critical_interrupt_handler,      // IVOR0
  [1] = machine_check_handler,            // IVOR1
  [2] = data_storage_handler,             // IVOR2
  [3] = instruction_storage_handler,      // IVOR3
  [4] = external_interrupt_handler,       // IVOR4
  // ... other handlers ...
};
```

#### 3.2 Startup Code Modification

**File**: `compiler-rt/lib/crt/crt0_ppc.S`

Add IVOR table initialization section (or create separate file):

```assembly
.section .ivor_table, "a", @progbits
.align 4
.global __ivor_table
__ivor_table:
    // IVOR0 - Critical Input
    .long critical_interrupt_handler
    // IVOR1 - Machine Check
    .long machine_check_handler
    // IVOR2 - Data Storage
    .long data_storage_handler
    // IVOR3 - Instruction Storage
    .long instruction_storage_handler
    // IVOR4 - External Input
    .long external_interrupt_handler
    // ... initialize remaining IVORs ...
    
    // Initialize IVPR (Interrupt Vector Prefix Register)
    // IVPR contains base address of interrupt vector table
    lis     %r3, __ivor_table@h
    ori     %r3, %r3, __ivor_table@l
    mtspr   63, %r3  // SPR 63 is IVPR
```

**Alternative**: Provide C helper function:

**File**: `compiler-rt/lib/crt/crt0_ppc.c`

```c
#include <stdint.h>

// Weak symbols for interrupt handlers - user can override
__attribute__((weak)) void critical_interrupt_handler(void) {
    while(1) {} // Default: infinite loop
}

__attribute__((weak)) void machine_check_handler(void) {
    while(1) {}
}

// ... other default handlers ...

// IVOR table
__attribute__((section(".ivor_table"))) 
void (*const ivor_table[64])(void) = {
    [0] = critical_interrupt_handler,
    [1] = machine_check_handler,
    // ... initialize table ...
};

void __attribute__((weak)) init_ivor_table(void) {
    // Set IVPR to point to ivor_table
    uint32_t ivpr = (uint32_t)(uintptr_t)ivor_table;
    __asm__ __volatile__("mtspr 63, %0" : : "r" (ivpr));
}
```

---

### Phase 4: Testing

#### 4.1 Attribute Parsing Tests

**File**: `clang/test/Sema/ppc-interrupt-attr.c`

```c
// RUN: %clang_cc1 -fsyntax-only -verify %s

// Valid interrupt handler
__attribute__((interrupt)) void valid_handler(void) {}

// Error: has return value
__attribute__((interrupt)) int invalid_return(void) { return 0; } // expected-error {{interrupt attribute requires void return type}}

// Error: has parameters
__attribute__((interrupt)) void invalid_params(int x) {} // expected-error {{interrupt attribute requires no parameters}}

// Valid with interrupt type
__attribute__((interrupt("critical"))) void critical_handler(void) {}
__attribute__((interrupt("external"))) void external_handler(void) {}

// Error: unknown interrupt type
__attribute__((interrupt("unknown"))) void bad_handler(void) {} // expected-error {{unknown interrupt type}}
```

#### 4.2 Code Generation Tests

**File**: `llvm/test/CodeGen/PowerPC/interrupt-handler.ll`

```llvm
; RUN: llc -mtriple=powerpc-none-eabivle %s -o - | FileCheck %s

define void @test_interrupt() #0 {
; CHECK-LABEL: test_interrupt:
; CHECK: mflr r0
; CHECK: stw r0, {{[0-9]+}}(r1)
; CHECK: # ... register saves ...
; CHECK: # handler body
; CHECK: # ... register restores ...
; CHECK: e_rfi
  ret void
}

attributes #0 = { interrupt }
```

#### 4.3 Integration Tests

Create test cases for:
- Basic interrupt handler with register save/restore
- VLE mode interrupt handler (uses `e_rfi`)
- Standard mode interrupt handler (uses `rfi`)
- Critical vs standard interrupt handlers
- Interrupt handlers that make function calls

---

## Implementation Complexity

### Estimated Effort

1. **Clang Attribute Support**: 2-3 days
   - Attribute definition and parsing
   - Validation logic
   - Documentation

2. **LLVM Backend Support**: 3-4 days
   - Register save list definitions
   - Frame lowering modifications
   - Instruction selection validation
   - Return instruction generation

3. **Startup Code**: 1-2 days
   - IVOR table initialization
   - Helper functions

4. **Testing**: 2-3 days
   - Unit tests
   - Code generation tests
   - Integration tests

**Total**: ~8-12 days of development work

---

## Comparison with Other Targets

### RISC-V Implementation Pattern

**What RISC-V does**:
1. ✅ Defines interrupt attribute in `Attr.td`
2. ✅ Validates function signature (void, no params)
3. ✅ Saves all caller-saved registers in frame lowering
4. ✅ Generates special return instruction (`mret`, `sret`, `uret`)
5. ✅ Has separate callee-saved register list for interrupts

**PowerPC e200 should do**:
1. ✅ Define interrupt attribute (similar)
2. ✅ Validate function signature (similar)
3. ✅ Save LR, CR, and used GPRs (PowerPC-specific)
4. ✅ Generate `rfi`/`e_rfi` instruction (PowerPC-specific)
5. ✅ Initialize IVOR table (PowerPC Book E-specific)

### AVR Implementation Pattern

**What AVR does**:
1. Uses `AFI->isInterruptHandler()` to detect interrupts
2. Generates special prologue code for interrupt handlers
3. Saves R1, R0, SREG registers first

**PowerPC e200 should do**:
1. Use `hasFnAttribute("interrupt")` (already standard pattern)
2. Generate prologue saving LR, CR, GPRs
3. Generate epilogue restoring registers and `rfi`/`e_rfi`

---

## Open Questions / Design Decisions

1. **Register Save Strategy**:
   - **Option A**: Save all GPRs (conservative, simpler)
   - **Option B**: Save only registers actually used (optimal, complex)
   - **Recommendation**: Start with Option A, optimize to Option B later

2. **IVOR Table Initialization**:
   - **Option A**: Initialize in `crt0` automatically
   - **Option B**: Provide helper function, user calls it
   - **Option C**: Document requirements, user implements
   - **Recommendation**: Option B - provide helper, user can override

3. **Interrupt Type Handling**:
   - Currently only defines "critical" and "external"
   - May need more types based on actual e200 usage
   - **Recommendation**: Start minimal, extend as needed

4. **Floating-Point Register Saving**:
   - Should interrupt handlers save FP registers?
   - **Recommendation**: Yes, if FPU present and handler uses FP

---

## Success Criteria

Implementation is complete when:

1. ✅ `__attribute__((interrupt))` compiles without errors
2. ✅ Interrupt handlers save/restore LR, CR, and used GPRs
3. ✅ `e_rfi` generated for VLE mode, `rfi` for standard mode
4. ✅ IVOR table can be initialized (via helper function)
5. ✅ Test suite passes
6. ✅ Documentation complete

---

## References

- RISC-V Implementation: `llvm/lib/Target/RISCV/RISCVFrameLowering.cpp:533-560`
- AVR Implementation: `llvm/lib/Target/AVR/AVRFrameLowering.cpp:61-66`
- PowerPC e200 Core Reference Manuals (IVOR register descriptions)
- PowerPC Book E Architecture Specification
- `PPCInstrVLE.td:1355-1358` - `E_RFI` instruction definition

