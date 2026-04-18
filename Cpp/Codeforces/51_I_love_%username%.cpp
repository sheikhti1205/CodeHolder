#include <iostream>
using namespace std;
int main(){
    int n, i, max = 0, min = 9999999, count = 0;
    cin >> n;
    n -= 1;
    cin >> i;
    if(i > max){
        max = i;
    }
    if(i < min){
        min = i;
    }
    while(n--){
        cin >> i;
        if(i > max){
            max = i;
            count++;
        }if(i < min){
            min = i;
            count++;
        }
    } cout << count << endl;
    return 0;
}