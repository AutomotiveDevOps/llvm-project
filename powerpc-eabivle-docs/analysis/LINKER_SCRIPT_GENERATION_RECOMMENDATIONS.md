# PowerPC Linker Script Generation - Recommendations

## Summary

After analyzing 45+ linker scripts from PlatformIO PowerPC examples, a clear pattern emerges:
- **~90% of content is identical** across different MCUs
- **Variations** are primarily:
  - Memory sizes/addresses (MCU-specific)
  - Optional sections (RCHW, reset vectors, local DMEM)
  - Mixed VLE/BookE mode configurations

## Recommendation: Hybrid Approach

### ✅ Use Generator Script for Projects

**Keep the generator script** (`generate-ppc-linker-script.py`) as the primary tool for creating linker scripts:

1. **Efficiency**: Generate 95% of the boilerplate automatically
2. **Consistency**: Ensures all scripts follow the same pattern
3. **Maintainability**: Update template once, regenerate all
4. **Customization**: Easy to add new MCU configs

### ⚠️ Keep Source Templates for Special Cases

**Store as source** only for:
- Highly customized linker scripts with non-standard sections
- Project-specific memory layouts that differ significantly from standard
- Reference examples for complex configurations (e.g., mixed VLE/BookE)

## Implementation Strategy

### 1. Generator Script (✅ Created)

**Location**: `clang/tools/generate-ppc-linker-script.py`

**Features**:
- Pre-configured MCU templates (mpc5643l, mpc5646c, mpc5748g, mpc5744p, mpc5775k)
- Custom memory layout support
- Mixed VLE/BookE mode support
- Custom heap/stack sizing

**Usage**:
```bash
# Standard usage
generate-ppc-linker-script.py --mcu mpc5748g -o linker.ld

# Custom configuration
generate-ppc-linker-script.py --mcu mpc5748g \
    --heap-size 8192 --stack-size 16384 \
    --flash-base 0x1000000 --ram-base 0x40000000 \
    -o linker.ld
```

### 2. Integration with Clang Toolchain (Future Enhancement)

**Optional**: Integrate automatic generation when `-T` is not specified:

```cpp
// In BareMetal::Linker::ConstructJob()
if (!Args.hasArg(options::OPT_T)) {
    // Generate default linker script for MCU
    std::string DefaultLinkerScript = generateDefaultLinkerScript(Triple);
    CmdArgs.push_back(Args.MakeArgString("-T" + DefaultLinkerScript));
}
```

**Pros**:
- Zero-configuration for common MCUs
- Better developer experience

**Cons**:
- Requires Python in build environment
- May hide important memory layout details

**Recommendation**: **Keep manual for now**, document the generator tool clearly.

### 3. Template Library

**Provide templates** for common configurations:
- `templates/mpc5748g.ld.in` - Template with variables
- `templates/mixed-vle-booke.ld.in` - Mixed mode template
- `templates/minimal.ld.in` - Minimal template

Users can customize templates or use the generator.

## Comparison: Generator vs Source Templates

| Aspect | Generator Script | Source Templates |
|--------|------------------|------------------|
| **Setup Time** | Fast (one command) | Manual copy/edit |
| **Consistency** | High (same structure) | Variable (copy-paste errors) |
| **Maintenance** | Easy (update script) | Hard (update many files) |
| **Customization** | CLI flags | Manual editing |
| **Version Control** | Small (one script) | Large (many .ld files) |
| **Special Cases** | Requires script changes | Easy to modify |

## Best Practices

### For New Projects

1. **Start with generator**:
   ```bash
   generate-ppc-linker-script.py --mcu mpc5748g -o linker.ld
   ```

2. **Customize if needed**:
   - Edit generated `linker.ld` for project-specific sections
   - Or regenerate with custom flags

3. **Version control**:
   - Commit the generated `linker.ld`
   - Or commit MCU config and regenerate (if script is available)

### For Existing Projects

1. **Keep existing linker scripts** if they work
2. **Regenerate periodically** to pick up improvements
3. **Compare differences** to ensure no regressions

## Common Patterns Identified

### Standard Sections (95% identical across all scripts)
- `.startup` - Startup code
- `.core_exceptions_table` - Core exceptions
- `.intc_vector_table` - Interrupt vectors
- `.text` - Code
- `.rodata` - Read-only data
- `.data` - Initialized data (with AT> for load address)
- `.bss` - Uninitialized data
- `.stack` - Stack and heap

### MCU-Specific Variations

1. **Memory Layouts**:
   - Flash base/size (varies by MCU)
   - RAM base/size (varies by MCU)
   - Local DMEM (some MCUs have it)

2. **Special Sections**:
   - `.rchw` - Reset configuration halfword (MPC5643L, MPC5748G, etc.)
   - `.cpu0_reset_vector` - CPU0 reset vector (MPC5748G, MPC5744P)
   - `.spt` - SPT commands (MPC5775K)

3. **Mixed Mode**:
   - `.text_vle` vs `.text_booke` - Separate sections for VLE/BookE

### Required Symbols for crt0

The generator ensures these symbols are provided:
- `__DATA_SRAM_ADDR` / `__data_start__` - .data start in RAM
- `__DATA_ROM_ADDR` / `__data_load__` - .data load address in Flash
- `__BSS_START` / `__bss_start__` - .bss start
- `__BSS_END` / `__bss_end__` - .bss end
- `_stack_addr` / `_stack_top` - Stack top

**Note**: The generator provides `__DATA_SRAM_ADDR` and `__DATA_ROM_ADDR`, but crt0 expects `__data_start__` and `__data_load__`. We should either:
1. Add aliases in the generator
2. Update crt0 to use the generated symbols

**Recommendation**: Add aliases in the generator for compatibility.

## Conclusion

**Primary Recommendation**: **Use the generator script** for most projects.

**Rationale**:
- The vast majority of linker script content is boilerplate
- Manual maintenance of many similar files is error-prone
- Generator provides consistency and easy updates
- Source templates remain useful for reference and special cases

**Next Steps**:
1. ✅ Generator script created
2. ✅ Documentation provided
3. ⚠️ Add symbol aliases for crt0 compatibility
4. 📝 Consider toolchain integration (optional)

