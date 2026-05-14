#include <iostream>
using namespace std;
int main(){
    int n, ax, ay, bx, by, cx, cy;
    cin >> n >> ax >> ay >> bx >> by >> cx >> cy;
    if((bx < ax && cx < ax || bx > ax && cx > ax) && (by < ay && cy < ay || by > ay && cy > ay)){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
    return 0;
}