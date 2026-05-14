#include <iostream>
using namespace std;
int main(){
    int t, n; cin >> t;
    while(t--){
        cin >> n;
        string a, b;
        cin >> a >> b;
        bool possible = true;
        for(int i = 0; i < n; i++){
            if(a[i] == '1' && b[i] == '1'){
                possible = false;
                break;
            }
        }
        cout << (possible ? "YES" : "NO") << endl;
    }
    return 0;
}