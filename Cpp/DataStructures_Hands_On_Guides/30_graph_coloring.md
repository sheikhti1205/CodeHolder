# Graph Coloring

## What Problem This Solves
Graph coloring assigns colors so adjacent vertices do not share a color.

## Core Idea In Simple Words
For each vertex, choose the smallest color not used by already-colored neighbors.

## Visual Model
If neighbor colors are 0 and 1, choose color 2.

## Beginner-Friendly C++17 Code

```cpp
#include <iostream>
#include <vector>
using namespace std;
int main() {
    vector<vector<int>> g = {{1,2},{0,2,3},{0,1,3},{1,2}};
    int n = g.size();
    vector<int> color(n, -1);
    for (int v = 0; v < n; v++) {
        vector<bool> used(n, false);
        for (int to : g[v]) if (color[to] != -1) used[color[to]] = true;
        int c = 0;
        while (used[c]) c++;
        color[v] = c;
    }
    for (int v = 0; v < n; v++) cout << v << ":" << color[v] << "\n";
    return 0;
}
```

## Code Breakdown
Greedy coloring is easy but not guaranteed minimum.

## Step-By-Step Dry Run
| Vertex | Chosen color |
|---:|---:|
| 0 | 0 |
| 1 | 1 |
| 2 | 2 |
| 3 | 0 |

## Time And Space Complexity
Greedy time about `O(V+E)`, space `O(V)`.

## Common Mistakes
- Thinking greedy always gives chromatic number.
- Ignoring already-colored neighbors.
- Forgetting to test the smallest input, such as empty data or one item.

## Practice Problems
1. Color a cycle.
2. Color a complete graph.
3. Model exam scheduling.

## Quick Recap
Graph coloring is conflict avoidance.
