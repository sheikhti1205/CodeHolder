# Topological Sorting

## What Problem This Solves
Topological sort orders directed tasks so prerequisites appear first.

## Core Idea In Simple Words
Use indegree counts. Start with nodes that have no prerequisites.

## Visual Model
If A -> C and B -> C, both A and B appear before C.

## Beginner-Friendly C++17 Code

```cpp
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main() {
    int n = 6;
    vector<vector<int>> g(n);
    vector<int> indeg(n, 0);
    vector<pair<int,int>> edges = {{5,2},{5,0},{4,0},{4,1},{2,3},{3,1}};
    for (auto e : edges) { g[e.first].push_back(e.second); indeg[e.second]++; }
    queue<int> q;
    for (int i = 0; i < n; i++) if (indeg[i] == 0) q.push(i);
    vector<int> order;
    while (!q.empty()) {
        int v = q.front(); q.pop(); order.push_back(v);
        for (int to : g[v]) if (--indeg[to] == 0) q.push(to);
    }
    for (int v : order) cout << v << " ";
    cout << "\n";
    return 0;
}
```

## Code Breakdown
`indegree[x]` counts prerequisites of `x`. Removing a node reduces indegree of its neighbors.

## Step-By-Step Dry Run
| Queue idea | Meaning |
|---|---|
| 4,5 | no prerequisites |
| remove 5 | may unlock 2 |
| remove 4 | may unlock 0 |

## Time And Space Complexity
Time `O(V+E)`, space `O(V+E)`.

## Common Mistakes
- Using it on undirected graphs.
- Not checking cycle by output length.
- Forgetting to test the smallest input, such as empty data or one item.

## Practice Problems
1. Course order.
2. Cycle detection.
3. Lexicographically smallest order.

## Quick Recap
Topological sort is prerequisite ordering for DAGs.
