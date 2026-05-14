# Bipartite Graph

## What Problem This Solves
A graph is bipartite if vertices can be split into two groups and every edge crosses groups.

## Core Idea In Simple Words
Use BFS coloring with two colors. Same-color edge means not bipartite.

## Visual Model
Even cycle is bipartite; odd cycle is not.

## Beginner-Friendly C++17 Code

```cpp
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
bool bipartite(const vector<vector<int>>& g) {
    vector<int> color(g.size(), -1);
    for (int s = 0; s < (int)g.size(); s++) {
        if (color[s] != -1) continue;
        queue<int> q; color[s] = 0; q.push(s);
        while (!q.empty()) {
            int v = q.front(); q.pop();
            for (int to : g[v]) {
                if (color[to] == -1) { color[to] = 1 - color[v]; q.push(to); }
                else if (color[to] == color[v]) return false;
            }
        }
    }
    return true;
}
int main() {
    vector<vector<int>> g = {{1,3},{0,2},{1,3},{0,2}};
    cout << (bipartite(g) ? "Bipartite" : "Not bipartite") << "\n";
    return 0;
}
```

## Code Breakdown
The outer loop handles disconnected components.

## Step-By-Step Dry Run
| Vertex | Color |
|---:|---:|
| 0 | 0 |
| 1 | 1 |
| 3 | 1 |
| 2 | 0 |

## Time And Space Complexity
Time `O(V+E)`, space `O(V)`.

## Common Mistakes
- Checking only from vertex 0.
- Giving same color to neighbors.
- Forgetting to test the smallest input, such as empty data or one item.

## Practice Problems
1. Test triangle.
2. Test square.
3. Separate students into two teams.

## Quick Recap
Bipartite checking is two-color graph coloring.
