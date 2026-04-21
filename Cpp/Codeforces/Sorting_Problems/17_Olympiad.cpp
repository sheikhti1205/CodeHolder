#include <iostream>
#include <set>
using namespace std;
int main(){
    int n; cin >> n;
    int val;
    set<int> a;
    for(int i = 0; i < n; i++){
        cin >> val;
        if(val > 0){
            a.insert(val);
        }
    }
    cout << a.size() << endl;
    return 0;
}