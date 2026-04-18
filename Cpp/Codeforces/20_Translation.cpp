#include <iostream>
using namespace std;
int main(){
    string str1, str2;
    int confirm = 1;
    cin >> str1 >> str2;
    if(str1.size() == str2.size()){
        for(int i=0; i<str1.size(); i++){
            if(str1[i] != str2[str2.size()-1-i]){
                confirm = 0;
                break;
            }
        }
    }else{
        confirm = 0;
    }
    cout << ((confirm == 0) ? "NO" : "YES") << endl;
    return 0;
}