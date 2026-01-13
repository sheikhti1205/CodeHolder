#include <iostream>
#include <vector>
using namespace std;

vector<int> arr;

vector<int> merge(vector<int> left, vector<int> right){
    // Merge two already-sorted lists into one sorted result.
    int i = 0, j = 0;
    vector<int> result;
    while(i < left.size() && j < right.size()){
        if(left[i] < right[j]){
            result.push_back(left[i]);
            i++;
        }else{
            result.push_back(right[j]);
            j++;
        }
    }
    while(i < left.size()){
        result.push_back(left[i]);
        i++;
    }
    while(j < right.size()){
        result.push_back(right[j]);
        j++;
    }
    return result;
}

vector<int> mergesort(int left, int right){
    // Split the array until single elements, then merge back up.
    if(left >= right){
        return {arr[left]}; // or arr[right] as it would be...
    }
    if(left < right){
        int mid = (left + right) / 2;
        // Example: for indices 0..5, mid = 2 -> split into 0..2 and 3..5
        vector<int> L = mergesort(left, mid);
        vector<int> R = mergesort(mid + 1, right);
        return merge(L, R);
    }
    return {};
}

int main(){
    int n; cout << "Enter the size of array: " << endl;
    cin >> n; arr.resize(n);
    // Example input: 38 27 43 3 9 82 10
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    // mergesort returns a new sorted vector
    vector<int> output = mergesort(0, n - 1);
    bool first = true;
    for(int it : output){
        if(!first) cout << ", ";
        cout << it;
        first = false;
    }
    return 0;
}
