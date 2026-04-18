#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main(){
    string name, sorted = "";
    char a;
    cin >> name;
    sort(name.begin(), name.end());
    if(!name.empty()){
        sorted = name[0];
    }
    for(int i=1; i<name.size(); i++){
        if(name[i] != name[i-1]){
            sorted += name[i];
        }
    }
    cout << ((sorted.size() % 2 == 0) ? "CHAT WITH HER!" : "IGNORE HIM!") << endl;
    return 0;
}