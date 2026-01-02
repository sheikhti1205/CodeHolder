#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n; cout << "Enter the number of elements: " << endl;
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the elements (N.B. they need to be ascending and sorted!!!)" << endl;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        if(i != 0 && arr[i] < arr[i-1]){
            cout << "You failed to follow conditions! Exiting now!...." << endl;
            return 0;
        }
    }
    int t; cout << "Enter your target element: " << endl;
    cin >> t;
    int lb = 0, ub = n - 1, mid;
    while(lb <= ub){
        mid = (ub + lb) / 2;
        if(arr[mid] == t){
            cout << "Target element found at index: " << mid << endl;
            return 0;
        }
        if(arr[mid] > t){
            ub = mid - 1;
        }else{
            lb = mid + 1;
        }
    }
    cout << "Target element not found!" << endl;
    return 0;
}