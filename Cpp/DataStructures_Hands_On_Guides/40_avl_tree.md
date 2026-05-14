# AVL Tree

## What Problem This Solves
AVL tree is a self-balancing BST that keeps height differences small.

## Core Idea In Simple Words
After insertion, update height and rotate if balance factor becomes outside -1 to 1.

## Visual Model
LL case: 30 <- 20 <- 10 rotates right, making 20 the root.

## Beginner-Friendly C++17 Code

```cpp
#include <iostream>
#include <algorithm>
using namespace std;
struct Node { int key; int height; Node* left; Node* right; };
int h(Node* n) { return n ? n->height : 0; }
int bal(Node* n) { return n ? h(n->left) - h(n->right) : 0; }
Node* node(int x) { return new Node{x, 1, nullptr, nullptr}; }
Node* rightRotate(Node* y) {
    Node* x = y->left; Node* t = x->right;
    x->right = y; y->left = t;
    y->height = 1 + max(h(y->left), h(y->right));
    x->height = 1 + max(h(x->left), h(x->right));
    return x;
}
Node* leftRotate(Node* x) {
    Node* y = x->right; Node* t = y->left;
    y->left = x; x->right = t;
    x->height = 1 + max(h(x->left), h(x->right));
    y->height = 1 + max(h(y->left), h(y->right));
    return y;
}
Node* insert(Node* r, int key) {
    if (!r) return node(key);
    if (key < r->key) r->left = insert(r->left, key);
    else if (key > r->key) r->right = insert(r->right, key);
    else return r;
    r->height = 1 + max(h(r->left), h(r->right));
    int b = bal(r);
    if (b > 1 && key < r->left->key) return rightRotate(r);
    if (b < -1 && key > r->right->key) return leftRotate(r);
    if (b > 1 && key > r->left->key) { r->left = leftRotate(r->left); return rightRotate(r); }
    if (b < -1 && key < r->right->key) { r->right = rightRotate(r->right); return leftRotate(r); }
    return r;
}
void pre(Node* r) { if (!r) return; cout << r->key << " "; pre(r->left); pre(r->right); }
int main() {
    Node* root = nullptr;
    int a[] = {30,20,10,25,40,50};
    for (int x : a) root = insert(root, x);
    pre(root); cout << "\n";
    return 0;
}
```

## Code Breakdown
AVL insertion begins like BST insertion, then repairs balance using rotations.

## Step-By-Step Dry Run
| Case | Fix |
|---|---|
| LL | right rotation |
| RR | left rotation |
| LR | left then right |
| RL | right then left |

## Time And Space Complexity
Search/insert/delete `O(log n)`, rotations `O(1)`.

## Common Mistakes
- Updating balance before height.
- Mixing rotation order for LR/RL.
- Forgetting to test the smallest input, such as empty data or one item.

## Practice Problems
1. Trigger each rotation type.
2. Print balance factors.
3. Compare BST and AVL height.

## Quick Recap
AVL is BST plus height balance plus rotations.
