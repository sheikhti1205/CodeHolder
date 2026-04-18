#include <iostream>
using namespace std;
int main(){
    int k, w, n, i;
    cin >> k >> w >> n;
    // first, init, number
    for(i=1; i<=n; i++){
        w -= k*i;
    }
    if(w>0){
        cout << '0' << endl;
    }else{
        cout << -w << endl;
    }
    return 0;
}