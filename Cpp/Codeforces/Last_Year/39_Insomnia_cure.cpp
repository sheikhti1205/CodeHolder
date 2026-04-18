#include <iostream>
#include <set>
using namespace std;
int main(){
    int k, l, m, n, d;
    cin >> k >> l >> m >> n >> d;
    set<int>count;
    //int count = 0;
    for(int i=1; i<=d; i++){
        if(i % k == 0){
            count.insert(i);
        }
        if(i % l == 0){
            count.insert(i);
        }
        if(i % m == 0){
            count.insert(i);
        }
        if(i % n == 0){
            count.insert(i);
        }
    }
    cout << count.size() << endl;
    return 0;
}