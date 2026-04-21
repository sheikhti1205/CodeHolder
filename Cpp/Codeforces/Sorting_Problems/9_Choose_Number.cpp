#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> A(n);
    for (int i = 0; i < n; i++) cin >> A[i];

    int m;
    cin >> m;

    vector<int> B(m);
    for (int i = 0; i < m; i++) cin >> B[i];

    // Step 1: store all values of A and B in sets for fast checking
    set<int> inA, inB;

    for (int x : A) inA.insert(x);
    for (int x : B) inB.insert(x);

    // Step 2: try all pairs
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int sum = A[i] + B[j];

            if (!inA.count(sum) && !inB.count(sum)) {
                cout << A[i] << " " << B[j] << endl;
                return 0;
            }
        }
    }

    return 0;
}