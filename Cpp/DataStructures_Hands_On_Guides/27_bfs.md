# Breadth First Search

## What Problem This Solves
BFS visits a graph level by level and gives shortest paths in unweighted graphs.

## Core Idea In Simple Words
Use a queue and mark vertices when they enter the queue.

## Visual Model
Start 0: visit level 0, then all level 1 neighbors, then level 2.

## Beginner-Friendly C++17 Code

```cpp
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
void bfs(const vector<vector<int>>& g, int start) {
    vector<bool> vis(g.size(), false);
    queue<int> q;
    vis[start] = true; q.push(start);
    while (!q.empty()) {
        int v = q.front(); q.pop();
        cout << v << " ";
        for (int to : g[v]) if (!vis[to]) { vis[to] = true; q.push(to); }
    }
}
int main() {
    vector<vector<int>> g = {{1,2},{0,3},{0,3},{1,2}};
    bfs(g, 0); cout << "\n";
    return 0;
}
```

## Code Breakdown
Queue controls level order. `visited` prevents repeats.

## Step-By-Step Dry Run
| Step | Queue | Output |
|---|---|---|
| start | 0 | |
| pop 0 | 1,2 | 0 |
| pop 1 | 2,3 | 0 1 |

## Time And Space Complexity
Time `O(V+E)`, space `O(V)`.

## Common Mistakes
- Marking visited too late.
- Assuming one fixed BFS order.
- Forgetting to test the smallest input, such as empty data or one item.

## Practice Problems
1. Compute distances.
2. BFS on grid.
3. Check connected graph.

## Quick Recap
BFS is queue-based level traversal.
