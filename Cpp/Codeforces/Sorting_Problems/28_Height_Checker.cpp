#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> temp = heights;
        int count = 0;
        sort(temp.begin(), temp.end());
        for(int i=0; i<heights.size(); i++){
            if(temp[i] != heights[i]){
                count++;
            }
        }
        return count;
    }
};

int main(){
    int n; cin >> n;
    vector<int> heights(n);
    for(int i=0; i<n; i++){
        cin >> heights[i];
    }
    Solution obj;
    cout << obj.heightChecker(heights) << endl;
    return 0;
}