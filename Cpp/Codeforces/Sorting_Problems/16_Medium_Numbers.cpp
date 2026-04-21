#include <iostream>
using namespace std;
int main(){
    int t; cin >> t;
    while(t--){
        int a, b, c; cin >> a >> b >> c;
        if((a > c && a < b) || (a < c && a > b)) cout << a << endl;
        else if((c > a && c < b) || (c < a && c > b)) cout << c << endl;
        else cout << b << endl;
    }
    return 0;
}