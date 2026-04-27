#include <iostream>
using namespace std;

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

int bad = 4;  // suppose version 4 is the first bad one

bool isBadVersion(int version) {
    return version >= bad;
}

class Solution {
public:
    int firstBadVersion(int n) {
        long long left = 0, right = n-1;
        while(left <= right){
            long long mid = (left + right) / 2;
            if(isBadVersion(mid)){
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }
        return left;
    }
};

int main(){
    int n = 5;
    Solution obj;
    cout << obj.firstBadVersion(n) << endl;
    return 0;
}