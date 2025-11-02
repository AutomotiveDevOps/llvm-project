#!/usr/bin/env python3
"""Extract instruction lists from Power ISA 2.07 specification."""

import re
from collections import defaultdict
from typing import Dict, List, Set, Tuple


def extract_instruction_definitions(content: str) -> Set[str]:
    """Extract instruction mnemonics from specification text."""
    mnemonics = set()
    
    # Pattern 1: Instruction mnemonic at start of line or after whitespace
    # Format: MNEMONIC (description) or MNEMONIC operands
    pattern1 = r'(?:^|\s)([A-Z][A-Z0-9]{1,10})\s+(?:\([^)]*\)|--|Extended|Format|Instruction|\.|:|\s+[rfv])'
    matches = re.findall(pattern1, content, re.MULTILINE)
    mnemonics.update([m for m in matches if len(m) >= 2 and m.isupper()])
    
    # Pattern 2: In instruction tables: mnemonic followed by register or immediate
    pattern2 = r'\b([A-Z][A-Z0-9]{2,8})\s+(?:r\d+|f\d+|v\d+|cr\d+|\$|#|[0-9]+|RT|RS|RA|RB)'
    matches = re.findall(pattern2, content)
    mnemonics.update([m for m in matches if len(m) >= 2])
    
    # Pattern 3: In opcode tables - mnemonic columns
    pattern3 = r'\|?\s*([A-Z][A-Z0-9]{2,8})\s*\|'
    matches = re.findall(pattern3, content)
    mnemonics.update([m for m in matches if len(m) >= 2])
    
    # Filter out common false positives
    false_positives = {
        'BOOK', 'POWER', 'ISA', 'VLE', 'THE', 'FOR', 'AND', 'OR', 'NOT',
        'ALL', 'ARE', 'SEE', 'REF', 'FIG', 'TAB', 'PAGE', 'CHAPTER', 'SECTION'
    }
    mnemonics = {m for m in mnemonics if m not in false_positives and len(m) <= 10}
    
    return mnemonics


def extract_by_category(content: str) -> Dict[str, Set[str]]:
    """Extract instructions organized by category."""
    categories = defaultdict(set)
    
    # Look for category markers
    category_patterns = [
        (r'\[Category:\s*([^\]]+)\]', 'category'),
        (r'Category:\s*([A-Za-z\s]+?)(?:instruction|mode|format)', 'category'),
        (r'Book\s+([IVX]+(?:-[ES])?)', 'book'),
    ]
    
    current_category = 'Unknown'
    current_book = None
    
    lines = content.split('\n')
    for i, line in enumerate(lines):
        # Check for category markers
        for pattern, ptype in category_patterns:
            matches = re.findall(pattern, line, re.IGNORECASE)
            if matches:
                if ptype == 'category':
                    current_category = matches[0].strip()
                elif ptype == 'book':
                    current_book = matches[0]
        
        # Extract instructions near category markers
        if i < len(lines) - 10:  # Look ahead a few lines
            context = '\n'.join(lines[i:min(i+20, len(lines))])
            instructions = extract_instruction_definitions(context[:2000])
            if instructions:
                cat_key = f"{current_category} ({current_book})" if current_book else current_category
                categories[cat_key].update(instructions)
    
    return dict(categories)


def extract_vle_instructions(chapter7_file: str) -> Dict[str, Set[str]]:
    """Extract VLE-specific instructions from Chapter 7."""
    vle_instructions = defaultdict(set)
    
    with open(chapter7_file, 'r', encoding='utf-8', errors='ignore') as f:
        content = f.read()
    
    # Look for VLE instruction sections
    # Pattern: instruction mnemonic followed by VLE encoding info
    vle_pattern = r'([A-Z][A-Z0-9]{2,8})\s+(?:\(|16-bit|32-bit|VLE|Extended)'
    matches = re.findall(vle_pattern, content)
    vle_instructions['VLE-specific'] = {m for m in matches if len(m) >= 2 and len(m) <= 10}
    
    # Look for instruction tables in appendices
    if 'Appendix' in content:
        # Find appendix sections
        appendix_pattern = r'Appendix\s+[A-Z]\.?\d*[:\s]+([^\n]+)'
        appendices = re.findall(appendix_pattern, content, re.IGNORECASE)
        
        for appendix_title in appendices:
            if 'instruction' in appendix_title.lower() or 'mnemonic' in appendix_title.lower():
                # Extract instructions from this appendix
                # This is a simplified extraction
                instructions = extract_instruction_definitions(content)
                vle_instructions[appendix_title[:50]].update(instructions)
    
    return dict(vle_instructions)


def analyze_all_chapters():
    """Analyze all Power ISA 2.07 chapters."""
    all_instructions = defaultdict(set)
    chapter_instructions = {}
    
    print("=== Extracting Instructions from Power ISA 2.07 Chapters ===\n")
    
    # Analyze each chapter
    for ch_num in range(1, 13):
        chapter_file = f'e200_core_reference_extracted/powerisa_v2_07/Chapter_{ch_num:02d}.txt'
        try:
            with open(chapter_file, 'r', encoding='utf-8', errors='ignore') as f:
                content = f.read()
            
            # Extract instructions
            instructions = extract_instruction_definitions(content)
            
            # Extract by category
            categorized = extract_by_category(content[:100000])  # First 100KB for categorization
            
            chapter_instructions[ch_num] = {
                'count': len(instructions),
                'instructions': instructions,
                'categories': categorized
            }
            
            # Aggregate
            for cat, insts in categorized.items():
                all_instructions[cat].update(insts)
            
            print(f"Chapter {ch_num}: {len(instructions)} unique instructions found")
            if categorized:
                print(f"  Categories: {', '.join(list(categorized.keys())[:3])}")
        
        except FileNotFoundError:
            print(f"Chapter {ch_num}: File not found")
        except Exception as e:
            print(f"Chapter {ch_num}: Error - {e}")
    
    print(f"\n=== Summary ===")
    print(f"Total instruction categories: {len(all_instructions)}")
    for cat in sorted(all_instructions.keys()):
        print(f"  {cat}: {len(all_instructions[cat])} instructions")
    
    # Save results
    with open('powerisa_v2_07_instructions.txt', 'w') as f:
        f.write("Power ISA 2.07 Instruction Inventory\n")
        f.write("=" * 50 + "\n\n")
        
        for cat in sorted(all_instructions.keys()):
            f.write(f"\n{cat} ({len(all_instructions[cat])} instructions):\n")
            for inst in sorted(all_instructions[cat]):
                f.write(f"  {inst}\n")
    
    return all_instructions, chapter_instructions


def extract_instruction_reference_tables():
    """Extract instructions from instruction reference tables/appendix."""
    print("\n=== Extracting from Instruction Reference Tables ===\n")
    
    # Look for appendices with instruction lists
    instructions = set()
    
    # Check Chapter 7 (VLE) for appendices
    try:
        with open('e200_core_reference_extracted/powerisa_v2_07/Chapter_07.txt', 'r', encoding='utf-8', errors='ignore') as f:
            content = f.read()
        
        # Look for "Appendix A" style sections with instruction tables
        # Pattern: table rows with mnemonic and opcode
        table_pattern = r'^\s*([A-Z][A-Z0-9]{2,8})\s+[0-9A-Fx-]+'
        matches = re.findall(table_pattern, content, re.MULTILINE)
        instructions.update(matches)
        
        print(f"Found {len(instructions)} instructions in reference tables")
    except Exception as e:
        print(f"Error extracting reference tables: {e}")
    
    return instructions


if __name__ == '__main__':
    all_inst, ch_inst = analyze_all_chapters()
    ref_instructions = extract_instruction_reference_tables()
    
    # Combine
    total_unique = set()
    for inst_set in all_inst.values():
        total_unique.update(inst_set)
    total_unique.update(ref_instructions)
    
    print(f"\n=== Final Summary ===")
    print(f"Total unique instructions across all categories: {len(total_unique)}")
    print(f"Instructions from reference tables: {len(ref_instructions)}")
    print(f"\nSample instructions: {', '.join(sorted(total_unique)[:20])}")

