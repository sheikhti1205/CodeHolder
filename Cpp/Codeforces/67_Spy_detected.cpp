#include <iostream>
using namespace std;
int main(){
    int t, n, index = 0, temp; cin >> t;
    while(t--){
        cin >> n;
        int arr[n];
        for(int i=0; i<n; i++){
            cin >> arr[i];
        }
        for(int i=1; i<n; i++){
            if(arr[i] != arr[i-1]){
                temp = i-1;
                index = i;
                break;
            }
        }
        if(arr[index] == arr[index+1]){
            index = temp;
        }
        cout << index + 1 << endl;
    }
}