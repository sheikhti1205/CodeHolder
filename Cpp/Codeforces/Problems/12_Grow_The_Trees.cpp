#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 1; i < n; i++){
        int j = i - 1, temp = a[i];
        while(j >= 0 && a[j] > temp){
            a[j + 1] = a[j];
            j--;
        } a[j + 1] = temp;
    }
    long long int Xi = 0, Yi = 0;
    int x = n/2;
    for(int i = 0; i < n; i++){
        if(i < x){
            Xi += a[i];
        }else{
            Yi += a[i];
        }
    }
    cout << ((Xi * Xi) + (Yi * Yi)) << endl;
    return 0;
}