# PowerPC EABI/VLE Documentation

This directory contains all documentation specific to the PowerPC e200 EABI/VLE fork of LLVM. The documentation is organized into several categories for easy navigation.

## Directory Structure

### `analysis/`
Analysis documents and reports:
- **ANALYSIS_REPORT.md** - Comprehensive analysis of VLE implementation status, PlatformIO compatibility, and production readiness
- **CODE_SIZE_OPTIMIZATION_COMPLETE.md** - Documentation of completed code size optimization features
- **CODE_SIZE_OPTIMIZATION_REQUIREMENTS.md** - Requirements and implementation plan for VLE code size optimization
- **GCC_BINUTILS_INTERRUPT_ANALYSIS.md** - Analysis of GCC/binutils interrupt handler support for comparison
- **LINKER_SCRIPT_GENERATION_RECOMMENDATIONS.md** - Recommendations for linker script generation approach
- **POWERPC_E200_CORE_CONCERNS.md** - Three critical areas of concern in the e200 core port
- **POWERPC_E200_EABI_IMPROVEMENTS.md** - Comprehensive list of improvement areas for e200 EABI implementation
- **POWERPC_E200_INTERRUPT_HANDLER_ANALYSIS.md** - Detailed analysis of missing interrupt handler support
- **SOURCE_CODE_ANALYSIS.md** - Overall source code analysis of the LLVM PowerPC fork

### `user-guides/`
User-facing documentation (RST format for Sphinx):
- **EmbeddedPowerPC.rst** - Main user guide for PowerPC embedded development
- **EmbeddedPowerPCQuickStart.rst** - Quick start guide for PowerPC embedded targets
- **HowToBuildPowerPCEmbedded.rst** - Build instructions for PowerPC embedded toolchain
- **MigratingFromGCCPowerPCVLE.rst** - Migration guide from GCC VLE fork

### `implementation/`
Implementation status and technical documentation:
- **README_VLE_STATUS.md** - Current status of VLE implementation features
- **README_VLE.md** - Overview of VLE (Variable Length Encoding) support
- **VLE_WHY.md** - Historical context and rationale for VLE implementation
- **VLEPEM_IMPLEMENTATION_ASSESSMENT.md** - Detailed assessment of VLEPEM specification compliance

### `reference/`
Reference materials and specifications:
- **README.md** - Index of reference documentation
- **ANALYSIS.md** - Analysis of reference materials
- **URLS.md** - URLs for reference documentation
- **GCC_VLE_ANALYSIS.md** - Analysis of GCC VLE fork source code
- **PowerPC_BookE_Enhanced_PowerPC_Architecture.pdf** - Book E architecture specification
- **VLEPIM.pdf** - VLE Programming Interface Manual
- **E200Z0_Core_Reference_Manual.pdf** - e200z0 core reference manual
- **E200Z3_Core_Reference_Manual.pdf** - e200z3 core reference manual
- **E200Z4_Core_Reference_Manual.pdf** - e200z4 core reference manual
- **E200Z6_Core_Reference_Manual.pdf** - e200z6 core reference manual

### `tools/`
Tool-specific documentation:
- **ppc-linker-script-templates.md** - Linker script template documentation

### `examples/`
Example-specific documentation:
- **README.md** - PowerPC Embedded examples README

## Quick Navigation

### Getting Started
1. Read `user-guides/EmbeddedPowerPCQuickStart.rst` for a quick introduction
2. Review `user-guides/EmbeddedPowerPC.rst` for comprehensive usage documentation
3. Check `implementation/README_VLE_STATUS.md` for current feature status

### Understanding the Implementation
1. Start with `implementation/README_VLE.md` for VLE overview
2. Read `implementation/VLEPEM_IMPLEMENTATION_ASSESSMENT.md` for compliance details
3. Review `analysis/ANALYSIS_REPORT.md` for overall implementation analysis

### Planning Improvements
1. Review `analysis/POWERPC_E200_EABI_IMPROVEMENTS.md` for improvement areas
2. Check `analysis/CODE_SIZE_OPTIMIZATION_REQUIREMENTS.md` for optimization roadmap
3. Read `analysis/POWERPC_E200_CORE_CONCERNS.md` for critical concerns

### Reference Materials
1. See `reference/README.md` for an index of reference documents
2. Check `reference/URLS.md` for documentation URLs
3. Review PDF manuals in `reference/` as needed

## Document Formats

- **Markdown (.md)**: Analysis documents, status reports, and documentation
- **ReStructuredText (.rst)**: User guides (integrated with LLVM's Sphinx documentation)
- **PDF**: Reference manuals and specifications

## Related Code Locations

While documentation is consolidated here, related code can be found in:

- `llvm/lib/Target/PowerPC/` - PowerPC backend implementation
- `clang/lib/Driver/ToolChains/BareMetal.cpp` - Bare metal toolchain support
- `compiler-rt/lib/crt/` - Startup code for bare metal
- `clang/docs/` - Main Clang documentation (non-PowerPC specific)
- `llvm/docs/` - Main LLVM documentation (non-PowerPC specific)

## Maintenance

This documentation directory should be updated whenever:
- New PowerPC e200/VLE features are implemented
- Analysis documents are created or updated
- User guides are enhanced
- Reference materials are added

For questions or updates, refer to the individual document authors or maintainers.

