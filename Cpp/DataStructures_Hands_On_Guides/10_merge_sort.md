# Merge Sort

## What Problem This Solves
Merge sort sorts efficiently by splitting an array and merging sorted halves.

## Core Idea In Simple Words
Split until one-element lists, then merge sorted lists upward.

## Visual Model
[8,3,5,1] -> [8,3] [5,1] -> [8] [3] [5] [1] -> [1,3,5,8]

## Beginner-Friendly C++17 Code

```cpp
#include <iostream>
#include <vector>
using namespace std;

void mergeParts(vector<int>& a, int l, int m, int r) {
    vector<int> temp;
    int i = l, j = m + 1;
    while (i <= m && j <= r) {
        if (a[i] <= a[j]) temp.push_back(a[i++]);
        else temp.push_back(a[j++]);
    }
    while (i <= m) temp.push_back(a[i++]);
    while (j <= r) temp.push_back(a[j++]);
    for (int k = 0; k < (int)temp.size(); k++) a[l + k] = temp[k];
}

void mergeSort(vector<int>& a, int l, int r) {
    if (l >= r) return;
    int m = l + (r - l) / 2;
    mergeSort(a, l, m);
    mergeSort(a, m + 1, r);
    mergeParts(a, l, m, r);
}

int main() {
    vector<int> a = {8, 3, 5, 1};
    mergeSort(a, 0, (int)a.size() - 1);
    for (int x : a) cout << x << " ";
    cout << "\n";
    return 0;
}
```

## Code Breakdown
`mergeSort` splits; `mergeParts` combines two sorted ranges.

## Step-By-Step Dry Run
| Stage | Result |
|---|---|
| Sort left | 3 8 |
| Sort right | 1 5 |
| Merge | 1 3 5 8 |

## Time And Space Complexity
`O(n log n)` time and `O(n)` extra space.

## Common Mistakes
- Forgetting to copy temp back.
- Wrong midpoint causing infinite recursion.
- Forgetting to test the smallest input, such as empty data or one item.

## Practice Problems
1. Print every merge.
2. Sort descending.
3. Count comparisons.

## Quick Recap
Merge sort is divide, solve, combine.
