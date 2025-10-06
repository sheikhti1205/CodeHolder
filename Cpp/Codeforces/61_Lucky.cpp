#include <iostream>
using namespace std;
int main(){
    int t, sum1, sum2; cin >> t;
    string str;
    while(t--){
        cin >> str;
        sum1 = (int) (str[0] + str[1] + str[2]);
        sum2 = (int) (str[str.size()-1] + str[str.size()-2] + str[str.size()-3]);
        if(sum1 == sum2){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
}