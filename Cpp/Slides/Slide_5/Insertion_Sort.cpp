#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n; cout << "Enter the size of your array: " << endl;
    cin >> n;
    cout << "Enter the elements of your array: " << endl;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int temp;
    for(int i = 1; i < n; i++){
        temp = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > temp){
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
    bool first = true;
    for(int i = 0; i < n; i++){
        if(first == false){
            cout << ", ";
        }
        cout << arr[i];
        first = false;
    }
}