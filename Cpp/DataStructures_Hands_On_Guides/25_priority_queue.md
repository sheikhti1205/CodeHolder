# Priority Queue

## What Problem This Solves
A priority queue removes the highest-priority item first.

## Core Idea In Simple Words
C++ max priority queue returns largest first; min priority queue uses `greater<int>`.

## Visual Model
Push 10, 40, 20; max top is 40, min top is 10.

## Beginner-Friendly C++17 Code

```cpp
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main() {
    priority_queue<int> maxPQ;
    maxPQ.push(10); maxPQ.push(40); maxPQ.push(20);
    cout << maxPQ.top() << "\n";
    priority_queue<int, vector<int>, greater<int>> minPQ;
    minPQ.push(10); minPQ.push(40); minPQ.push(20);
    cout << minPQ.top() << "\n";
    return 0;
}
```

## Code Breakdown
`top` is best-priority item. Internally this is heap-based.

## Step-By-Step Dry Run
| Structure | First item |
|---|---:|
| maxPQ | 40 |
| minPQ | 10 |

## Time And Space Complexity
Push/pop `O(log n)`, top `O(1)`.

## Common Mistakes
- Forgetting default is max-first.
- Trying to loop without popping.
- Forgetting to test the smallest input, such as empty data or one item.

## Practice Problems
1. Print largest to smallest.
2. Store task priorities.
3. Use in Dijkstra.

## Quick Recap
Priority queue is ordered by importance, not arrival time.
