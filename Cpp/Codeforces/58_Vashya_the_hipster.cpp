#include <iostream>
using namespace std;
int main(){
    int a, b; cin >> a >> b;
    int countd = 0, counts = 0;
    countd = min(a, b);
    counts = (max(a, b) - countd) / 2;
    cout << countd << " " << counts << endl;
    return 0;
}