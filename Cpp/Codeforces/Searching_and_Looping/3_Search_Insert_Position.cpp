#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        long long int lb = 0, ub = n - 1;
        long long int mid = (lb + ub) / 2;
        while(lb <= ub){
            mid = (lb + ub) / 2;
            if(nums[mid] == target){
                return mid;
            }
            if(nums[mid] < target){
                lb = mid + 1;
            }else{
                ub = mid - 1;
            }
        }
        return lb; 
    }
};

int main(){
    vector<int> nums = {1,3,5,6};
    int target; cin >> target;
    Solution obj;
    cout << obj.searchInsert(nums, target) << endl;
    return 0;
}