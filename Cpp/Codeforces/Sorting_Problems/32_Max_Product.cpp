#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int a = (nums[0] * nums[1] * nums[n-1]),
            b = (nums[n-1] * nums[n-2] * nums[n-3]);
        return max(a, b);
    }
};

int main(){
    vector<int> nums = {1,2,3,4};
    Solution obj;
    cout << obj.maximumProduct(nums) << endl;
    return 0;
}