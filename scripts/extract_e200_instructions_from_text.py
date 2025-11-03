#!/usr/bin/env python3
"""
Extract instruction lists from e200 core manual Chapter 3 text files.

This script extracts:
1. Unsupported/illegal instructions from Table 3-1
2. Optionally supported instructions from Table 3-2
3. Core-specific extensions (e.g., isel, se_rfdi, wait)
"""

import re
from pathlib import Path
from typing import Dict, List, Set
from collections import defaultdict


def extract_unsupported_instructions(text: str) -> List[str]:
    """Extract unsupported instructions from Table 3-1."""
    unsupported = []
    
    # Look for Table 3-1 or "List of Unsupported Instructions"
    table_pattern = r'Table\s+3-1.*?List\s+of\s+Unsupported\s+Instructions'
    
    # Try to find the table content
    lines = text.split('\n')
    in_table = False
    table_lines = []
    
    for i, line in enumerate(lines):
        if re.search(r'Table\s+3-1|List\s+of\s+Unsupported\s+Instructions', line, re.IGNORECASE):
            in_table = True
            # Collect next 20-30 lines (typical table size)
            for j in range(i, min(i + 40, len(lines))):
                table_lines.append(lines[j])
                if j > i + 5 and re.search(r'Table\s+3-2|Optionally\s+Supported', lines[j], re.IGNORECASE):
                    break
            break
    
    if table_lines:
        table_text = '\n'.join(table_lines)
        # Extract instruction mnemonics
        # Pattern: Common instruction patterns
        inst_patterns = [
            r'\b([a-z][a-z0-9_]{2,10})\s*,',  # Comma-separated list
            r'\b([a-z][a-z0-9_]{2,10})\s+(?:instruction|mnemonic)',  # Instruction name
            r'Mnemonics[:\s]+([a-z][a-z0-9_]+(?:\s*,\s*[a-z][a-z0-9_]+)*)',  # Mnemonics: field
        ]
        
        for pattern in inst_patterns:
            matches = re.finditer(pattern, table_text, re.IGNORECASE)
            for match in matches:
                mnemonic_text = match.group(1)
                # Split by comma if multiple
                for inst in re.split(r'[,;\s]+', mnemonic_text):
                    inst = inst.strip().lower()
                    # Filter: must look like an instruction mnemonic
                    if inst and len(inst) >= 2 and len(inst) <= 15 and \
                       re.match(r'^[a-z][a-z0-9_]*$', inst) and \
                       inst not in ['the', 'and', 'for', 'with', 'instruction', 'mnemonics', 'type', 'name']:
                        unsupported.append(inst)
    
    # Also try direct patterns for known unsupported instructions
    known_unsupported = [
        'lswi', 'lswx', 'stswi', 'stswx',  # String instructions
        'mfapidi', 'mfdcrx', 'mtdcrx',  # Device control register
    ]
    
    for inst in known_unsupported:
        if inst in text.lower():
            unsupported.append(inst)
    
    return sorted(set(unsupported))


def extract_optionally_supported(text: str) -> Dict[str, List[str]]:
    """Extract optionally supported instructions from Table 3-2."""
    optional = defaultdict(list)
    
    # Look for Table 3-2
    lines = text.split('\n')
    in_table = False
    table_lines = []
    
    for i, line in enumerate(lines):
        if re.search(r'Table\s+3-2|Optionally\s+Supported', line, re.IGNORECASE):
            in_table = True
            for j in range(i, min(i + 50, len(lines))):
                table_lines.append(lines[j])
                if j > i + 10 and re.search(r'Table\s+3-3|Memory\s+Access', lines[j], re.IGNORECASE):
                    break
            break
    
    if table_lines:
        table_text = '\n'.join(table_lines)
        
        # Extract by category
        categories = {
            'cache': ['dcba', 'dcbf', 'dcbi', 'dcbt', 'dcbtst', 'dcbst', 'dcbz', 'icbi', 'icbt'],
            'cache_locking': ['dcbtls', 'dcbtstls', 'dcblc', 'icbtls', 'icblc'],
            'tlb': ['tlbivax', 'tlbre', 'tlbsx', 'tlbsync', 'tlbwe'],
            'dcr': ['mfdcr', 'mtdcr'],
        }
        
        for category, expected_insts in categories.items():
            for inst in expected_insts:
                if inst in table_text.lower():
                    optional[category].append(inst)
    
    return dict(optional)


def extract_core_extensions(text: str) -> List[str]:
    """Extract core-specific instruction extensions."""
    extensions = []
    
    # Look for "New e200 Instructions" section
    section_pattern = r'New\s+e200\s+Instructions|e200\s+Instructions'
    lines = text.split('\n')
    
    for i, line in enumerate(lines):
        if re.search(section_pattern, line, re.IGNORECASE):
            # Extract next 200 lines
            section_text = '\n'.join(lines[i:min(i + 200, len(lines))])
            
            # Look for known extensions
            known_extensions = [
                'isel',  # ISEL APU
                'se_rfdi',  # Debug APU
                'wait',  # Wait instruction
                'e_wait',  # Wait in VLE
            ]
            
            for ext in known_extensions:
                if ext in section_text.lower():
                    extensions.append(ext)
            
            # Also look for instruction definitions
            inst_def_pattern = r'^([a-z][a-z0-9_]+)\s+(?:Instruction|APU)'
            for line in section_text.split('\n'):
                match = re.search(inst_def_pattern, line, re.IGNORECASE)
                if match:
                    inst = match.group(1).lower()
                    if inst not in extensions:
                        extensions.append(inst)
            
            break
    
    return sorted(set(extensions))


def extract_from_chapter3(chapter_file: Path, core_name: str) -> Dict[str, any]:
    """Extract instruction information from Chapter 3 text file."""
    print(f"Extracting from {chapter_file.name} ({core_name})...")
    
    if not chapter_file.exists():
        print(f"  Error: {chapter_file} does not exist")
        return {}
    
    with open(chapter_file, 'r', encoding='utf-8', errors='ignore') as f:
        text = f.read()
    
    results = {
        'unsupported': extract_unsupported_instructions(text),
        'optional': extract_optionally_supported(text),
        'extensions': extract_core_extensions(text),
    }
    
    print(f"  Unsupported: {len(results['unsupported'])} instructions")
    print(f"  Optional: {sum(len(v) for v in results['optional'].values())} instructions")
    print(f"  Extensions: {len(results['extensions'])} instructions")
    
    return results


def main():
    """Main execution."""
    base_dir = Path('.')
    extracted_dir = base_dir / 'e200_core_reference_extracted'
    
    cores = {
        'e200z0': extracted_dir / 'z0' / 'Chapter_03.txt',
        'e200z3': extracted_dir / 'z3' / 'Chapter_03.txt',
        'e200z4': extracted_dir / 'z4' / 'Chapter_03.txt',
        'e200z6': extracted_dir / 'z760' / 'Chapter_03.txt',  # z6 uses z760 manual
        'e200z7': extracted_dir / 'z760' / 'Chapter_03.txt',  # z7 uses z760 manual
    }
    
    all_results = {}
    
    for core_name, chapter_file in cores.items():
        if chapter_file.exists():
            results = extract_from_chapter3(chapter_file, core_name)
            all_results[core_name] = results
        else:
            print(f"Skipping {core_name}: {chapter_file} not found")
    
    # Write consolidated report
    output_file = base_dir / 'e200_manual_instructions_extracted.txt'
    with open(output_file, 'w', encoding='utf-8') as f:
        f.write("e200 Core Reference Manuals - Extracted Instruction Information\n")
        f.write("=" * 80 + "\n\n")
        
        for core_name, results in all_results.items():
            f.write(f"\n### {core_name.upper()}\n\n")
            
            f.write(f"Unsupported Instructions ({len(results['unsupported'])}):\n")
            for inst in results['unsupported']:
                f.write(f"  - {inst}\n")
            
            f.write(f"\nOptionally Supported Instructions:\n")
            for category, insts in results['optional'].items():
                f.write(f"  {category}: {', '.join(insts)}\n")
            
            f.write(f"\nCore Extensions ({len(results['extensions'])}):\n")
            for inst in results['extensions']:
                f.write(f"  - {inst}\n")
    
    print(f"\nReport written to: {output_file}")
    return all_results


if __name__ == '__main__':
    main()

