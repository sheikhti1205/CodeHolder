#include <iostream>
using namespace std;
int main(){
    int t, a, b, c;
    cin >> t;
    while(t--){
        cin >> a >> b >> c;
        if(a != b){
            if(a != c){
                cout << a << endl;
            }else{
                cout << b << endl;
            }
        }else{
            cout << c << endl;
        }
    }
    return 0;
}