#!/usr/bin/env python3
"""Extract Power ISA 2.07 structure and instruction categories."""

import re
from typing import Dict, List, Set, Tuple


def extract_sections(chapter_file: str) -> List[Tuple[str, str]]:
    """Extract section headers and their content."""
    sections = []
    current_section = None
    current_content = []
    
    with open(chapter_file, 'r', encoding='utf-8', errors='ignore') as f:
        for line in f:
            # Match section numbers like "7.1", "7.10", etc.
            section_match = re.match(r'^(\d+\.\d+)\s+(.+)', line)
            if section_match:
                if current_section:
                    sections.append((current_section, ''.join(current_content)))
                current_section = section_match.group(1) + ' ' + section_match.group(2).strip()[:100]
                current_content = [line]
            else:
                current_content.append(line)
        
        if current_section:
            sections.append((current_section, ''.join(current_content)))
    
    return sections


def extract_instruction_mnemonics(content: str) -> Set[str]:
    """Extract instruction mnemonics from content."""
    mnemonics = set()
    
    # Pattern 1: Mnemonic at start of line, possibly with parentheses or description
    pattern1 = r'^\s*([A-Z][A-Z0-9]{1,9})\s+(?:\(|--|Extended|Format|Instruction|\.|:)'
    matches = re.findall(pattern1, content, re.MULTILINE)
    mnemonics.update(matches)
    
    # Pattern 2: In instruction tables with format like "mnemonic operands"
    pattern2 = r'\b([A-Z][A-Z0-9]{2,8})\s+(?:r\d+|f\d+|v\d+|cr\d+|\$|imm)'
    matches = re.findall(pattern2, content)
    mnemonics.update(matches)
    
    return mnemonics


def identify_book_references(content: str) -> Set[str]:
    """Identify references to different Power ISA Books."""
    books = set()
    
    # Look for Book I, Book II, Book III, Book VLE references
    book_pattern = r'Book\s+([IVX]+(?:-[ES])?)'
    matches = re.findall(book_pattern, content, re.IGNORECASE)
    books.update(matches)
    
    # Look for category references
    category_pattern = r'category\s+([A-Za-z\s]+?)(?:instruction|mode|format)'
    matches = re.findall(category_pattern, content, re.IGNORECASE)
    
    return books


def analyze_powerisa_chapter7():
    """Analyze Chapter 7 structure."""
    print("=== Analyzing Power ISA 2.07 Chapter 7 ===\n")
    
    sections = extract_sections('e200_core_reference_extracted/powerisa_v2_07/Chapter_07.txt')
    
    print(f"Found {len(sections)} sections\n")
    
    # Categorize sections
    instruction_categories = {}
    all_books = set()
    all_mnemonics = set()
    
    for section_num, section_content in sections:
        # Extract section number
        section_match = re.match(r'^(\d+\.\d+)', section_num)
        if not section_match:
            continue
            
        section_id = section_match.group(1)
        section_title = section_num[len(section_id):].strip()
        
        # Find instruction mnemonics
        mnemonics = extract_instruction_mnemonics(section_content[:100000])  # First 100KB of section
        books = identify_book_references(section_content[:100000])
        
        all_books.update(books)
        all_mnemonics.update(mnemonics)
        
        if mnemonics or books:
            instruction_categories[section_id] = {
                'title': section_title[:80],
                'mnemonics_count': len(mnemonics),
                'books': list(books),
                'sample_mnemonics': list(mnemonics)[:10]
            }
    
    print("=== Instruction Categories ===")
    for section_id in sorted(instruction_categories.keys(), key=lambda x: float(x)):
        cat = instruction_categories[section_id]
        print(f"\n{section_id}: {cat['title']}")
        print(f"  Books referenced: {', '.join(cat['books']) if cat['books'] else 'None'}")
        print(f"  Mnemonics found: {cat['mnemonics_count']}")
        if cat['sample_mnemonics']:
            print(f"  Sample: {', '.join(cat['sample_mnemonics'])}")
    
    print(f"\n=== Summary ===")
    print(f"Total unique mnemonics found: {len(all_mnemonics)}")
    print(f"Books referenced: {sorted(all_books)}")
    
    return instruction_categories, all_mnemonics


def analyze_chapter12():
    """Analyze Chapter 12 structure."""
    print("\n=== Analyzing Power ISA 2.07 Chapter 12 ===\n")
    
    try:
        sections = extract_sections('e200_core_reference_extracted/powerisa_v2_07/Chapter_12.txt')
        print(f"Found {len(sections)} sections")
        
        # Look for instruction tables or appendices
        with open('e200_core_reference_extracted/powerisa_v2_07/Chapter_12.txt', 'r', encoding='utf-8', errors='ignore') as f:
            content = f.read()
        
        # Check for appendices or instruction lists
        if 'Appendix' in content or 'instruction' in content.lower():
            print("Chapter 12 appears to contain instruction reference material")
            mnemonics = extract_instruction_mnemonics(content)
            print(f"Found {len(mnemonics)} unique mnemonics in Chapter 12")
            return mnemonics
    except Exception as e:
        print(f"Error analyzing Chapter 12: {e}")
    
    return set()


if __name__ == '__main__':
    categories, ch7_mnemonics = analyze_powerisa_chapter7()
    ch12_mnemonics = analyze_chapter12()
    
    print(f"\n=== Overall Summary ===")
    print(f"Chapter 7 unique mnemonics: {len(ch7_mnemonics)}")
    print(f"Chapter 12 unique mnemonics: {len(ch12_mnemonics)}")
    print(f"Combined unique: {len(ch7_mnemonics | ch12_mnemonics)}")

