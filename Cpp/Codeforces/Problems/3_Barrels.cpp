#include <iostream>
#include <algorithm>
using namespace std;
/*
So, for this one. First of 't' is the number of tests.
then we take n number of barrel ( and how much water they hold)
then we sort them

so for example input is (5, 6, 7, 9) it becomes (9, 7, 6, 5)
since we need maximum litre and minimal water we do this sort
then just add things from the array based on k which is the number of attemts we can do. or basically the number of times we can do the adding part.
*/
int main(){
    int t, n, k;
    cin >> t;
    while(t--){
        cin >> n >> k;
        int arr[n];
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }
        // sort(arr, arr + n, greater<int>());
        int temp;
        for(int i = 1; i < n; i++){
        // Treat arr[0..i-1] as a sorted hand; 
        // insert arr[i] into its correct position.
            temp = arr[i];
            int j = i - 1;
            while(j >= 0 && arr[j] < temp){
                // Shift smaller elements right to make space for temp.
                arr[j + 1] = arr[j];
                j--;
            }
            // Place temp into the "hole" created by shifting.
            arr[j + 1] = temp;
        }
        long long int sum = arr[0];
        for(int j = 1; j <= k; j++){
            sum += arr[j];
        }
        cout << sum << endl;
    }
    return 0;
}