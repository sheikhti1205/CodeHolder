#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;
int main(){
    int n, l; cin >> n >> l;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    double ans = a[0];
    ans = max(ans, (double)(l - a[n - 1]));
    for (int i = 1; i < n; i++) {
        ans = max(ans, (a[i] - a[i - 1]) / 2.0);
    }
    cout << fixed << setprecision(10) << ans << endl;
    return 0;
}