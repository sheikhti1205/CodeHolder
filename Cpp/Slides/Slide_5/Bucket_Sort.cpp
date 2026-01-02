#include <iostream>
#include <vector>
using namespace std;

void In_Sort(vector<float> &buckets){
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
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    vector<vector<float>> buckets(n);
    for(int i = 0; i < n; i++){
        int idx = (int)(n * arr[i]);
        if(idx == n) idx = n - 1;
        buckets[idx].push_back(arr[i]);
    }
    for(int i = 0; i < n; i++){
        bool first = true;
        cout << "Buckets at index: " << i << endl;
        for(int j = 0; j < buckets[i].size(); j++){
            if(first == false){
                cout << ", ";
            }
            cout << buckets[i][j];
            first = false;
        } cout << endl;
    }
    for(int i = 0; i < n; i++){
        In_Sort(buckets[i]);
    }
    cout << "After sorting: " << endl;
    bool first = true;
    for(int i = 0; i < n; i++){
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