#include <iostream>
using namespace std;
int main(){
    int t, count = 0; cin >> t;
    char c;
    string str = "codeforces";
    while(t--){
        count = 0;
        cin >> c;
        for(int i=0; i<str.size(); i++){
            if(c == str[i]){
                cout << "YES" << endl;
                count = 1;
                break;
            }
        }if(count == 0){
            cout << "NO" << endl;
        }
    }
    return 0;
}