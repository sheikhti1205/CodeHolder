#include <iostream>
using namespace std;
int main(){
    int t, n; cin >> t;
    while(t--){
        cin >> n;
        string str = "";
        int timesten = 1, count = 0;
        while(n > 0){
            int d = n % 10;
            if(d != 0){
                str += to_string(d * timesten) + " ";
                //cout << d * timesten << " ";
                count++;
            }
            timesten *= 10;
            n /= 10;
        } cout << count << endl << str << endl;
    }
}