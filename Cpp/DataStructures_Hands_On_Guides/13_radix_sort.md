# Radix Sort

## What Problem This Solves
Radix sort sorts non-negative integers digit by digit.

## Core Idea In Simple Words
Sort by ones digit, then tens, then hundreds, using a stable counting step.

## Visual Model
| Pass | Order idea |
|---|---|
| ones | group by last digit |
| tens | keep ones order inside tens groups |
| hundreds | final order |

## Beginner-Friendly C++17 Code

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void countDigit(vector<int>& a, int place) {
    vector<int> out(a.size()), count(10, 0);
    for (int x : a) count[(x / place) % 10]++;
    for (int i = 1; i < 10; i++) count[i] += count[i - 1];
    for (int i = (int)a.size() - 1; i >= 0; i--) {
        int d = (a[i] / place) % 10;
        out[count[d] - 1] = a[i];
        count[d]--;
    }
    a = out;
}

void radixSort(vector<int>& a) {
    int mx = *max_element(a.begin(), a.end());
    for (int place = 1; mx / place > 0; place *= 10) countDigit(a, place);
}

int main() {
    vector<int> a = {170, 45, 75, 90, 802, 24, 2, 66};
    radixSort(a);
    for (int x : a) cout << x << " ";
    cout << "\n";
    return 0;
}
```

## Code Breakdown
- `place` selects digit position.
- Counting sort groups by digit.
- Processing from right to left keeps stability.

## Step-By-Step Dry Run
| Number | Ones digit |
|---:|---:|
| 170 | 0 |
| 45 | 5 |
| 75 | 5 |
| 90 | 0 |

## Time And Space Complexity
- Time: `O(d*(n+10))`.
- Space: `O(n+10)`.

## Common Mistakes
- Using an unstable digit sort.
- Forgetting this version does not handle negative numbers.
- Forgetting to test the smallest input, such as empty data or one item.

## Practice Problems
1. Print after each digit pass.
2. Sort roll numbers.
3. Extend to fixed-length strings.

## Quick Recap
Radix sort uses digit positions instead of direct comparisons.
