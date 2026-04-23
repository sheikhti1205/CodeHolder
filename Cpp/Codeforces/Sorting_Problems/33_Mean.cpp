#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
using namespace std;

class Solution {
public:
    double trimMean(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        int remain = n / 20;
        double sum = 0;
        for(int i=remain; i<n-remain; i++){
            sum += arr[i];
        }
        return sum / (n - (2 * remain));
    }
};

int main(){
    vector<int> arr = {6,2,7,5,1,2,0,3,10,2,5,0,5,5,0,8,7,6,8,0};
    Solution obj;
    cout << fixed << setprecision(10) << obj.trimMean(arr) << endl;
    return 0;
}