#!/usr/bin/env python3
"""Extract instruction lists from Power ISA 2.07 specification - improved version."""

import re
from collections import defaultdict
from typing import Dict, List, Set, Tuple, Optional


def extract_instruction_table_rows(content: str) -> List[Dict]:
    """Extract instruction entries from tables.
    
    Format example:
    XO       7C000214     SR          B     add[o][.]        Add
    EVX      100002E4             SP.FD   efdabs        Floating-Point Double-Precision Absolute Value
    """
    instructions = []
    
    lines = content.split('\n')
    
    for i, line in enumerate(lines):
        # Pattern: Format code, hex opcode, categories, mnemonic, description
        # Format codes: XO, X, D, I16A, SCI8, BD24, EVX, XL, ESC, etc.
        pattern = r'^([A-Z0-9]{2,6})\s+([0-9A-F]{8}|[0-9A-F]{6})\s+([^\s]+(?:\s+[^\s]+)*?)\s+([a-z][a-z0-9_]{1,15}(?:\[[^\]]+\])?)\s+(.+)$'
        match = re.match(pattern, line.strip())
        
        if match:
            format_code, opcode, categories, mnemonic, description = match.groups()
            
            # Clean up mnemonic (remove optional suffixes like [o][.])
            clean_mnemonic = re.sub(r'\[[^\]]+\]', '', mnemonic)
            
            # Parse categories
            category_list = categories.strip().split()
            
            instructions.append({
                'mnemonic': clean_mnemonic,
                'format': format_code,
                'opcode': opcode,
                'categories': category_list,
                'description': description[:100]
            })
        else:
            # Try simpler pattern for lines with just mnemonic and description
            simple_pattern = r'^([a-z][a-z0-9_]{2,15}(?:\[[^\]]+\])?)\s+(.+)$'
            simple_match = re.match(simple_pattern, line.strip())
            if simple_match:
                mnemonic, description = simple_match.groups()
                clean_mnemonic = re.sub(r'\[[^\]]+\]', '', mnemonic)
                if clean_mnemonic and len(clean_mnemonic) >= 2:
                    instructions.append({
                        'mnemonic': clean_mnemonic,
                        'format': 'Unknown',
                        'opcode': '',
                        'categories': [],
                        'description': description[:100]
                    })
    
    return instructions


def extract_from_appendix(content: str) -> List[Dict]:
    """Extract instructions from Appendix A (VLE Instruction Set Sorted by Mnemonic)."""
    instructions = []
    
    # Find Appendix A section
    appendix_start = content.find('Appendix A. VLE Instruction Set Sorted by Mnemonic')
    if appendix_start == -1:
        return instructions
    
    # Extract section (next 500KB or until next major section)
    appendix_content = content[appendix_start:appendix_start+500000]
    
    # Extract instruction table rows
    instructions = extract_instruction_table_rows(appendix_content)
    
    return instructions


def categorize_instructions(instructions: List[Dict]) -> Dict[str, List[Dict]]:
    """Categorize instructions by their categories."""
    categorized = defaultdict(list)
    
    for inst in instructions:
        if not inst['categories']:
            categorized['Uncategorized'].append(inst)
        else:
            for cat in inst['categories']:
                # Normalize category names
                if cat == 'VLE':
                    categorized['VLE-specific'].append(inst)
                elif cat.startswith('SP'):
                    categorized['SPE (Signal Processing Engine)'].append(inst)
                elif '64' in cat:
                    categorized['64-bit'].append(inst)
                elif cat in ['SR', 'B']:
                    categorized['Base (Book I)'].append(inst)
                else:
                    categorized[f'Category: {cat}'].append(inst)
        
        # Also categorize by mnemonic prefix
        mnemonic = inst['mnemonic']
        if mnemonic.startswith('e_'):
            categorized['VLE-prefixed'].append(inst)
        elif mnemonic.startswith('ef'):
            categorized['SPE Floating-Point'].append(inst)
        elif mnemonic.startswith('ev'):
            categorized['SPE Vector'].append(inst)
    
    return dict(categorized)


def analyze_powerisa_chapter7():
    """Analyze Chapter 7 which contains VLE instruction definitions."""
    print("=== Analyzing Power ISA 2.07 Chapter 7 (VLE Instructions) ===\n")
    
    with open('e200_core_reference_extracted/powerisa_v2_07/Chapter_07.txt', 'r', encoding='utf-8', errors='ignore') as f:
        content = f.read()
    
    # Extract from Appendix A
    appendix_instructions = extract_from_appendix(content)
    print(f"Found {len(appendix_instructions)} instructions in Appendix A")
    
    # Also extract from main content
    all_instructions = extract_instruction_table_rows(content)
    print(f"Found {len(all_instructions)} total instruction entries")
    
    # Remove duplicates (by mnemonic)
    unique_instructions = {}
    for inst in all_instructions + appendix_instructions:
        mnemonic = inst['mnemonic']
        if mnemonic and mnemonic not in unique_instructions:
            unique_instructions[mnemonic] = inst
    
    print(f"Unique instructions: {len(unique_instructions)}\n")
    
    # Categorize
    categorized = categorize_instructions(list(unique_instructions.values()))
    
    print("=== Instructions by Category ===")
    for category in sorted(categorized.keys()):
        insts = categorized[category]
        print(f"\n{category}: {len(insts)} instructions")
        # Show samples
        sample_mnemonics = [inst['mnemonic'] for inst in insts[:10]]
        print(f"  Sample: {', '.join(sample_mnemonics)}")
    
    # Save to file
    with open('powerisa_v2_07_instruction_list.txt', 'w') as f:
        f.write("Power ISA 2.07 (Book VLE) Instruction List\n")
        f.write("=" * 60 + "\n\n")
        
        for category in sorted(categorized.keys()):
            f.write(f"\n{category} ({len(categorized[category])} instructions):\n")
            f.write("-" * 60 + "\n")
            for inst in sorted(categorized[category], key=lambda x: x['mnemonic']):
                f.write(f"  {inst['mnemonic']:<20} {inst.get('format', '')[:8]:<10} ")
                f.write(f"{', '.join(inst['categories']):<20} {inst['description'][:40]}\n")
    
    return unique_instructions, categorized


def check_references_to_other_books(content: str):
    """Check what instructions from other books are referenced."""
    print("\n=== Instructions Referenced from Other Books ===\n")
    
    # Look for patterns like "see Book I Chapter X" or "defined in Book III-E"
    book_refs = {}
    
    patterns = [
        (r'Book\s+I[^,]*(?:Chapter|Section)\s+(\d+)', 'Book I'),
        (r'Book\s+III-E[^,]*(?:Chapter|Section)\s+(\d+|\w)', 'Book III-E'),
        (r'Book\s+II[^,]*(?:Chapter|Section)\s+(\d+)', 'Book II'),
    ]
    
    for pattern, book in patterns:
        matches = re.findall(pattern, content, re.IGNORECASE)
        if matches:
            book_refs[book] = set(matches)
            print(f"{book}: Referenced in {len(matches)} places")
    
    return book_refs


if __name__ == '__main__':
    unique_inst, categorized = analyze_powerisa_chapter7()
    
    # Check references to other books
    with open('e200_core_reference_extracted/powerisa_v2_07/Chapter_07.txt', 'r', encoding='utf-8', errors='ignore') as f:
        content = f.read()
    book_refs = check_references_to_other_books(content)
    
    print(f"\n=== Summary ===")
    print(f"Total unique instructions in Book VLE: {len(unique_inst)}")
    print(f"Categories identified: {len(categorized)}")
    print(f"\nNote: Book VLE references many instructions from Book I, II, and III-E.")
    print("For complete Power ISA 2.07 coverage, we need the full specification including all books.")

