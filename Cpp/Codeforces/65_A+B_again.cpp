#include <iostream>
using namespace std;
int main(){
    int t;
    string n;
    cin >> t;
    while(t--){
        cin >> n;
        cout << n[0] + n[1] - ('0' + '0') << endl;
    }
    return 0;
}