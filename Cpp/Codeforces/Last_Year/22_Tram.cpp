#include <iostream>
using namespace std;
int main(){
    int n, count = 0, entx, max = 0; // Number of stop || exits - enters
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<2; j++){
            cin >> entx;
            if(j==0){
                count-=entx;
            }
            if(j==1){
                count+=entx;
                if(count>max){
                    max = count;
                }
            }
        }

    } cout << max << endl;
    return 0;
}