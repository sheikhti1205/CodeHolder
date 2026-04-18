#include <iostream>
using namespace std;
int main(){
    int y = 0;
    string n;
    cin >> n;
    for(char ch : n){
        if(ch == '4' || ch == '7'){
            y++;
        }
    }
    cout << ((y == 4 || y == 7) ? "YES" : "NO") << endl;
}