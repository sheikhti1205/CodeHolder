#include <iostream>
using namespace std;
int main(){
    int n, k, count = 0;
    cin >> n >> k;
// time - 240 min
    int time = 240 - k;
    for(int i=1; i<=n; i++){
        if(time - i*5 >= 0){
            time -= i*5;
            count++;
        }
    } cout << count << endl;
    return 0;
}