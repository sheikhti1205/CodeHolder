#include <iostream>
using namespace std;
int main(){
    int n, p, count = 0, temp;
    cin >> n;
    while(n--){
        cin >> p;
        if(p != temp){
            count++;
        }
        temp = p;
    } cout << count << endl;
    return 0;
}