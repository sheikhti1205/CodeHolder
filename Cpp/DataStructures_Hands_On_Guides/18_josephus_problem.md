# Josephus Problem

## What Problem This Solves
Josephus finds the survivor when every k-th person is removed from a circle.

## Core Idea In Simple Words
Use a queue to rotate safe people and remove the k-th person.

## Visual Model
n=5, k=2 removes 2, 4, 1, 5; survivor is 3.

## Beginner-Friendly C++17 Code

```cpp
#include <iostream>
#include <queue>
using namespace std;

int josephus(int n, int k) {
    queue<int> q;
    for (int i = 1; i <= n; i++) q.push(i);
    while (q.size() > 1) {
        for (int c = 1; c < k; c++) {
            q.push(q.front());
            q.pop();
        }
        q.pop();
    }
    return q.front();
}

int main() {
    cout << josephus(5, 2) << "\n";
    return 0;
}
```

## Code Breakdown
Rotate `k-1` survivors, then pop the k-th person.

## Step-By-Step Dry Run
| Round | Removed |
|---:|---:|
| 1 | 2 |
| 2 | 4 |
| 3 | 1 |
| 4 | 5 |

## Time And Space Complexity
Simulation time `O(n*k)`, space `O(n)`.

## Common Mistakes
- Removing before rotating.
- Mixing 0-based and 1-based labels.
- Forgetting to test the smallest input, such as empty data or one item.

## Practice Problems
1. Print elimination order.
2. Try n=7 k=3.
3. Implement recurrence version.

## Quick Recap
Queue simulation makes Josephus easy to see.
