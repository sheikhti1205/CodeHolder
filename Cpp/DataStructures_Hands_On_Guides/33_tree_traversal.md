# Tree Traversal

## What Problem This Solves
Tree traversal visits every node in a chosen order.

## Core Idea In Simple Words
Preorder prints root first, inorder prints root between subtrees, postorder prints root last.

## Visual Model
For root A with children B and C: preorder A B C, inorder B A C, postorder B C A.

## Beginner-Friendly C++17 Code

```cpp
#include <iostream>
using namespace std;
struct Node { char data; Node* left; Node* right; };
Node* node(char x) { return new Node{x, nullptr, nullptr}; }
void pre(Node* r) { if (!r) return; cout << r->data << " "; pre(r->left); pre(r->right); }
void in(Node* r) { if (!r) return; in(r->left); cout << r->data << " "; in(r->right); }
void post(Node* r) { if (!r) return; post(r->left); post(r->right); cout << r->data << " "; }
int main() {
    Node* root = node('A'); root->left = node('B'); root->right = node('C');
    pre(root); cout << "\n"; in(root); cout << "\n"; post(root); cout << "\n";
    return 0;
}
```

## Code Breakdown
The only difference is where the print line appears.

## Step-By-Step Dry Run
| Traversal | Order rule |
|---|---|
| Preorder | root, left, right |
| Inorder | left, root, right |
| Postorder | left, right, root |

## Time And Space Complexity
Time `O(n)`, stack `O(h)`.

## Common Mistakes
- No null base case.
- Mixing order rules.
- Forgetting to test the smallest input, such as empty data or one item.

## Practice Problems
1. Build 5-node tree.
2. Count nodes.
3. Use inorder on BST.

## Quick Recap
Traversal order is controlled by root position.
