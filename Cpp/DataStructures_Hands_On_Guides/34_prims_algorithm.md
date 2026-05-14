# Prim Algorithm

## What Problem This Solves
Prim finds a minimum spanning tree of a connected weighted undirected graph.

## Core Idea In Simple Words
Start from any vertex and repeatedly add the cheapest edge reaching a new vertex.

## Visual Model
Chosen set grows like an island connected by cheapest bridges.

## Beginner-Friendly C++17 Code

```cpp
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main() {
    int n = 4;
    vector<vector<pair<int,int>>> g(n);
    auto add = [&](int u,int v,int w){ g[u].push_back({v,w}); g[v].push_back({u,w}); };
    add(0,1,10); add(0,2,6); add(0,3,5); add(1,3,15); add(2,3,4);
    vector<bool> used(n, false);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0,0});
    int total = 0;
    while (!pq.empty()) {
        int w = pq.top().first, v = pq.top().second; pq.pop();
        if (used[v]) continue;
        used[v] = true; total += w;
        for (auto e : g[v]) if (!used[e.first]) pq.push({e.second, e.first});
    }
    cout << total << "\n";
    return 0;
}
```

## Code Breakdown
Priority queue stores candidate edges. Add weight only when a new vertex joins MST.

## Step-By-Step Dry Run
| Chosen | Weight | Total |
|---:|---:|---:|
| 0 | 0 | 0 |
| 3 | 5 | 5 |
| 2 | 4 | 9 |
| 1 | 10 | 19 |

## Time And Space Complexity
Time `O(E log E)`, space `O(V+E)`.

## Common Mistakes
- Using directed graph.
- Adding stale edge weights.
- Forgetting to test the smallest input, such as empty data or one item.

## Practice Problems
1. Print chosen edges.
2. Try different start.
3. Detect disconnected graph.

## Quick Recap
Prim grows one MST tree one cheap edge at a time.
