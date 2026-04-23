#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int minDiff = INT_MAX;
        for(int i = 1; i < arr.size(); i++) {
            minDiff = min(minDiff, arr[i] - arr[i-1]);
        }
        vector<vector<int>> res;
        for(int i = 1; i < arr.size(); i++) {
            if(arr[i] - arr[i-1] == minDiff) {
                res.push_back({arr[i-1], arr[i]});
            }
        }
        return res;
    }
};

int main(){
    vector<int> arr = {3,8,-10,23,19,-4,-14,27};
    Solution obj;
    vector<vector<int>> ans = obj.minimumAbsDifference(arr);
    for(auto &pair : ans){
        cout << pair[0] << " " << pair[1] << endl;
    }
    return 0;
}