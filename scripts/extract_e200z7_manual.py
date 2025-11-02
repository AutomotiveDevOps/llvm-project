#!/usr/bin/env python3
"""
Extract key information from e200z7/e200z760 Core Reference Manual PDF.

This script extracts timing specifications, pairing rules, and functional unit
details from Chapter 4 of the manual for validation against LLVM implementation.
"""

import sys
import re
from pathlib import Path

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
        print("Warning: No PDF library available. Install pypdf: pip install pypdf")

def extract_text_from_pdf(pdf_path):
    """Extract text from PDF file."""
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
            print("Error: No PDF library available")
            return None
    except Exception as e:
        print(f"Error reading PDF: {e}")
        return None
    
    return '\n'.join(text_content)

def find_chapter_4(text, pdf_path):
    """Find and extract Chapter 4 content."""
    # Look for Chapter 4 markers
    chapter_patterns = [
        r'Chapter\s+4[:\s]+.*?Instruction\s+Pipeline',
        r'Chapter\s+4[:\s]+.*?Execution\s+Timing',
        r'4\s+Instruction\s+Pipeline',
    ]
    
    # Try to find chapter boundaries
    lines = text.split('\n')
    chapter_start = None
    chapter_end = None
    
    for i, line in enumerate(lines):
        if re.search(r'Chapter\s+4', line, re.IGNORECASE):
            chapter_start = i
        elif chapter_start and re.search(r'Chapter\s+5', line, re.IGNORECASE):
            chapter_end = i
            break
    
    if chapter_start:
        chapter_text = '\n'.join(lines[chapter_start:chapter_end] if chapter_end else lines[chapter_start:])
        return chapter_text
    else:
        # Fallback: search for key terms
        print("Warning: Could not find explicit Chapter 4 boundary")
        return text

def extract_timing_tables(text):
    """Extract instruction timing tables."""
    timing_data = {}
    
    # Look for latency specifications
    patterns = [
        (r'(\w+)\s+latency[:\s]+(\d+)\s+cycle', re.IGNORECASE),
        (r'latency[:\s]+(\d+)\s+cycle', re.IGNORECASE),
        (r'(\d+)\s+cycle[s]?\s+latency', re.IGNORECASE),
    ]
    
    for pattern, flags in patterns:
        matches = re.finditer(pattern, text)
        for match in matches:
            inst_name = match.group(1) if match.groups() > 1 else "Unknown"
            cycles = int(match.group(2) if match.groups() > 1 else match.group(1))
            timing_data[inst_name] = cycles
    
    return timing_data

def extract_pairing_rules(text):
    """Extract dual-issue pairing rules."""
    pairing_rules = []
    
    # Look for pairing rule tables
    # Pattern: "Instruction X can pair with Instruction Y"
    patterns = [
        r'([A-Z_]+)\s+can\s+pair\s+with\s+([A-Z_]+)',
        r'pairing[:\s]+([A-Z_]+)\s+and\s+([A-Z_]+)',
    ]
    
    for pattern in patterns:
        matches = re.finditer(pattern, text, re.IGNORECASE)
        for match in matches:
            pairing_rules.append((match.group(1), match.group(2)))
    
    return pairing_rules

def extract_functional_units(text):
    """Extract functional unit descriptions."""
    units = {}
    
    # Look for functional unit mentions
    unit_patterns = [
        r'ALU0[:\s]+(.*?)(?:\.|\n|;)',
        r'ALU1[:\s]+(.*?)(?:\.|\n|;)',
        r'SPE[:\s]+(.*?)(?:\.|\n|;)',
        r'FPU[:\s]+(.*?)(?:\.|\n|;)',
        r'LSU[:\s]+(.*?)(?:\.|\n|;)',
    ]
    
    for pattern in unit_patterns:
        matches = re.finditer(pattern, text, re.IGNORECASE)
        for match in matches:
            unit_name = match.group(0).split(':')[0].strip()
            description = match.group(1).strip()
            units[unit_name] = description
    
    return units

def main():
    if len(sys.argv) < 2:
        print("Usage: extract_e200z7_manual.py <pdf_path>")
        print("\nExample:")
        print("  extract_e200z7_manual.py /path/to/e200z760_Core_Reference_Manual.pdf")
        sys.exit(1)
    
    pdf_path = Path(sys.argv[1])
    if not pdf_path.exists():
        print(f"Error: PDF file not found: {pdf_path}")
        sys.exit(1)
    
    print(f"Extracting text from: {pdf_path}")
    text = extract_text_from_pdf(pdf_path)
    
    if not text:
        print("Failed to extract text from PDF")
        sys.exit(1)
    
    print(f"Extracted {len(text)} characters of text")
    print("=" * 80)
    
    # Extract Chapter 4
    chapter_4 = find_chapter_4(text, pdf_path)
    print(f"\nChapter 4 text length: {len(chapter_4)} characters")
    
    # Extract timing data
    print("\nExtracting timing tables...")
    timing_data = extract_timing_tables(chapter_4)
    print(f"Found {len(timing_data)} timing specifications")
    for inst, cycles in timing_data.items():
        print(f"  {inst}: {cycles} cycles")
    
    # Extract pairing rules
    print("\nExtracting pairing rules...")
    pairing_rules = extract_pairing_rules(chapter_4)
    print(f"Found {len(pairing_rules)} pairing rules")
    for inst1, inst2 in pairing_rules:
        print(f"  {inst1} <-> {inst2}")
    
    # Extract functional units
    print("\nExtracting functional unit descriptions...")
    units = extract_functional_units(chapter_4)
    print(f"Found {len(units)} functional unit descriptions")
    for unit, desc in units.items():
        print(f"  {unit}: {desc[:100]}...")
    
    # Save extracted Chapter 4 for manual review
    output_file = pdf_path.parent / f"{pdf_path.stem}_chapter4_extracted.txt"
    with open(output_file, 'w', encoding='utf-8') as f:
        f.write(chapter_4)
    print(f"\nSaved Chapter 4 text to: {output_file}")
    print("\nNext steps:")
    print("1. Review the extracted Chapter 4 text")
    print("2. Manually extract timing tables and pairing rules")
    print("3. Update e200z7_manual_extracted_data.sdoc with findings")
    print("4. Update PPCScheduleE200Z7.td with correct latencies")

if __name__ == '__main__':
    main()

