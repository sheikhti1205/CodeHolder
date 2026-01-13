#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n; cout << "Enter the size: " << endl;
    cin >> n;
    vector<int>arr(n);
    cout << "Enter the elements: " << endl;
    // Example: 10 22 35 40 57
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cout << "Enter the target element: " << endl;
    int t; cin >> t;
    int i = 0;
    // Scan from left to right until the target is found.
    // This assumes the target exists in the array.
    while(arr[i] != t){
        i++;
    }
    if(i < n){
        cout << "Target found at index: " << i << endl;
    }else{
        cout << "Something unexpected happened? Tho it shouldn't" << endl;
    }
    return 0;
}
