# Linear Search

## What Problem This Solves
Linear search finds a target by checking each element one by one. It works on unsorted data.

## Core Idea In Simple Words
Start at index 0 and move right until the target is found or the array ends.

## Visual Model
`[12, 7, 25, 9]`, target `25`: check 12, then 7, then 25.

## Beginner-Friendly C++17 Code

```cpp
#include <iostream>
#include <vector>
using namespace std;

int linearSearch(const vector<int>& a, int target) {
    for (int i = 0; i < (int)a.size(); i++) {
        if (a[i] == target) return i;
    }
    return -1;
}

int main() {
    vector<int> a = {12, 7, 25, 9};
    cout << linearSearch(a, 25) << "\n";
    return 0;
}
```

## Code Breakdown
- Check every index in order.
- Return immediately on a match.
- Return `-1` when not found because `0` can be a real index.

## Step-By-Step Dry Run
| i | a[i] | Decision |
|---:|---:|---|
| 0 | 12 | no |
| 1 | 7 | no |
| 2 | 25 | found |

## Time And Space Complexity
- Best: `O(1)`.
- Worst: `O(n)`.
- Space: `O(1)`.

## Common Mistakes
- Returning 0 for not found.
- Skipping the last index.
- Forgetting to test the smallest input, such as empty data or one item.

## Practice Problems
1. Search a character in a string.
2. Count all occurrences.
3. Search records by ID.

## Quick Recap
Linear search is universal: simple, works anywhere, but can be slow.
