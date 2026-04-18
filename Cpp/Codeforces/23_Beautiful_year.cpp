#include <iostream>
#include <sstream>
using namespace std;
int main(){
    int year;
    cin >> year;
    while(1){
        bool confirm = true;
        year++;
        string str = to_string(year);
        for(int i=0; i<str.size(); i++){
            for(int j=0; j<str.size(); j++){
                if((i != j) && (str[i] == str[j])){
                    confirm = false;
                    break;
                }
            }
        } if(confirm == true){
            cout << year << endl;
            break;
        }
    }

    return 0;
}