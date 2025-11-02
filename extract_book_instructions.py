#!/usr/bin/env python3
"""Extract instructions from Power ISA 2.07 by book."""

import re
from collections import defaultdict
from typing import Dict, List, Set, Tuple


def extract_instruction_table(content: str, book_context: str = None) -> List[Dict]:
    """Extract instructions from instruction tables, filtering by book context."""
    instructions = []
    
    lines = content.split('\n')
    
    for i, line in enumerate(lines):
        # Pattern: Format code, hex opcode, categories, mnemonic, description
        # Example: XO       7C000214     SR          B     add[o][.]        Add
        pattern = r'^([A-Z0-9]{2,6})\s+([0-9A-F]{8}|[0-9A-F]{6})\s+([^\s]+(?:\s+[^\s]+)*?)\s+([a-z][a-z0-9_]{1,15}(?:\[[^\]]+\])?)\s+(.+)$'
        match = re.match(pattern, line.strip())
        
        if match:
            format_code, opcode, categories, mnemonic, description = match.groups()
            
            # Clean up mnemonic (remove optional suffixes like [o][.])
            clean_mnemonic = re.sub(r'\[[^\]]+\]', '', mnemonic)
            
            # Parse categories
            category_list = categories.strip().split()
            
            # Determine which book this instruction belongs to
            book = determine_book_from_context(clean_mnemonic, category_list, description, book_context)
            
            instructions.append({
                'mnemonic': clean_mnemonic.lower(),
                'format': format_code,
                'opcode': opcode,
                'categories': category_list,
                'description': description[:100],
                'book': book
            })
    
    return instructions


def determine_book_from_context(mnemonic: str, categories: List[str], description: str, explicit_book: str = None) -> str:
    """Determine which Power ISA book an instruction belongs to."""
    
    if explicit_book:
        return explicit_book
    
    mnemonic_lower = mnemonic.lower()
    
    # Book VLE indicators
    if mnemonic_lower.startswith('e_'):
        return 'V'
    
    # Book I - Fixed-Point indicators
    if any(op in mnemonic_lower for op in ['add', 'sub', 'mul', 'div', 'and', 'or', 'xor', 'slw', 'srw', 'sraw', 'cntlz', 'popcnt']):
        if 'VLE' not in ' '.join(categories):
            return 'I'
    
    # Book I - Floating-Point indicators
    if any(op in mnemonic_lower for op in ['fadd', 'fsub', 'fmul', 'fdiv', 'fabs', 'fneg', 'fsel', 'fmadd', 'fmsub']):
        if 'VLE' not in ' '.join(categories):
            return 'I'
    
    # Book I - Vector/Altivec indicators
    if mnemonic_lower.startswith('v') and len(mnemonic_lower) > 2:
        if mnemonic_lower[1].isalpha():  # vadd, vmadd, etc.
            return 'I'
    
    # Book I - SPE indicators
    if mnemonic_lower.startswith('ef') or mnemonic_lower.startswith('ev') or mnemonic_lower == 'brinc':
        return 'I'
    
    # Book I - DFP indicators
    if any(op in mnemonic_lower for op in ['dadd', 'dsub', 'dmul', 'ddiv', 'dqua', 'dct', 'dcffix', 'dctfix']):
        return 'I'
    
    # Book II - Storage/Transactional Memory
    if any(op in mnemonic_lower for op in ['tbegin', 'tend', 'tabort', 'tcheck', 'trechkpt', 'treclaim']):
        return 'II'
    
    # Book III - Supervisor instructions
    if any(op in mnemonic_lower for op in ['rfid', 'hrfid', 'slbie', 'slbia', 'tlbie', 'tlbia', 'mtspr', 'mfspr']):
        if 'E' in ' '.join(categories) or 'Embedded' in description:
            return 'III-E'
        else:
            return 'III-S'
    
    # Book III-E - IVOR, embedded specific
    if 'ivor' in mnemonic_lower or 'ivpr' in mnemonic_lower:
        return 'III-E'
    
    # Check category codes
    if 'VLE' in ' '.join(categories):
        return 'V'
    
    # Default based on common patterns
    return 'I'  # Most instructions are Book I


def extract_from_chapter(chapter_file: str, target_books: List[str] = None) -> List[Dict]:
    """Extract instructions from a chapter file, optionally filtering by book."""
    instructions = []
    
    try:
        with open(chapter_file, 'r', encoding='utf-8', errors='ignore') as f:
            content = f.read()
        
        # Determine book context from chapter
        book_context = None
        if 'VLE' in chapter_file or 'Chapter_0' in chapter_file:
            ch_num = int(re.search(r'Chapter_(\d+)', chapter_file).group(1))
            if ch_num <= 7:
                book_context = 'V'
            elif ch_num >= 8:
                book_context = 'III-E'
        
        # Extract instructions
        extracted = extract_instruction_table(content, book_context)
        
        # Filter by target books if specified
        if target_books:
            extracted = [inst for inst in extracted if inst['book'] in target_books]
        
        instructions.extend(extracted)
    
    except Exception as e:
        print(f"Error processing {chapter_file}: {e}")
    
    return instructions


def extract_all_book_instructions():
    """Extract instructions for all Power ISA books."""
    print("=== Extracting Instructions by Book ===\n")
    
    all_instructions_by_book = defaultdict(list)
    
    # Process all chapters
    for ch_num in range(1, 13):
        chapter_file = f'e200_core_reference_extracted/powerisa_v2_07/Chapter_{ch_num:02d}.txt'
        print(f"Processing Chapter {ch_num}...")
        
        instructions = extract_from_chapter(chapter_file)
        
        for inst in instructions:
            all_instructions_by_book[inst['book']].append(inst)
        
        print(f"  Found {len(instructions)} instructions")
    
    # Remove duplicates (same mnemonic in same book)
    unique_by_book = {}
    for book, insts in all_instructions_by_book.items():
        seen = set()
        unique = []
        for inst in insts:
            mnemonic = inst['mnemonic']
            key = (book, mnemonic)
            if key not in seen:
                seen.add(key)
                unique.append(inst)
        unique_by_book[book] = unique
    
    print("\n=== Summary by Book ===\n")
    for book in sorted(unique_by_book.keys()):
        count = len(unique_by_book[book])
        print(f"Book {book}: {count} unique instructions")
    
    # Save results
    for book in sorted(unique_by_book.keys()):
        filename = f'powerisa_v2_07_book_{book}_instructions.txt'
        with open(filename, 'w') as f:
            f.write(f"Power ISA 2.07 Book {book} Instructions\n")
            f.write("=" * 60 + "\n\n")
            
            for inst in sorted(unique_by_book[book], key=lambda x: x['mnemonic']):
                f.write(f"{inst['mnemonic']:<20} {inst['format']:<10} ")
                f.write(f"{', '.join(inst['categories']):<30} ")
                f.write(f"{inst['description'][:40]}\n")
        
        print(f"  Saved to {filename}")
    
    return unique_by_book


if __name__ == '__main__':
    all_instructions = extract_all_book_instructions()
    
    # Also create facility-based categorization
    print("\n=== Categorizing by Facility ===\n")
    
    facilities = {
        'Fixed-Point': ['add', 'sub', 'mul', 'div', 'and', 'or', 'xor', 'slw', 'srw', 'sraw', 'cntlz', 'extsb', 'extsh', 'extsw'],
        'Floating-Point': ['fadd', 'fsub', 'fmul', 'fdiv', 'fabs', 'fneg', 'fsel', 'fmadd', 'fmsub', 'fmr', 'fcmp'],
        'Vector/Altivec': ['vadd', 'vsub', 'vmul', 'vand', 'vor', 'vxor', 'vsldoi', 'vperm', 'vmsum', 'vmadd'],
        'SPE': ['ef', 'ev', 'brinc'],
        'DFP': ['dadd', 'dsub', 'dmul', 'ddiv', 'dqua', 'dct', 'dcffix', 'dctfix'],
        'Transactional Memory': ['tbegin', 'tend', 'tabort', 'tcheck', 'trechkpt', 'treclaim'],
        'Supervisor': ['rfid', 'hrfid', 'slbie', 'slbia', 'tlbie', 'tlbia', 'mtspr', 'mfspr']
    }
    
    facility_counts = defaultdict(int)
    
    for book, insts in all_instructions.items():
        for inst in insts:
            mnemonic = inst['mnemonic']
            for facility, keywords in facilities.items():
                if any(kw in mnemonic for kw in keywords):
                    facility_counts[facility] += 1
                    break
    
    for facility in sorted(facility_counts.keys()):
        print(f"{facility}: {facility_counts[facility]} instructions")

