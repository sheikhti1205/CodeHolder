#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> output(10);

void sort(vector<int> &sort){
    // Placeholder: this should sort a single bucket (or perform stable extraction).
}

void radix(const vector<int> &arr, int maxVal, int n){
    // Radix sort idea: group numbers by digit (ones, tens, hundreds...) using 10 buckets.
    // Example: arr = {170, 45, 75, 90, 802, 24, 2, 66}
    // Pass 1 (ones): buckets by last digit -> then collect in order.
    while(maxVal = maxVal / 10){
        for(int pos = 10; pos <= maxVal; pos*=10){
            for(int i = 0; i < n; i++){
                // Bucket index is the current digit; this line is intended to group by digit.
                output[arr[i] % pos].push_back(arr[i]);
            }
            for(int i = 0; i < output.size(); i++){
                // Sort or stably collect each bucket before moving to next digit.
                sort(output[i]);
            }
        }
    }
}

int main(){
    int n; cout << "Enter array size: " << endl;
    cin >> n;
    cout << "Enter the elements: " << endl;
    vector<int> arr(n);
    cin >> arr[0]; int maxVal = arr[0];
    for(int i = 1; i < n; i++){
        cin >> arr[i];
        if(maxVal < arr[i]){
            maxVal = arr[i];
        }
    }
    // Run radix sort using the maximum value to know how many digit passes to do.
    radix(arr, maxVal, n);
}
