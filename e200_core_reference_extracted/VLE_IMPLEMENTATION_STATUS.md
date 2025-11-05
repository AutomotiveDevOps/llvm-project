# VLE Instruction Implementation Status

## Overview

Initial implementation of VLE (Variable Length Encoding) instructions for e200 cores has been started. This document tracks the implementation progress.

## Completed

### Infrastructure
- ✅ Created `PPCInstrVLE.td` file for VLE instruction definitions
- ✅ Included VLE instructions in `PPCInstrInfo.td`
- ✅ Established instruction format classes for VLE:
  - `VLE_SCI8Form` - Scaled Immediate 8-bit format
  - `VLE_BD15Form` - Branch Displacement 15-bit format
  - `VLE_BForm` - Unconditional branch format
- ✅ Feature gating: All VLE instructions require `IsBookE` and `IsISA2_07`

### Implemented Instructions (Initial Framework)

#### Arithmetic Instructions
- `e_addi` - Add Scaled Immediate (E_ADDI)
- `e_addic` - Add Scaled Immediate Carrying (E_ADDIC)
- `e_subfic` - Subtract From Scaled Immediate Carrying (E_SUBFIC)

#### Logical Instructions
- `e_andi` - AND Scaled Immediate (E_ANDI)
- `e_ori` - OR Scaled Immediate (E_ORI)
- `e_xori` - XOR Scaled Immediate (E_XORI)

#### Branch Instructions
- `e_b` - Branch unconditional (E_B)
- `e_bl` - Branch and Link (E_BL)
- `e_bc` - Branch Conditional (E_BC)
- `e_bcl` - Branch Conditional and Link (E_BCL)

## Pending Implementation

### High Priority
1. **Load/Store Instructions**
   - `e_lbzu` - Load Byte with Update Zero
   - `e_lhzu` - Load Halfword with Update Zero
   - `e_lwzu` - Load Word with Update Zero
   - `e_stbu` - Store Byte with Update
   - `e_sthu` - Store Halfword with Update
   - `e_stwu` - Store Word with Update

2. **Load/Store Multiple**
   - `e_lmw` - Load Multiple Word
   - `e_stmw` - Store Multiple Word

3. **Compare Instructions**
   - `e_cmpi` - Compare Immediate
   - `e_cmpli` - Compare Logical Immediate
   - `e_cmp16i` - Compare 16-bit Immediate
   - `e_cmph16i` - Compare Halfword 16-bit Immediate
   - `e_cmphl16i` - Compare Halfword Logical 16-bit Immediate
   - `e_cmpl16i` - Compare Logical 16-bit Immediate

4. **Condition Register Instructions**
   - `e_crand` - Condition Register AND
   - `e_crandc` - Condition Register AND with Complement
   - `e_creqv` - Condition Register Equivalence
   - `e_crnand` - Condition Register NAND
   - `e_crnor` - Condition Register NOR
   - `e_cror` - Condition Register OR
   - `e_crorc` - Condition Register OR with Complement
   - `e_crxor` - Condition Register XOR
   - `e_mcrf` - Move Condition Register Field

5. **Move Instructions**
   - `e_li` - Load Immediate
   - `e_lis` - Load Immediate Shifted
   - `e_mulli` - Multiply Immediate
   - `e_mull2i` - Multiply Immediate (variant)

6. **System Instructions**
   - `e_sc` - System Call
   - `e_rfi` - Return From Interrupt (VLE form)

### Medium Priority
- Additional arithmetic operations
- Shift and rotate instructions
- 16-bit VLE instructions (se_* prefix)

### Low Priority
- Rarely used VLE instruction forms
- Simplified mnemonics

## Encoding Verification Required

**CRITICAL**: The instruction encodings in the current implementation are **initial estimates** and must be verified against:

1. **Power ISA Version 2.07 Book VLE** specification
   - Located in: `e200_core_reference_extracted/powerisa_v2_07/`
   - Chapter with VLE instruction encodings

2. **e200 Core Reference Manuals**
   - z0, z1, z3, z4, z759, z760 Core Reference Manuals
   - Instruction reference chapters contain encoding details

3. **VLE Programming Interface Manual**
   - Located in: `e200_core_reference_extracted/vlepim/`
   - Contains instruction format specifications

## Next Steps

1. **Verify Encodings**: Review actual VLE instruction encoding specifications from Core Reference Manuals
2. **Fix Format Classes**: Update `VLE_SCI8Form`, `VLE_BD15Form`, `VLE_BForm` with correct bit field assignments
3. **Implement Load/Store**: Add load and store instructions with proper addressing modes
4. **Add Tests**: Create test cases for each implemented instruction
5. **Implement Remaining**: Continue with compare, condition register, and system instructions

## References

- Implementation Plan: `e200_core_reference_extracted/OPCODE_IMPLEMENTATION_PLAN.md`
- Extracted Opcodes: `e200_core_reference_extracted/extracted_opcodes.txt`
- Core Reference Manuals: `e200_core_reference_extracted/` (z0, z1, z3, z4, z759, z760)
- VLE Manuals: `e200_core_reference_extracted/vlepim/`, `e200_core_reference_extracted/vlepem/`

## Notes

- All VLE instructions are gated with `IsBookE` and `IsISA2_07` predicates
- VLE instructions are available on all e200 cores (e200z0 through e200z7)
- VLE instructions use 16-bit and 32-bit encodings for improved code density
- The actual instruction formats may differ from initial estimates - verification required

