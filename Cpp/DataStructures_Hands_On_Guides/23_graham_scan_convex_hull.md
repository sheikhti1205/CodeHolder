# Graham Scan Convex Hull

## What Problem This Solves
Convex hull finds the outer boundary around a set of points.

## Core Idea In Simple Words
Sort points and keep removing turns that bend inward.

## Visual Model
A clockwise turn means the middle point is not on the hull.

## Beginner-Friendly C++17 Code

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Point { int x, y; };
int cross(Point a, Point b, Point c) {
    return (b.x-a.x)*(c.y-a.y) - (b.y-a.y)*(c.x-a.x);
}
vector<Point> hull(vector<Point> p) {
    sort(p.begin(), p.end(), [](Point a, Point b){ return a.x == b.x ? a.y < b.y : a.x < b.x; });
    vector<Point> h;
    for (Point pt : p) { while (h.size() >= 2 && cross(h[h.size()-2], h.back(), pt) <= 0) h.pop_back(); h.push_back(pt); }
    int lower = h.size();
    for (int i = (int)p.size()-2; i >= 0; i--) { while ((int)h.size() > lower && cross(h[h.size()-2], h.back(), p[i]) <= 0) h.pop_back(); h.push_back(p[i]); }
    if (!h.empty()) h.pop_back();
    return h;
}
int main() {
    vector<Point> p = {{0,0},{1,1},{2,0},{1,2},{0,2}};
    for (Point q : hull(p)) cout << "(" << q.x << "," << q.y << ") ";
    cout << "\n";
    return 0;
}
```

## Code Breakdown
This monotonic-chain version teaches the same turn-removal principle used in Graham scan.

## Step-By-Step Dry Run
| Test | Meaning |
|---|---|
| cross > 0 | left turn |
| cross <= 0 | remove middle point |

## Time And Space Complexity
Sorting `O(n log n)`, scan `O(n)`, space `O(n)`.

## Common Mistakes
- Getting cross-product sign backward.
- Not deciding how to handle collinear points.
- Forgetting to test the smallest input, such as empty data or one item.

## Practice Problems
1. Draw hull by hand.
2. Keep collinear boundary points.
3. Compare with angle sorting.

## Quick Recap
Convex hull keeps the outside turns and removes inward bends.
