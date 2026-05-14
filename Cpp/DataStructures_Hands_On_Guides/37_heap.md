# Heap

## What Problem This Solves
A heap keeps the highest-priority value at the root while maintaining complete-tree shape.

## Core Idea In Simple Words
Insert at the end then move up. Delete root by replacing it with the last item then moving down.

## Visual Model
Max heap rule: every parent is greater than or equal to its children.

## Beginner-Friendly C++17 Code

```cpp
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
void insertHeap(vector<int>& h, int x) {
    h.push_back(x);
    int i = h.size() - 1;
    while (i > 0) {
        int p = (i - 1) / 2;
        if (h[p] >= h[i]) break;
        int t = h[p]; h[p] = h[i]; h[i] = t;
        i = p;
    }
}
int deleteRoot(vector<int>& h) {
    int root = h[0];
    h[0] = h.back(); h.pop_back();
    int i = 0;
    while (true) {
        int l = 2*i+1, r = 2*i+2, best = i;
        if (l < (int)h.size() && h[l] > h[best]) best = l;
        if (r < (int)h.size() && h[r] > h[best]) best = r;
        if (best == i) break;
        int t = h[i]; h[i] = h[best]; h[best] = t; i = best;
    }
    return root;
}
int main() {
    vector<int> h;
    insertHeap(h, 40); insertHeap(h, 20); insertHeap(h, 60); insertHeap(h, 10);
    cout << deleteRoot(h) << "\n";
    priority_queue<int, vector<int>, greater<int>> minHeap;
    minHeap.push(40); minHeap.push(20); minHeap.push(60);
    cout << minHeap.top() << "\n";
    return 0;
}
```

## Code Breakdown
This guide shows manual max heap insertion/deletion and C++ min heap with `priority_queue`.

## Step-By-Step Dry Run
| Action | Heap |
|---|---|
| insert 40 | 40 |
| insert 20 | 40 20 |
| insert 60 | 60 20 40 |

## Time And Space Complexity
Insert/delete `O(log n)`, root access `O(1)`, space `O(n)`.

## Common Mistakes
- Not restoring heap order after deletion.
- Mixing min heap and max heap rules.
- Forgetting to test the smallest input, such as empty data or one item.

## Practice Problems
1. Build heap from input.
2. Delete root repeatedly.
3. Use min heap for smallest-first tasks.

## Quick Recap
Heap is complete-tree shape plus priority order.
