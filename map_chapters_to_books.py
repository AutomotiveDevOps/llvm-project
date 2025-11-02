#!/usr/bin/env python3
"""Map Power ISA 2.07 chapters to their respective books."""

import re
import os
from collections import defaultdict
from typing import Dict, List, Tuple


def analyze_chapter_book_mapping():
    """Analyze which chapters belong to which Power ISA books."""
    print("=== Mapping Chapters to Power ISA 2.07 Books ===\n")
    
    chapter_mapping = {}
    book_chapters = defaultdict(list)
    
    for ch_num in range(1, 13):
        chapter_file = f'e200_core_reference_extracted/powerisa_v2_07/Chapter_{ch_num:02d}.txt'
        
        if not os.path.exists(chapter_file):
            continue
        
        try:
            with open(chapter_file, 'r', encoding='utf-8', errors='ignore') as f:
                content = f.read(200000)  # First 200KB for analysis
            
            # Extract chapter title
            title_match = re.search(r'Chapter\s+\d+[\.\s]+([^\n]{10,100})', content)
            title = title_match.group(1).strip() if title_match else f"Chapter {ch_num}"
            
            # Find book references
            books = set()
            
            # Direct book references
            book_pattern = r'Book\s+([IVX]+(?:-[ES])?)'
            book_matches = re.findall(book_pattern, content[:50000], re.IGNORECASE)
            books.update(book_matches)
            
            # Check for VLE indicators
            if 'VLE' in content[:10000] or 'Variable Length' in content[:10000]:
                books.add('V')
            
            # Determine primary book based on content
            primary_book = None
            if 'Book I' in content[:20000] and 'Book I' not in str(books):
                # Check if this is a Book I chapter
                if any(facility in content[:50000] for facility in 
                       ['Fixed-Point', 'Floating-Point', 'Vector', 'Decimal Floating', 'SPE', 'Signal Processing']):
                    primary_book = 'I'
            elif 'Book II' in content[:20000]:
                if any(facility in content[:50000] for facility in 
                       ['Storage Model', 'Transactional Memory', 'Decorated Storage', 'Time Base']):
                    primary_book = 'II'
            elif 'Book III-S' in content[:20000]:
                primary_book = 'III-S'
            elif 'Book III-E' in content[:20000]:
                if any(facility in content[:50000] for facility in 
                       ['IVOR', 'Embedded', 'Reset', 'Timer', 'Debug']):
                    primary_book = 'III-E'
            
            # If primary book not found, use most referenced book
            if not primary_book and books:
                # Count occurrences
                book_counts = {}
                for book in book_matches:
                    book_counts[book] = book_counts.get(book, 0) + 1
                if book_counts:
                    primary_book = max(book_counts.items(), key=lambda x: x[1])[0]
            
            # VLE chapters are usually 1-7 based on previous analysis
            if ch_num <= 7 and ('VLE' in title or 'VLE' in content[:5000]):
                primary_book = 'V'
            
            # Book III-E chapters are usually 8-12 based on previous analysis
            if ch_num >= 8 and ('Embedded' in title or 'Timer' in title or 'Debug' in title or 'Reset' in title):
                primary_book = 'III-E'
            
            chapter_mapping[ch_num] = {
                'title': title[:80],
                'books_referenced': sorted(books),
                'primary_book': primary_book,
                'file_size': os.path.getsize(chapter_file)
            }
            
            if primary_book:
                book_chapters[primary_book].append(ch_num)
            
            print(f"Chapter {ch_num}: {title[:60]}")
            print(f"  Primary Book: {primary_book if primary_book else 'Unknown'}")
            print(f"  Books Referenced: {', '.join(sorted(books)) if books else 'None'}")
            print(f"  Size: {os.path.getsize(chapter_file):,} bytes")
            print()
        
        except Exception as e:
            print(f"Chapter {ch_num}: Error - {e}\n")
    
    print("\n=== Summary by Book ===\n")
    for book in sorted(book_chapters.keys()):
        chapters = sorted(book_chapters[book])
        print(f"Book {book}: Chapters {', '.join(map(str, chapters))}")
        print(f"  Total chapters: {len(chapters)}")
    
    # Save mapping
    with open('powerisa_v2_07_chapter_book_mapping.txt', 'w') as f:
        f.write("Power ISA 2.07 Chapter to Book Mapping\n")
        f.write("=" * 60 + "\n\n")
        
        for ch_num in sorted(chapter_mapping.keys()):
            info = chapter_mapping[ch_num]
            f.write(f"Chapter {ch_num}: {info['title']}\n")
            f.write(f"  Primary Book: {info['primary_book'] if info['primary_book'] else 'Unknown'}\n")
            f.write(f"  Books Referenced: {', '.join(info['books_referenced']) if info['books_referenced'] else 'None'}\n")
            f.write(f"  Size: {info['file_size']:,} bytes\n\n")
        
        f.write("\n=== Book Summary ===\n")
        for book in sorted(book_chapters.keys()):
            f.write(f"\nBook {book}: Chapters {', '.join(map(str, sorted(book_chapters[book])))}\n")
    
    return chapter_mapping, book_chapters


def identify_book_i_chapters(chapter_mapping: Dict) -> List[int]:
    """Identify chapters that contain Book I content."""
    book_i_chapters = []
    
    book_i_keywords = [
        'Fixed-Point', 'Floating-Point', 'Vector', 'Decimal Floating',
        'Signal Processing', 'SPE', 'Embedded Floating', 'Legacy Move',
        'Branch Facility'
    ]
    
    for ch_num, info in chapter_mapping.items():
        title = info['title'].lower()
        # Check if chapter title or content suggests Book I
        if any(keyword.lower() in title for keyword in book_i_keywords):
            if 'I' in info['books_referenced'] or info['primary_book'] == 'I':
                book_i_chapters.append(ch_num)
    
    return book_i_chapters


def identify_book_ii_chapters(chapter_mapping: Dict) -> List[int]:
    """Identify chapters that contain Book II content."""
    book_ii_chapters = []
    
    book_ii_keywords = [
        'Storage Model', 'Transactional Memory', 'Decorated Storage',
        'Time Base', 'Event-Based Branch'
    ]
    
    for ch_num, info in chapter_mapping.items():
        title = info['title'].lower()
        if any(keyword.lower() in title for keyword in book_ii_keywords):
            if 'II' in info['books_referenced'] or info['primary_book'] == 'II':
                book_ii_chapters.append(ch_num)
    
    return book_ii_chapters


if __name__ == '__main__':
    chapter_mapping, book_chapters = analyze_chapter_book_mapping()
    
    print("\n=== Identifying Book-Specific Chapters ===\n")
    
    book_i_chs = identify_book_i_chapters(chapter_mapping)
    print(f"Book I chapters identified: {book_i_chs}")
    
    book_ii_chs = identify_book_ii_chapters(chapter_mapping)
    print(f"Book II chapters identified: {book_ii_chs}")
    
    # Note: The extracted text might not have complete book separation
    # as the PDF might interleave content. We'll need to analyze
    # instruction definitions more carefully.
    print("\nNote: Chapters may contain content from multiple books.")
    print("Instruction extraction will need to filter by book context.")

