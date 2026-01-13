#include <iostream>
#include <vector>
using namespace std;

void In_Sort(vector<float> &buckets){
    // Insertion sort for one bucket (keeps bucket elements ordered)
    float temp;
    for(int i = 1; i < buckets.size(); i++){
        temp = buckets[i];
        int j = i - 1;
        while(j >= 0 && buckets[j] > temp){
            buckets[j + 1] = buckets[j];
            j--;
        }
        buckets[j + 1] = temp;
    }
}

int main(){
    int n; cout << "Enter the size of the array: " << endl;
    cin >> n;
    cout << "Enter the elements: " << endl;
    vector<float> arr(n);
    // Example input (n = 5): 0.42 0.32 0.25 0.19 0.77
    // These are assumed to be in [0, 1), which makes bucket mapping easy.
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    vector<vector<float>> buckets(n);
    // Create n buckets for ranges [0,1): bucket 0 for [0,1/n), bucket 1 for [1/n,2/n), ...
    // For n = 5, ranges are: [0,0.2), [0.2,0.4), [0.4,0.6), [0.6,0.8), [0.8,1.0)
    for(int i = 0; i < n; i++){
        // Map value to bucket index by scaling: idx = floor(n * value)
        // Example: value 0.42 -> idx = floor(5 * 0.42) = 2 (bucket [0.4,0.6))
        int idx = (int)(n * arr[i]);
        // Handle edge case: if value is exactly 1.0, push it into the last bucket
        if(idx == n) idx = n - 1;
        buckets[idx].push_back(arr[i]);
    }
    for(int i = 0; i < n; i++){
        bool first = true;
        cout << "Buckets at index: " << i << endl;
        // Visualize the distribution before sorting inside each bucket
        for(int j = 0; j < buckets[i].size(); j++){
            if(first == false){
                cout << ", ";
            }
            cout << buckets[i][j];
            first = false;
        } cout << endl;
    }
    for(int i = 0; i < n; i++){
        // Sort each bucket independently (small buckets -> fast with insertion sort)
        In_Sort(buckets[i]);
    }
    cout << "After sorting: " << endl;
    bool first = true;
    for(int i = 0; i < n; i++){
        // Concatenate buckets in order to get the fully sorted list
        for(int j = 0; j < buckets[i].size(); j++){
            if(first == false){
                cout << ", ";
            }
            cout << buckets[i][j];
            first = false;
        } //cout << endl;
    }
    return 0;
}
