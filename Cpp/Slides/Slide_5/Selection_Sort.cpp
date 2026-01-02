#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n; cout << "Enter the size of the array: " << endl;
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the elements: " << endl;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int idx, minVal;
    for(int i = 0; i < n; i++){
        minVal = arr[i];
        idx = i;
        for(int j = i + 1; j < n; j++){
            if(minVal > arr[j]){
                minVal = arr[j];
                idx = j;
            }
        }
        int temp = arr[i];
        arr[i] = minVal;
        arr[idx] = temp;
    }
    for(int i = 0; i < n; i++){
        cout << arr[i];
    }
}