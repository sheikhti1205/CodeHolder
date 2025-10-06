#include <iostream>
using namespace std;
int main(){
    int a, b, c, d, largest;
    cin >> a >> b >> c >> d;
    largest = a;
    if(b > a && b > c && b > d){
        cout << b - a << " " << b - c << " " << b - d << endl;
    }else if(c > a && c > d && c > b){
        cout << c - a << " " << c - b << " " << c - d << endl;
    }else if(d > a && d > c && d > b){
        cout << d - a << " " << d - c << " " << d - b << endl;
    }else{
        cout << a - b << " " << a - c << " " << a - d << endl;
    }
    return 0;
}