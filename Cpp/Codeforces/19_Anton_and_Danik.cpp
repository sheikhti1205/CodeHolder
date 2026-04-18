#include <iostream>
using namespace std;
int main(){
    int n, A = 0, D = 0;
    string str;
    cin >> n >> str;
    for(char ch : str){
        if(ch == 'A'){
            A++;
        }
        if(ch == 'D'){
            D++;
        }
    }
    cout << ((A == D) ? "Friendship" : ((A > D) ? "Anton" : "Danik")) << endl;

    return 0;
}