#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    while(true){
        int n; cin >> n;
        if(n == 0) break;
        vector<int> count(100, 0); // create an array with 100 zeroes inside it - (0, 0, 0, 0....)

        for(int i = 0; i < n; i++){
            int age; cin >> age;
            count[age]++;
        }

        bool first = true;
        for(int i = 1; i < 100; i++){
            while(count[i]--){
                if(!first) cout << " ";
                cout << i;
                first = false;
            }
        }
        cout << endl;
    }
    return 0;
}