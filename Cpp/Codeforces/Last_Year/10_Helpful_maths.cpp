#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    string str, sorted_numbers = "";
    cin >> str;
    sort(str.begin(), str.end());
    int sizes = (str.size()) / 2;
    bool first = true;
    for(int i=sizes; i<str.size(); i++){
        if(first == false){
            sorted_numbers += "+";
        }
        sorted_numbers += str[i];
        first = false;
    }
    cout << sorted_numbers;
    return 0;
}