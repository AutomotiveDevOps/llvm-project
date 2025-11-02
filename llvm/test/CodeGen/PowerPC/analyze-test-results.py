#!/usr/bin/env python3
"""
Analyze PPCVLEOpt test file and show expected results
This demonstrates what the tests verify without needing built tools
"""

import re
import sys

def analyze_test_file(filename):
    """Parse the MIR test file and show what each test case does"""
    
    print("=" * 70)
    print("PPCVLEOpt Test File Analysis")
    print("=" * 70)
    print()
    
    with open(filename, 'r') as f:
        content = f.read()
    
    # Split by function boundaries
    functions = re.split(r'^---\n', content, flags=re.MULTILINE)
    
    test_cases = []
    for func in functions[1:]:  # Skip first empty/header
        # Extract function name
        name_match = re.search(r'^name:\s+(\S+)', func, re.MULTILINE)
        if not name_match:
            continue
        
        func_name = name_match.group(1)
        
        # Extract comment describing the test
        comment_match = re.search(r'^#\s*(Test case:.*)', func, re.MULTILINE)
        description = comment_match.group(1) if comment_match else "No description"
        
        # Extract instructions
        body_match = re.search(r'body:\s*\|\s*\n(.*?)(?:^\.\.\.|\Z)', func, re.MULTILINE | re.DOTALL)
        if not body_match:
            continue
        
        body = body_match.group(1)
        
        # Extract CHECK expectations
        check_lines = re.findall(r';\s*CHECK[^:]*:\s*(.+)', body)
        
        # Extract actual instructions (non-comment lines in body)
        instructions = []
        for line in body.split('\n'):
            line = line.strip()
            if line and not line.startswith(';') and not line.startswith('#'):
                # Clean up the instruction
                inst = line.split(';')[0].strip()  # Remove inline comments
                if inst:
                    instructions.append(inst)
        
        # Extract register info from liveins
        liveins_match = re.search(r'liveins:\s*\n\s*-\s*{\s*reg:\s*[\'"]?(\$?\w+)', func, re.MULTILINE)
        registers = []
        if liveins_match:
            registers.append(liveins_match.group(1))
        # Also get from liveins in body
        body_liveins = re.findall(r'liveins:\s*(\$r\d+)', body)
        registers.extend(body_liveins)
        
        test_cases.append({
            'name': func_name,
            'description': description,
            'registers': list(set(registers)),
            'instructions': instructions,
            'check_expectations': check_lines
        })
    
    # Display results
    for i, test in enumerate(test_cases, 1):
        print(f"Test Case {i}: {test['name']}")
        print("-" * 70)
        print(f"Description: {test['description']}")
        print(f"Registers used: {', '.join(test['registers']) if test['registers'] else 'None specified'}")
        print()
        
        print("Input Instructions:")
        for inst in test['instructions']:
            # Highlight key parts
            if 'LBZ' in inst or 'STW' in inst or 'ADDI' in inst or 'ADD4' in inst or 'CMPWI' in inst:
                print(f"  {inst}")
            else:
                print(f"  {inst}")
        print()
        
        print("Expected Output (from CHECK directives):")
        for check in test['check_expectations']:
            if 'CHECK-NOT' in check:
                print(f"  ❌ Must NOT contain: {check.split('CHECK-NOT:')[1].strip()}")
            elif 'SE_' in check:
                print(f"  ✓ Should convert to: {check}")
            else:
                print(f"  → Should remain: {check}")
        print()
        
        # Analyze what limitation this tests
        if 'ineligible' in test['name']:
            if 'reg' in test['name']:
                print("🔍 Tests Limitation #2: Register range (R8+ cannot convert)")
            elif 'imm' in test['name']:
                print("🔍 Tests: Immediate value constraints")
        else:
            print("🔍 Tests: Successful conversion when constraints are met")
        
        print()
        print("=" * 70)
        print()
    
    # Summary
    print("SUMMARY")
    print("=" * 70)
    print()
    print(f"Total test cases: {len(test_cases)}")
    print()
    print("What these tests demonstrate:")
    print()
    print("1. POST-RA LIMITATION:")
    print("   - All test cases use PHYSICAL registers (R0-R7 or R8+)")
    print("   - No virtual registers → shows pass runs after register allocation")
    print()
    print("2. REGISTER RANGE CONSTRAINT:")
    eligible = [t for t in test_cases if 'eligible' in t['name'] and 'ineligible' not in t['name']]
    ineligible_reg = [t for t in test_cases if 'ineligible_reg' in t['name']]
    print(f"   - {len(eligible)} cases with R0-R7 → convert to SE_*")
    print(f"   - {len(ineligible_reg)} case(s) with R8+ → stay as standard instructions")
    print()
    print("3. IMMEDIATE CONSTRAINT:")
    ineligible_imm = [t for t in test_cases if 'ineligible_imm' in t['name']]
    print(f"   - {len(ineligible_imm)} case(s) with large immediate → no conversion")
    print()
    print("4. NO REALLOCATION LIMITATION:")
    print("   - Test 'test_vle_load_ineligible_reg' shows R8 cannot be changed")
    print("   - Pass sees R8, cannot convert, cannot fix it")
    print()
    
    print("To run these tests, you need:")
    print("  1. Built LLVM with PowerPC target")
    print("  2. llc tool available")
    print("  3. Run: llc -run-pass=ppc-vle-opt -mtriple=powerpc-none-eabivle")
    print("          -mcpu=e200z4 -mvle -verify-machineinstrs ppc-vle-opt-test.mir")
    print()

if __name__ == '__main__':
    test_file = 'ppc-vle-opt-test.mir'
    if len(sys.argv) > 1:
        test_file = sys.argv[1]
    
    try:
        analyze_test_file(test_file)
    except FileNotFoundError:
        print(f"Error: Test file '{test_file}' not found")
        print(f"Looking in: {sys.path[0]}")
        sys.exit(1)
    except Exception as e:
        print(f"Error analyzing file: {e}")
        import traceback
        traceback.print_exc()
        sys.exit(1)

