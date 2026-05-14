# Queue

## What Problem This Solves
A queue stores items in First-In First-Out order.

## Core Idea In Simple Words
Push at rear, pop from front.

## Visual Model
Front -> 10 20 30 <- Rear; pop removes 10.

## Beginner-Friendly C++17 Code

```cpp
#include <iostream>
#include <queue>
using namespace std;
int main() {
    queue<int> q;
    q.push(10); q.push(20); q.push(30);
    while (!q.empty()) { cout << q.front() << " "; q.pop(); }
    cout << "\n";
    return 0;
}
```

## Code Breakdown
`front` reads the oldest item. `pop` removes it.

## Step-By-Step Dry Run
| Operation | Queue |
|---|---|
| push 10 | 10 |
| push 20 | 10,20 |
| pop | 20 |

## Time And Space Complexity
Push/pop/front `O(1)`, space `O(n)`.

## Common Mistakes
- Calling front on empty queue.
- Expecting newest item first.
- Forgetting to test the smallest input, such as empty data or one item.

## Practice Problems
1. Simulate ticket line.
2. Reverse first k elements.
3. Use queue for BFS.

## Quick Recap
Queue is fair waiting: first in, first out.
