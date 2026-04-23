#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int L;
        cin >> L;
        vector<int> a(L);
        for (int i = 0; i < L; i++) {
            cin >> a[i];
        }
        int swaps = 0;
        for (int i = 0; i < L; i++) {
            for (int j = 0; j < L - 1; j++) {
                if (a[j] > a[j + 1]) {
                    swap(a[j], a[j + 1]);
                    swaps++;
                }
            }
        }
        cout << "Optimal train swapping takes " << swaps << " swaps.\n";
    }
    return 0;
}