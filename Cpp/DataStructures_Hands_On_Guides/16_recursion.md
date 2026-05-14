# Recursion

## What Problem This Solves
Recursion solves a problem by solving a smaller version of itself.

## Core Idea In Simple Words
Use a base case to stop and a recursive case that moves toward the base case.

## Visual Model
factorial(4) = 4 * factorial(3) = 4 * 3 * 2 * 1.

## Beginner-Friendly C++17 Code

```cpp
#include <iostream>
using namespace std;

int factorial(int n) {
    if (n == 0 || n == 1) return 1;
    return n * factorial(n - 1);
}

int main() {
    cout << factorial(5) << "\n";
    return 0;
}
```

## Code Breakdown
Base case returns 1. Recursive case multiplies by the smaller factorial.

## Step-By-Step Dry Run
| Call | Return |
|---|---:|
| factorial(1) | 1 |
| factorial(2) | 2 |
| factorial(3) | 6 |

## Time And Space Complexity
Time `O(n)`, recursion stack `O(n)`.

## Common Mistakes
- Missing the base case.
- Calling with the same value forever.
- Forgetting to test the smallest input, such as empty data or one item.

## Practice Problems
1. Recursive sum.
2. Print numbers descending.
3. Compare recursive and iterative Fibonacci.

## Quick Recap
Recursion is self-calling with a stop condition.
