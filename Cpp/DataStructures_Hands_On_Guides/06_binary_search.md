# Binary Search

## What Problem This Solves
Binary search quickly finds a target in sorted data.

## Core Idea In Simple Words
Compare the target with the middle value and discard half of the remaining range.

## Visual Model
| low | high | mid | a[mid] | Decision |
|---:|---:|---:|---:|---|
| 0 | 5 | 2 | 12 | go right |
| 3 | 5 | 4 | 31 | found |

## Beginner-Friendly C++17 Code

```cpp
#include <iostream>
#include <vector>
using namespace std;

int binarySearch(const vector<int>& a, int target) {
    int low = 0, high = (int)a.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (a[mid] == target) return mid;
        if (target < a[mid]) high = mid - 1;
        else low = mid + 1;
    }
    return -1;
}

int main() {
    vector<int> a = {3, 8, 12, 20, 31, 45};
    cout << binarySearch(a, 31) << "\n";
    return 0;
}
```

## Code Breakdown
- `low` and `high` mark the active range.
- `mid` is chosen safely.
- Move left or right depending on comparison.
- Sorted order is required.

## Step-By-Step Dry Run
For target 31, first middle is 12, so discard the left part. New middle is 31, so return index 4.

## Time And Space Complexity
- Time: `O(log n)`.
- Space: `O(1)`.

## Common Mistakes
- Using binary search on unsorted data.
- Using `while (low < high)` and missing the last candidate.
- Forgetting to test the smallest input, such as empty data or one item.

## Practice Problems
1. Find first occurrence in duplicates.
2. Count comparisons.
3. Implement recursive binary search.

## Quick Recap
Binary search is fast because each step halves the search space.
