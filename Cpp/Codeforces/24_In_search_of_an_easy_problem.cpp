#include <iostream>
using namespace std;
int main(){
    int n, a, cond = 1;
    cin >> n;
    while(n--){
        cin >> a;
        if(a == 1){
            cond = 0;
            break;
        }
    } cout << ((cond == 0) ? "HARD" : "EASY") << endl;
    return 0;
}