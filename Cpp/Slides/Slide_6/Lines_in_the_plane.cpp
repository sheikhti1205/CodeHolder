#include <iostream>
using namespace std;

int div(int n){
    if(n == 0) return 1;
    int count = div(n - 1) + n;
    return count;
}

int main(){
    int n; cout << "Enter n: " << endl;
    cin >> n;
    cout << "Divided regions: " << div(n) << endl;
    return 0;
}