#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    int t, n, x;
    cin >> t;
    while(t--){
        cin >> n >> x;
        vector<int> a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        sort(a.rbegin(), a.rend());
        int team_count = 0, count = 0;
        for(int i = 0; i < n; i++){
            count++;
            if(1LL * count * a[i] >= x){
                team_count++;
                count = 0;
            }
        }
        cout << team_count << endl;
    }
    return 0;
}