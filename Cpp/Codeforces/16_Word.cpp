#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    string str, copys;
    int counts = 0, countc = 0;
    cin >> str;
    copys = str;
    sort(copys.begin(), copys.end());
    for(char ch : copys){
        if(ch >= 97){
            counts++;
        }else{
            countc++;
        }
    }
    if(countc <= counts){
        for(char &ch : str){
            ch = tolower(ch);
        }
    }else{
        for(char &ch : str){
            ch = toupper(ch);
        }
    } cout << str << endl;

    return 0;
}