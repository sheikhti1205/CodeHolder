#include <iostream>
using namespace std;
int main(){
    int arr[3];
    cin >> arr[0] >> arr[1] >> arr[2];
    for(int i = 0; i < 3; i++){
        int temp = arr[i], j = i - 1;
        while(j >= 0 && arr[j] > temp){
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
    cout << abs(arr[0] - arr[1]) + abs(arr[2] - arr[1]) << endl;
    return 0;
}