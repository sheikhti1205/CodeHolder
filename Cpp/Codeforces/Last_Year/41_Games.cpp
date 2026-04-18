#include <iostream>
using namespace std;
int main(){
    int n, count = 0; cin >> n;
    int host[n], guest[n];
    for(int i=0; i<n; i++){
        cin >> host[i] >> guest[i];
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(host[i] == guest[j]){
                count++;
            }
        }
    } cout << count << endl;
    return 0;
}