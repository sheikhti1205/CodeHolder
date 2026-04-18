#include <iostream>
using namespace std;
int main(){
    int n, k, l, c, d, p, nl, np;
// n - people
// k - bottle
// l - mililitre
// c - lime
// d - slice
// p - salt
// each needs - nl water
//            - slice of lime
//            - np salt
// Everyone drinks equal amount
    cin >> n >> k >> l >> c >> d >> p >> nl >> np;
// Total drink = n * l
    int x = (k * l) / nl, y = (d * c), z = p / np;
//  cout << x << y << z << endl;
    if(x <= y && x <= z){
        cout << x / n << endl;
    }else if(y <= x && y <= z){
        cout << y / n << endl;
    }else if(z <= y && z <= x){
        cout << z / n << endl;
    }
    return 0;
}