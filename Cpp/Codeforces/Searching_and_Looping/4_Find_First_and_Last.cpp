#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = FindLeft(nums, target);
        int last = FindRight(nums, target);
        return {first, last};
    }
    int FindLeft(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1, ans = -1;
        while(left <= right){
            int mid = (left + right) / 2;
            if(nums[mid] == target){
                ans = mid;
                right = mid - 1;
            }else if(nums[mid] > target){
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }
        return ans;
    }
    int FindRight(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1, ans = -1;
        while(left <= right){
            int mid = (left + right) / 2;
            if(nums[mid] == target){
                ans = mid;
                left = mid + 1;
            }else if(nums[mid] > target){
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }
        return ans;
    }
};

int main(){
    vector<int> nums = {5,7,7,8,8,10};
    int target; cin >> target;
    Solution obj;
    vector<int> ans = obj.searchRange(nums, target);
    cout << '[' << ans[0] << ", " << ans[1] << ']' << endl;
    return 0; 
}