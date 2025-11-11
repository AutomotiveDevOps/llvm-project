# EWL Header Compatibility Fixes for LLVM/Clang

## Overview

This document describes the required fixes to make the Embedded Wrapper Library (EWL) headers compatible with LLVM/Clang compiler for PowerPC e200 VLE targets.

## Problem Statement

When building with Clang/LLVM, the EWL headers fail with the error:
```
/usr/local/s32ds-power-linux/e200_ewl2/EWL_C/include/ewlGlobals.h:29:6: error: ewlGlobals.h could not include prefix file
```

This occurs because `ewlGlobals.h` cannot determine which platform prefix file to include, as Clang doesn't define the same preprocessor macros that GCC defines automatically.

## Root Cause Analysis

### Missing Preprocessor Defines

GCC 4.9.4 (powerpc-eabivle-gcc) automatically defines the following macros for PowerPC e200 VLE targets:

```c
#define __PPC 1
#define __PPC__ 1
#define __PPCE200Z4__ 1        // CPU-specific (varies by -mcpu)
#define __PPC_EABI__ 1         // Required for EWL platform detection
#define __PPCVLE__ 1            // VLE mode indicator
#define __VLE__ 1               // Alternative VLE indicator
```

Clang/LLVM only defines:
```c
#define __POWERPC__ 1
#define __PPC__ 1
```

**Critical Missing Defines:**
- `__PPC_EABI__` - Required by `ewlGlobals.h` to select PowerPC EABI prefix file
- `__PPCVLE__` or `__VLE__` - VLE mode indicator (may be needed by prefix file)
- `__PPCE200Z4__` - CPU-specific define (needed for e200z4-specific code paths)

### EWL Header Structure

The `ewlGlobals.h` file uses a chain of `#if defined()` checks to determine the platform:

```c
#if defined(__COLDFIRE__)
    #include <coldfire/ansi_prefix.CF.h>
#elif defined(__HC12__)
    #include <s12z/ansi_prefix.S12Z.h>
#elif defined(__VSPA__)
    #include <vspa/ansi_prefix.VSPA.h>
#elif defined(__PPC_EABI__)    // <-- This check fails with Clang
    #include <pa/ansi_prefix.PA_EABI.bare.h>
#elif ...
#else
    #error ewlGlobals.h could not include prefix file
#endif
```

Since Clang doesn't define `__PPC_EABI__`, none of the platform checks match, and the `#error` is triggered.

### Prefix File Dependencies

The `ansi_prefix.PA_EABI.bare.h` file also checks for compiler-specific defines:

```c
#if defined(__GNUC__)
    #define __POWERPC__ 1
    #define __PPC_LINUXABI__ 1
    #define __PPC_EABI__ 1
    // ... other defines
#elif defined(_GHSPORT_)
    // Green Hills compiler
#else
    // Unknown compiler
#endif
```

Clang defines `__GNUC__` (for GCC compatibility), so this path should work once `__PPC_EABI__` is defined before `ewlGlobals.h` is included.

## Required Fixes

### Fix 1: Add Missing Preprocessor Defines in Build System

**Location**: `/tun/projects/vle/DEVKIT-Makefile/include.mk`

**Current State** (line 358):
```makefile
C_FLAGS += -D__PPC_EABI__                                # Required by EWL headers
```

**Issue**: 
1. This define may not be sufficient - additional defines are needed
2. The define may not be passed correctly if GCC-specific flags are not properly filtered
3. CPU-specific defines (like `__PPCE200Z4__`) are missing

**Required Fix**: Ensure all necessary defines are added for Clang builds:

```makefile
ifeq (${COMPILER},llvm)
    # LLVM/Clang-specific flags
    C_FLAGS += -target powerpc-none-eabivle
    
    # Define EWL-compatible macros (GCC defines these automatically)
    C_FLAGS += -D__PPC_EABI__=1                          # Required by ewlGlobals.h
    C_FLAGS += -D__PPCVLE__=1                            # VLE mode indicator
    C_FLAGS += -D__VLE__=1                               # Alternative VLE indicator
    C_FLAGS += -D__PPC__=1                               # PowerPC architecture (may already be defined)
    C_FLAGS += -D__PPC=1                                 # Alternative PowerPC define
    
    # CPU-specific define (extract from MACH_OPTS or set based on MCU)
    # For MPC5744P (e200z4):
    C_FLAGS += -D__PPCE200Z4__=1                        # e200z4 CPU identifier
    
    # Ensure __GNUC__ is defined for EWL compatibility (Clang defines this, but verify)
    # Clang should already define __GNUC__ and __GNUC_MINOR__ for compatibility
```

**Alternative Approach**: Create a header wrapper that defines these macros before including EWL headers.

### Fix 2: Create EWL Compatibility Header Wrapper

**Location**: Create new file `/tun/projects/vle/DEVKIT-Makefile/llvm_ewl_compat.h`

**Content**:
```c
#ifndef LLVM_EWL_COMPAT_H
#define LLVM_EWL_COMPAT_H

/*
 * LLVM/Clang Compatibility Definitions for EWL Headers
 * 
 * GCC automatically defines these macros for PowerPC e200 targets,
 * but Clang requires explicit definition.
 */

/* PowerPC EABI identification - required by ewlGlobals.h */
#ifndef __PPC_EABI__
#define __PPC_EABI__ 1
#endif

/* VLE mode indicators */
#ifndef __PPCVLE__
#define __PPCVLE__ 1
#endif

#ifndef __VLE__
#define __VLE__ 1
#endif

/* PowerPC architecture identifiers */
#ifndef __PPC__
#define __PPC__ 1
#endif

#ifndef __PPC
#define __PPC 1
#endif

/* CPU-specific defines - should be set based on actual target CPU */
/* For e200z4 (MPC5744P): */
#ifndef __PPCE200Z4__
#define __PPCE200Z4__ 1
#endif

/* Ensure GCC compatibility macros are defined */
/* Clang should define __GNUC__ automatically, but verify */
#ifndef __GNUC__
#define __GNUC__ 4
#define __GNUC_MINOR__ 9
#endif

#endif /* LLVM_EWL_COMPAT_H */
```

**Usage**: Include this header before any EWL headers in project source files, or add `-include llvm_ewl_compat.h` to compiler flags.

### Fix 3: Update ewlGlobals.h to Support Clang

**Location**: `/usr/local/s32ds-power-linux/e200_ewl2/EWL_C/include/ewlGlobals.h`

**Current Code** (lines 18-19):
```c
#elif defined(__PPC_EABI__)
    #include <pa/ansi_prefix.PA_EABI.bare.h>    /* Embedded Power Architecture */
```

**Proposed Fix**: Add Clang-specific detection as fallback:

```c
#elif defined(__PPC_EABI__)
    #include <pa/ansi_prefix.PA_EABI.bare.h>    /* Embedded Power Architecture */
#elif (defined(__POWERPC__) || defined(__PPC__)) && defined(__clang__)
    /* Clang/LLVM for PowerPC - define __PPC_EABI__ and include prefix */
    #ifndef __PPC_EABI__
    #define __PPC_EABI__ 1
    #endif
    #include <pa/ansi_prefix.PA_EABI.bare.h>    /* Embedded Power Architecture (Clang) */
```

**Note**: This requires modifying the EWL installation, which may not be desirable. Prefer Fix 1 or Fix 2.

### Fix 4: Update ansi_prefix.PA_EABI.bare.h for Clang

**Location**: `/usr/local/s32ds-power-linux/e200_ewl2/EWL_C/include/pa/ansi_prefix.PA_EABI.bare.h`

**Current Code** (line 23):
```c
#if defined(__GNUC__)
```

**Issue**: Clang defines `__GNUC__` for compatibility, so this should work. However, the prefix file may need additional Clang-specific handling.

**Proposed Enhancement**: Add explicit Clang support:

```c
#if defined(__GNUC__) || defined(__clang__)
    #ifndef __option
     #define __option(x)		x
    #endif
    #define ANSI_strict        	__STRICT_ANSI__
    // ... rest of GCC/Clang common defines
    
    #ifndef __PPC_EABI__
    #define __PPC_EABI__ 1
    #endif
    
    #ifndef __PPCVLE__
    #define __PPCVLE__ 1
    #endif
```

## Recommended Solution

**Primary Fix**: Implement **Fix 1** in the DEVKIT-Makefile build system. This is the cleanest approach as it:
- Doesn't require modifying EWL installation files
- Works for all projects using the build system
- Centralizes the fix in one location
- Maintains compatibility with GCC builds

**Implementation Steps**:

1. **Update `/tun/projects/vle/DEVKIT-Makefile/include.mk`**:
   - Add all required preprocessor defines for Clang builds
   - Extract CPU type from `MACH_OPTS` or `MCU` variable to set CPU-specific defines
   - Ensure defines are added before any source files are compiled

2. **Test with a simple project**:
   ```bash
   cd /tun/projects/vle/DEVKIT-Makefile/Examples/MPC5744P/Hello_World_PLL
   COMPILER=llvm LLVM_TOOLCHAIN_DIR=/tun/projects/vle/llvm-project2/build make clean
   COMPILER=llvm LLVM_TOOLCHAIN_DIR=/tun/projects/vle/llvm-project2/build make
   ```

3. **Verify defines are present**:
   ```bash
   COMPILER=llvm LLVM_TOOLCHAIN_DIR=/tun/projects/vle/llvm-project2/build \
   make -n 2>&1 | grep -E "__PPC_EABI__|__PPCVLE__|__VLE__"
   ```

## Additional Considerations

### CPU-Specific Defines

Different e200 cores require different CPU-specific defines:
- e200z0: `__PPCE200Z0__`
- e200z1: `__PPCE200Z1__`
- e200z2: `__PPCE200Z2__`
- e200z3: `__PPCE200Z3__`
- e200z4: `__PPCE200Z4__` (MPC5744P)
- e200z6: `__PPCE200Z6__`
- e200z7: `__PPCE200Z7__`

The build system should extract the CPU type from `MACH_OPTS` (e.g., `cpu=e200z4`) and set the appropriate define.

### VLE Mode Detection

The EWL headers may check for VLE mode using `__PPCVLE__` or `__VLE__`. Both should be defined when targeting VLE-enabled cores.

### Endianness

GCC defines `_BIG_ENDIAN` or `_LITTLE_ENDIAN` based on `-mbig` or `-mlittle`. Clang should handle this via the target triple (`powerpc-none-eabivle` is big-endian), but may need explicit defines.

## Testing Checklist

After implementing fixes:

- [ ] Simple C program compiles with Clang
- [ ] EWL headers are included without errors
- [ ] `ewlGlobals.h` successfully includes prefix file
- [ ] All EWL library functions are accessible
- [ ] Linking succeeds with EWL libraries
- [ ] Binary executes correctly (if hardware/simulator available)

## References

- EWL Header Location: `/usr/local/s32ds-power-linux/e200_ewl2/EWL_C/include/`
- Main Header: `ewlGlobals.h`
- Prefix File: `pa/ansi_prefix.PA_EABI.bare.h`
- DEVKIT-Makefile: `/tun/projects/vle/DEVKIT-Makefile/include.mk`

## Implementation Example

### Step-by-Step Fix for DEVKIT-Makefile

**File**: `/tun/projects/vle/DEVKIT-Makefile/include.mk`

**Location**: Around line 357-370 (in the `ifeq (${COMPILER},llvm)` block)

**Replace**:
```makefile
C_FLAGS += -D__PPC_EABI__                                # Required by EWL headers
```

**With**:
```makefile
# Define EWL-compatible macros (GCC defines these automatically for PowerPC e200)
# Note: Using =1 ensures the macro is defined to 1, matching GCC's behavior
C_FLAGS += -D__PPC_EABI__=1                              # Required by ewlGlobals.h (CRITICAL)
C_FLAGS += -D__PPCVLE__=1                                # VLE mode indicator
C_FLAGS += -D__VLE__=1                                   # Alternative VLE indicator
C_FLAGS += -D__PPC__=1                                   # PowerPC architecture (may already be defined by Clang)
C_FLAGS += -D__PPC=1                                     # Alternative PowerPC define

# Extract CPU type from MACH_OPTS and set CPU-specific define
# MACH_OPTS contains "cpu=e200z4" for MPC5744P
CPU_FROM_OPTS := $(filter cpu=%,${MACH_OPTS})
CPU_TYPE := $(patsubst cpu=%,%,$(firstword ${CPU_FROM_OPTS}))
ifeq (${CPU_TYPE},e200z4)
    C_FLAGS += -D__PPCE200Z4__=1
else ifeq (${CPU_TYPE},e200z0)
    C_FLAGS += -D__PPCE200Z0__=1
else ifeq (${CPU_TYPE},e200z1)
    C_FLAGS += -D__PPCE200Z1__=1
else ifeq (${CPU_TYPE},e200z2)
    C_FLAGS += -D__PPCE200Z2__=1
else ifeq (${CPU_TYPE},e200z3)
    C_FLAGS += -D__PPCE200Z3__=1
else ifeq (${CPU_TYPE},e200z6)
    C_FLAGS += -D__PPCE200Z6__=1
else ifeq (${CPU_TYPE},e200z7)
    C_FLAGS += -D__PPCE200Z7__=1
endif
```

**Alternative Simpler Approach** (if CPU extraction is complex):

```makefile
# Define EWL-compatible macros
C_FLAGS += -D__PPC_EABI__=1
C_FLAGS += -D__PPCVLE__=1
C_FLAGS += -D__VLE__=1
C_FLAGS += -D__PPC__=1
C_FLAGS += -D__PPC=1

# For MPC5744P (e200z4) - can be made configurable per MCU
# TODO: Extract from MCU or CPU variable
C_FLAGS += -D__PPCE200Z4__=1
```

## Current State Analysis

**Current Implementation** (line 358 of `include.mk`):
- `-D__PPC_EABI__` is being added (without `=1`)
- This define is present in the build command (verified in `.args` files)
- However, the build still fails, indicating additional defines are needed

**Why Current Fix Isn't Working:**
1. The define `-D__PPC_EABI__` (without value) should work, but `-D__PPC_EABI__=1` matches GCC's behavior more closely
2. Missing `__PPCVLE__` and `__VLE__` defines may be required by the prefix file
3. Missing CPU-specific define (`__PPCE200Z4__`) may be needed for e200z4-specific code paths
4. The prefix file `ansi_prefix.PA_EABI.bare.h` checks for `__GNUC__` which Clang defines, but may need the above defines to be set before it's included

## Verification

After implementing the fix, verify the defines are present:

```bash
cd /tun/projects/vle/DEVKIT-Makefile/Examples/MPC5744P/Hello_World_PLL
COMPILER=llvm LLVM_TOOLCHAIN_DIR=/tun/projects/vle/llvm-project2/build make clean
COMPILER=llvm LLVM_TOOLCHAIN_DIR=/tun/projects/vle/llvm-project2/build make src/platform_inits.o
cat src/platform_inits.o.args | grep -E "__PPC|__VLE|__EABI"
```

**Current output** (before fix):
```
-D__PPC_EABI__
```

**Expected output** (after fix):
```
-D__PPC_EABI__=1
-D__PPCVLE__=1
-D__VLE__=1
-D__PPCE200Z4__=1
```

**Test compilation**:
```bash
COMPILER=llvm LLVM_TOOLCHAIN_DIR=/tun/projects/vle/llvm-project2/build make
```

Should compile without the `ewlGlobals.h could not include prefix file` error.

## Summary

The primary issue is that Clang doesn't automatically define `__PPC_EABI__` and related PowerPC/VLE macros that GCC defines. The fix is to explicitly define these macros in the Clang compiler command line via the build system. This can be done by updating the DEVKIT-Makefile to add the necessary `-D` flags for Clang builds.

**Key Missing Defines:**
- `__PPC_EABI__` - **Critical**: Required by `ewlGlobals.h` to select PowerPC EABI platform
- `__PPCVLE__` or `__VLE__` - VLE mode indicators
- `__PPCE200Z4__` - CPU-specific identifier (varies by target CPU)

Once these defines are added, the EWL headers should compile successfully with Clang.

