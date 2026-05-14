# Tower Of Hanoi

## What Problem This Solves
Tower of Hanoi moves disks between pegs without placing a larger disk on a smaller disk.

## Core Idea In Simple Words
Move `n-1` disks away, move the largest disk, then move `n-1` disks onto it.

## Visual Model
For 3 disks: move 2 from A to B, disk 3 from A to C, then 2 from B to C.

## Beginner-Friendly C++17 Code

```cpp
#include <iostream>
using namespace std;

void hanoi(int n, char from, char helper, char to) {
    if (n == 0) return;
    hanoi(n - 1, from, to, helper);
    cout << "Move disk " << n << " from " << from << " to " << to << "\n";
    hanoi(n - 1, helper, from, to);
}

int main() {
    hanoi(3, 'A', 'B', 'C');
    return 0;
}
```

## Code Breakdown
The first recursive call clears the largest disk. The second rebuilds the tower on the target peg.

## Step-By-Step Dry Run
| Disk count | Minimum moves |
|---:|---:|
| 1 | 1 |
| 2 | 3 |
| 3 | 7 |

## Time And Space Complexity
Time `O(2^n)`, stack `O(n)`.

## Common Mistakes
- Swapping helper and target pegs.
- Forgetting `n == 0`.
- Forgetting to test the smallest input, such as empty data or one item.

## Practice Problems
1. Print moves for 2 disks.
2. Count moves only.
3. Prove `2^n - 1`.

## Quick Recap
Hanoi is recursion wrapped around one largest-disk move.
