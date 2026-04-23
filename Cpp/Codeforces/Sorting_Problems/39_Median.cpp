#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> a;
    int x;
    while (cin >> x) {
        a.push_back(x);
        sort(a.begin(), a.end());
        int n = a.size();
        if (n % 2 == 1) {
            cout << a[n / 2] << "\n";
        } else {
            cout << (a[n / 2 - 1] + a[n / 2]) / 2 << "\n";
        }
    }
    return 0;
}