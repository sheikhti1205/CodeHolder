#include <iostream>
using namespace std;
int main(){
    string str; cin >> str;
    for(int i=0; i<str.size(); i++){
        if(str[i] != '.'){
            if(str[i+1] == '-'){
                cout << 2;
                i++;
            }else{
                cout << 1;
                i++;
            }
        }else{
            cout << 0;
        }
    } cout << endl;
    return 0;
}