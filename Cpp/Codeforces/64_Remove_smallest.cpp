#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int t, n, k, yes = 1; cin >> t;
    while(t--){
        cin >> n; yes = 1;
        vector<int>arr;
        for(int i=0; i<n; i++){
            cin >> k;
            arr.push_back(k);
        }
        sort(arr.begin(), arr.end());
        for(int i=0; i<n; i++){
            if(i != 0){
                if(abs(arr[i] - arr[i-1]) > 1){
                    cout << "NO" << endl;
                    yes = 0;
                    break;
                }
            }
        }if(yes == 1){
            cout << "YES" << endl;
        }
    }
    return 0;
}