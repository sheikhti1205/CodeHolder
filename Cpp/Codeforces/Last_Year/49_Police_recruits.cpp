#include <iostream>
using namespace std;
int main(){
    int t, n, count = 0, k = 0;
    cin >> t;
    while(t--){
        cin >> n;
        if(n == -1){
            if(k < 1){
                count++;
            }else{
                k--;
            }
        }else if(n >= 1){
            k += n;
        }
    } cout << count << endl;
    return 0;
}