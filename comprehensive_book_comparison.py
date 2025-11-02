#!/usr/bin/env python3
"""Comprehensive comparison of Power ISA 2.07 books against LLVM implementation."""

import re
from collections import defaultdict
from typing import Dict, List, Set, Tuple


def normalize_mnemonic(mnemonic: str) -> str:
    """Normalize instruction mnemonic for comparison."""
    # Convert to lowercase
    mnemonic = mnemonic.lower().strip()
    
    # Remove underscores (LLVM uses them, spec doesn't)
    mnemonic = mnemonic.replace('_', '')
    
    # Remove common suffixes
    mnemonic = re.sub(r'\[[^\]]+\]', '', mnemonic)  # [o][.]
    mnemonic = re.sub(r'\.$', '', mnemonic)  # Trailing dot
    
    return mnemonic


def load_spec_instructions() -> Dict[str, Set[str]]:
    """Load spec instructions by book."""
    spec_by_book = defaultdict(set)
    
    # Load from extracted files
    for book in ['I', 'II', 'III-S', 'III-E', 'V']:
        filename = f'powerisa_v2_07_book_{book}_complete.txt'
        try:
            with open(filename, 'r') as f:
                for line in f:
                    if line.strip() and not line.startswith('=') and not line.startswith('Power'):
                        parts = line.split()
                        if parts:
                            mnemonic = parts[0].lower()
                            spec_by_book[book].add(normalize_mnemonic(mnemonic))
        except FileNotFoundError:
            pass
    
    # Also try the VLE file
    try:
        with open('powerisa_v2_07_book_V_instructions.txt', 'r') as f:
            for line in f:
                if line.strip() and not line.startswith('='):
                    parts = line.split()
                    if parts:
                        mnemonic = parts[0].lower()
                        spec_by_book['V'].add(normalize_mnemonic(mnemonic))
    except FileNotFoundError:
        pass
    
    return dict(spec_by_book)


def load_llvm_instructions() -> Dict[str, Set[str]]:
    """Load LLVM instructions by book."""
    llvm_by_book = defaultdict(set)
    
    try:
        with open('llvm_ppc_instructions_by_book.txt', 'r') as f:
            current_book = None
            for line in f:
                # Detect book header
                book_match = re.search(r'Book\s+([IVX]+(?:-[ES])?)', line)
                if book_match:
                    current_book = book_match.group(1)
                    continue
                
                # Extract instruction
                if current_book and line.strip() and not line.startswith('-') and not line.startswith('='):
                    parts = line.split()
                    if parts:
                        mnemonic = parts[0].lower()
                        llvm_by_book[current_book].add(normalize_mnemonic(mnemonic))
    except FileNotFoundError:
        # Fallback: extract directly from source files
        pass
    
    return dict(llvm_by_book)


def compare_book(spec_insts: Set[str], llvm_insts: Set[str], book_name: str) -> Dict:
    """Compare spec and LLVM instructions for a book."""
    
    # Find matches
    matching = spec_insts & llvm_insts
    
    # Find missing (in spec but not in LLVM)
    missing = spec_insts - llvm_insts
    
    # Find extra (in LLVM but not in spec - may be newer ISA or variants)
    extra = llvm_insts - spec_insts
    
    # Calculate coverage
    coverage = (len(matching) / len(spec_insts) * 100) if spec_insts else 0
    
    return {
        'book': book_name,
        'spec_count': len(spec_insts),
        'llvm_count': len(llvm_insts),
        'matching': len(matching),
        'missing': len(missing),
        'extra': len(extra),
        'coverage': coverage,
        'missing_list': sorted(list(missing))[:50],  # Sample
        'matching_list': sorted(list(matching))[:20],  # Sample
        'extra_list': sorted(list(extra))[:20]  # Sample
    }


def generate_comprehensive_report():
    """Generate comprehensive completeness report."""
    print("=== Power ISA 2.07 Comprehensive Completeness Analysis ===\n")
    
    # Load instructions
    print("Loading spec instructions...")
    spec_by_book = load_spec_instructions()
    
    print("Loading LLVM instructions...")
    llvm_by_book = load_llvm_instructions()
    
    print("\n=== Spec Instructions by Book ===\n")
    for book in sorted(spec_by_book.keys()):
        print(f"Book {book}: {len(spec_by_book[book])} instructions")
    
    print("\n=== LLVM Instructions by Book ===\n")
    for book in sorted(llvm_by_book.keys()):
        print(f"Book {book}: {len(llvm_by_book[book])} instructions")
    
    # Compare each book
    print("\n=== Book-by-Book Comparison ===\n")
    
    comparisons = {}
    
    for book in sorted(set(list(spec_by_book.keys()) + list(llvm_by_book.keys()))):
        spec_insts = spec_by_book.get(book, set())
        llvm_insts = llvm_by_book.get(book, set())
        
        if spec_insts or llvm_insts:
            comp = compare_book(spec_insts, llvm_insts, book)
            comparisons[book] = comp
            
            print(f"Book {book}:")
            print(f"  Spec: {comp['spec_count']} instructions")
            print(f"  LLVM: {comp['llvm_count']} instructions")
            print(f"  Matching: {comp['matching']}")
            print(f"  Coverage: {comp['coverage']:.1f}%")
            if comp['missing'] > 0:
                print(f"  Missing: {comp['missing']} instructions")
                print(f"    Sample: {', '.join(comp['missing_list'][:10])}")
            if comp['extra'] > 0:
                print(f"  Extra in LLVM: {comp['extra']} (may be newer ISA or variants)")
            print()
    
    # Overall summary
    total_spec = sum(len(insts) for insts in spec_by_book.values())
    total_llvm = sum(len(insts) for insts in llvm_by_book.values())
    total_matching = sum(comp['matching'] for comp in comparisons.values())
    overall_coverage = (total_matching / total_spec * 100) if total_spec > 0 else 0
    
    print(f"\n=== Overall Summary ===\n")
    print(f"Total spec instructions: {total_spec}")
    print(f"Total LLVM instructions: {total_llvm}")
    print(f"Total matching: {total_matching}")
    print(f"Overall coverage: {overall_coverage:.1f}%")
    
    # Generate markdown report
    with open('POWERISA_V2_07_COMPLETE_COMPLETENESS_REPORT.md', 'w') as f:
        f.write("# Power ISA 2.07 Complete Implementation Completeness Report\n\n")
        f.write("## Executive Summary\n\n")
        f.write(f"**Overall Coverage: {overall_coverage:.1f}%** ({total_matching} of {total_spec} spec instructions)\n\n")
        f.write("### Key Findings\n\n")
        
        for book in sorted(comparisons.keys()):
            comp = comparisons[book]
            f.write(f"- **Book {book}**: {comp['coverage']:.1f}% coverage ")
            f.write(f"({comp['matching']}/{comp['spec_count']} instructions)\n")
        
        f.write("\n## Detailed Book-by-Book Analysis\n\n")
        
        for book in sorted(comparisons.keys()):
            comp = comparisons[book]
            f.write(f"### Book {book}\n\n")
            f.write(f"- **Spec Instructions**: {comp['spec_count']}\n")
            f.write(f"- **LLVM Instructions**: {comp['llvm_count']}\n")
            f.write(f"- **Matching**: {comp['matching']}\n")
            f.write(f"- **Coverage**: {comp['coverage']:.1f}%\n")
            
            if comp['missing'] > 0:
                f.write(f"- **Missing from LLVM**: {comp['missing']} instructions\n")
                f.write(f"  - Sample: {', '.join(comp['missing_list'][:20])}\n")
            
            if comp['extra'] > 0:
                f.write(f"- **Additional in LLVM**: {comp['extra']} instructions ")
            f.write("(may include newer ISA versions or instruction variants)\n")
            f.write("\n")
        
        f.write("## Notes\n\n")
        f.write("1. Instruction name normalization accounts for case differences and underscores\n")
        f.write("2. LLVM may include instructions from Power ISA versions beyond 2.07 (3.0, 3.1)\n")
        f.write("3. Some spec instructions may be aliases or have different names in LLVM\n")
        f.write("4. Coverage calculated based on matching instruction mnemonics\n")
        f.write("5. This analysis is based on extracted instruction lists from the PDF\n\n")
        
        f.write("## Conclusion\n\n")
        f.write("**Answer:** Based on the analysis of Power ISA 2.07 specification ")
        f.write(f"(as extracted from the PDF), LLVM implements **{overall_coverage:.1f}%** of the instructions.\n\n")
        
        f.write("However, note that:\n")
        f.write("- The PDF extraction may not capture all instructions\n")
        f.write("- LLVM includes instructions from newer ISA versions\n")
        f.write("- Some instructions may be implemented but with different names\n")
        f.write("- Complete verification requires full specification comparison\n")
    
    print(f"\n=== Report Generated ===\n")
    print(f"Saved comprehensive report to POWERISA_V2_07_COMPLETE_COMPLETENESS_REPORT.md")
    
    return comparisons, overall_coverage


if __name__ == '__main__':
    comparisons, coverage = generate_comprehensive_report()
    print(f"\nFinal Answer: LLVM implements approximately {coverage:.1f}% of Power ISA 2.07")

