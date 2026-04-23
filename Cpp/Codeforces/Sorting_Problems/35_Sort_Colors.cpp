#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        for(int i=1; i<nums.size(); i++){
            int temp = nums[i], j = i - 1;
            while(j >= 0 && nums[j] > temp){
                nums[j+1] = nums[j];
                j--;
            }
            nums[j+1] = temp;
        }
        bool first = true;
        for(int i=0; i<nums.size(); i++){
            if(!first){
                cout << ", ";
            }
            cout << nums[i];
            first = false;
        }
        cout << endl;
    }
};

int main(){
    vector<int> nums = {2,0,2,1,1,0};
    Solution obj;
    obj.sortColors(nums);
    return 0;
}