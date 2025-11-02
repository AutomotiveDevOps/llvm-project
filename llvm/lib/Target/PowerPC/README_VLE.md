# PowerPC VLE Backend Implementation

## Overview

This document describes the implementation of VLE (Variable Length Encoding) support
in the PowerPC backend. VLE is an instruction set extension for PowerPC e200 cores
designed to reduce code size by 20-30% through the use of 16-bit and 32-bit
instruction formats.

## VLE Instruction Formats

VLE instructions can be either 16-bit or 32-bit:

- **16-bit instructions**: Use the `se_` prefix (e.g., `se_addi`, `se_bl`)
- **32-bit instructions**: Use the `e_` prefix (e.g., `e_add`, `e_bl`)
- **Mixed mode**: Both formats can be used in the same function/compilation unit

## Instruction Selection

VLE instructions are defined in `PPCInstrVLE.td` using TableGen. The instruction
selection process:

1. **Feature Detection**: VLE mode is enabled via the `HasVLE` subtarget feature
2. **Pattern Matching**: DAG patterns match IR operations to VLE instructions
3. **Instruction Selection**: The instruction selector chooses VLE forms when
   beneficial for code size

### Key Files

- `PPCInstrVLE.td` - VLE instruction definitions and patterns
- `PPCSubtarget.cpp/h` - VLE feature detection and CPU variant support
- `PPCISelLowering.cpp` - Instruction selection and lowering logic
- `PPCInstrInfo.cpp` - VLE instruction encoding/decoding support

## VLE vs Standard PowerPC Mode

### Differences

- **Instruction encoding**: VLE uses 16/32-bit formats vs 32-bit only for standard
- **Register access**: VLE has restrictions on which registers can be used
- **Code size**: VLE instructions are typically smaller
- **Performance**: Standard PowerPC may be faster due to simpler decode

### Mode Selection

VLE mode is controlled by:

- Target triple: `powerpc-none-eabivle` enables VLE by default
- Command-line: `-mvle` / `-mno-vle` flags
- Subtarget feature: `HasVLE` feature flag

## Code Size Optimization

VLE instructions are prioritized when:

- `-Oz` optimization flag is used
- `-mvle` is explicitly enabled
- Function-level optimization hints suggest code size matters

The instruction selector considers:

- Instruction size (16-bit vs 32-bit)
- Register pressure
- Execution frequency (from profile data if available)

## Scheduling Models

Separate scheduling models exist for e200 cores:

- `PPCScheduleE200Z0.td` - e200z0 (4-stage pipeline)
- `PPCScheduleE200Z4.td` - e200z4 (5-stage dual-issue)
- `PPCScheduleE200Z6.td` - e200z6 (7-stage single-issue)

Each model defines:
- Pipeline stages and functional units
- Instruction latencies
- Bypass paths
- Resource constraints

## Instruction Encoding

VLE instructions are encoded according to the PowerPC Book E specification,
VLE Appendix, and VLEPIM (VLE Programming Interface Manual).

### 16-bit Format Example

```
se_addi rD, rA, SIMM
Bit pattern: [0-4][5-9][10-15]
            opcode   rD   rA/SIMM
```

### 32-bit Format Example

```
e_add rD, rA, rB
Bit pattern: [0-5][6-10][11-15][16-20][21-31]
            opcode   rD    rA    rB    extended
```

## Testing VLE Code Generation

### Verify VLE Instructions

```bash
clang -target powerpc-none-eabivle -mcpu=e200z4 -mvle -S test.c
# Check test.s for se_* or e_* prefixed instructions
```

### Check Object File

```bash
llvm-objdump -d test.o | grep -E "(se_|e_)"
# Should show VLE instruction encodings
```

### Test Patterns

Add tests in `llvm/test/CodeGen/PowerPC/vle/`:

```llvm
; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle < %s | FileCheck %s

define i32 @test_add(i32 %a, i32 %b) {
  %sum = add i32 %a, %b
  ret i32 %sum
}
; CHECK: e_add
```

## Known Limitations

- Not all PowerPC instructions have VLE equivalents
- Some operations require mode switching (performance impact)
- VLE register constraints may prevent optimal register allocation
- Floating-point VLE support varies by e200 core variant

## Future Work

- Improved code size optimization heuristics
- Additional VLE instruction patterns
- Better register allocation for VLE constraints
- Profile-guided code size optimization

## References

- PowerPC Book E Enhanced Architecture (VLE Appendix)
- VLE Programming Interface Manual (VLEPIM)
- e200 Core Reference Manuals
- `llvm/lib/Target/PowerPC/reference/README.md` for documentation sources

