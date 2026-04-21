#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int t, n; cin >> t;
    while(t--){
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        bool is_true = false;
        for(int i = 2; i < n; i++){
            if(a[i] == a[i - 1] && a[i] == a[i - 2]){
                cout << a[i] << endl;
                is_true = true;
                break;
            }
        }
        if(!is_true){
            cout << "-1" << endl;
        }
    }
    return 0;
}