#include <iostream>
using namespace std;
int main(){
    int k, r, count = 1; cin >> k >> r;
    while((((k * count) - r) % 10) != 0 && ((k * count) % 10) != 0){
        count++;
    } cout << count << endl;
    return 0;
}