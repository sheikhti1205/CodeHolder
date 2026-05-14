# Dijkstra Algorithm

## What Problem This Solves
Dijkstra finds shortest paths from one source in graphs with non-negative weights.

## Core Idea In Simple Words
Always expand the currently closest known vertex first using a min priority queue.

## Visual Model
If B has distance 4 and C has distance 1, process C first.

## Beginner-Friendly C++17 Code

```cpp
#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;
int main() {
    int n = 5;
    vector<vector<pair<int,int>>> g(n);
    g[0].push_back({1,4}); g[0].push_back({2,1});
    g[2].push_back({1,2}); g[1].push_back({3,1});
    g[2].push_back({3,5}); g[3].push_back({4,3});
    vector<int> dist(n, numeric_limits<int>::max());
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    dist[0] = 0; pq.push({0,0});
    while (!pq.empty()) {
        int d = pq.top().first, v = pq.top().second; pq.pop();
        if (d != dist[v]) continue;
        for (auto e : g[v]) {
            int to = e.first, w = e.second;
            if (dist[v] + w < dist[to]) { dist[to] = dist[v] + w; pq.push({dist[to], to}); }
        }
    }
    for (int i = 0; i < n; i++) cout << dist[i] << " ";
    cout << "\n";
    return 0;
}
```

## Code Breakdown
`dist` stores best known distances. Relaxation improves a neighbor through the current vertex.

## Step-By-Step Dry Run
| Process | Update |
|---|---|
| 0 | dist[1]=4, dist[2]=1 |
| 2 | dist[1]=3, dist[3]=6 |
| 1 | dist[3]=4 |

## Time And Space Complexity
Time `O((V+E) log V)`, space `O(V+E)`.

## Common Mistakes
- Using negative edges.
- Not skipping stale queue entries.
- Forgetting to test the smallest input, such as empty data or one item.

## Practice Problems
1. Print paths with parent array.
2. Compare with BFS.
3. Use undirected weighted graph.

## Quick Recap
Dijkstra is greedy shortest path for non-negative weights.
