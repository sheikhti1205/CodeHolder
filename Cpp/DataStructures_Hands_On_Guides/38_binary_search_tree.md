# Binary Search Tree

## What Problem This Solves
BST stores values so smaller values go left and larger values go right.

## Core Idea In Simple Words
Search direction is decided at each node by comparison.

## Visual Model
Root 50: 30 goes left, 70 goes right.

## Beginner-Friendly C++17 Code

```cpp
#include <iostream>
using namespace std;
struct Node { int data; Node* left; Node* right; };
Node* node(int x) { return new Node{x, nullptr, nullptr}; }
Node* insert(Node* r, int x) {
    if (!r) return node(x);
    if (x < r->data) r->left = insert(r->left, x);
    else if (x > r->data) r->right = insert(r->right, x);
    return r;
}
bool search(Node* r, int x) {
    if (!r) return false;
    if (r->data == x) return true;
    if (x < r->data) return search(r->left, x);
    return search(r->right, x);
}
void inorder(Node* r) {
    if (!r) return;
    inorder(r->left); cout << r->data << " "; inorder(r->right);
}
int main() {
    Node* root = nullptr;
    int a[] = {50,30,70,20,40,60,80};
    for (int x : a) root = insert(root, x);
    inorder(root); cout << "\n" << search(root, 60) << "\n";
    return 0;
}
```

## Code Breakdown
Inorder traversal of a BST prints sorted order.

## Step-By-Step Dry Run
| Insert 40 | Decision |
|---|---|
| compare 50 | go left |
| compare 30 | go right |
| null | insert |

## Time And Space Complexity
Average `O(log n)`, worst `O(n)` if unbalanced.

## Common Mistakes
- Thinking BST is always balanced.
- No clear duplicate rule.
- Forgetting to test the smallest input, such as empty data or one item.

## Practice Problems
1. Find min/max.
2. Implement deletion.
3. Print sorted values.

## Quick Recap
BST is ordered binary search by comparison.
