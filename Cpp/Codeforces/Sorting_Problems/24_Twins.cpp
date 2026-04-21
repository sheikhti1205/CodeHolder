#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n, sum = 0; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        sum += a[i];
    }
    sort(a.rbegin(), a.rend());
    int amount = 0, count = 0;
    for(int i = 0; i < n; i++){
        if(amount <= sum / 2){
            amount += a[i];
            count++;
        }else{
            break;
        }
    }
    cout << count << endl;
}