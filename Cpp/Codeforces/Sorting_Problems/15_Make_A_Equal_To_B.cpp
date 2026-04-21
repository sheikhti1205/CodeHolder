#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int t, n; cin >> t;
    while(t--){
        cin >> n;
        vector<int> a(n), b(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        for(int i = 0; i < n; i++){
            cin >> b[i];
        }
        int diff = 0, cntA = 0, cntB = 0;
        for(int i = 0; i < n; i++){
            if(a[i] != b[i]){
                diff++;
            }
            if(a[i] == 1){
                cntA++;
            }
            if(b[i] == 1){
                cntB++;
            }
        }
        if(diff < abs(cntA - cntB) + 1 ){
            cout << diff << endl;
        }else{
            cout << abs(cntA - cntB) + 1 << endl;
        }
    }
    return 0;
}