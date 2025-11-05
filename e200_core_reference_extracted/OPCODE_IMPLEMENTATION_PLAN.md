# Opcode Implementation Plan

## Overview

This document outlines the plan for implementing all opcodes from the Core Reference Manuals for e200 cores. The extracted documentation contains comprehensive instruction lists that must be implemented in LLVM's PowerPC backend.

## Extraction Results

### Instruction Counts

- **Power ISA 2.07 List**: 797 instructions
- **Core Reference Manuals**:
  - z0: ~2,675 potential instructions
  - z1: ~2,784 potential instructions  
  - z3: ~3,677 potential instructions
  - z4: ~3,868 potential instructions
  - z759: ~4,244 potential instructions
  - z760: ~4,552 potential instructions
- **Power ISA 2.07 Chapters**: ~3,174 potential instructions
- **VLE Manuals**: 
  - vlepim: ~1,233 instructions
  - vlepem: ~1,563 instructions

**Total Unique Extracted**: ~7,371 (includes false positives from text parsing)

**Current LLVM Definitions**: ~1,681 instruction definitions

### Note on Extraction

The extraction process includes some false positives (common words, etc.) from parsing text. The actual instruction count is lower, but comprehensive. Manual review of the extracted list is needed to identify truly missing opcodes.

## Implementation Strategy

### 1. VLE Instructions (e_* prefix)

VLE (Variable Length Encoding) instructions are critical for e200 cores. Examples:
- `e_addi`, `e_addic`, `e_andi`, `e_b`, `e_bc`, `e_cmpi`, `e_cmpli`
- `e_lbzu`, `e_lhzu`, `e_lwzu`, `e_stbu`, `e_sthu`, `e_stwu`
- `e_mulli`, `e_ori`, `e_subfic`, `e_xori`
- `e_lmw`, `e_stmw`, `e_sc`

**Implementation Location**: `llvm/lib/Target/PowerPC/PPCInstrInfo.td` or a new `PPCInstrVLE.td`

### 2. SPE Instructions (ef* and ev* prefixes)

SPE (Signal Processing Extension) instructions:
- EFPU (Embedded Floating-Point): `efd*`, `efs*` instructions
- SPE vector: `ev*` instructions

**Implementation Location**: `llvm/lib/Target/PowerPC/PPCInstrSPE.td`

### 3. Book E Instructions

Standard PowerPC Book E instructions that may be missing.

### 4. Core-Specific Instructions

Instructions specific to individual e200 cores (z0-z7 variants).

## Implementation Process

### Step 1: Identify Missing Opcodes

1. Review extracted opcodes list: `e200_core_reference_extracted/extracted_opcodes.txt`
2. Cross-reference with existing LLVM definitions in:
   - `PPCInstrInfo.td`
   - `PPCInstrSPE.td`
   - `PPCInstrVSX.td`
   - Other `PPCInstr*.td` files
3. Check instruction reference chapters in Core Reference Manuals:
   - z759: Chapter 12 (Instruction Reference)
   - z760: Chapter 11 (Instruction Reference)
   - Other cores: Last chapters typically contain instruction references

### Step 2: Implement Each Opcode

For each missing opcode:

1. **Reference Documentation**: Check the appropriate Core Reference Manual chapter
2. **Define Instruction Format**: Use TableGen syntax in appropriate `.td` file
3. **Define Encoding**: Specify opcode, extended opcode, and field encoding
4. **Define Operands**: Specify register classes and immediate constraints
5. **Define Scheduling**: Add to appropriate scheduling model (PPCScheduleE500.td for e200)
6. **Feature Gating**: Ensure instruction is properly gated with:
   - `FeatureISA2_07` (all e200 cores)
   - `FeatureBookE` (Book E instructions)
   - `FeatureSPE` (SPE instructions)
   - `FeatureVLE` (VLE instructions, if feature exists)
   - Core-specific features

### Step 3: Testing

1. Create test cases for each implemented instruction
2. Verify encoding matches manual specifications
3. Verify scheduling information is correct
4. Test code generation for each instruction

## Key Documentation References

### Core Reference Manuals
- **z0**: `e200_core_reference_extracted/z0/`
- **z1**: `e200_core_reference_extracted/z1/`
- **z3**: `e200_core_reference_extracted/z3/`
- **z4**: `e200_core_reference_extracted/z4/`
- **z759**: `e200_core_reference_extracted/z759/` (most comprehensive)
- **z760**: `e200_core_reference_extracted/z760/`

### Architecture Manuals
- **Power ISA 2.07**: `e200_core_reference_extracted/powerisa_v2_07/`
- **Book E**: `e200_core_reference_extracted/book_e/`
- **VLE**: `e200_core_reference_extracted/vlepim/`, `e200_core_reference_extracted/vlepem/`

### Instruction Lists
- `powerisa_v2_07_instruction_list.txt` (root directory)
- `e200_core_reference_extracted/extracted_opcodes.txt` (extracted list)

## Implementation Priority

### High Priority (Critical for e200 cores)
1. VLE instructions (e_* prefix) - Required for e200 cores
2. Basic SPE instructions (efd*, efs*, ev* core set)
3. Book E instructions commonly used in embedded code

### Medium Priority
1. Extended SPE instructions
2. Core-specific optimizations
3. Advanced VLE forms

### Low Priority
1. Rarely used instructions
2. Deprecated instruction forms
3. Architecture extensions not commonly used

## ISA Version Enforcement

**CRITICAL**: All e200 core opcodes must use **Power ISA 2.07 only**. 

- All e200 core processor models now include `FeatureISA2_07`
- No e200 cores should use ISA 3.0, 3.1, or future ISAs
- Instructions requiring higher ISA versions must NOT be enabled for e200 cores

## Automation

The script `scripts/extract_opcodes.py` can be run to:
1. Extract instruction lists from documentation
2. Compare with existing LLVM definitions
3. Generate updated extraction lists

Run: `python3 scripts/extract_opcodes.py`

## Next Steps

1. **Systematic Review**: Manually review extracted opcodes to identify truly missing instructions
2. **Prioritize**: Focus on VLE and critical SPE instructions first
3. **Implement**: Add missing opcodes systematically, referencing Core Reference Manuals
4. **Test**: Verify each implementation with test cases
5. **Document**: Update this plan as implementation progresses

## Notes

- This is an ongoing effort due to the large number of opcodes
- Each opcode should reference its source in the Core Reference Manuals
- Implementation should follow existing LLVM PowerPC patterns
- All opcodes must be properly feature-gated for e200 cores

