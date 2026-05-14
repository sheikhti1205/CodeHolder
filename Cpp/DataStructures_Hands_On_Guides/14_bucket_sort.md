# Bucket Sort

## What Problem This Solves
Bucket sort sorts values by distributing them into range-based buckets.

## Core Idea In Simple Words
Put similar values in the same bucket, sort each bucket, then concatenate.

## Visual Model
For values in `[0,1)`, bucket index can be `value * number_of_buckets`.

## Beginner-Friendly C++17 Code

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void bucketSort(vector<double>& a) {
    int n = a.size();
    vector<vector<double>> buckets(n);
    for (double x : a) {
        int index = min(n - 1, (int)(x * n));
        buckets[index].push_back(x);
    }
    for (int i = 0; i < n; i++) sort(buckets[i].begin(), buckets[i].end());
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (double x : buckets[i]) a[k++] = x;
    }
}

int main() {
    vector<double> a = {0.42, 0.12, 0.89, 0.34};
    bucketSort(a);
    for (double x : a) cout << x << " ";
    cout << "\n";
    return 0;
}
```

## Code Breakdown
- This example assumes values are in `[0,1)`.
- Each bucket is sorted separately.
- Concatenating buckets gives sorted order.

## Step-By-Step Dry Run
| Value | Bucket when n=4 |
|---:|---:|
| 0.42 | 1 |
| 0.12 | 0 |
| 0.89 | 3 |

## Time And Space Complexity
- Average: about `O(n)` with even distribution.
- Worst: depends on bucket sorting.
- Space: `O(n)`.

## Common Mistakes
- Using bucket sort without knowing the value range.
- Letting `1.0` map to index `n`.
- Forgetting to test the smallest input, such as empty data or one item.

## Practice Problems
1. Sort marks using 10 buckets.
2. Print bucket contents.
3. Compare with counting sort.

## Quick Recap
Bucket sort is distribution-based and needs a sensible value range.
