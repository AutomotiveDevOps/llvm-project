# PowerPC e200 Reference Documentation

This directory contains reference documentation for PowerPC e200 cores and VLE (Variable Length Encoding) support.

## Required Documentation

### PowerPC Book E Specification
- **Status**: ⚠️ NOT FOUND - Needs to be obtained
- **Purpose**: Architectural specification for Book E, including VLE appendix
- **Location**: Should be placed here once obtained
- **Usage**: Primary reference for VLE instruction encoding and architectural details
- **Priority**: HIGH - Required for VLE implementation

### VLE Programming Interface Manual (VLEPIM)
- **Status**: ✅ DOWNLOADED - Available in reference directory
- **URL**: https://www.nxp.com/docs/en/supporting-information/VLEPIM.pdf
- **File**: `VLEPIM.pdf` (905K)
- **Purpose**: Complete VLE instruction set reference with encoding details
- **Location**: `/projects/llvm-project/llvm/lib/Target/PowerPC/reference/VLEPIM.pdf`
- **Usage**: VLE instruction definitions, instruction selection, disassembler
- **Priority**: HIGH - Required for VLE implementation

### GCC VLE Fork Source Code
- **Location**: `/projects/gcc-4.9.4-vle`
- **Status**: ✅ LOCATION CONFIRMED - GCC 4.9.4 with VLE modifications
- **Findings**: 
  - This is the actual VLE fork (not `/projects/gcc`)
  - Contains standard PowerPC backend with e500/e500mc/e5500 support
  - VLE implementation details need further analysis
  - Key files: `gcc/config/rs6000/rs6000.c` (34,552 lines), `rs6000.md` (15,940 lines)
- **Usage**: Reference for VLE instruction encoding patterns and code generation strategies
- **Analysis Status**: Initial search completed - detailed VLE pattern analysis pending

## e200 Processor Documentation Sources

### NXP/Freescale Documentation

#### e200z0 Core Reference Manual
- **Status**: ✅ DOWNLOADED - Available in reference directory
- **URL**: https://www.elektronikjk.com/elementy_czynne/IC/E200Z0.pdf
- **File**: `E200Z0_Core_Reference_Manual.pdf` (3.4M)
- **Purpose**: 4-stage pipeline details, VLE timing, instruction model
- **Source**: Freescale (e200z0CORERM Rev. 0 4/2008)
- **Location**: `/projects/llvm-project/llvm/lib/Target/PowerPC/reference/E200Z0_Core_Reference_Manual.pdf`
- **Contents**: 
  - e200z0 and e200z0h Overview
  - Register Model
  - Instruction Model (including VLE)
  - Instruction Pipeline and Execution Timing
  - Interrupts and Exceptions
  - Core Complex Interfaces
  - Power Management
  - Debug Support
  - Nexus 2+ Module
- **Priority**: MEDIUM - Needed for scheduling refinement

#### e200z4 Core Reference Manual
- **Status**: ⚠️ NOT FOUND - Needs to be obtained
- **Purpose**: 5-stage dual-issue pipeline, SPE, FPU timing
- **Source**: NXP/Freescale
- **Priority**: MEDIUM - Needed for scheduling refinement

#### e200z6 Core Reference Manual
- **Status**: ✅ DOWNLOADED - Available in reference directory
- **URL**: https://web.eecs.umich.edu/~jfr/embeddedctrls/files/E200Z6_RM.pdf
- **File**: `E200Z6_Core_Reference_Manual.pdf` (2.7M)
- **Purpose**: 7-stage single-issue pipeline, unified cache
- **Location**: `/projects/llvm-project/llvm/lib/Target/PowerPC/reference/E200Z6_Core_Reference_Manual.pdf`
- **Note**: **IMPORTANT**: e200z6 is 7-stage **single-issue**, not dual-issue
- **Priority**: MEDIUM - Needed for scheduling refinement and correction

## Implementation Notes

### e200 Core Variants
- **e200z0**: 4-stage pipeline, VLE-focused, minimal features (no MMU/cache/FPU)
- **e200z4**: 5-stage **dual-issue** pipeline, SPE, FPU, I-cache, VLE support
- **e200z6**: 7-stage **single-issue** pipeline, FPU, unified 32KB L1 cache, 32-entry MMU, VLE support
- **e200z3**: TODO - Future support
- **e200z7**: TODO - Future support

**Important**: e200z6 scheduling model needs correction - it's single-issue, not dual-issue.

### VLE (Variable Length Encoding)
VLE is a critical feature for e200 cores, providing:
- 16-bit and 32-bit instruction formats
- Significant code size reduction for embedded applications
- Instruction set optimized for small code footprint

The VLE instruction set is documented in the PowerPC Book E specification, VLE Appendix.

## Links
- [NXP PowerPC e200 Documentation](https://www.nxp.com/products/processors-and-microcontrollers/power-architecture-processors/powerpc-cores/e200-powerpc-core:E200_POWERPC_CORE)
- [Freescale/NXP Technical Documentation](https://www.nxp.com/support/developer-resources)

