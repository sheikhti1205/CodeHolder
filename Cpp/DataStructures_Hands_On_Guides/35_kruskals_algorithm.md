# Kruskal Algorithm

## What Problem This Solves
Kruskal finds MST by choosing cheapest edges without cycles.

## Core Idea In Simple Words
Sort edges by weight and use DSU to skip cycle-forming edges.

## Visual Model
Take 2-3 weight 4, take 0-3 weight 5, skip 0-2 weight 6 if cycle.

## Beginner-Friendly C++17 Code

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Edge { int u, v, w; };
struct DSU {
    vector<int> p;
    DSU(int n) { p.resize(n); for (int i=0;i<n;i++) p[i]=i; }
    int find(int x) { return p[x] == x ? x : p[x] = find(p[x]); }
    bool unite(int a,int b) { a=find(a); b=find(b); if (a==b) return false; p[b]=a; return true; }
};
int main() {
    vector<Edge> edges = {{0,1,10},{0,2,6},{0,3,5},{1,3,15},{2,3,4}};
    sort(edges.begin(), edges.end(), [](Edge a, Edge b){ return a.w < b.w; });
    DSU dsu(4); int total = 0;
    for (Edge e : edges) if (dsu.unite(e.u,e.v)) total += e.w;
    cout << total << "\n";
    return 0;
}
```

## Code Breakdown
DSU tracks components. Same component means adding the edge creates a cycle.

## Step-By-Step Dry Run
| Edge | Action |
|---|---|
| 2-3 (4) | take |
| 0-3 (5) | take |
| 0-2 (6) | skip |
| 0-1 (10) | take |

## Time And Space Complexity
Time `O(E log E)`, space `O(V+E)`.

## Common Mistakes
- Not sorting edges.
- Adding cycle edges.
- Forgetting to test the smallest input, such as empty data or one item.

## Practice Problems
1. Print MST edges.
2. Handle disconnected graph.
3. Compare with Prim.

## Quick Recap
Kruskal builds MST from cheapest safe edges.
