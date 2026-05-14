# Complete Binary Tree

## What Problem This Solves
A complete binary tree fills levels from left to right and is used by heaps.

## Core Idea In Simple Words
Array formulas locate parent and children without pointers.

## Visual Model
0-based array: left child `2*i+1`, right child `2*i+2`, parent `(i-1)/2`.

## Beginner-Friendly C++17 Code

```cpp
#include <iostream>
#include <vector>
using namespace std;
int main() {
    vector<int> tree = {10, 20, 30, 40, 50, 60};
    for (int i = 0; i < (int)tree.size(); i++) {
        int l = 2*i + 1, r = 2*i + 2;
        cout << tree[i] << ": ";
        if (l < (int)tree.size()) cout << "L=" << tree[l] << " ";
        if (r < (int)tree.size()) cout << "R=" << tree[r];
        cout << "\n";
    }
    return 0;
}
```

## Code Breakdown
Complete shape makes array storage compact.

## Step-By-Step Dry Run
| i | left | right |
|---:|---:|---:|
| 0 | 1 | 2 |
| 1 | 3 | 4 |
| 2 | 5 | 6 |

## Time And Space Complexity
Index calculations `O(1)`, traversal `O(n)`.

## Common Mistakes
- Using 1-based formulas on 0-based vector.
- Calling a tree complete even with gaps.
- Forgetting to test the smallest input, such as empty data or one item.

## Practice Problems
1. Find parent of index 5.
2. Print leaves.
3. Check complete shape.

## Quick Recap
Complete binary tree shape is level-filled left to right.
