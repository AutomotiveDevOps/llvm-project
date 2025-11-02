#!/usr/bin/env python3
"""Extract instructions from all Power ISA 2.07 books in the full manual."""

import re
from collections import defaultdict
from typing import Dict, List, Set, Tuple


def identify_book_sections(content: str) -> Dict[str, List[Tuple[int, int, str]]]:
    """Identify sections for each book in the full manual."""
    book_sections = defaultdict(list)
    
    # Pattern to find book markers
    # Look for "Book I:", "Book II:", etc. as section headers
    book_pattern = r'Book\s+([IVX]+(?:-[ES])?)[:\s]+([^\n]{0,100})'
    
    lines = content.split('\n')
    current_book = None
    section_start = 0
    
    for i, line in enumerate(lines):
        # Check for book markers
        match = re.search(book_pattern, line, re.IGNORECASE)
        if match:
            # Save previous section
            if current_book:
                book_sections[current_book].append((section_start, i-1, "Section"))
            
            current_book = match.group(1)
            section_start = i
        
        # Check for chapter markers that might indicate book boundaries
        chapter_match = re.search(r'Chapter\s+\d+[\.\s]+([^\n]{10,80})', line)
        if chapter_match:
            chapter_title = chapter_match.group(1).lower()
            
            # Determine book from chapter title
            if 'fixed-point' in chapter_title or 'floating-point' in chapter_title or \
               'vector' in chapter_title or 'decimal' in chapter_title or \
               'signal processing' in chapter_title or 'spe' in chapter_title:
                if not current_book or current_book != 'I':
                    current_book = 'I'
                    section_start = i
            elif 'storage model' in chapter_title or 'transactional' in chapter_title or \
                 'time base' in chapter_title or 'event-based' in chapter_title or \
                 'decorated storage' in chapter_title:
                if not current_book or current_book != 'II':
                    current_book = 'II'
                    section_start = i
            elif ('interrupt' in chapter_title or 'timer' in chapter_title or \
                  'debug' in chapter_title or 'performance monitor' in chapter_title) and \
                 ('embedded' in chapter_title or 'ivor' in chapter_title):
                if not current_book or current_book != 'III-E':
                    current_book = 'III-E'
                    section_start = i
            elif 'vle' in chapter_title or 'variable length' in chapter_title:
                if not current_book or current_book != 'V':
                    current_book = 'V'
                    section_start = i
    
    # Save last section
    if current_book:
        book_sections[current_book].append((section_start, len(lines)-1, "Final section"))
    
    return dict(book_sections)


def extract_instructions_from_content(content: str, book: str = None) -> List[Dict]:
    """Extract instructions from content, optionally filtering by book."""
    instructions = []
    
    lines = content.split('\n')
    
    for i, line in enumerate(lines):
        # Pattern: Format code, hex opcode, categories, mnemonic, description
        pattern = r'^([A-Z0-9]{2,6})\s+([0-9A-F]{8}|[0-9A-F]{6})\s+([^\s]+(?:\s+[^\s]+)*?)\s+([a-z][a-z0-9_]{1,15}(?:\[[^\]]+\])?)\s+(.+)$'
        match = re.match(pattern, line.strip())
        
        if match:
            format_code, opcode, categories, mnemonic, description = match.groups()
            
            # Clean mnemonic
            clean_mnemonic = re.sub(r'\[[^\]]+\]', '', mnemonic).lower()
            
            category_list = categories.strip().split()
            
            # Determine book if not provided
            determined_book = book
            if not determined_book:
                determined_book = determine_book_from_instruction(clean_mnemonic, category_list, description)
            
            instructions.append({
                'mnemonic': clean_mnemonic,
                'format': format_code,
                'opcode': opcode,
                'categories': category_list,
                'description': description[:100],
                'book': determined_book
            })
    
    return instructions


def determine_book_from_instruction(mnemonic: str, categories: List[str], description: str) -> str:
    """Determine which book an instruction belongs to."""
    
    # VLE prefix
    if mnemonic.startswith('e_'):
        return 'V'
    
    # SPE
    if mnemonic.startswith('ef') or mnemonic.startswith('ev') or mnemonic == 'brinc':
        return 'I'
    
    # DFP
    if 'dadd' in mnemonic or 'dsub' in mnemonic or 'dmul' in mnemonic or 'ddiv' in mnemonic or \
       'dqua' in mnemonic or 'dct' in mnemonic or 'dcffix' in mnemonic or 'dctfix' in mnemonic:
        return 'I'
    
    # Vector/Altivec
    if len(mnemonic) > 2 and mnemonic[0] == 'v' and mnemonic[1].isalpha():
        return 'I'
    
    # Transactional Memory
    if 'tbegin' in mnemonic or 'tend' in mnemonic or 'tabort' in mnemonic or \
       'tcheck' in mnemonic or 'trechkpt' in mnemonic or 'treclaim' in mnemonic:
        return 'II'
    
    # Supervisor (check categories and description)
    if 'Embedded' in description or 'E.' in ' '.join(categories):
        return 'III-E'
    elif 'Server' in description or 'S.' in ' '.join(categories):
        return 'III-S'
    elif any(spr in mnemonic for spr in ['rfid', 'hrfid', 'slbie', 'tlbie']):
        return 'III-S'  # Default supervisor to III-S
    
    # Most instructions are Book I
    if 'VLE' not in ' '.join(categories):
        return 'I'
    
    return 'V'


def extract_all_books_instructions():
    """Extract instructions from all books in the full manual."""
    print("=== Extracting Instructions from All Power ISA 2.07 Books ===\n")
    
    # Read full manual in chunks (it's large)
    full_manual_file = 'e200_core_reference_extracted/powerisa_v2_07/00_Full_Manual.txt'
    
    print(f"Reading {full_manual_file}...")
    with open(full_manual_file, 'r', encoding='utf-8', errors='ignore') as f:
        content = f.read()
    
    print(f"File size: {len(content):,} characters")
    print(f"Lines: {len(content.splitlines()):,}\n")
    
    # Extract all instructions (this will take a while)
    print("Extracting instructions...")
    all_instructions = extract_instructions_from_content(content)
    
    print(f"Found {len(all_instructions)} total instruction entries\n")
    
    # Group by book
    by_book = defaultdict(list)
    for inst in all_instructions:
        by_book[inst['book']].append(inst)
    
    # Remove duplicates per book
    unique_by_book = {}
    for book, insts in by_book.items():
        seen = set()
        unique = []
        for inst in insts:
            mnemonic = inst['mnemonic']
            if mnemonic not in seen:
                seen.add(mnemonic)
                unique.append(inst)
        unique_by_book[book] = unique
    
    print("=== Summary by Book ===\n")
    for book in sorted(unique_by_book.keys()):
        count = len(unique_by_book[book])
        print(f"Book {book}: {count} unique instructions")
    
    # Save results
    print("\n=== Saving Results ===\n")
    for book in sorted(unique_by_book.keys()):
        filename = f'powerisa_v2_07_book_{book}_complete.txt'
        with open(filename, 'w') as f:
            f.write(f"Power ISA 2.07 Book {book} - Complete Instruction List\n")
            f.write("=" * 70 + "\n\n")
            
            for inst in sorted(unique_by_book[book], key=lambda x: x['mnemonic']):
                f.write(f"{inst['mnemonic']:<25} {inst['format']:<12} ")
                f.write(f"{', '.join(inst['categories']):<35} ")
                f.write(f"{inst['description'][:50]}\n")
        
        print(f"Book {book}: Saved {len(unique_by_book[book])} instructions to {filename}")
    
    # Also create facility-based breakdown
    print("\n=== Facility Breakdown ===\n")
    facilities = categorize_by_facility(unique_by_book)
    for facility in sorted(facilities.keys()):
        print(f"{facility}: {len(facilities[facility])} instructions")
    
    return unique_by_book


def categorize_by_facility(by_book: Dict[str, List[Dict]]) -> Dict[str, List[str]]:
    """Categorize instructions by facility."""
    facilities = defaultdict(list)
    
    facility_keywords = {
        'Fixed-Point': ['add', 'sub', 'mul', 'div', 'and', 'or', 'xor', 'slw', 'srw', 'sraw', 
                       'cntlz', 'popcnt', 'extsb', 'extsh', 'extsw', 'cnttz', 'prtyw', 'prtyd'],
        'Floating-Point': ['fadd', 'fsub', 'fmul', 'fdiv', 'fabs', 'fneg', 'fsel', 'fmadd', 
                          'fmsub', 'fmr', 'fcmp', 'fctiw', 'fctid', 'frsp', 'fcfid'],
        'Vector/Altivec': ['vadd', 'vsub', 'vmul', 'vand', 'vor', 'vxor', 'vsldoi', 'vperm', 
                          'vmsum', 'vmadd', 'vsl', 'vsr', 'vsel', 'vcmp'],
        'SPE': ['ef', 'ev', 'brinc'],
        'DFP': ['dadd', 'dsub', 'dmul', 'ddiv', 'dqua', 'dct', 'dcffix', 'dctfix', 'dtst'],
        'Transactional Memory': ['tbegin', 'tend', 'tabort', 'tcheck', 'trechkpt', 'treclaim'],
        'Supervisor': ['rfid', 'hrfid', 'slbie', 'slbia', 'tlbie', 'tlbia', 'mtspr', 'mfspr', 
                      'isync', 'sync', 'msync', 'eieio'],
        'VLE': ['e_']
    }
    
    for book, insts in by_book.items():
        for inst in insts:
            mnemonic = inst['mnemonic']
            categorized = False
            
            for facility, keywords in facility_keywords.items():
                if any(kw in mnemonic for kw in keywords):
                    facilities[facility].append(mnemonic)
                    categorized = True
                    break
            
            if not categorized:
                facilities['Other'].append(mnemonic)
    
    return dict(facilities)


if __name__ == '__main__':
    all_instructions = extract_all_books_instructions()
    
    # Final summary
    total_unique = set()
    for book, insts in all_instructions.items():
        total_unique.update(inst['mnemonic'] for inst in insts)
    
    print(f"\n=== Final Summary ===")
    print(f"Total unique instructions across all books: {len(total_unique)}")
    print(f"Books covered: {', '.join(sorted(all_instructions.keys()))}")

