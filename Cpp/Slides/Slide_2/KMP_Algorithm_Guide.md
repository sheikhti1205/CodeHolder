# KMP Algorithm: Complete Visual Guide

## Overview
The Knuth-Morris-Pratt (KMP) algorithm efficiently finds all occurrences of a pattern in a text by using a preprocessed **Longest Proper Prefix which is also Suffix (LPS)** array to avoid redundant comparisons.

---

## Phase 1: buildLPS() Function - LPS Array Construction

### What is LPS?
For each position in the pattern, LPS stores the length of the longest proper prefix that is also a suffix.

### Example: Pattern = "ABABC"
```
Pattern:  A B A B C
Index:    0 1 2 3 4
LPS:      0 0 1 2 0

Explanation:
- lps[0] = 0    (single character has no proper prefix-suffix)
- lps[1] = 0    (prefix "A" ≠ suffix "B")
- lps[2] = 1    (prefix "A" = suffix "A")
- lps[3] = 2    (prefix "AB" = suffix "AB")
- lps[4] = 0    (no matching prefix-suffix pair)
```

### Algorithm Steps:
```
1. Initialize: len = 0, i = 1, lps = [0, 0, 0, 0, 0]

2. Loop through pattern (i = 1 to 4):
   
   i=1: P[1]='B' ≠ P[0]='A' → len=0, lps[1]=0, i=2
   
   i=2: P[2]='A' = P[0]='A' → len=1, lps[2]=1, i=3
   
   i=3: P[3]='B' = P[1]='B' → len=2, lps[3]=2, i=4
   
   i=4: P[4]='C' ≠ P[2]='A' → len=lps[1]=0, lps[4]=0, i=5
   
3. Return: lps = [0, 0, 1, 2, 0]
```

### Data Flow Arrows:
```
input: Pattern "ABABC"
   ↓
Initialize lps[0]=0
   ↓
Loop through pattern indices 1 to 4
   ↓
For each position: Compare pattern characters
   ↓
If match: Increment len, store len in lps[i]
   ↓
If mismatch: Fallback to lps[len-1]
   ↓
Return LPS array → Used in kmpSearch()
```

---

## Phase 2: kmpSearch() Function - Pattern Matching

### Setup
```
Text:    "ABABDABACD"  (length = 10)
Pattern: "ABABD"       (length = 5)
LPS:     [0, 0, 1, 2, 0]
```

### Matching Process with Pointers

```
Key Variables:
- i = pointer for Text    (starts at 0)
- j = pointer for Pattern (starts at 0)
- result = vector to store match positions
```

### Step-by-Step Execution:

```
Step 1: i=0, j=0
   T[0]='A' = P[0]='A' ✓
   → i++, j++  (i=1, j=1)

Step 2: i=1, j=1
   T[1]='B' = P[1]='B' ✓
   → i++, j++  (i=2, j=2)

Step 3: i=2, j=2
   T[2]='A' = P[2]='A' ✓
   → i++, j++  (i=3, j=3)

Step 4: i=3, j=3
   T[3]='B' = P[3]='B' ✓
   → i++, j++  (i=4, j=4)

Step 5: i=4, j=4
   T[4]='D' = P[4]='D' ✓
   → i++, j++  (i=5, j=5)
   
   j == m (5) → MATCH FOUND at position (5-5)=0 ✓
   → result.push_back(0)
   → j = lps[4] = 0  (Continue searching for overlaps)

Step 6: i=5, j=0
   T[5]='A' = P[0]='A' ✓
   → i++, j++  (i=6, j=1)

Step 7: i=6, j=1
   T[6]='B' = P[1]='B' ✓
   → i++, j++  (i=7, j=2)

Step 8: i=7, j=2
   T[7]='A' = P[2]='A' ✓
   → i++, j++  (i=8, j=3)

Step 9: i=8, j=3
   T[8]='C' ≠ P[3]='B' ✗
   → Fallback: j = lps[2] = 1
   → i stays at 8

Step 10: i=8, j=1
   T[8]='C' ≠ P[1]='B' ✗
   → Fallback: j = lps[0] = 0
   → i stays at 8

Step 11: i=8, j=0
   T[8]='C' ≠ P[0]='A' ✗
   → j = 0 (no fallback), so i++
   → i=9

Step 12: i=9, j=0
   T[9]='D' ≠ P[0]='A' ✗
   → i++ (i=10)

End: i=10 (reached end of text)

Final Result: Matches at position [0]
```

### Key Decision Points (Highlighted with Arrows):

```
In kmpSearch loop:

     ↓ T[i] == P[j]?
    YES→ Increment both i++, j++
    NO ↓
      Check if j==m?
      YES→ Record match, use LPS to continue
      NO ↓
         Check if j != 0?
         YES→ j = lps[j-1]  (Use LPS to skip)
         NO → i++
```

---

## Phase 3: main() Function - Orchestration

```
Code Flow with Arrows:

START
   ↓
Input: text, pattern
   ↓
Call kmpSearch(text, pattern)
   ↓
   ├─→ buildLPS(pattern)  ←returns LPS array
   └─→ Perform matching using LPS
   ↓
Get result vector
   ↓
if (matches.empty())
   YES→ Output "No match."
   NO ↓→ Output all match positions
   ↓
END
```

---

## Why LPS Helps (The Core Optimization)

### Without LPS (Naive):
```
Text:    ABABDABACD
Pattern: ABABD

When mismatch at i=8, j=3:
T[8]='C' ≠ P[3]='B'

Naive approach: Reset j=0, i=5 (restart from next char)
Total comparisons: Many redundant checks
```

### With LPS (KMP):
```
When mismatch at i=8, j=3:
T[8]='C' ≠ P[3]='B'

KMP approach: j = lps[j-1] = lps[2] = 1
This means: "We already matched 'AB' at the end,
 so skip re-checking them. Start from j=1"
 
Result: Avoid redundant comparisons!
```

### Time Complexity:
- **buildLPS**: O(m) where m = pattern length
- **kmpSearch**: O(n) where n = text length
- **Total**: O(n + m) - Much better than naive O(n×m)

---

## Complete Arrow Diagram

```
┌─────────────────────────────────────┐
│          main()                     │
│    ┌─────────────────────────┐     │
│    │ Read: text, pattern     │     │
│    └──────────┬──────────────┘     │
│               ↓                     │
│    ┌─────────────────────────┐     │
│    │ Call kmpSearch()        │────→│
│    │ (returns result vector) │     │
│    └──────────┬──────────────┘     │
│               ↓                     │
│    ┌─────────────────────────┐     │
│    │ if (result.empty)?      │     │
│    └──────┬──────────┬───────┘     │
│         YES          NO            │
│          │            │            │
│          ↓            ↓            │
│       "No       "Found at       │
│       match"    indices: ..."   │
└─────────────────────────────────────┘
          ↑
          │ CALLS
          │
┌─────────────────────────────────────┐
│    kmpSearch(text, pattern)         │
│                                      │
│  1) lps = buildLPS(pattern) ────→  │
│  2) Initialize i=0, j=0, result    │
│  3) Loop while i < n:              │
│     ├─→ If T[i]==P[j]: i++, j++   │
│     ├─→ If j==m: Record match,    │
│     │        j=lps[j-1]            │
│     ├─→ Else: j = lps[j-1]        │
│     │    or i++ if j==0            │
│  4) Return result vector           │
└─────────────────────────────────────┘
          ↑
          │ CALLS
          │
┌─────────────────────────────────────┐
│    buildLPS(pattern)                │
│                                      │
│  1) Initialize lps[], len=0, i=1   │
│  2) While i < m:                    │
│     ├─→ If P[i]==P[len]:           │
│     │    lps[i]=++len, i++          │
│     ├─→ Else: len=lps[len-1]       │
│     │    (or set lps[i]=0, i++)    │
│  3) Return lps array                │
└─────────────────────────────────────┘
```

---

## Summary

| Phase | Function | Input | Output | Time |
|-------|----------|-------|--------|------|
| 1 | buildLPS | Pattern | LPS Array | O(m) |
| 2 | kmpSearch | Text, Pattern, LPS | Match Positions | O(n) |
| 3 | main | User Input | Display Results | O(n+m) |

**Key Insight**: The LPS array eliminates wasteful re-comparisons by providing intelligent fallback positions, making KMP fundamentally different from naive string matching.
