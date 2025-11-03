#!/usr/bin/env python3
"""
Consolidate Power ISA 2.07 instructions from all books into a master list.

This script:
1. Reads existing book-specific instruction lists
2. Consolidates into a single master list
3. Handles instruction variants and naming differences
4. Outputs a comprehensive list for comparison
"""

import re
from pathlib import Path
from typing import Dict, List, Set, Tuple
from collections import defaultdict


def parse_instruction_line(line: str) -> Tuple[str, str, str]:
    """
    Parse an instruction line from the book files.
    
    Format examples:
    - "brinc                     EVX          SP                                  Bit Reversed Increment"
    - "and                       I16A         SR, VLE, e_add2i., Add, (2, operand), Immediate Record"
    """
    line = line.strip()
    if not line or line.startswith('=') or line.startswith('Power ISA'):
        return None, None, None
    
    # Split into fields - mnemonic is first field (up to 25 chars typically)
    parts = line.split(None, 3)
    if len(parts) < 3:
        return None, None, None
    
    mnemonic = parts[0].strip().lower()
    format_code = parts[1].strip() if len(parts) > 1 else ''
    categories = parts[2].strip() if len(parts) > 2 else ''
    description = parts[3].strip() if len(parts) > 3 else ''
    
    # Clean up mnemonic (remove record bit indicators, etc.)
    # Handle cases like "add." -> "add", "addo" -> "addo"
    clean_mnemonic = re.sub(r'\.$', '', mnemonic)
    
    return clean_mnemonic, categories, description


def read_book_instructions(book_file: Path) -> List[Dict[str, str]]:
    """Read instructions from a book file."""
    instructions = []
    
    if not book_file.exists():
        print(f"Warning: {book_file} does not exist")
        return instructions
    
    with open(book_file, 'r', encoding='utf-8', errors='ignore') as f:
        for line_num, line in enumerate(f, 1):
            mnemonic, categories, description = parse_instruction_line(line)
            if mnemonic:
                instructions.append({
                    'mnemonic': mnemonic,
                    'categories': categories,
                    'description': description,
                    'source_file': str(book_file),
                    'line': line_num
                })
    
    return instructions


def normalize_mnemonic(mnemonic: str) -> str:
    """
    Normalize instruction mnemonic for comparison.
    Removes variants that don't change the base instruction.
    """
    # Remove record bit suffix
    mnemonic = re.sub(r'\.$', '', mnemonic)
    
    # Handle VLE prefixes - keep them as they're different instructions
    # e_* and se_* are distinct
    
    # Remove overflow variants? No, keep them as they may be different
    
    return mnemonic.lower()


def consolidate_instructions() -> Dict[str, List[Dict[str, str]]]:
    """Consolidate instructions from all Power ISA 2.07 books."""
    
    base_dir = Path('.')
    
    # Map of book names to file paths
    book_files = {
        'I': base_dir / 'powerisa_v2_07_book_I_complete.txt',
        'II': base_dir / 'powerisa_v2_07_book_II_complete.txt',  # May not exist
        'III-S': base_dir / 'powerisa_v2_07_book_III-S_complete.txt',  # May not exist
        'III-E': base_dir / 'powerisa_v2_07_book_III-E_complete.txt',
        'V': base_dir / 'powerisa_v2_07_book_V_complete.txt',
    }
    
    all_instructions = {}
    by_book = defaultdict(list)
    
    print("=== Consolidating Power ISA 2.07 Instructions ===\n")
    
    for book_name, book_file in book_files.items():
        print(f"Reading Book {book_name}...")
        instructions = read_book_instructions(book_file)
        
        if instructions:
            by_book[book_name] = instructions
            print(f"  Found {len(instructions)} instructions")
            
            # Add to master list (deduplicate by normalized mnemonic)
            for inst in instructions:
                norm_mnemonic = normalize_mnemonic(inst['mnemonic'])
                if norm_mnemonic not in all_instructions:
                    all_instructions[norm_mnemonic] = {
                        'mnemonic': inst['mnemonic'],
                        'books': set([book_name]),
                        'categories': inst['categories'],
                        'description': inst['description'],
                        'sources': [inst]
                    }
                else:
                    all_instructions[norm_mnemonic]['books'].add(book_name)
                    all_instructions[norm_mnemonic]['sources'].append(inst)
        else:
            print(f"  No instructions found (file may not exist)")
    
    print(f"\n=== Summary ===")
    print(f"Total unique instructions: {len(all_instructions)}")
    for book_name in sorted(by_book.keys()):
        print(f"  Book {book_name}: {len(by_book[book_name])} instructions")
    
    # Count instructions in multiple books
    multi_book = sum(1 for inst in all_instructions.values() 
                    if len(inst['books']) > 1)
    print(f"  Instructions in multiple books: {multi_book}")
    
    return {
        'all': all_instructions,
        'by_book': dict(by_book),
        'summary': {
            'total_unique': len(all_instructions),
            'by_book_counts': {k: len(v) for k, v in by_book.items()},
            'multi_book_count': multi_book
        }
    }


def write_master_list(consolidated: Dict, output_file: Path):
    """Write consolidated master list to file."""
    
    output_file.parent.mkdir(parents=True, exist_ok=True)
    
    with open(output_file, 'w', encoding='utf-8') as f:
        f.write("Power ISA 2.07 - Complete Master Instruction List\n")
        f.write("=" * 80 + "\n\n")
        f.write("This file consolidates instructions from all Power ISA 2.07 books:\n")
        f.write("- Book I: User Instruction Set Architecture\n")
        f.write("- Book II: Virtual Environment Architecture\n")
        f.write("- Book III-S: Operating Environment Architecture (Server)\n")
        f.write("- Book III-E: Operating Environment Architecture (Embedded)\n")
        f.write("- Book V: Variable Length Encoding (VLE)\n\n")
        f.write(f"Total unique instructions: {consolidated['summary']['total_unique']}\n\n")
        f.write("=" * 80 + "\n\n")
        
        # Write by book
        for book_name in sorted(consolidated['by_book'].keys()):
            f.write(f"\n### Book {book_name} Instructions ({len(consolidated['by_book'][book_name])} total)\n\n")
            
            # Sort instructions by mnemonic
            sorted_insts = sorted(consolidated['by_book'][book_name], 
                                key=lambda x: x['mnemonic'])
            
            for inst in sorted_insts:
                f.write(f"{inst['mnemonic']:<30} {inst['categories']:<40} {inst['description'][:50]}\n")
        
        # Write master list (deduplicated)
        f.write(f"\n\n### Master List (Deduplicated, {consolidated['summary']['total_unique']} unique)\n\n")
        
        # Sort by mnemonic
        sorted_all = sorted(consolidated['all'].items(), 
                          key=lambda x: x[1]['mnemonic'])
        
        for norm_mnemonic, inst_info in sorted_all:
            books_str = ', '.join(sorted(inst_info['books']))
            f.write(f"{inst_info['mnemonic']:<30} [Books: {books_str:<15}] {inst_info['description'][:50]}\n")
    
    print(f"\nMaster list written to: {output_file}")


def write_instruction_set(consolidated: Dict, output_file: Path):
    """Write simple instruction set (just mnemonics) for comparison."""
    
    output_file.parent.mkdir(parents=True, exist_ok=True)
    
    with open(output_file, 'w', encoding='utf-8') as f:
        f.write("# Power ISA 2.07 - Complete Instruction Set (Mnemonics Only)\n")
        f.write("# For use in comparing against e200 core manuals and LLVM implementation\n\n")
        
        # Write all unique mnemonics
        sorted_all = sorted(consolidated['all'].keys())
        
        for mnemonic in sorted_all:
            inst_info = consolidated['all'][mnemonic]
            books_str = ','.join(sorted(inst_info['books']))
            f.write(f"{inst_info['mnemonic']}\n")
    
    print(f"Instruction set (mnemonics) written to: {output_file}")


def main():
    """Main execution."""
    consolidated = consolidate_instructions()
    
    # Write output files
    output_dir = Path('.')
    
    master_list_file = output_dir / 'powerisa_v2_07_master_list.txt'
    write_master_list(consolidated, master_list_file)
    
    instruction_set_file = output_dir / 'powerisa_v2_07_instruction_set.txt'
    write_instruction_set(consolidated, instruction_set_file)
    
    print(f"\n=== Consolidation Complete ===")
    print(f"Total unique Power ISA 2.07 instructions: {consolidated['summary']['total_unique']}")
    print(f"Files generated:")
    print(f"  - {master_list_file}")
    print(f"  - {instruction_set_file}")


if __name__ == '__main__':
    main()

