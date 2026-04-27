#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int lb = 0, ub = arr.size() - 1;
        while(lb < ub){
            int mid = lb + ((ub - lb) / 2);
            if(arr[mid] < arr[mid + 1]){
                lb = mid + 1;
            }else{
                ub = mid;
            }
        }
        return lb; // lb and ub same here
    }
};

int main(){
    vector<int> arr = {1, 3, 5, 7, 6, 4, 2};
    Solution obj;
    cout << obj.peakIndexInMountainArray(arr) << endl;
    return 0;
}