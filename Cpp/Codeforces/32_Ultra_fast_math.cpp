#include <iostream>
using namespace std;
int main(){
    string str1, str2;
    cin >> str1 >> str2;
    for(int i=0; i<str1.size(); i++){
        if(str1[i] != str2[i]){
            cout << "1";
        }else{
            cout << "0";
        }
    } cout << endl;
    return 0;
}