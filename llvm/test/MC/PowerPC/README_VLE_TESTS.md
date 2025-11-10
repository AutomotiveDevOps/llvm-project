# VLE Instruction Encoding Tests

## Overview

This directory contains tests for PowerPC VLE (Variable Length Encoding) instruction encoding and disassembly for e200 cores.

## Current Status

The test file `vle-encoding.s` has been created with comprehensive test cases for all currently implemented VLE instructions. However, these tests cannot run yet because:

1. **Assembler Parser Support**: The PowerPC assembler parser (`PPCAsmParser.cpp`) does not yet recognize VLE instruction mnemonics (e.g., `e_addi`, `e_lbz`). This is Phase 4.1 work from the implementation plan.

2. **Target Triple**: The correct target triple for VLE may need to be `powerpc-none-eabivle` or similar, but this needs verification once assembler support is added.

## Test File Structure

The test file `vle-encoding.s` includes tests for:

- **Arithmetic Instructions**: E_ADDI, E_ADDIC, E_SUBFIC, E_SUBI
- **Logical Instructions**: E_ANDI, E_ORI, E_XORI
- **Load Instructions**: E_LBZ, E_LHZ, E_LWZ, E_LBZU, E_LHZU, E_LWZU
- **Store Instructions**: E_STB, E_STH, E_STW, E_STBU, E_STHU, E_STWU
- **Immediate Instructions**: E_LI, E_LIS, E_OR2I
- **Branch Instructions**: E_B, E_BL, E_BC, E_BCL
- **System Instructions**: E_RFI, E_SC
- **Compare Instructions**: E_CMP16I

## Next Steps

To make these tests functional:

1. **Phase 4.1**: Implement assembler parser support for VLE instructions in `PPCAsmParser.cpp`
2. **Phase 4.2**: Verify disassembler can decode VLE instructions correctly
3. **Phase 4.3**: Verify code emitter produces correct encodings

Once assembler support is added, these tests should run with:

```bash
llvm-mc -triple powerpc-none-eabivle -mcpu=e200z0 -show-encoding vle-encoding.s
```

## Test Format

Tests follow the standard LLVM MC test format:
- `# RUN:` directives specify how to run the test
- `# CHECK:` directives verify expected output
- Instructions are tested for correct encoding

## References

- Implementation Plan: `fix-build-sh-and-add-tools.plan.md` Phase 13.1
- VLE Instruction Definitions: `llvm/lib/Target/PowerPC/PPCInstrVLE.td`

