#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
int main(){
    int n, count = 0, a;
    cin >> n;
    set<int> x;
    int p, q;
    cin >> p;
    for(int i=0; i<p; i++){
        cin >> a;
        x.insert(a);
    }
    cin >> q;
    for(int i=0; i<q; i++){
        cin >> a;
        x.insert(a);
    }
    if(x.size() != n){
        cout << "Oh, my keyboard!" << endl;
    }else{
        cout << "I become the guy." << endl;
    }
    return 0;
}