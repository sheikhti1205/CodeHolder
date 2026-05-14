# Bubble Sort

## What Problem This Solves
Bubble sort arranges values by repeatedly swapping adjacent values that are in the wrong order.

## Core Idea In Simple Words
Large values bubble toward the end after each pass.

## Visual Model
Start `[5, 1, 4, 2]`; after pass 1, the largest value `5` reaches the end.

## Beginner-Friendly C++17 Code

```cpp
#include <iostream>
#include <vector>
using namespace std;

void bubbleSort(vector<int>& a) {
    int n = a.size();
    for (int pass = 0; pass < n - 1; pass++) {
        bool swapped = false;
        for (int i = 0; i < n - 1 - pass; i++) {
            if (a[i] > a[i + 1]) {
                int temp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = temp;
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

int main() {
    vector<int> a = {5, 1, 4, 2};
    bubbleSort(a);
    for (int x : a) cout << x << " ";
    cout << "\n";
    return 0;
}
```

## Code Breakdown
- Inner loop compares adjacent pairs.
- Swap if the left value is bigger.
- Each pass fixes one value at the end.
- `swapped` stops early.

## Step-By-Step Dry Run
| Pass | Result |
|---:|---|
| 1 | 1 4 2 5 |
| 2 | 1 2 4 5 |
| 3 | no swap, stop |

## Time And Space Complexity
- Worst/average: `O(n^2)`.
- Best with early stop: `O(n)`.
- Space: `O(1)`.

## Common Mistakes
- Accessing `a[i+1]` out of range.
- Forgetting the last part is already sorted.
- Forgetting to test the smallest input, such as empty data or one item.

## Practice Problems
1. Print after each pass.
2. Sort descending.
3. Count swaps.

## Quick Recap
Bubble sort is easy to trace, but inefficient for large input.
