#include <iostream>
#include <iomanip>
using namespace std;
int main(){
    int n;
    double percent = 0, x;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> x;
        percent += x;
    } cout << fixed << setprecision(10) << percent/n << endl;
    return 0;
}