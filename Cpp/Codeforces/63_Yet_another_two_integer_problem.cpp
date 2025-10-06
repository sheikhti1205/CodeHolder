#include <iostream>
using namespace std;
int main(){
    int t, a, b, count = 0; cin >> t;
    while(t--){
        cin >> a >> b;
        count = abs(a - b);
        count = (count + 9) / 10;
        cout << count << endl;
    }
    return 0;
}