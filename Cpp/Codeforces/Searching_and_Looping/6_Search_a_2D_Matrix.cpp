#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size(),
            cols = matrix[0].size();
        int lb = 0, ub = (rows * cols) - 1;
        while(lb <= ub){
            int mid = lb + ((ub -lb) / 2);
            int r = mid / cols,
                c = mid % cols;
            int val = matrix[r][c];
            if(val == target){
                return true;
            }else if(val < target){
                lb = mid + 1;
            }else{
                ub = mid - 1;
            }
        }
        return false;
    }
};

int main(){
    vector<vector<int>> matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    int target = 3;
    Solution obj;
    cout << obj.searchMatrix(matrix, target) << endl;
    return 0;
}