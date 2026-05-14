# Two-Dimensional Array

## What Problem This Solves
A 2D array stores rows and columns, like marks tables, matrices, boards, and grids.

## Core Idea In Simple Words
Use two indexes: row first, column second.

## Visual Model
| Row/Col | 0 | 1 | 2 |
|---|---:|---:|---:|
| 0 | 1 | 2 | 3 |
| 1 | 4 | 5 | 6 |

## Beginner-Friendly C++17 Code

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<vector<int>> a = {{1, 2, 3}, {4, 5, 6}};
    for (int r = 0; r < (int)a.size(); r++) {
        for (int c = 0; c < (int)a[r].size(); c++) {
            cout << a[r][c] << " ";
        }
        cout << "\n";
    }
    cout << a[1][2] << "\n";
    return 0;
}
```

## Code Breakdown
- `a[r][c]` means row `r`, column `c`.
- Outer loop visits rows.
- Inner loop visits columns in that row.

## Step-By-Step Dry Run
| r | Printed row |
|---:|---|
| 0 | 1 2 3 |
| 1 | 4 5 6 |

## Time And Space Complexity
- Traversal: `O(rows * cols)`.
- Access: `O(1)`.
- Space: `O(rows * cols)`.

## Common Mistakes
- Mixing row and column order.
- Assuming a matrix has at least one row.
- Forgetting to test the smallest input, such as empty data or one item.

## Practice Problems
1. Sum each row.
2. Find largest value.
3. Add two matrices.

## Quick Recap
A 2D array is a table; nested loops are the natural tool.
