# Pattern Matching

## What Problem This Solves
Pattern matching finds whether a smaller string appears inside a larger text.

## Core Idea In Simple Words
Try every possible starting position. At each position, compare the pattern from left to right.

## Visual Model
Text: `ABABCAB`, Pattern: `ABC`

| Start | Compared | Result |
|---:|---|---|
| 0 | ABA vs ABC | fail |
| 1 | BAB vs ABC | fail |
| 2 | ABC vs ABC | found |

## Beginner-Friendly C++17 Code

```cpp
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> naiveSearch(const string& text, const string& pattern) {
    vector<int> positions;
    int n = text.size(), m = pattern.size();
    if (m == 0 || m > n) return positions;
    for (int start = 0; start <= n - m; start++) {
        int j = 0;
        while (j < m && text[start + j] == pattern[j]) j++;
        if (j == m) positions.push_back(start);
    }
    return positions;
}

int main() {
    vector<int> ans = naiveSearch("ABABCAB", "ABC");
    for (int pos : ans) cout << pos << " ";
    cout << "\n";
    return 0;
}
```

## Code Breakdown
- The outer loop selects a possible start.
- The inner loop checks the pattern.
- If `j == m`, every character matched.
- Store all matches, including later ones.

## Step-By-Step Dry Run
At start 0, `A` and `B` match but `A != C`. At start 1, `B != A`. At start 2, all three characters match, so output index 2.

## Time And Space Complexity
- Time: `O(n*m)` worst case.
- Space: `O(k)` for `k` matches.

## Common Mistakes
- Stopping after one mismatch without trying the next start.
- Looping to `start < n` and reading past the end.
- Forgetting to test the smallest input, such as empty data or one item.

## Practice Problems
1. Count all matches.
2. Return only the first match.
3. Allow overlapping matches.

## Quick Recap
Naive matching is simple and exam-friendly: align, compare, move one step.
