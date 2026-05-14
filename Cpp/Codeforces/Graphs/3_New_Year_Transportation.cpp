#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n, t; cin >> n >> t;
    vector<int> a(n + 1);
    int pos = 1;
    for(int i = 1; i < n; i++){
        cin >> a[i];
    }
    while(pos < t){
        pos += a[pos];
    }
    if(pos == t){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    return 0;
}