# Huffman Coding

## What Problem This Solves
Huffman coding compresses data with shorter codes for frequent characters.

## Core Idea In Simple Words
Repeatedly combine the two lowest-frequency nodes to build a prefix-free tree.

## Visual Model
a:5 and b:9 combine into 14; low frequencies combine first.

## Beginner-Friendly C++17 Code

```cpp
#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;
struct Node { char ch; int freq; Node* left; Node* right; };
struct Cmp { bool operator()(Node* a, Node* b) { return a->freq > b->freq; } };
void print(Node* r, string code) {
    if (!r) return;
    if (!r->left && !r->right) { cout << r->ch << ": " << code << "\n"; return; }
    print(r->left, code + "0");
    print(r->right, code + "1");
}
int main() {
    vector<pair<char,int>> data = {{'a',5},{'b',9},{'c',12},{'d',13},{'e',16},{'f',45}};
    priority_queue<Node*, vector<Node*>, Cmp> pq;
    for (auto x : data) pq.push(new Node{x.first, x.second, nullptr, nullptr});
    while (pq.size() > 1) {
        Node* l = pq.top(); pq.pop();
        Node* r = pq.top(); pq.pop();
        pq.push(new Node{'#', l->freq + r->freq, l, r});
    }
    print(pq.top(), "");
    return 0;
}
```

## Code Breakdown
Min heap chooses two smallest frequencies. Left path is 0, right path is 1.

## Step-By-Step Dry Run
| Step | Combine |
|---:|---|
| 1 | 5 + 9 = 14 |
| 2 | 12 + 13 = 25 |
| 3 | 14 + 16 = 30 |

## Time And Space Complexity
Build tree `O(k log k)`, where `k` is distinct characters.

## Common Mistakes
- Using max heap.
- Thinking codes are fixed length.
- Forgetting to test the smallest input, such as empty data or one item.

## Practice Problems
1. Calculate average code length.
2. Encode a word.
3. Decode from tree.

## Quick Recap
Huffman is greedy compression: frequent symbols get shorter paths.
