# e200 Missing Instructions - Final Verification Report

## Executive Summary

After thorough verification of the 13 instructions initially identified as "missing", the analysis reveals:

- **Actually Missing**: **3 instructions**
  - `ehpriv` - Embedded Hypervisor Privilege (Book III-E)
  - `evlddepx` - Vector Load Doubleword into Doubleword by External (Book I, E.PD)
  - `evstddepx` - Vector Store Doubleword into Doubleword by External (Book I, E.PD)

- **False Positives**: **7 instructions** (implemented but missed by comparison script)
  - `and` - AND instruction (implemented as AND, SE_AND, E_ANDI, etc.)
  - `e_or2i` - VLE OR immediate (implemented as E_OR2I in PPCInstrVLE.td)
  - `e_or2is` - VLE OR immediate shifted (implemented as E_OR2IS in PPCInstrVLE.td)
  - `e_sc` - VLE system call (implemented as SE_SC and E_SC in PPCInstrVLE.td)
  - `mulhw` - Multiply high word (implemented as MULHW in PPCInstrInfo.td line 3390)
  - `mulhwu` - Multiply high word unsigned (implemented as MULHWU in PPCInstrInfo.td line 3393)
  - `to` - Listed in Book V but appears to be a parsing artifact

- **Not Applicable**: **3 instructions** (64-bit only, e200 cores are 32-bit)
  - `mulhd` - Multiply high doubleword (64-bit only)
  - `mulhdu` - Multiply high doubleword unsigned (64-bit only)
  - `sradi` - Shift right algebraic doubleword immediate (64-bit only)

## Detailed Analysis

### Actually Missing Instructions (3)

#### 1. ehpriv - Embedded Hypervisor Privilege

- **Power ISA 2.07 Book**: III-E
- **Format**: XL
- **Category**: E.HV (Embedded Hypervisor)
- **Status**: NOT IMPLEMENTED
- **Evidence**:
  - Not found in LLVM PowerPC backend
  - Listed in powerisa_v2_07_book_III-E_complete.txt
  - Category E.HV suggests it requires hypervisor support
- **Recommendation**: 
  - Check if e200 cores support hypervisor mode
  - If required, implement in PPCInstrInfo.td with appropriate predicates

#### 2. evlddepx - Vector Load Doubleword into Doubleword by External

- **Power ISA 2.07 Book**: I
- **Format**: EVX
- **Category**: P, E.PD (Privileged, Embedded Doubleword)
- **Status**: NOT IMPLEMENTED
- **Evidence**:
  - Not found in LLVM PowerPC backend
  - Listed in powerisa_v2_07_book_I_complete.txt line 102
  - Category E.PD suggests it requires privileged mode or special feature
  - Related instructions evldd, evlddx are implemented (PPCInstrSPE.td)
- **Recommendation**:
  - Verify if e200 cores with SPE support this instruction
  - Check if E.PD feature is available on e200
  - If required, implement in PPCInstrSPE.td

#### 3. evstddepx - Vector Store Doubleword into Doubleword by External

- **Power ISA 2.07 Book**: I
- **Format**: EVX
- **Category**: P, E.PD (Privileged, Embedded Doubleword)
- **Status**: NOT IMPLEMENTED
- **Evidence**:
  - Not found in LLVM PowerPC backend
  - Listed in powerisa_v2_07_book_I_complete.txt line 233
  - Category E.PD suggests it requires privileged mode or special feature
  - Related instructions evstdd, evstddx are implemented (PPCInstrSPE.td)
- **Recommendation**:
  - Verify if e200 cores with SPE support this instruction
  - Check if E.PD feature is available on e200
  - If required, implement in PPCInstrSPE.td

### False Positives (7)

These instructions are implemented in LLVM but were missed by the comparison script due to:
- Naming differences (uppercase LLVM definitions vs lowercase ISA mnemonics)
- Variant forms (record bit, different encodings)
- Normalization issues in the comparison script

**Recommendation**: Improve comparison script to:
- Better handle case-insensitive matching
- Account for instruction variants
- Check both definition names and mnemonic strings

### Not Applicable (3)

These are 64-bit instructions that are not required for 32-bit e200 cores:
- `mulhd`, `mulhdu`: 64-bit multiply high instructions
- `sradi`: 64-bit shift right algebraic immediate

**Note**: `sradi` is implemented in LLVM but only for 64-bit targets (PPCInstr64Bit.td).

## Conclusion

The initial analysis identified 13 "missing" instructions, but verification shows:
- **Only 3 instructions are actually missing** and may require implementation
- **7 are false positives** - already implemented
- **3 are not applicable** - 64-bit only instructions

The **3 actually missing instructions** (`ehpriv`, `evlddepx`, `evstddepx`) may require:
1. Verification that e200 cores actually support them (they may be optional/privileged)
2. Confirmation of required features (hypervisor, privileged doubleword access)
3. Implementation if confirmed as required

## Next Steps

1. **Verify e200 Core Support**:
   - Check e200 core reference manuals for support of:
     - Hypervisor mode (for `ehpriv`)
     - Privileged doubleword load/store (for `evlddepx`, `evstddepx`)
   
2. **Implement if Required**:
   - Add `ehpriv` to PPCInstrInfo.td with E.HV predicate
   - Add `evlddepx` and `evstddepx` to PPCInstrSPE.td with E.PD predicate

3. **Improve Comparison Script**:
   - Better normalization (case-insensitive, handle variants)
   - Check both instruction definitions and mnemonic strings
   - Account for 64-bit vs 32-bit distinctions

## Coverage Update

With false positives removed:
- **Expected Instructions**: ~445-452 (Power ISA 2.07 minus unsupported)
- **Actually Implemented**: ~442-445
- **Actually Missing**: 3 (potentially optional/privileged)
- **Coverage**: **99.3%** (vs initial 98.5% estimate)

