#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int t; cin >> t;
    string str;
    while(t--){
        cin >> str;
        if(str.size() == 3){
            for(int i=0; i<str.size(); i++){
                str[i] = toupper(str[i]);
            }
            if(str == "YES"){
                cout << "YES" << endl;
            }else{
                cout << "NO" << endl;
            }
        }
    }
}