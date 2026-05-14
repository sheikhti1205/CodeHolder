# Infix To Prefix

## What Problem This Solves
Converts infix expressions into prefix notation, where operators come before operands.

## Core Idea In Simple Words
Reverse the expression, swap parentheses, convert to postfix, then reverse the result.

## Visual Model
A+B*C -> reverse C*B+A -> postfix CB*A+ -> prefix +A*BC.

## Beginner-Friendly C++17 Code

```cpp
#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

int prec(char op) { if (op=='+'||op=='-') return 1; if (op=='*'||op=='/') return 2; return 0; }
bool operand(char c) { return isalnum((unsigned char)c); }
string postfix(const string& s) {
    stack<char> ops; string out;
    for (char c : s) {
        if (operand(c)) out += c;
        else if (c == '(') ops.push(c);
        else if (c == ')') { while (!ops.empty() && ops.top()!='(') { out += ops.top(); ops.pop(); } if (!ops.empty()) ops.pop(); }
        else { while (!ops.empty() && prec(ops.top()) > prec(c)) { out += ops.top(); ops.pop(); } ops.push(c); }
    }
    while (!ops.empty()) { out += ops.top(); ops.pop(); }
    return out;
}
string prefix(string s) {
    reverse(s.begin(), s.end());
    for (char& c : s) { if (c == '(') c = ')'; else if (c == ')') c = '('; }
    string p = postfix(s);
    reverse(p.begin(), p.end());
    return p;
}
int main() { cout << prefix("A+B*C") << "\n"; return 0; }
```

## Code Breakdown
The reverse trick lets us reuse postfix logic.

## Step-By-Step Dry Run
| Step | Expression |
|---|---|
| Original | A+B*C |
| Reversed | C*B+A |
| Postfix | CB*A+ |
| Prefix | +A*BC |

## Time And Space Complexity
Time `O(n)`, space `O(n)`.

## Common Mistakes
- Forgetting to swap parentheses.
- Mishandling associativity.
- Forgetting to test the smallest input, such as empty data or one item.

## Practice Problems
1. Convert `(A+B)*C`.
2. Convert `A*(B+C)/D`.
3. Compare prefix and postfix.

## Quick Recap
Prefix conversion can be learned as reverse plus postfix plus reverse.
