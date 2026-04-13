#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int t, n;
    cin >> t;
    while(t--){
        cin >> n;
        int arr[n];
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }
        sort(arr, arr + n);
        int middle = n/2;
        cout << arr[middle] << " ";
        int i = middle - 1, j = middle + 1;
        while(i >= 0 || j < n){
            if(i >= 0) cout << arr[i--] << " ";
            if(j < n) cout << arr[j++] << " ";
        } cout << endl;
    }
    return 0;
}