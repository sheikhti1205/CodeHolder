#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int t;
    cin >> t; // test case count
    while(t--){
        int n;
        long long x; // number of people & minimum money to be wealthy
// note that we're taking x as long since there's a need for it in the second for loop (not the first one :)
        cin >> n >> x;
        int arr[n];
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }
        sort(arr, arr + n, greater<int>());

        long long sum = 0;
        int ans = 0;

        for(int i = 0; i < n; i++){
            sum += arr[i];
            if(sum >= x * (i + 1)){ // we're starting from index 0 arr[0] in case you feel confused like me
                ans = i + 1;
            }else{
                break;
            } //below part unnecessary if we're doing line 9 long long int
            // if(sum >= 1LL * x * (i + 1)){ // 1LL basically means we're doing long long int work (mainly since overflow will occur)
            //     ans = i + 1;
            // }else{
            //     break;
            // }
        }
        cout << ans << endl;
    }
}