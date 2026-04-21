#include <iostream>
#include <vector>
using namespace std;
int main(){
    int t, n; cin >> t;
    while(t--){
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        for(int i = 1; i < n; i++){
            int temp = a[i], j = i - 1;
            while(j >= 0 && a[j] > temp){
                a[j + 1] = a[j];
                j--;
            }
            a[j + 1] = temp;
        }
        bool pass = true;
        for(int i = 1; i < n; i++){
            if(a[i] - a[i - 1] > 1){
                pass = false;
                break;
            }
        }
        cout << (pass ? "YES" : "NO") << endl;
    }
    return 0;
}