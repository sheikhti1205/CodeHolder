#include <iostream>
using namespace std;
int main(){
    int t, a, b, c;
    cin >> t;
    while(t--){
        cin >> a >> b >> c;
        if(a+b == c) cout << "YES" << endl;
        else if(b+c == a) cout << "YES" << endl;
        else if(a+c == b) cout << "YES" << endl;
        else{
            cout << "NO" << endl;
        }
    }
    return 0;
}