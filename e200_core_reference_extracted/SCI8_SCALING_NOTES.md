# SCI8 Scaling Logic Documentation

## Overview

SCI8 (Scaled Immediate 8-bit) format is used in VLE instructions to encode immediate values efficiently using scaling. The format allows encoding a wider range of immediate values by using a fill bit (F) and scale bits (SCL) along with an 8-bit immediate (UI8).

## Format Structure

From Power ISA 2.07 Book VLE Chapter 5, Section 1.4.16:

```
Bits 0-5:   Primary opcode (6)
Bits 6-10:  RT/RS (register)
Bits 11-15: RA (register)
Bits 16-19: Extended opcode (XO)
Bit 20:     Rc (record bit)
Bit 21:     F (fill bit, 1 bit)
Bits 22-23: SCL (scale bits, 2 bits)
Bits 24-31: UI8 (8-bit unsigned immediate)
```

## Encoding Formula

The scaled immediate value `sci8` is formed from F, UI8, and SCL fields as:

```
sci8 = (56-SCL×8 bits of F) || UI8 || (SCL×8 bits of F)
```

Where:
- SCL = 0: No shift (sci8 = 56 bits of F || UI8 || 0 bits)
- SCL = 1: Shift by 8 bits (sci8 = 48 bits of F || UI8 || 8 bits of F)
- SCL = 2: Shift by 16 bits (sci8 = 40 bits of F || UI8 || 16 bits of F)
- SCL = 3: Shift by 24 bits (sci8 = 32 bits of F || UI8 || 24 bits of F)

## Examples

For a value of 0x1234:
- SCL = 2 (shift 16): F = 0x12 (high byte), UI8 = 0x34 (low byte)
- Result: sci8 = 0x0000000000001234

For a value of 0x000000FF:
- SCL = 0 (no shift): F = 0, UI8 = 0xFF
- Result: sci8 = 0x00000000000000FF

## Current Implementation Status

**MVP (Phase 1)**: Basic implementation
- F = 0 (always)
- SCL = 0 (no scaling)
- UI8 = immediate value (for values 0-255)
- This allows encoding immediate values in the range 0-255 without scaling

**Future Enhancement**: Full scaling logic
- Implement algorithm to find best SCL value (0, 1, 2, or 3)
- Extract F and UI8 values from immediate
- Handle values that require scaling
- Implement in encoder/assembler (likely in PPCMCCodeEmitter.cpp or PPCAsmParser.cpp)

## Implementation Location

The SCI8 scaling logic should be implemented in:
1. **Encoder**: `llvm/lib/Target/PowerPC/MCTargetDesc/PPCMCCodeEmitter.cpp`
   - When encoding immediate operands for SCI8 format instructions
   - Calculate F, SCL, and UI8 from the immediate value

2. **Assembler**: `llvm/lib/Target/PowerPC/AsmParser/PPCAsmParser.cpp`
   - When parsing SCI8 immediate operands
   - Validate that immediate can be encoded in SCI8 format

3. **Instruction Selector**: May need to prefer SCI8 instructions when immediate fits

## Algorithm (Future Implementation)

For encoding an immediate value `imm` into SCI8 format:

1. Try SCL = 0: Check if `imm` fits in 8 bits (0-255)
   - If yes: F = 0, UI8 = imm, SCL = 0
   
2. Try SCL = 1: Check if `imm` can be encoded with 8-bit shift
   - Extract high byte: F = (imm >> 8) & 0xFF
   - Extract low byte: UI8 = imm & 0xFF
   - Check if middle bits are all F
   
3. Try SCL = 2: Check if `imm` can be encoded with 16-bit shift
   - Extract high 16 bits: F = (imm >> 16) & 0xFF
   - Extract low 8 bits: UI8 = imm & 0xFF
   - Check if middle bits are all F
   
4. Try SCL = 3: Check if `imm` can be encoded with 24-bit shift
   - Extract high 24 bits: F = (imm >> 24) & 0xFF
   - Extract low 8 bits: UI8 = imm & 0xFF
   - Check if middle bits are all F

5. If no SCL value works, the immediate cannot be encoded in SCI8 format

## References

- Power ISA Version 2.07 Book VLE, Chapter 5, Section 1.4.16 (SCI8-form)
- Power ISA Version 2.07 Book VLE, Chapter 5, Section 5.6 (Fixed-Point Compare instructions)
- Power ISA Version 2.07 Book VLE, Chapter 1, Section 1.4.19 (Instruction Fields)

