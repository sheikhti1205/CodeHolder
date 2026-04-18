#include <iostream>
using namespace std;
int main(){
    string str;
    cin >> str;
    char ch = str[0];
    ch = toupper(ch);
    str[0] = ch;
    cout << str << endl;
    return 0;
}