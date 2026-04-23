#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int lb = 0, ub = n - 1;
        while(lb <= ub){
            int mid = (lb + ub) / 2;
            if(nums[mid] == target){
                //cout << mid << endl;
                return mid;
            }
            if(target < nums[mid]){
                ub = mid - 1;
            }else{
                lb = mid + 1;
            }
        }
        return -1;
    }
};

int main(){
    vector<int> nums = {-1,0,3,5,9,12};
    int target; cin >> target;
    Solution obj;
    cout << obj.search(nums, target) << endl;
    return 0;
}