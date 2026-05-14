# String Operations

## What Problem This Solves
String operations measure, cut, join, insert, delete, replace, and search text. These are core tools for editors, search boxes, parsers, and file processing.

## Core Idea In Simple Words
Treat a string as an indexed row of characters. Most operations either read a position, copy a range, or shift characters after an edit.

## Visual Model
`COMPUTER`

| Index | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 |
|---|---|---|---|---|---|---|---|---|
| Char | C | O | M | P | U | T | E | R |

## Beginner-Friendly C++17 Code

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string text = "ABCDEFG";
    cout << "Length: " << text.length() << "\n";
    cout << "Substring: " << text.substr(2, 3) << "\n";
    cout << "Index of CD: " << text.find("CD") << "\n";

    string inserted = text;
    inserted.insert(3, "XYZ");
    cout << inserted << "\n";

    string deleted = text;
    deleted.erase(3, 2);
    cout << deleted << "\n";

    string replaced = text;
    size_t pos = replaced.find("CD");
    if (pos != string::npos) replaced.replace(pos, 2, "xx");
    cout << replaced << "\n";
    return 0;
}
```

## Code Breakdown
- `length()` counts characters.
- `substr(start, length)` copies a range.
- `find()` returns a position or `string::npos`.
- `insert`, `erase`, and `replace` modify the text.

## Step-By-Step Dry Run
For `ABCDEFG`: substring `(2,3)` gives `CDE`; inserting `XYZ` at index 3 gives `ABCXYZDEFG`; deleting 2 characters at index 3 gives `ABCFG`; replacing `CD` gives `ABxxEFG`.

## Time And Space Complexity
- `find`: simple model `O(n*m)`.
- Insert/delete/replace: `O(n)` because characters may shift.
- Space: often `O(n)` when a new string is built.

## Common Mistakes
- Mixing 0-based C++ indexes with 1-based lecture positions.
- Not checking `string::npos` before replacing.
- Forgetting to test the smallest input, such as empty data or one item.

## Practice Problems
1. Delete a word from a sentence.
2. Replace the first occurrence of a pattern.
3. Implement length, substring, insert, delete, and replace as menu options.

## Quick Recap
String work is position work. Know your index and always handle the not-found case.
