# Longest Common Subsequence

## What Problem This Solves
LCS finds the longest sequence that appears in two strings in the same order, not necessarily side by side.

## Core Idea In Simple Words
Use dynamic programming. Each cell stores the LCS length for two prefixes.

## Visual Model
`ABC` and `AC` have LCS `AC` with length 2. The `B` is skipped.

## Beginner-Friendly C++17 Code

```cpp
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    string a = "ABCBDAB", b = "BDCABA";
    int n = a.size(), m = b.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i - 1] == b[j - 1]) dp[i][j] = 1 + dp[i - 1][j - 1];
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    cout << dp[n][m] << "\n";
    return 0;
}
```

## Code Breakdown
- `dp[i][j]` means first `i` chars of `a` and first `j` chars of `b`.
- Match: diagonal plus one.
- Mismatch: max of top and left.
- Row 0 and column 0 represent empty strings.

## Step-By-Step Dry Run
| Case | Formula |
|---|---|
| `a[i-1] == b[j-1]` | `1 + dp[i-1][j-1]` |
| otherwise | `max(dp[i-1][j], dp[i][j-1])` |

## Time And Space Complexity
- Time: `O(n*m)`.
- Space: `O(n*m)`.

## Common Mistakes
- Confusing subsequence with substring.
- Using `a[i]` instead of `a[i-1]`.
- Forgetting to test the smallest input, such as empty data or one item.

## Practice Problems
1. Print only the length.
2. Backtrack and print the LCS string.
3. Compare with longest common substring.

## Quick Recap
LCS is a classic DP: diagonal on match, max of top/left on mismatch.
