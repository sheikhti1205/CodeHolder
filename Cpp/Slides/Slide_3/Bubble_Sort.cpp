#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n; cout << "Enter the size of the array: " << endl;
    cin >> n;
    vector<int>arr(n);
    cout << "Enter the elements: " << endl;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int temp;
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(arr[j] > arr[j + 1]){
                temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
        }
    }
    bool first = true;
    for(int i = 0; i < n; i++){
        if(first == false){
            cout << ", ";
        }
        cout << arr[i];
        first = false;
    }
    return 0;
}