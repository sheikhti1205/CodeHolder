# Stack

## What Problem This Solves
A stack stores items in Last-In First-Out order.

## Core Idea In Simple Words
Push adds to top; pop removes from top.

## Visual Model
Push 10, 20, 30. Pop returns 30 first.

## Beginner-Friendly C++17 Code

```cpp
#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << "\n";
    return 0;
}
```

## Code Breakdown
`top` reads newest item. `pop` removes it. Check `empty()` first.

## Step-By-Step Dry Run
| Operation | Stack top first |
|---|---|
| push 10 | 10 |
| push 20 | 20,10 |
| push 30 | 30,20,10 |

## Time And Space Complexity
Push/pop/top `O(1)`, space `O(n)`.

## Common Mistakes
- Calling top on an empty stack.
- Expecting insertion order output.
- Forgetting to test the smallest input, such as empty data or one item.

## Practice Problems
1. Reverse a word.
2. Check parentheses.
3. Simulate undo.

## Quick Recap
Stack means last in, first out.
