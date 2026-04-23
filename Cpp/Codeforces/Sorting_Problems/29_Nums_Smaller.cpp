#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> temp = nums, ans(nums.size());
        sort(temp.begin(), temp.end());
        for(int i=0; i<nums.size(); i++){
            for(int j=0; j<nums.size(); j++){
                if(nums[i] == temp[j]){
                    ans[i] = j;
                    break;
                }
            }
        }
        return ans;
    }
};

int main(){
    int n; cin >> n;
    vector<int> nums(n);
    for(int i=0; i<n; i++){
        cin >> nums[i];
    }
    Solution obj;
    vector<int> ans =  obj.smallerNumbersThanCurrent(nums);
    bool first = true;
    for(int i=0; i<ans.size(); i++){
        if(!first){
            cout << ", ";
        }
        cout << ans[i];
        first = false;
    }
    cout << endl;
    return 0;
}