#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lb = 0, ub = nums.size() - 1;
        while(lb <= ub){
            int mid = lb + (ub - lb) / 2;
            if(nums[mid] == target){
                return mid;
            }
            if(nums[lb] <= nums[mid]){
                if(nums[lb] <= target && target < nums[mid]){
                    ub = mid - 1;
                }else{
                    lb = mid + 1;
                }
            }else{
                if(nums[mid] < target && target <= nums[ub]){
                    lb = mid + 1;
                }else{
                    ub = mid - 1;
                }
            }
        }
        return -1;
    }
};

int main(){
    vector<int> nums = {4,5,6,7,0,1,2};
    int target; cin >> target;
    Solution obj;
    cout << obj.search(nums, target) << endl;
    return 0;
}