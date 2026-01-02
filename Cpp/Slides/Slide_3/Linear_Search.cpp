#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n; cout << "Enter the size: " << endl;
    cin >> n;
    vector<int>arr(n);
    cout << "Enter the elements: " << endl;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cout << "Enter the target element: " << endl;
    int t; cin >> t;
    int i = 0;
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