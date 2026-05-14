# Swap Two Numbers

## What Problem This Solves
Swapping exchanges two stored values. This tiny idea appears inside sorting, array rearrangement, and many update operations.

## Core Idea In Simple Words
Save one value in a temporary variable, copy the second value into the first variable, then copy the saved value into the second variable.

## Visual Model
| Step | temp | a | b |
|---|---:|---:|---:|
| Start | - | 10 | 20 |
| Save `a` | 10 | 10 | 20 |
| Put `b` in `a` | 10 | 20 | 20 |
| Put `temp` in `b` | 10 | 20 | 10 |

## Beginner-Friendly C++17 Code

```cpp
#include <iostream>
using namespace std;

int main() {
    int a = 10;
    int b = 20;

    cout << "Before: " << a << " " << b << "\n";
    int temp = a;
    a = b;
    b = temp;
    cout << "After: " << a << " " << b << "\n";
    return 0;
}
```

## Code Breakdown
- `temp` protects the original value of `a`.
- Assignment copies values from right to left.
- The temporary-variable method is safe and easy to explain in exams.

## Step-By-Step Dry Run
For `a = 10`, `b = 20`, after `temp = a`, temp is 10. After `a = b`, both variables temporarily hold 20 and temp still holds 10. After `b = temp`, the exchange is complete.

## Time And Space Complexity
- Time: `O(1)`.
- Space: `O(1)`.

## Common Mistakes
- Doing `a = b` first and losing the original value of `a`.
- Using arithmetic swap and causing overflow for large values.
- Forgetting to test the smallest input, such as empty data or one item.

## Practice Problems
1. Swap two user-entered integers.
2. Swap two characters.
3. Swap first and last elements of a vector.

## Quick Recap
Swapping is a constant-time value exchange. Use a temporary variable when clarity matters.
