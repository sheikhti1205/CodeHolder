#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    char findTheDifference(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        for(int i=0; i<t.size(); i++){
            if(s[i] != t[i]){
                return t[i];
            }
        }
        return t[t.size()-1];
    }
};

int main(){
    string s, t; cin >> s >> t;
    Solution obj;
    cout << obj.findTheDifference(s, t) << endl;
    return 0;
}