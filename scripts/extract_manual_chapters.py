#!/usr/bin/env python3
"""
Extract chapters from e200z7 PDF manuals into separate text files.
Organizes by variant (z759/z760) and chapter number.
"""

import re
import sys
from pathlib import Path


def extract_chapters_from_text(text: str, output_dir: Path, variant_name: str) -> None:
    """Extract chapters from text and write to separate files."""
    
    # Pattern to match chapter headers
    # Matches: "Chapter 1", "Chapter 2", etc. or "1.1", "Chapter 1", etc.
    chapter_pattern = re.compile(
        r'^(?:Chapter\s+(\d+)|(\d+)\.\s+.*?(?:Chapter|Overview|Features|Programming Model))',
        re.MULTILINE | re.IGNORECASE
    )
    
    # Also try to find chapter boundaries by looking for table of contents patterns
    # Look for patterns like "Chapter 1", "1.1 Overview", etc.
    toc_pattern = re.compile(
        r'^Chapter\s+(\d+)\s+(?:.*?)(?=\n|$)',
        re.MULTILINE | re.IGNORECASE
    )
    
    # Split by chapter markers
    chapters = []
    current_chapter = None
    current_content = []
    
    lines = text.split('\n')
    i = 0
    
    while i < len(lines):
        line = lines[i]
        
        # Check for chapter start
        chapter_match = re.match(
            r'^Chapter\s+(\d+)(?:\.\s*(.*?))?$',
            line.strip(),
            re.IGNORECASE
        )
        
        if chapter_match:
            # Save previous chapter if exists
            if current_chapter is not None and current_content:
                chapters.append((current_chapter, '\n'.join(current_content)))
            
            # Start new chapter
            current_chapter = int(chapter_match.group(1))
            current_content = [line]
            i += 1
            continue
        
        # Check for section headers that might indicate chapter start
        # Look for "1.1", "2.1" patterns at start of lines
        section_match = re.match(r'^(\d+)\.\s+(?:Overview|Introduction|Features)', line.strip(), re.IGNORECASE)
        if section_match and current_chapter is None:
            # Might be start of first chapter
            chapter_num = int(section_match.group(1))
            if chapter_num <= 20:  # Reasonable chapter number
                if current_chapter is not None and current_chapter != chapter_num:
                    # New chapter
                    if current_content:
                        chapters.append((current_chapter, '\n'.join(current_content)))
                    current_chapter = chapter_num
                    current_content = [line]
                    i += 1
                    continue
        
        # Accumulate content
        if current_chapter is not None:
            current_content.append(line)
        
        i += 1
    
    # Save last chapter
    if current_chapter is not None and current_content:
        chapters.append((current_chapter, '\n'.join(current_content)))
    
    # If no chapters found by pattern, try to split by page numbers or major sections
    if not chapters:
        # Fallback: look for major section breaks
        # Try to find "Chapter X" patterns anywhere in text
        chapter_positions = []
        for match in re.finditer(r'\n(Chapter\s+(\d+))', text, re.IGNORECASE):
            chapter_positions.append((match.start(), int(match.group(2)), match.group(1)))
        
        if chapter_positions:
            for idx, (pos, ch_num, header) in enumerate(chapter_positions):
                start_pos = pos
                end_pos = chapter_positions[idx + 1][0] if idx + 1 < len(chapter_positions) else len(text)
                chapter_content = text[start_pos:end_pos]
                chapters.append((ch_num, chapter_content))
    
    # Write chapters to files
    print(f"Found {len(chapters)} chapters for {variant_name}")
    
    for chapter_num, content in chapters:
        output_file = output_dir / f"Chapter_{chapter_num:02d}.txt"
        with open(output_file, 'w', encoding='utf-8') as f:
            f.write(content)
        print(f"  Written: {output_file.name} ({len(content)} bytes)")
    
    # Also write a combined overview/first few pages
    if text:
        overview_file = output_dir / "00_Overview.txt"
        # Get first ~100 lines as overview
        overview_lines = text.split('\n')[:100]
        with open(overview_file, 'w', encoding='utf-8') as f:
            f.write('\n'.join(overview_lines))
        print(f"  Written: {overview_file.name}")


def main():
    if len(sys.argv) < 3:
        print(f"Usage: {sys.argv[0]} <pdf_file> <variant_name>")
        print("Example: {sys.argv[0]} e200_core_reference/powerpc-e200z759.pdf z759")
        sys.exit(1)
    
    pdf_file = Path(sys.argv[1])
    variant_name = sys.argv[2]
    
    if not pdf_file.exists():
        print(f"Error: PDF file not found: {pdf_file}")
        sys.exit(1)
    
    # Create output directory
    output_dir = Path("e200_core_reference_extracted") / variant_name
    output_dir.mkdir(parents=True, exist_ok=True)
    
    # Extract text from PDF
    print(f"Extracting text from {pdf_file}...")
    
    import subprocess
    result = subprocess.run(
        ['pdftotext', '-layout', str(pdf_file), '-'],
        capture_output=True,
        text=True
    )
    
    if result.returncode != 0:
        print(f"Error running pdftotext: {result.stderr}")
        sys.exit(1)
    
    text = result.stdout
    
    # Save full text first
    full_text_file = output_dir / "00_Full_Manual.txt"
    with open(full_text_file, 'w', encoding='utf-8') as f:
        f.write(text)
    print(f"Saved full text to {full_text_file}")
    
    # Extract chapters
    print(f"\nExtracting chapters for {variant_name}...")
    extract_chapters_from_text(text, output_dir, variant_name)
    
    print(f"\nDone! Extracted files in {output_dir}")


if __name__ == '__main__':
    main()

