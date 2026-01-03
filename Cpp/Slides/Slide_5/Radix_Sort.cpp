#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> output(10);

void sort(vector<int> &sort){
    
}

void radix(const vector<int> &arr, int maxVal, int n){
    while(maxVal = maxVal / 10){
        for(int pos = 10; pos <= maxVal; pos*=10){
            for(int i = 0; i < n; i++){
                output[arr[i] % pos].push_back(arr[i]);
            }
            for(int i = 0; i < output.size(); i++){
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
    radix(arr, maxVal, n);
}