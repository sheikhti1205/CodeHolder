#include <iostream>
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    int count = 0;
    for(int i=0; i<n; i++){
        if(i % 2 == 0){
            for(int j=0; j<m; j++){
                cout << "#";
            }
            if(count == 0){
                count = m-1;
            }else{
                count = 0;
            }
        }else{
            for(int j=0; j<m; j++){
                if(j == count){
                    cout << "#";
                }else{
                    cout << ".";
                }
            }
        } cout << endl;
    }
    return 0;
}