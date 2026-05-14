# Infix To Postfix

## What Problem This Solves
Converts human-style expressions into machine-friendly postfix notation.

## Core Idea In Simple Words
Output operands immediately and use a stack to delay operators.

## Visual Model
A+B*C becomes ABC*+ because multiplication happens first.

## Beginner-Friendly C++17 Code

```cpp
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int prec(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}
bool operand(char c) { return isalnum((unsigned char)c); }
string convert(const string& s) {
    stack<char> ops; string out;
    for (char c : s) {
        if (c == ' ') continue;
        if (operand(c)) out += c;
        else if (c == '(') ops.push(c);
        else if (c == ')') {
            while (!ops.empty() && ops.top() != '(') { out += ops.top(); ops.pop(); }
            if (!ops.empty()) ops.pop();
        } else {
            while (!ops.empty() && prec(ops.top()) >= prec(c)) { out += ops.top(); ops.pop(); }
            ops.push(c);
        }
    }
    while (!ops.empty()) { out += ops.top(); ops.pop(); }
    return out;
}
int main() { cout << convert("A+B*C") << "\n"; return 0; }
```

## Code Breakdown
Operands go to output. Operators wait on stack until precedence says they can leave.

## Step-By-Step Dry Run
| Symbol | Output | Stack |
|---|---|---|
| A | A | empty |
| + | A | + |
| B | AB | + |
| * | AB | +,* |
| C | ABC | +,* |
| end | ABC*+ | empty |

## Time And Space Complexity
Time `O(n)`, space `O(n)`.

## Common Mistakes
- Not popping remaining operators.
- Popping past `(`.
- Forgetting to test the smallest input, such as empty data or one item.

## Practice Problems
1. Convert `(A+B)*C`.
2. Support exponent.
3. Support multi-digit numbers.

## Quick Recap
Postfix conversion is operator scheduling with a stack.
