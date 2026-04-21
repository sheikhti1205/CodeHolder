#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n), b(n);

        for (int i = 0; i < n; i++) {
            cin >> a[i];
            b[i] = a[i]; // copy
        }

        // sort the copied array
        sort(b.begin(), b.end());

        int largest = b[n - 1];
        int secondLargest = b[n - 2];

        // compute answers
        for (int i = 0; i < n; i++) {
            if (a[i] == largest) {
                cout << a[i] - secondLargest << " ";
            } else {
                cout << a[i] - largest << " ";
            }
        }

        cout << endl;
    }

    return 0;
}