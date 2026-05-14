# Selection Sort

## What Problem This Solves
Selection sort repeatedly chooses the smallest remaining value.

## Core Idea In Simple Words
Find the minimum in the unsorted part and swap it into the next position.

## Visual Model
[29,10,14,7] -> smallest 7 -> [7,10,14,29]

## Beginner-Friendly C++17 Code

```cpp
#include <iostream>
#include <vector>
using namespace std;

void selectionSort(vector<int>& a) {
    for (int i = 0; i < (int)a.size() - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < (int)a.size(); j++) {
            if (a[j] < a[minIndex]) minIndex = j;
        }
        int temp = a[i];
        a[i] = a[minIndex];
        a[minIndex] = temp;
    }
}

int main() {
    vector<int> a = {29, 10, 14, 7};
    selectionSort(a);
    for (int x : a) cout << x << " ";
    cout << "\n";
    return 0;
}
```

## Code Breakdown
`i` marks where the next smallest value belongs.

## Step-By-Step Dry Run
| i | Minimum | Result |
|---:|---:|---|
| 0 | 7 | 7 10 14 29 |
| 1 | 10 | 7 10 14 29 |

## Time And Space Complexity
Time `O(n^2)`, space `O(1)`.

## Common Mistakes
- Swapping inside the inner loop.
- Searching inside the already sorted part.
- Forgetting to test the smallest input, such as empty data or one item.

## Practice Problems
1. Sort descending.
2. Count swaps.
3. Sort marks.

## Quick Recap
Selection sort is simple: select minimum, place it, repeat.
