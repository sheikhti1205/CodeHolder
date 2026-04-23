#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int r;
        cin >> r;
        vector<int> a(r);
        for (int i = 0; i < r; i++) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        int vito = a[r / 2];   // median
        int sum = 0;

        for (int i = 0; i < r; i++) {
            sum += abs(a[i] - vito);
        }
        cout << sum << "\n";
    }
    return 0;
}