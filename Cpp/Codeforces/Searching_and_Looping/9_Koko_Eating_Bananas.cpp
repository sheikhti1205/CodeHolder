#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = *max_element(piles.begin(), piles.end());

        while(low <= high){
            int mid = low + (high - low) / 2;

            long long hours = 0;
            for(int p : piles){
                hours += (p + mid - 1) / mid;
            }

            if(hours <= h){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }

        return low;
    }
};

int main(){
    vector<int> piles = {3,6,7,11};
    int h; cin >> h;
    Solution obj;
    cout << obj.minEatingSpeed(piles, h) << endl;
    return 0;
}