# Insertion Sort

## What Problem This Solves
Insertion sort builds a sorted part one item at a time.

## Core Idea In Simple Words
Take the next item and slide larger items right until it fits.

## Visual Model
[5] 2 4 1 -> [2 5] 4 1 -> [2 4 5] 1 -> [1 2 4 5]

## Beginner-Friendly C++17 Code

```cpp
#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<int>& a) {
    for (int i = 1; i < (int)a.size(); i++) {
        int key = a[i], j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

int main() {
    vector<int> a = {5, 2, 4, 1};
    insertionSort(a);
    for (int x : a) cout << x << " ";
    cout << "\n";
    return 0;
}
```

## Code Breakdown
`key` is inserted into the sorted left part.

## Step-By-Step Dry Run
| key | Shifts | Result |
|---:|---|---|
| 2 | 5 | 2 5 4 1 |
| 4 | 5 | 2 4 5 1 |
| 1 | 5,4,2 | 1 2 4 5 |

## Time And Space Complexity
Best `O(n)`, worst `O(n^2)`, space `O(1)`.

## Common Mistakes
- Putting `key` back inside the while loop.
- Using unsigned `j` while moving below zero.
- Forgetting to test the smallest input, such as empty data or one item.

## Practice Problems
1. Sort names.
2. Count shifts.
3. Sort nearly sorted data.

## Quick Recap
Insertion sort is excellent for small or almost-sorted input.
