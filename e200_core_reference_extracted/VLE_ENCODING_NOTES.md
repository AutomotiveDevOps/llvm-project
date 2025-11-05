# VLE Instruction Encoding Notes

## Source
Based on VLE Programming Interface Manual (vlepim) Appendix A and other Core Reference Manuals.

## Implemented Instructions

### e_bc (Branch Conditional - 32-bit) ✅ IMPLEMENTED
From vlepim Appendix A, Figure A-1:
```
Bits 0-5:   011110 (0x1E = 30) - Primary opcode
Bits 6-9:   1010 (0xA = 10) - Extended opcode/VLE identifier
Bits 10-11: BO32 (2 bits) - Branch option
Bits 12-15: BI32 (4 bits) - Condition register bit
Bits 16-30: BD15 (15 bits) - Branch displacement
Bit 31:     LK (1 bit) - Link bit (0 for e_bc, 1 for e_bcl)
```
**Status**: Implemented in `PPCInstrVLE.td` with verified encoding

### e_bcl (Branch Conditional and Link - 32-bit) ✅ IMPLEMENTED
Same as e_bc but with LK=1.
**Status**: Implemented in `PPCInstrVLE.td` with verified encoding

### se_bc (Branch Conditional - 16-bit) ⏳ PENDING
From vlepim Appendix A, Figure A-1:
```
Bits 0-4:   11110 (0x1E = 30) - Primary opcode (5 bits for 16-bit)
Bits 5:      BO16 (1 bit) - Branch option
Bits 6-7:    BI16 (2 bits) - Condition register bit (CR0 only)
Bits 8-15:   BD8 (8 bits) - Branch displacement
```
**Status**: Encoding format known, pending implementation

### e_b / e_bl (Unconditional Branch) ⏳ PENDING
**Status**: Encoding format needs extraction from Core Reference Manuals

## Pending Instructions (Encodings Need Extraction)

### Arithmetic Instructions
- e_addi, e_addic, e_subfic
- e_andi, e_ori, e_xori
**Status**: Format classes defined, encodings need verification

### Load/Store Instructions
- e_lbzu, e_lhzu, e_lwzu
- e_stbu, e_sthu, e_stwu
- e_lmw, e_stmw

### Compare Instructions
- e_cmpi, e_cmpli, e_cmp16i, e_cmph16i, e_cmphl16i, e_cmpl16i

### Condition Register Instructions
- e_crand, e_crandc, e_creqv, e_crnand, e_crnor, e_cror, e_crorc, e_crxor

### Other Instructions
- e_li, e_lis, e_mcrf
- e_mulli, e_mull2i
- e_sc, e_rfi

## Key Findings

From VLE Programming Interface Manual Chapter 3:
- VLE instructions from primary opcode 31 are encoded identically in 32-bit VLE instructions
- Primary opcode 4 is available for additional instructions with identical encodings
- Most VLE instructions have different encodings than standard Book E instructions

## Implementation Status

VLE instruction encodings are being extracted from:
- VLE Programming Interface Manual (vlepim) ✅ Referenced
- VLE Execution Model Manual (vlepem)  
- e200 Core Reference Manuals (z0, z1, z3, z4, z759, z760)
- Embedded Reference Manual (erefrm) ✅ Referenced
- Power ISA 2.07 Book VLE specification

## Notes

- VLE uses both 16-bit and 32-bit instruction formats
- 16-bit instructions are prefixed with `se_` (short encoding)
- 32-bit instructions that differ from Book E are prefixed with `e_`
- VLE instructions are selected at the memory page level (page attribute bit)
- Same opcode can mean different things depending on page attribute
- Encodings need verification against actual hardware specifications

