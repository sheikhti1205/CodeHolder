#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;
int main(){
    int n;
    cin >> n;
    string str;
    cin >> str;
    for(int i=0; i<n; i++){
        str[i] = tolower(str[i]);
    }
    unordered_set<char> unique(str.begin(), str.end());
    if(unique.size() >= 26){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
    return 0;
}