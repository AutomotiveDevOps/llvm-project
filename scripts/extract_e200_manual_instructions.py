#!/usr/bin/env python3
"""
Extract instruction lists from e200 core reference manuals.

This script extracts:
1. Supported instructions (from instruction tables/opcode tables)
2. Unsupported/illegal instructions (from "Unsupported Instructions" sections)
3. Core-specific instruction extensions

Supports e200z0, e200z3, e200z4, e200z6, e200z7 cores.
"""

import re
import sys
from pathlib import Path
from typing import Dict, List, Set, Tuple, Optional
from collections import defaultdict

try:
    import pypdf
    HAS_PYPDF = True
except ImportError:
    try:
        import PyPDF2
        HAS_PYPDF2 = True
        HAS_PYPDF = False
    except ImportError:
        HAS_PYPDF = False
        HAS_PYPDF2 = False


def extract_text_from_pdf(pdf_path: Path) -> Optional[str]:
    """Extract text from PDF file."""
    if not pdf_path.exists():
        return None
    
    text_content = []
    
    try:
        if HAS_PYPDF:
            with open(pdf_path, 'rb') as f:
                pdf_reader = pypdf.PdfReader(f)
                for page in pdf_reader.pages:
                    text_content.append(page.extract_text())
        elif HAS_PYPDF2:
            with open(pdf_path, 'rb') as f:
                pdf_reader = PyPDF2.PdfReader(f)
                for page in pdf_reader.pages:
                    text_content.append(page.extract_text())
        else:
            print("Warning: No PDF library available. Install pypdf: pip install pypdf")
            return None
    except Exception as e:
        print(f"Error reading PDF {pdf_path}: {e}")
        return None
    
    return '\n'.join(text_content)


def find_chapter_3(text: str) -> str:
    """Find and extract Chapter 3 (Instruction Model) content."""
    lines = text.split('\n')
    chapter_start = None
    chapter_end = None
    
    # Look for Chapter 3 markers
    for i, line in enumerate(lines):
        if re.search(r'Chapter\s+3[:\s]+.*?Instruction\s+Model', line, re.IGNORECASE):
            chapter_start = i
        elif chapter_start and re.search(r'Chapter\s+4', line, re.IGNORECASE):
            chapter_end = i
            break
    
    if chapter_start:
        return '\n'.join(lines[chapter_start:chapter_end] if chapter_end else lines[chapter_start:])
    
    return text  # Fallback to full text


def extract_instruction_table(text: str) -> List[str]:
    """Extract instructions from instruction tables."""
    instructions = []
    
    # Look for instruction mnemonics in tables
    # Pattern: mnemonic at start of line or in structured table
    patterns = [
        # Table rows with instruction mnemonics
        r'^([a-z][a-z0-9_]+)\s+[A-Z0-9]{2,6}',  # mnemonic followed by format code
        r'\b([a-z][a-z0-9_]{2,15})\s+[A-Z0-9]{2,6}\s+',  # mnemonic with format
        r'^\s*([e_]?[a-z][a-z0-9_]+)\s+',  # mnemonic at start (VLE format)
    ]
    
    lines = text.split('\n')
    for line in lines:
        # Skip header lines
        if re.search(r'(?:Table|Chapter|Page|Mnemonic|Opcode)', line, re.IGNORECASE):
            continue
        
        for pattern in patterns:
            match = re.search(pattern, line, re.IGNORECASE)
            if match:
                mnemonic = match.group(1).strip().lower()
                # Filter out common false positives
                if mnemonic and len(mnemonic) >= 2 and \
                   mnemonic not in ['table', 'chapter', 'page', 'section', 'note']:
                    instructions.append(mnemonic)
                    break
    
    return sorted(set(instructions))


def extract_unsupported_instructions(text: str) -> List[str]:
    """Extract unsupported/illegal instructions from manual."""
    unsupported = []
    
    # Look for "Unsupported Instructions" or "Illegal Instructions" sections
    unsupported_section = None
    lines = text.split('\n')
    
    for i, line in enumerate(lines):
        if re.search(r'(?:Unsupported|Illegal)\s+Instructions', line, re.IGNORECASE):
            # Extract section until next major heading
            section_lines = []
            for j in range(i, min(i + 200, len(lines))):
                next_line = lines[j]
                if j > i and re.search(r'^Chapter\s+\d+|^Section\s+\d+|^Table\s+\d+', next_line, re.IGNORECASE):
                    break
                section_lines.append(next_line)
            unsupported_section = '\n'.join(section_lines)
            break
    
    if unsupported_section:
        # Extract instruction mnemonics from the section
        # Patterns for instruction mnemonics
        pattern = r'\b([a-z][a-z0-9_]{2,15})\b'
        matches = re.findall(pattern, unsupported_section, re.IGNORECASE)
        for match in matches:
            # Filter to likely instruction names
            if len(match) >= 2 and match not in ['the', 'and', 'are', 'not', 'for', 'with', 'that', 'this']:
                unsupported.append(match.lower())
    
    return sorted(set(unsupported))


def extract_opcode_table(text: str) -> List[str]:
    """Extract instructions from opcode tables."""
    instructions = []
    
    # Look for opcode tables (instructions sorted by opcode)
    # Pattern: opcode hex value followed by instruction mnemonic
    patterns = [
        r'([0-9A-F]{4})\s+([a-z][a-z0-9_]+)',  # Opcode hex + mnemonic
        r'([0-9A-F]{8})\s+([a-z][a-z0-9_]+)',  # 32-bit opcode + mnemonic
    ]
    
    for pattern in patterns:
        matches = re.finditer(pattern, text, re.IGNORECASE)
        for match in matches:
            mnemonic = match.group(2).strip().lower()
            if mnemonic and len(mnemonic) >= 2:
                instructions.append(mnemonic)
    
    return sorted(set(instructions))


def extract_vle_instructions(text: str) -> List[str]:
    """Extract VLE-specific instructions (e_* and se_* prefixes)."""
    vle_instructions = []
    
    # Look for VLE instruction patterns
    patterns = [
        r'\b([es]_[a-z][a-z0-9_]+)\b',  # e_* or se_* prefixes
        r'\b([es][es]_[a-z][a-z0-9_]+)\b',  # se_* prefix
    ]
    
    for pattern in patterns:
        matches = re.finditer(pattern, text, re.IGNORECASE)
        for match in matches:
            mnemonic = match.group(1).strip().lower()
            if mnemonic:
                vle_instructions.append(mnemonic)
    
    return sorted(set(vle_instructions))


def extract_manual_instructions(pdf_path: Path, core_name: str) -> Dict[str, List[str]]:
    """Extract all instruction information from a manual."""
    print(f"Extracting instructions from {pdf_path.name} ({core_name})...")
    
    text = extract_text_from_pdf(pdf_path)
    if not text:
        print(f"  Warning: Could not extract text from {pdf_path}")
        return {}
    
    print(f"  Extracted {len(text)} characters")
    
    # Find Chapter 3 (Instruction Model)
    chapter_3 = find_chapter_3(text)
    
    results = {
        'supported': [],
        'unsupported': [],
        'vle_specific': [],
        'all_found': []
    }
    
    # Extract from instruction tables
    print("  Extracting from instruction tables...")
    table_instructions = extract_instruction_table(chapter_3)
    results['supported'].extend(table_instructions)
    results['all_found'].extend(table_instructions)
    
    # Extract from opcode tables
    print("  Extracting from opcode tables...")
    opcode_instructions = extract_opcode_table(chapter_3)
    results['supported'].extend(opcode_instructions)
    results['all_found'].extend(opcode_instructions)
    
    # Extract unsupported instructions
    print("  Extracting unsupported instructions...")
    unsupported = extract_unsupported_instructions(text)
    results['unsupported'] = unsupported
    
    # Extract VLE-specific instructions
    print("  Extracting VLE instructions...")
    vle_insts = extract_vle_instructions(text)
    results['vle_specific'] = vle_insts
    results['all_found'].extend(vle_insts)
    
    # Deduplicate
    results['supported'] = sorted(set(results['supported']))
    results['all_found'] = sorted(set(results['all_found']))
    
    print(f"  Found {len(results['supported'])} supported instructions")
    print(f"  Found {len(results['unsupported'])} unsupported instructions")
    print(f"  Found {len(results['vle_specific'])} VLE-specific instructions")
    
    return results


def write_extraction_report(results: Dict[str, Dict[str, List[str]]], output_dir: Path):
    """Write extraction reports for each core."""
    output_dir.mkdir(parents=True, exist_ok=True)
    
    for core_name, core_results in results.items():
        report_file = output_dir / f"{core_name}_manual_instructions.txt"
        
        with open(report_file, 'w', encoding='utf-8') as f:
            f.write(f"{core_name.upper()} Core Reference Manual - Extracted Instructions\n")
            f.write("=" * 80 + "\n\n")
            
            f.write(f"Supported Instructions ({len(core_results['supported'])} total):\n")
            f.write("-" * 80 + "\n")
            for inst in core_results['supported']:
                f.write(f"  {inst}\n")
            
            f.write(f"\n\nUnsupported/Illegal Instructions ({len(core_results['unsupported'])} total):\n")
            f.write("-" * 80 + "\n")
            for inst in core_results['unsupported']:
                f.write(f"  {inst}\n")
            
            f.write(f"\n\nVLE-Specific Instructions ({len(core_results['vle_specific'])} total):\n")
            f.write("-" * 80 + "\n")
            for inst in core_results['vle_specific']:
                f.write(f"  {inst}\n")
            
            f.write(f"\n\nAll Instructions Found ({len(core_results['all_found'])} total):\n")
            f.write("-" * 80 + "\n")
            for inst in core_results['all_found']:
                f.write(f"  {inst}\n")
        
        print(f"  Report written to: {report_file}")


def main():
    """Main execution."""
    if len(sys.argv) < 2:
        print("Usage: extract_e200_manual_instructions.py <core_name> [pdf_path]")
        print("\nExample:")
        print("  extract_e200_manual_instructions.py e200z0 e200_core_reference/powerpc-e200z0.pdf")
        print("  extract_e200_manual_instructions.py all  # Extract from all cores")
        sys.exit(1)
    
    core_name = sys.argv[1].lower()
    
    base_dir = Path('.')
    manual_dir = base_dir / 'e200_core_reference'
    
    # Map core names to PDF files
    core_pdfs = {
        'e200z0': manual_dir / 'powerpc-e200z0.pdf',
        'e200z3': manual_dir / 'powerpc-e200z3.pdf',
        'e200z4': manual_dir / 'powerpc-e200z4.pdf',
        'e200z6': manual_dir / 'powerpc-e200z6.pdf',
        'e200z7': manual_dir / 'powerpc-e200z760n3.pdf',
    }
    
    all_results = {}
    
    if core_name == 'all':
        # Extract from all cores
        print("=== Extracting Instructions from All e200 Core Manuals ===\n")
        for name, pdf_path in core_pdfs.items():
            if pdf_path.exists():
                results = extract_manual_instructions(pdf_path, name)
                all_results[name] = results
            else:
                print(f"  Warning: {pdf_path} does not exist")
    elif core_name in core_pdfs:
        # Extract from single core
        pdf_path = core_pdfs[core_name]
        if len(sys.argv) > 2:
            pdf_path = Path(sys.argv[2])
        
        results = extract_manual_instructions(pdf_path, core_name)
        all_results[core_name] = results
    else:
        print(f"Error: Unknown core name: {core_name}")
        print(f"Supported: {', '.join(core_pdfs.keys())}, or 'all'")
        sys.exit(1)
    
    # Write reports
    if all_results:
        output_dir = base_dir / 'e200_manual_extractions'
        write_extraction_report(all_results, output_dir)
        
        print(f"\n=== Extraction Complete ===")
        for name, results in all_results.items():
            print(f"{name}: {len(results['supported'])} supported, "
                  f"{len(results['unsupported'])} unsupported")


if __name__ == '__main__':
    main()

