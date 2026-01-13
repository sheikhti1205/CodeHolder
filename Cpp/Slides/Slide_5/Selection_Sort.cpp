#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n; cout << "Enter the size of the array: " << endl;
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the elements: " << endl;
    // Example: 64 25 12 22 11 (n = 5)
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int idx, minVal;
    for(int i = 0; i < n; i++){
        // Find the minimum in the unsorted suffix arr[i..n-1]
        minVal = arr[i];
        idx = i;
        for(int j = i + 1; j < n; j++){
            if(minVal > arr[j]){
                minVal = arr[j];
                idx = j;
            }
        }
        // Swap the smallest element into position i.
        int temp = arr[i];
        arr[i] = minVal;
        arr[idx] = temp;
    }
    for(int i = 0; i < n; i++){
        cout << arr[i];
    }
}
