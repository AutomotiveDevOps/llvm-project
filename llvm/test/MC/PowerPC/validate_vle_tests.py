#!/usr/bin/env python3
"""
Validation script for VLE instruction encoding tests.

This script validates the structure and format of VLE test files
without requiring the assembler to be functional.

Usage:
    python3 validate_vle_tests.py vle-encoding.s
"""

import sys
import re
from typing import List, Tuple, Set


# VLE instructions that should be tested (from PPCInstrVLE.td)
EXPECTED_VLE_INSTRUCTIONS = {
    # Arithmetic
    'e_addi', 'e_addic', 'e_subfic', 'e_subi',
    # Logical
    'e_andi', 'e_ori', 'e_xori',
    # Load
    'e_lbz', 'e_lhz', 'e_lwz', 'e_lbzu', 'e_lhzu', 'e_lwzu',
    # Store
    'e_stb', 'e_sth', 'e_stw', 'e_stbu', 'e_sthu', 'e_stwu',
    # Immediate
    'e_li', 'e_lis', 'e_or2i',
    # Branch
    'e_b', 'e_bl', 'e_bc', 'e_bcl',
    # System
    'e_rfi', 'e_sc',
    # Compare
    'e_cmp16i',
    # Load/Store Multiple
    'e_lmw', 'e_stmw',
}


def extract_instructions(content: str) -> List[Tuple[str, int]]:
    """Extract VLE instruction mnemonics and their line numbers."""
    instructions = []
    lines = content.split('\n')
    
    for line_num, line in enumerate(lines, 1):
        # Look for VLE instructions (e_ prefix)
        match = re.search(r'\be_(\w+)', line)
        if match:
            mnemonic = 'e_' + match.group(1)
            instructions.append((mnemonic, line_num))
    
    return instructions


def extract_check_directives(content: str) -> Set[str]:
    """Extract CHECK directive patterns to verify test structure."""
    check_patterns = set()
    lines = content.split('\n')
    
    for line in lines:
        # Match CHECK directives
        match = re.search(r'#\s*CHECK[^:]*:\s*(.+)', line)
        if match:
            check_patterns.add(match.group(1).strip())
    
    return check_patterns


def validate_test_file(filename: str) -> Tuple[bool, List[str]]:
    """Validate a VLE test file."""
    errors = []
    warnings = []
    
    try:
        with open(filename, 'r') as f:
            content = f.read()
    except FileNotFoundError:
        return False, [f"File not found: {filename}"]
    
    # Check for RUN directives
    if '# RUN:' not in content:
        errors.append("Missing # RUN: directives")
    else:
        run_directives = [line for line in content.split('\n') if '# RUN:' in line]
        if len(run_directives) == 0:
            errors.append("No # RUN: directives found")
    
    # Check for CHECK directives
    if '# CHECK:' not in content:
        warnings.append("No # CHECK: directives found (tests may not verify output)")
    
    # Extract and validate instructions
    instructions = extract_instructions(content)
    found_instructions = {inst for inst, _ in instructions}
    
    # Check for expected instructions
    missing_instructions = EXPECTED_VLE_INSTRUCTIONS - found_instructions
    if missing_instructions:
        warnings.append(f"Expected instructions not found: {', '.join(sorted(missing_instructions))}")
    
    # Check for unexpected instructions
    unexpected = found_instructions - EXPECTED_VLE_INSTRUCTIONS
    if unexpected:
        warnings.append(f"Unexpected VLE instructions found: {', '.join(sorted(unexpected))}")
    
    # Validate instruction format
    for mnemonic, line_num in instructions:
        if not mnemonic.startswith('e_'):
            errors.append(f"Line {line_num}: Invalid VLE mnemonic format: {mnemonic}")
    
    # Check for proper test structure
    if 'target:' not in content.lower():
        warnings.append("No target label found (branch tests may be incomplete)")
    
    return len(errors) == 0, errors + warnings


def main():
    if len(sys.argv) < 2:
        print("Usage: python3 validate_vle_tests.py <test-file>")
        sys.exit(1)
    
    filename = sys.argv[1]
    is_valid, messages = validate_test_file(filename)
    
    if messages:
        for msg in messages:
            if 'error' in msg.lower() or 'Error' in msg:
                print(f"ERROR: {msg}", file=sys.stderr)
            else:
                print(f"WARNING: {msg}")
    
    if is_valid:
        print(f"✓ Test file '{filename}' structure is valid")
        sys.exit(0)
    else:
        print(f"✗ Test file '{filename}' has errors", file=sys.stderr)
        sys.exit(1)


if __name__ == '__main__':
    main()

