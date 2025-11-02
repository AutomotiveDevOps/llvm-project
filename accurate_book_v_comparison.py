#!/usr/bin/env python3
"""Accurate 1:1 comparison for Book V (VLE) instructions.

This script properly separates:
- VLE-specific instructions (e_ prefixed, se_ prefixed)
- Book I instructions that are VLE-compatible
"""

import re
from collections import defaultdict
from typing import Dict, List, Set, Tuple


def normalize_mnemonic(mnemonic: str) -> str:
    """Normalize instruction mnemonic for comparison."""
    # Convert to lowercase
    mnemonic = mnemonic.lower().strip()
    
    # Remove underscores (LLVM uses them, spec doesn't always)
    mnemonic = mnemonic.replace('_', '')
    
    # Remove common suffixes
    mnemonic = re.sub(r'\[[^\]]+\]', '', mnemonic)  # [o][.]
    mnemonic = re.sub(r'\.$', '', mnemonic)  # Trailing dot
    
    return mnemonic


def is_vle_specific(mnemonic: str) -> bool:
    """Check if an instruction is VLE-specific (not just VLE-compatible)."""
    mnemonic_lower = mnemonic.lower()
    
    # VLE-specific prefixes
    if mnemonic_lower.startswith('e_') or mnemonic_lower.startswith('se_'):
        return True
    
    # Check for VLE-only encoding forms
    # These are instructions that only exist in VLE encoding
    vle_only_patterns = [
        'e_add2is', 'e_add2i', 'e_or2i', 'e_or2is', 'e_mull2i',
        'e_cmp16i', 'e_cmph16i', 'e_cmphl16i', 'e_cmpl16i'
    ]
    
    for pattern in vle_only_patterns:
        if pattern in mnemonic_lower:
            return True
    
    return False


def categorize_book_v_instructions() -> Tuple[Set[str], Set[str]]:
    """Categorize Book V instructions into VLE-specific vs VLE-compatible Book I."""
    vle_specific = set()
    vle_compatible_book_i = set()
    
    # Load Book V instructions from spec
    try:
        with open('powerisa_v2_07_book_V_instructions.txt', 'r') as f:
            for line in f:
                if line.strip() and not line.startswith('=') and not line.startswith('Power'):
                    parts = line.split()
                    if parts:
                        mnemonic = parts[0]
                        normalized = normalize_mnemonic(mnemonic)
                        
                        if is_vle_specific(mnemonic):
                            vle_specific.add(normalized)
                        else:
                            vle_compatible_book_i.add(normalized)
    except FileNotFoundError:
        print("Warning: powerisa_v2_07_book_V_instructions.txt not found")
    
    return vle_specific, vle_compatible_book_i


def load_book_i_spec() -> Set[str]:
    """Load Book I instructions from spec."""
    book_i_spec = set()
    
    try:
        with open('powerisa_v2_07_book_I_complete.txt', 'r') as f:
            for line in f:
                if line.strip() and not line.startswith('=') and not line.startswith('Power'):
                    parts = line.split()
                    if parts:
                        mnemonic = parts[0]
                        book_i_spec.add(normalize_mnemonic(mnemonic))
    except FileNotFoundError:
        print("Warning: powerisa_v2_07_book_I_complete.txt not found")
    
    return book_i_spec


def load_llvm_vle_instructions() -> Set[str]:
    """Load LLVM VLE-specific instructions (Book V in LLVM)."""
    llvm_vle = set()
    
    try:
        with open('llvm_ppc_instructions_by_book.txt', 'r') as f:
            in_book_v = False
            for line in f:
                # Detect Book V section
                if re.search(r'Book\s+V', line, re.IGNORECASE):
                    in_book_v = True
                    continue
                
                # Detect next book section
                if in_book_v and re.search(r'^Book\s+[IVX]', line):
                    break
                
                # Extract instruction from Book V section
                if in_book_v and line.strip() and not line.startswith('-') and not line.startswith('='):
                    parts = line.split()
                    if parts:
                        mnemonic = parts[0]
                        llvm_vle.add(normalize_mnemonic(mnemonic))
    except FileNotFoundError:
        print("Warning: llvm_ppc_instructions_by_book.txt not found")
    
    return llvm_vle


def load_llvm_book_i_instructions() -> Set[str]:
    """Load LLVM Book I instructions."""
    llvm_book_i = set()
    
    try:
        with open('llvm_ppc_instructions_by_book.txt', 'r') as f:
            in_book_i = False
            for line in f:
                # Detect Book I section
                if re.search(r'Book\s+I\s*\(', line, re.IGNORECASE):
                    in_book_i = True
                    continue
                
                # Detect next book section
                if in_book_i and re.search(r'^Book\s+[IVX]', line) and 'Book I' not in line:
                    break
                
                # Extract instruction from Book I section
                if in_book_i and line.strip() and not line.startswith('-') and not line.startswith('=') and not line.startswith('Book'):
                    parts = line.split()
                    if parts:
                        mnemonic = parts[0]
                        llvm_book_i.add(normalize_mnemonic(mnemonic))
    except FileNotFoundError:
        print("Warning: llvm_ppc_instructions_by_book.txt not found")
    
    return llvm_book_i


def compare_vle_specific():
    """Compare VLE-specific instructions: spec vs LLVM."""
    print("=" * 70)
    print("VLE-SPECIFIC INSTRUCTIONS COMPARISON")
    print("=" * 70)
    
    # Categorize Book V spec instructions
    vle_spec_specific, vle_spec_book_i = categorize_book_v_instructions()
    
    # Load LLVM VLE instructions
    llvm_vle = load_llvm_vle_instructions()
    
    # Find matches
    matching_vle = vle_spec_specific & llvm_vle
    missing_vle = vle_spec_specific - llvm_vle
    extra_vle = llvm_vle - vle_spec_specific
    
    # Calculate coverage
    coverage_vle = (len(matching_vle) / len(vle_spec_specific) * 100) if vle_spec_specific else 0
    
    print(f"\nSpec VLE-specific instructions: {len(vle_spec_specific)}")
    print(f"LLVM VLE-specific instructions: {len(llvm_vle)}")
    print(f"Matching: {len(matching_vle)}")
    print(f"Coverage: {coverage_vle:.1f}%")
    
    if missing_vle:
        print(f"\nMissing from LLVM ({len(missing_vle)}):")
        for inst in sorted(list(missing_vle))[:20]:
            print(f"  - {inst}")
        if len(missing_vle) > 20:
            print(f"  ... and {len(missing_vle) - 20} more")
    
    if extra_vle:
        print(f"\nExtra in LLVM ({len(extra_vle)} - may be newer ISA/variants):")
        for inst in sorted(list(extra_vle))[:20]:
            print(f"  - {inst}")
        if len(extra_vle) > 20:
            print(f"  ... and {len(extra_vle) - 20} more")
    
    return {
        'spec_count': len(vle_spec_specific),
        'llvm_count': len(llvm_vle),
        'matching': len(matching_vle),
        'missing': len(missing_vle),
        'extra': len(extra_vle),
        'coverage': coverage_vle,
        'matching_list': sorted(list(matching_vle)),
        'missing_list': sorted(list(missing_vle)),
        'extra_list': sorted(list(extra_vle))
    }


def compare_vle_compatible_book_i():
    """Compare VLE-compatible Book I instructions."""
    print("\n" + "=" * 70)
    print("VLE-COMPATIBLE BOOK I INSTRUCTIONS COMPARISON")
    print("=" * 70)
    
    # Categorize Book V spec instructions
    vle_spec_specific, vle_spec_book_i = categorize_book_v_instructions()
    
    # Load LLVM Book I instructions
    llvm_book_i = load_llvm_book_i_instructions()
    
    # Also load spec Book I to verify these are actually Book I instructions
    spec_book_i = load_book_i_spec()
    
    # Find matches
    matching_book_i = vle_spec_book_i & llvm_book_i
    missing_book_i = vle_spec_book_i - llvm_book_i
    
    # Also check if they're in spec Book I
    in_spec_book_i = vle_spec_book_i & spec_book_i
    not_in_spec_book_i = vle_spec_book_i - spec_book_i
    
    coverage_book_i = (len(matching_book_i) / len(vle_spec_book_i) * 100) if vle_spec_book_i else 0
    
    print(f"\nVLE-compatible Book I instructions in spec: {len(vle_spec_book_i)}")
    print(f"LLVM Book I instructions: {len(llvm_book_i)}")
    print(f"Matching in LLVM Book I: {len(matching_book_i)}")
    print(f"Coverage: {coverage_book_i:.1f}%")
    
    print(f"\nOf {len(vle_spec_book_i)} VLE-compatible Book I instructions:")
    print(f"  - Found in spec Book I: {len(in_spec_book_i)}")
    print(f"  - Not in spec Book I (may be VLE-only variants): {len(not_in_spec_book_i)}")
    
    if missing_book_i:
        print(f"\nMissing from LLVM Book I ({len(missing_book_i)}):")
        for inst in sorted(list(missing_book_i))[:20]:
            print(f"  - {inst}")
        if len(missing_book_i) > 20:
            print(f"  ... and {len(missing_book_i) - 20} more")
    
    return {
        'spec_count': len(vle_spec_book_i),
        'llvm_count': len(llvm_book_i),
        'matching': len(matching_book_i),
        'missing': len(missing_book_i),
        'coverage': coverage_book_i,
        'in_spec_book_i': len(in_spec_book_i),
        'not_in_spec_book_i': len(not_in_spec_book_i)
    }


def generate_accurate_report():
    """Generate accurate 1:1 comparison report for Book V."""
    print("\n" + "=" * 70)
    print("ACCURATE BOOK V (VLE) COMPARISON REPORT")
    print("=" * 70)
    
    # Compare VLE-specific instructions
    vle_result = compare_vle_specific()
    
    # Compare VLE-compatible Book I instructions
    book_i_result = compare_vle_compatible_book_i()
    
    # Overall summary
    print("\n" + "=" * 70)
    print("SUMMARY")
    print("=" * 70)
    
    total_spec_vle = vle_result['spec_count'] + book_i_result['spec_count']
    total_matching = vle_result['matching'] + book_i_result['matching']
    overall_coverage = (total_matching / total_spec_vle * 100) if total_spec_vle > 0 else 0
    
    print(f"\nTotal Book V instructions in spec: {total_spec_vle}")
    print(f"  - VLE-specific: {vle_result['spec_count']}")
    print(f"  - VLE-compatible Book I: {book_i_result['spec_count']}")
    print(f"\nTotal matching: {total_matching}")
    print(f"  - VLE-specific matches: {vle_result['matching']} ({vle_result['coverage']:.1f}%)")
    print(f"  - Book I matches: {book_i_result['matching']} ({book_i_result['coverage']:.1f}%)")
    print(f"\nOverall Book V coverage: {overall_coverage:.1f}%")
    
    # Generate markdown report
    with open('BOOK_V_ACCURATE_COMPARISON.md', 'w') as f:
        f.write("# Book V (VLE) Accurate 1:1 Comparison Report\n\n")
        f.write("This report provides an accurate comparison by properly categorizing ")
        f.write("Book V instructions into VLE-specific vs VLE-compatible Book I instructions.\n\n")
        
        f.write("## Executive Summary\n\n")
        f.write(f"- **Total Book V spec instructions**: {total_spec_vle}\n")
        f.write(f"- **Total matching**: {total_matching}\n")
        f.write(f"- **Overall coverage**: {overall_coverage:.1f}%\n\n")
        
        f.write("## VLE-Specific Instructions\n\n")
        f.write(f"- **Spec count**: {vle_result['spec_count']}\n")
        f.write(f"- **LLVM count**: {vle_result['llvm_count']}\n")
        f.write(f"- **Matching**: {vle_result['matching']}\n")
        f.write(f"- **Coverage**: {vle_result['coverage']:.1f}%\n")
        f.write(f"- **Missing**: {vle_result['missing']}\n")
        f.write(f"- **Extra in LLVM**: {vle_result['extra']} (may be newer ISA/variants)\n\n")
        
        if vle_result['matching_list']:
            f.write("### Matching VLE-Specific Instructions:\n\n")
            for inst in vle_result['matching_list']:
                f.write(f"- `{inst}`\n")
            f.write("\n")
        
        if vle_result['missing_list']:
            f.write("### Missing VLE-Specific Instructions:\n\n")
            for inst in vle_result['missing_list']:
                f.write(f"- `{inst}`\n")
            f.write("\n")
        
        f.write("## VLE-Compatible Book I Instructions\n\n")
        f.write(f"- **Spec count**: {book_i_result['spec_count']}\n")
        f.write(f"- **LLVM Book I count**: {book_i_result['llvm_count']}\n")
        f.write(f"- **Matching**: {book_i_result['matching']}\n")
        f.write(f"- **Coverage**: {book_i_result['coverage']:.1f}%\n")
        f.write(f"- **In spec Book I**: {book_i_result['in_spec_book_i']}\n")
        f.write(f"- **Not in spec Book I**: {book_i_result['not_in_spec_book_i']}\n\n")
        
        f.write("## Conclusion\n\n")
        f.write(f"**VLE-Specific Instructions**: {vle_result['coverage']:.1f}% coverage ")
        f.write(f"({vle_result['matching']}/{vle_result['spec_count']})\n\n")
        f.write(f"**VLE-Compatible Book I Instructions**: {book_i_result['coverage']:.1f}% coverage ")
        f.write(f"({book_i_result['matching']}/{book_i_result['spec_count']})\n\n")
        f.write("**Note**: VLE-compatible Book I instructions are already covered ")
        f.write("in the Book I comparison (97.5% coverage). The VLE-specific instructions ")
        f.write("are the ones that require separate VLE encoding support.\n")
    
    print(f"\n=== Report Generated ===")
    print(f"Saved to BOOK_V_ACCURATE_COMPARISON.md")
    
    return vle_result, book_i_result, overall_coverage


if __name__ == '__main__':
    vle_result, book_i_result, overall = generate_accurate_report()
    print(f"\nFinal Summary:")
    print(f"  VLE-specific: {vle_result['coverage']:.1f}% coverage")
    print(f"  VLE-compatible Book I: {book_i_result['coverage']:.1f}% coverage")
    print(f"  Overall Book V: {overall:.1f}% coverage")

