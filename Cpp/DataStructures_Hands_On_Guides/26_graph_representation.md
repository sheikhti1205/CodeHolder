# Graph Representation

## What Problem This Solves
Graph representation stores vertices and edges so algorithms can run.

## Core Idea In Simple Words
Use adjacency lists: each vertex stores its neighbors.

## Visual Model
Edges 0-1, 0-2, 1-3 become `0: 1 2`, `1: 0 3`.

## Beginner-Friendly C++17 Code

```cpp
#include <iostream>
#include <vector>
using namespace std;
int main() {
    vector<vector<int>> g(4);
    g[0].push_back(1); g[1].push_back(0);
    g[0].push_back(2); g[2].push_back(0);
    g[1].push_back(3); g[3].push_back(1);
    for (int v = 0; v < 4; v++) {
        cout << v << ": ";
        for (int to : g[v]) cout << to << " ";
        cout << "\n";
    }
    return 0;
}
```

## Code Breakdown
For undirected edges, add both directions. For directed edges, add one direction.

## Step-By-Step Dry Run
| Edge | Update |
|---|---|
| 0-1 | add 1 to 0 and 0 to 1 |
| 1-3 | add 3 to 1 and 1 to 3 |

## Time And Space Complexity
Space `O(V+E)`, neighbor traversal total `O(V+E)`.

## Common Mistakes
- Adding one direction for undirected graph.
- Using invalid vertex labels.
- Forgetting to test the smallest input, such as empty data or one item.

## Practice Problems
1. Build from input.
2. Store directed graph.
3. Store weighted edges.

## Quick Recap
Adjacency list is the standard sparse-graph representation.
