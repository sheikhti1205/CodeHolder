#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    int s, n, x, y; cin >> s >> n;
    vector<pair<int, int>> dragons(n);
/*
    for(int i=0; i<n; i++){
    cin >> x >> y;
    dragons.push_back(make_pair(x, y));
    }
*/
    for(int i=0; i<n; i++){
        cin >> x >> y;
        dragons.push_back({x, y});
    }
    sort(dragons.begin(), dragons.end());
    for(auto it : dragons){
        if(it.first >= s){
            cout << "NO" << endl;
            return 0;
        }else{
            s += it.second;
        }
    }
    cout << "YES" << endl;
    return 0;
}