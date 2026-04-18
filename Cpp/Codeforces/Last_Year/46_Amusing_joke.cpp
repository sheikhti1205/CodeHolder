#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    string name1, name2, str, temp;
    cin >> name1 >> name2 >> str;
    temp = name1 + name2;
    bool pos = true;
    sort(str.begin(), str.end());
    sort(temp.begin(), temp.end());
    if(str.size() != temp.size()){
        cout << "NO" << endl;
        return 0;
    }
    for(int i=0; i<temp.size(); i++){
        if(str[i] != temp[i]){
            pos = false;
            break;
        }
    }
    if(pos == true){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
    // if(str.size() == (name1.size() + name2.size())){
    //     for(int i=0; i<str.size(); i++){
    //         for(int j=0; j<str.size(); j++){
    //             if(name1[i] == str[j]){
    //                 str.erase(j);
    //             }else if(name2[i] == str[j]){
    //                 str.erase(j);
    //             }
    //         }
    //     } if(str.size() == 0){
    //         cout << "YES" << endl;
    //     }else{
    //     cout << "NO" << endl;
    //     }
    // }else{
    //     cout << "NO" << endl;
    // }
    return 0;
}