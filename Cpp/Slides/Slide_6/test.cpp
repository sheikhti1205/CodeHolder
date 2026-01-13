#include <iostream>
#include <bitset>
using namespace std;
int main(){
    int n;
    cin >> n;
    // Example: input 5 -> bitset<3> prints 101
    bitset<3> nb(n);
    cout << nb << endl;
}
