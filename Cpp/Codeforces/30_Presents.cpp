#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    } bool first = true;
    for(int i=1; i<=n; i++){
        for(int j=0; j<n; j++){
            if(arr[j] == i){
                if(!first){
                    cout << '+';
                }
                cout << j+1;
                first = false;
            }
        }
    } cout << endl;
}