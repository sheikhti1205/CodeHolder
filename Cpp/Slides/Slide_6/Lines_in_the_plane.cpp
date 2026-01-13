#include <iostream>
using namespace std;

int div(int n){
    // Maximum regions formed by n lines: R(n) = R(n-1) + n, with R(0) = 1.
    // Example: n=3 -> 1 + 1 + 2 + 3 = 7 regions.
    if(n == 0) return 1;
    int count = div(n - 1) + n;
    return count;
}

int main(){
    int n; cout << "Enter n: " << endl;
    cin >> n;
    // Prints the number of regions after adding n straight lines.
    cout << "Divided regions: " << div(n) << endl;
    return 0;
}
