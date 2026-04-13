#include <iostream>

using namespace std;

int main(){

//  97 - 122

// t - number of test case, 
// n - size of string,
// s - string,
// a = 0

    int t, n, a = 0; string s;
    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> n;
        cin >> s;
        for(char ch : s){
            if(int(ch) > a){
                a = ch;
            }
        }
        // cout << a - 96 << endl; 
        cout << a - 'a' + 1 << endl;
        a = 0;
    }
    return 0;
}

/* Example Input
5 - test case
1 - size of string
a - string input
4 - next size of string
down - string input
10 - next...
codeforces - ...
3 - ...
bcf - ...
5 - ...
zzzzz - ...
*/
