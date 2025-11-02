# PowerPC e200 Reference Documentation URLs

Quick reference for all available documentation sources.

## Available Documents (Can Be Downloaded)

### e200z0 Core Reference Manual
- **URL**: https://www.elektronikjk.com/elementy_czynne/IC/E200Z0.pdf
- **Source**: Freescale (e200z0CORERM Rev. 0 4/2008)
- **Status**: ✅ URL Found
- **Contents**:
  - Chapter 1: e200z0 and e200z0h Overview
  - Chapter 2: Register Model
  - Chapter 3: Instruction Model (including VLE)
  - Chapter 4: Instruction Pipeline and Execution Timing
  - Chapter 5: Interrupts and Exceptions
  - Chapter 6: Core Complex Interfaces
  - Chapter 7: Power Management
  - Chapter 8: Debug Support
  - Chapter 9: Nexus 2+ Module

### e200z6 Core Reference Manual
- **URL**: https://web.eecs.umich.edu/~jfr/embeddedctrls/files/E200Z6_RM.pdf
- **Source**: Freescale/NXP
- **Status**: ✅ URL Found
- **Contents**: 7-stage single-issue pipeline details, unified 32KB L1 cache

### VLE Programming Interface Manual (VLEPIM)
- **URL**: https://www.nxp.com/docs/en/supporting-information/VLEPIM.pdf
- **Source**: NXP
- **Status**: ✅ URL Found
- **Contents**: Complete VLE instruction set reference with encoding details

## Needed Documents (URLs Not Available)

### PowerPC Book E Specification
- **Source**: IBM/NXP Power Architecture specifications
- **Status**: ⚠️ URL Needed
- **Contents**: Book E architecture specification including VLE appendix

### e200z4 Core Reference Manual
- **Source**: NXP/Freescale
- **Status**: ⚠️ URL Needed
- **Contents**: 5-stage dual-issue pipeline, SPE, FPU timing

## Download Instructions

Once downloaded, place all PDF files in:
```
/projects/llvm-project/llvm/lib/Target/PowerPC/reference/
```

## Usage Priority

1. **HIGH Priority** (Required for VLE implementation):
   - PowerPC Book E Specification
   - VLE Programming Interface Manual (VLEPIM.pdf)

2. **MEDIUM Priority** (Needed for scheduling refinement):
   - e200z0 Core Reference Manual ✅ Available
   - e200z4 Core Reference Manual ⚠️ Needed
   - e200z6 Core Reference Manual ✅ Available

