# Linear Array

## What Problem This Solves
A linear array stores same-type values in consecutive positions, making indexed access fast.

## Core Idea In Simple Words
Use the index to directly access or update a value. Use loops to traverse all values.

## Visual Model
Values: `[5, 10, 15, 20]`

Indexes: `0 1 2 3`; `a[2]` is `15`.

## Beginner-Friendly C++17 Code

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> a = {5, 10, 15, 20};
    for (int x : a) cout << x << " ";
    cout << "\nIndex 2: " << a[2] << "\n";
    a[1] = 99;
    for (int x : a) cout << x << " ";
    cout << "\n";
    return 0;
}
```

## Code Breakdown
- `vector<int>` is a dynamic array.
- Indexes start from 0.
- Traversal reads every element once.
- Updating `a[1]` changes the second value.

## Step-By-Step Dry Run
| Action | Array |
|---|---|
| Start | 5 10 15 20 |
| Read index 2 | 15 |
| Set index 1 to 99 | 5 99 15 20 |

## Time And Space Complexity
- Access: `O(1)`.
- Traversal: `O(n)`.
- Middle insert/delete: `O(n)`.
- Space: `O(n)`.

## Common Mistakes
- Using index `n` for the last element.
- Forgetting that middle edits shift values.
- Forgetting to test the smallest input, such as empty data or one item.

## Practice Problems
1. Print all elements.
2. Find sum and average.
3. Insert a value at a position by shifting.

## Quick Recap
Arrays are best when order and fast index access matter.
