#include <iostream>
#include <vector>
using namespace std;
int main(){
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << "Enter the position of the number to delete 0-9: " << endl;
    // Example: delete position 4 -> removes the value 5
    int n; cin >> n;
    for(; n < arr.size() - 1; n++){
        // Shift left to overwrite the deleted element.
        arr[n] = arr[n + 1];
    }
    // Shrink the array by one after shifting.
    arr.resize(9);
    bool first = true;
    for(n = 0; n < arr.size(); n++){
        if(first == false){
            cout << ", ";
        }
        cout << arr[n];
        first = false;
    }
    return 0;
}
