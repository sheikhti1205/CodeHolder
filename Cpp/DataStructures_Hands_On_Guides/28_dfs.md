# Depth First Search

## What Problem This Solves
DFS explores one path deeply before backtracking.

## Core Idea In Simple Words
Recursively visit an unvisited neighbor before trying the next neighbor.

## Visual Model
0 -> 1 -> 3 -> 2, then backtrack.

## Beginner-Friendly C++17 Code

```cpp
#include <iostream>
#include <vector>
using namespace std;
void dfs(const vector<vector<int>>& g, vector<bool>& vis, int v) {
    vis[v] = true;
    cout << v << " ";
    for (int to : g[v]) if (!vis[to]) dfs(g, vis, to);
}
int main() {
    vector<vector<int>> g = {{1,2},{0,3},{0,3},{1,2}};
    vector<bool> vis(g.size(), false);
    dfs(g, vis, 0); cout << "\n";
    return 0;
}
```

## Code Breakdown
DFS uses recursion as an implicit stack.

## Step-By-Step Dry Run
| Call | Action |
|---|---|
| dfs(0) | print 0, go deeper |
| dfs(1) | print 1 |
| dfs(3) | print 3 |

## Time And Space Complexity
Time `O(V+E)`, space `O(V)`.

## Common Mistakes
- No visited array on cyclic graph.
- Expecting only one possible order.
- Forgetting to test the smallest input, such as empty data or one item.

## Practice Problems
1. Count components.
2. Detect cycle.
3. Write iterative DFS.

## Quick Recap
DFS is deep exploration plus backtracking.
