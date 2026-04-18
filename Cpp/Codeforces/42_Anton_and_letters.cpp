#include <iostream>
#include <set>
using namespace std;
int main(){
    string str;
    set<char>count;
    getline(cin, str);
    for(char& ch : str){
        if(ch != '{' && ch != '}' && ch != ',' && ch != ' '){
            count.insert(ch);
        }
    } cout << count.size() << endl;
    return 0;
}