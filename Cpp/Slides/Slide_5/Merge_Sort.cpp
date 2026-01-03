#include <iostream>
#include <vector>
using namespace std;

vector<int> arr;

vector<int> merge(vector<int> left, vector<int> right){
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
    if(left >= right){
        return {arr[left]}; // or arr[right] as it would be...
    }
    if(left < right){
        int mid = (left + right) / 2;
        vector<int> L = mergesort(left, mid);
        vector<int> R = mergesort(mid + 1, right);
        return merge(L, R);
    }
    return {};
}

int main(){
    int n; cout << "Enter the size of array: " << endl;
    cin >> n; arr.resize(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    vector<int> output = mergesort(0, n - 1);
    bool first = true;
    for(int it : output){
        if(!first) cout << ", ";
        cout << it;
        first = false;
    }
    return 0;
}