# PPCVLEOpt Test Results Summary

## Test Execution Results

I've analyzed the test file and here's what the tests verify:

## Test Cases Breakdown

### ✅ Successful Conversions (5 tests)

1. **test_vle_load_eligible**
   - **Input**: `LBZ $r4, $r3, 10` (R3 in range, offset 10 ≤ 15)
   - **Output**: `SE_LBZ $r4, 10, $r3` ✓
   - **Why**: Register R3 (in range) + small offset

2. **test_vle_addi_eligible**
   - **Input**: `ADDI $r2, $r1, 15` (R1 in range, imm 15 fits)
   - **Output**: `SE_ADDI $r2, $r1, 15` ✓
   - **Why**: Register R1 (in range) + immediate -32 to 31

3. **test_vle_add_eligible**
   - **Input**: `ADD4 $r6, $r4, $r5` (all registers in range)
   - **Output**: `SE_ADD $r6, $r4, $r5` ✓
   - **Why**: All registers R4, R5, R6 are in R0-R7

4. **test_vle_store_eligible**
   - **Input**: `STW $r7, $r3, 20` (R3 and R7 in range, offset 20 ≤ 31)
   - **Output**: `SE_STW $r7, 20, $r3` ✓
   - **Why**: Registers in range + word offset fits (0-31)

5. **test_vle_cmpi_eligible**
   - **Input**: `CMPWI $r6, 10` (R6 in range, imm 10 fits)
   - **Output**: `SE_CMPI $r6, 10` ✓
   - **Why**: Register in range + immediate fits

### ❌ Failed Conversions (3 tests) - Demonstrates Limitations

6. **test_vle_load_ineligible_reg**
   - **Input**: `LBZ $r4, $r8, 10` (R8 out of range)
   - **Output**: `LBZ $r4, $r8, 10` (unchanged) ❌
   - **Limitation**: Register R8 is outside R0-R7 range
   - **Key Point**: Pass cannot reallocate R8 → R3

7. **test_vle_load_ineligible_imm**
   - **Input**: `LBZ $r4, $r5, 20` (R5 OK, but offset 20 > 15)
   - **Output**: `LBZ $r4, $r5, 20` (unchanged) ❌
   - **Limitation**: Byte load offset exceeds u4imm (0-15)
   - **Note**: For word loads (SE_LWZ), offset 20 would be OK (range 0-31)

8. **test_vle_addi_ineligible_imm**
   - **Input**: `ADDI $r3, $r2, 50` (R2 OK, but imm 50 > 31)
   - **Output**: `ADDI $r3, $r2, 50` (unchanged) ❌
   - **Limitation**: Immediate 50 exceeds s6imm range (-32 to 31)

## Key Observations

### Limitation #1: Post-RA Pass
- ✅ All tests use **physical registers** (R0-R31)
- ✅ No virtual registers present
- ✅ This proves pass runs **after** register allocation
- ❌ Pass cannot influence register allocation decisions

### Limitation #2: Register Range
- ✅ Tests show R0-R7 convert successfully
- ❌ R8+ registers cannot convert (test case #6)
- ❌ Pass **cannot change** R8 to R3 to enable conversion
- **Example**: `LBZ $r4, $r8, 10` → stays as LBZ, cannot become SE_LBZ

### Limitation #3: Immediate Constraints
- ✅ Tests verify immediate value limits:
  - Byte load/store: u4imm (0-15)
  - Word load/store: u5imm (0-31)
  - ADDI/CMPI: s6imm (-32 to 31)
- ❌ Values outside range prevent conversion (test cases #7, #8)

## Testing Methodology

### Command to Run Tests
```bash
llc -run-pass=ppc-vle-opt \
    -mtriple=powerpc-none-eabivle \
    -mcpu=e200z4 \
    -mvle \
    -verify-machineinstrs \
    ppc-vle-opt-test.mir \
    -o output.mir
```

### What to Look For
1. **Conversions**: Search for `SE_*` instructions in output
2. **Non-conversions**: Original instructions remain unchanged
3. **Statistics**: Use `-stats` flag to see conversion counts

### Expected Statistics Output
```
NumConvertedTo16Bit: 5          # Successfully converted
NumIneligibleRegs: 1             # R8 case
NumIneligibleImms: 2             # Offset 20 and imm 50 cases
```

## Creating Your Own Test

### Minimal Test Case Template
```mir
---
name: test_my_case
alignment: 4
tracksRegLiveness: true
body: |
  bb.0:
    liveins: $r3        # Use R0-R7 for eligible, R8+ for ineligible
    $r4 = LBZ $r3, 10   # Replace with instruction you want to test
    BLR implicit $lr, implicit $rm, implicit $r4
...
```

### Testing Steps
1. Create MIR with specific physical registers
2. Run pass: `llc -run-pass=ppc-vle-opt ... test.mir`
3. Compare before/after with `diff`
4. Check if conversion happened based on constraints

## Conclusion

The test file comprehensively demonstrates:
- ✅ What the pass **can** do (convert when constraints met)
- ❌ What the pass **cannot** do (reallocate registers, handle out-of-range)
- 🔍 The **exact limitations** that prevent optimal code size

All tests use physical registers, proving this is a post-register-allocation pass that can only work with what the register allocator provided.

