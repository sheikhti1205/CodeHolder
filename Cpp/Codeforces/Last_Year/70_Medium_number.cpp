#include <iostream>
using namespace std;
int main(){
    int t, a, b, c, x, y; cin >> t;
    while(t--){
        cin >> a >> b >> c;
        x = min(a, b);
        y = max(a, b);
        x = min(x, c);
        y = max(y, c);
        cout << (a+b+c) - (x+y) << endl;
    }
    return 0;
}