#include <iostream>
#include <vector>
using namespace std;
int main(){
    int t, n; cin >> t;
    while(t--){
        cin >> n;
        vector<int> a(n);
        for(int i=0; i<n; i++){
            cin >> a[i];
        }
// doing insertion sort
        for(int i=1; i<n; i++){
            int temp = a[i];
            int j = i-1;
            while(j>=0 && a[j]>temp){
                a[j+1] = a[j];
                j--;
            }
            a[j+1] = temp;
        }
// start counting
        int count = 0;
        for(int i=0; i<n; i++){
            count += a[i] - a[0];
        }
        cout << count << endl;
    }
    return 0;
}