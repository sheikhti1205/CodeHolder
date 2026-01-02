#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n; cout << "Enter array size: " << endl;
    cin >> n;
    vector<int> arr(n); // 4, 2, 2, 8, 3, 3, 1
    cout << "Enter elements: " << endl;
    int maxValue, minValue; cin >> arr[0]; maxValue = arr[0]; minValue = arr[0];
    for(int i = 1; i < n; i++){
        cin >> arr[i];
        if(arr[i] > maxValue) maxValue = arr[i];
        if(arr[i] < minValue) minValue = arr[i];
    } // max = 8, min = 1
    vector<int> count(maxValue - minValue + 1, 0); // count = {0, 0, 0, 0, 0, 0, 0, 0} 8 zeroes
    for(int i = 0; i < n; i++){ //                             1, 2, 3, 4, 5, 6, 7, 8
        count[arr[i] - minValue]++; // first arr[i] = 4, count[4 - 1] or count[3] = 1....
    } //                               then...count = {1, 2, 2, 1, 0, 0, 0, 1}
    //                                                 1, 2, 3, 4, 5, 6, 7, 8
    for(int i = 1; i < count.size(); i++){
        count[i] += count[i - 1];
    } // count = {1, 3, 5, 6, 6, 6, 6, 7}
    vector<int> output(n);
    // vector output has size of n = 7 elements
    for(int i = n - 1; i >= 0; i--){
        int val = arr[i]; // 4, 2, 2, 8, 3, 3, 1 --these values
        int pos = --count[val - minValue]; // val = 4, min = 1; 
        //count[3] = 6 -> pos = 5 (since we're doing pre_decrement)
        output[pos] = val; // output[5] = 4, as val = 4
    }
    bool first = true;
    for(int i = 0; i < n; i++){
        if(first == false){
            cout << ", ";
        }cout << output[i];
        first = false;
    }
    return 0;
}