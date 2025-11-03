#!/usr/bin/env python3
"""
Verify each of the 13 "missing" instructions to determine if they are:
1. Actually Missing - Not implemented
2. False Positive - Implemented but missed due to naming
3. Not Applicable - Not required for e200 (e.g., 64-bit only)
"""

import re
from pathlib import Path
from typing import Dict, List, Tuple, Optional


def search_llvm_instruction(mnemonic: str) -> Dict:
    """Search for instruction in LLVM codebase."""
    results = {
        'found_in': [],
        'variants': [],
        'has_predicates': False,
        'predicates': [],
        'file': None
    }
    
    ppc_dir = Path('llvm/lib/Target/PowerPC')
    
    # Search patterns
    patterns = [
        rf'def\s+([A-Z_]*{re.escape(mnemonic.upper())}[A-Z0-9_]*)',  # def INST_NAME
        rf'Mnemonic\s*=\s*"{re.escape(mnemonic)}"',  # Mnemonic = "inst"
        rf'"{re.escape(mnemonic)}\s+',  # "inst $operands"
        rf'\\"{re.escape(mnemonic)}"',  # \"inst\"
    ]
    
    # Files to search
    search_files = [
        'PPCInstrInfo.td',
        'PPCInstrVLE.td',
        'PPCInstrSPE.td',
        'PPCInstrAltivec.td',
        'PPCInstr64Bit.td',
    ]
    
    for filename in search_files:
        file_path = ppc_dir / filename
        if not file_path.exists():
            continue
        
        with open(file_path, 'r', encoding='utf-8', errors='ignore') as f:
            content = f.read()
            lines = content.split('\n')
            
            for pattern in patterns:
                matches = re.finditer(pattern, content, re.IGNORECASE)
                for match in matches:
                    if filename not in results['found_in']:
                        results['found_in'].append(filename)
                    if match.group(0) not in results['variants']:
                        results['variants'].append(match.group(0))
                    
                    # Get line number
                    line_num = content[:match.start()].count('\n') + 1
                    
                    # Check for predicates around this match
                    if 'Predicates' in content[max(0, match.start()-500):match.end()+500]:
                        results['has_predicates'] = True
                    
                    # Get context
                    start_line = max(0, line_num - 3)
                    end_line = min(len(lines), line_num + 3)
                    context = '\n'.join(lines[start_line:end_line])
                    
                    if not results['file']:
                        results['file'] = filename
                        results['context'] = context[:500]
    
    return results


def check_powerisa_spec(mnemonic: str) -> Dict:
    """Check if instruction is in Power ISA 2.07 specification."""
    result = {
        'found': False,
        'book': None,
        'format': None,
        'description': None
    }
    
    # Check master list
    master_file = Path('powerisa_v2_07_master_list.txt')
    if master_file.exists():
        with open(master_file, 'r', encoding='utf-8') as f:
            for line in f:
                if re.match(rf'^{re.escape(mnemonic)}\s+', line, re.IGNORECASE):
                    result['found'] = True
                    parts = line.split()
                    if len(parts) > 1:
                        result['book'] = parts[1] if parts[1].startswith('[') else None
                    break
    
    # Also check Book V (VLE instructions)
    if mnemonic.startswith('e_') or mnemonic.startswith('se_'):
        book_v_file = Path('powerisa_v2_07_book_V_complete.txt')
        if book_v_file.exists():
            with open(book_v_file, 'r', encoding='utf-8') as f:
                for line in f:
                    if re.match(rf'^{re.escape(mnemonic)}\s+', line, re.IGNORECASE):
                        result['found'] = True
                        result['book'] = 'V'
                        parts = line.split()
                        if len(parts) > 1:
                            result['format'] = parts[1]
                        break
    
    return result


def check_64bit_only(mnemonic: str) -> bool:
    """Check if instruction is 64-bit only."""
    # Common 64-bit indicators
    if '8' in mnemonic or mnemonic.endswith('8'):
        return True
    
    # Known 64-bit instructions
    known_64bit = ['mulhd', 'mulhdu', 'sradi', 'ld', 'ldu', 'ldx', 'std', 'stdu', 'stdx']
    if mnemonic in known_64bit:
        return True
    
    # Check if in 64-bit file only
    results = search_llvm_instruction(mnemonic)
    if results['found_in'] and all('64Bit' in f for f in results['found_in']):
        return True
    
    return False


def verify_instruction(mnemonic: str) -> Dict:
    """Comprehensive verification of an instruction."""
    print(f"\n=== Verifying: {mnemonic} ===")
    
    result = {
        'mnemonic': mnemonic,
        'status': 'UNKNOWN',
        'category': None,
        'llvm_found': False,
        'powerisa_found': False,
        'is_64bit': False,
        'evidence': []
    }
    
    # Check LLVM implementation
    llvm_results = search_llvm_instruction(mnemonic)
    if llvm_results['found_in']:
        result['llvm_found'] = True
        result['evidence'].append(f"Found in LLVM: {', '.join(llvm_results['found_in'])}")
        if llvm_results['variants']:
            result['evidence'].append(f"Variants: {', '.join(llvm_results['variants'][:3])}")
    else:
        result['evidence'].append("NOT found in LLVM codebase")
    
    # Check Power ISA 2.07
    powerisa_results = check_powerisa_spec(mnemonic)
    if powerisa_results['found']:
        result['powerisa_found'] = True
        result['evidence'].append(f"Found in Power ISA 2.07 Book {powerisa_results['book']}")
    
    # Check if 64-bit only
    is_64bit = check_64bit_only(mnemonic)
    if is_64bit:
        result['is_64bit'] = True
        result['evidence'].append("64-bit only instruction")
    
    # Categorize
    if result['llvm_found']:
        if result['is_64bit']:
            result['status'] = 'NOT_APPLICABLE'
            result['category'] = '64-bit only (e200 cores are 32-bit)'
        else:
            result['status'] = 'FALSE_POSITIVE'
            result['category'] = 'Implemented but missed by comparison script'
    elif result['powerisa_found']:
        if result['is_64bit']:
            result['status'] = 'NOT_APPLICABLE'
            result['category'] = '64-bit only (not required for 32-bit e200)'
        else:
            result['status'] = 'ACTUALLY_MISSING'
            result['category'] = 'Should be implemented'
    else:
        result['status'] = 'NOT_IN_ISA'
        result['category'] = 'Not in Power ISA 2.07 specification'
    
    print(f"Status: {result['status']}")
    print(f"Category: {result['category']}")
    for evidence in result['evidence']:
        print(f"  - {evidence}")
    
    return result


def main():
    """Main verification."""
    instructions = [
        'and',
        'e_or2i',
        'e_or2is',
        'e_sc',
        'ehpriv',
        'evlddepx',
        'evstddepx',
        'mulhd',
        'mulhdu',
        'mulhw',
        'mulhwu',
        'sradi',
        'to',
    ]
    
    print("=" * 80)
    print("Verification of 13 'Missing' Instructions")
    print("=" * 80)
    
    results = []
    for inst in instructions:
        result = verify_instruction(inst)
        results.append(result)
    
    # Generate report
    print("\n" + "=" * 80)
    print("SUMMARY")
    print("=" * 80)
    
    by_status = {}
    for result in results:
        status = result['status']
        if status not in by_status:
            by_status[status] = []
        by_status[status].append(result)
    
    for status in ['ACTUALLY_MISSING', 'FALSE_POSITIVE', 'NOT_APPLICABLE', 'NOT_IN_ISA']:
        if status in by_status:
            print(f"\n{status}: {len(by_status[status])}")
            for result in by_status[status]:
                print(f"  - {result['mnemonic']}: {result['category']}")
    
    # Write detailed report
    report_file = Path('e200_missing_instructions_verification.md')
    with open(report_file, 'w', encoding='utf-8') as f:
        f.write("# e200 Missing Instructions - Verification Report\n\n")
        f.write("## Overview\n\n")
        f.write("This report verifies each of the 13 instructions identified as 'missing'\n")
        f.write("and categorizes them as actually missing, false positives, or not applicable.\n\n")
        
        f.write("## Summary\n\n")
        f.write(f"- **Actually Missing**: {len(by_status.get('ACTUALLY_MISSING', []))}\n")
        f.write(f"- **False Positives**: {len(by_status.get('FALSE_POSITIVE', []))}\n")
        f.write(f"- **Not Applicable**: {len(by_status.get('NOT_APPLICABLE', []))}\n")
        f.write(f"- **Not in Power ISA 2.07**: {len(by_status.get('NOT_IN_ISA', []))}\n\n")
        
        f.write("## Detailed Verification\n\n")
        for result in results:
            f.write(f"### {result['mnemonic']}\n\n")
            f.write(f"- **Status**: {result['status']}\n")
            f.write(f"- **Category**: {result['category']}\n")
            f.write(f"- **Found in LLVM**: {'Yes' if result['llvm_found'] else 'No'}\n")
            f.write(f"- **Found in Power ISA 2.07**: {'Yes' if result['powerisa_found'] else 'No'}\n")
            f.write(f"- **64-bit Only**: {'Yes' if result['is_64bit'] else 'No'}\n")
            f.write("\n**Evidence**:\n")
            for evidence in result['evidence']:
                f.write(f"- {evidence}\n")
            f.write("\n")
    
    print(f"\nDetailed report written to: {report_file}")
    
    return results


if __name__ == '__main__':
    results = main()

