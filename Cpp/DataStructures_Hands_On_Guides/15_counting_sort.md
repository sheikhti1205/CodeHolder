# Counting Sort

## What Problem This Solves
Counting sort is fast for non-negative integers when the value range is small.

## Core Idea In Simple Words
Count how many times each value appears, then write values back in order.

## Visual Model
`[4,2,2,1]` -> counts: 1 once, 2 twice, 4 once -> `[1,2,2,4]`.

## Beginner-Friendly C++17 Code

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void countingSort(vector<int>& a) {
    int mx = *max_element(a.begin(), a.end());
    vector<int> count(mx + 1, 0);
    for (int x : a) count[x]++;
    int index = 0;
    for (int value = 0; value <= mx; value++) {
        while (count[value] > 0) {
            a[index++] = value;
            count[value]--;
        }
    }
}

int main() {
    vector<int> a = {4, 2, 2, 1, 3};
    countingSort(a);
    for (int x : a) cout << x << " ";
    cout << "\n";
    return 0;
}
```

## Code Breakdown
- `count[x]` stores frequency of `x`.
- Rebuild from smallest value to largest.
- Good when max value is not huge.

## Step-By-Step Dry Run
| Value | Frequency |
|---:|---:|
| 1 | 1 |
| 2 | 2 |
| 3 | 1 |
| 4 | 1 |

## Time And Space Complexity
- Time: `O(n+k)`.
- Space: `O(k)`.

## Common Mistakes
- Using it when max value is enormous.
- Forgetting this basic version does not handle negatives.
- Forgetting to test the smallest input, such as empty data or one item.

## Practice Problems
1. Sort exam marks 0 to 100.
2. Only print frequencies.
3. Add offset for negative numbers.

## Quick Recap
Counting sort counts first and writes later.
