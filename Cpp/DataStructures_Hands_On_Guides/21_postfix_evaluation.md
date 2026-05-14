# Postfix Expression Evaluation

## What Problem This Solves
Evaluates postfix expressions without parentheses or precedence rules.

## Core Idea In Simple Words
Push numbers. When an operator appears, pop two numbers, apply it, and push the result.

## Visual Model
234*+ means 2 + (3*4) = 14.

## Beginner-Friendly C++17 Code

```cpp
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int apply(int a, int b, char op) {
    if (op == '+') return a + b;
    if (op == '-') return a - b;
    if (op == '*') return a * b;
    return a / b;
}
int eval(const string& s) {
    stack<int> st;
    for (char c : s) {
        if (c == ' ') continue;
        if (isdigit((unsigned char)c)) st.push(c - '0');
        else {
            int b = st.top(); st.pop();
            int a = st.top(); st.pop();
            st.push(apply(a, b, c));
        }
    }
    return st.top();
}
int main() { cout << eval("234*+") << "\n"; return 0; }
```

## Code Breakdown
The second popped number is the left operand for `-` and `/`.

## Step-By-Step Dry Run
| Symbol | Stack |
|---|---|
| 2 | 2 |
| 3 | 2,3 |
| 4 | 2,3,4 |
| * | 2,12 |
| + | 14 |

## Time And Space Complexity
Time `O(n)`, space `O(n)`.

## Common Mistakes
- Reversing operands for subtraction.
- Assuming this simple version handles multi-digit numbers.
- Forgetting to test the smallest input, such as empty data or one item.

## Practice Problems
1. Evaluate `23+5*`.
2. Add multi-digit support.
3. Detect invalid expressions.

## Quick Recap
Postfix evaluation is a perfect stack application.
