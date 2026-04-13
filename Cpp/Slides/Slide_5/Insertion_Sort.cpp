#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n; cout << "Enter the size of your array: " << endl;
    cin >> n;
    cout << "Enter the elements of your array: " << endl;
    vector<int> arr(n);
    // Example input: 5  5 2 4 6 1  (n = 5, elements shown after)
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int temp;
    for(int i = 1; i < n; i++){
        // Treat arr[0..i-1] as a sorted hand; insert arr[i] into its correct position.
        temp = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] < temp){
            // Shift bigger elements right to make space for temp.
            arr[j + 1] = arr[j];
            j--;
        }
        // Place temp into the "hole" created by shifting.
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
