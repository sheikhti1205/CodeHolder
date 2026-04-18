#include <iostream>
using namespace std;
int main(){
    int n, maximum = 0, max_pos, minimum = 101, min_pos, count = 0;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
        if(arr[i] > maximum){
            maximum = arr[i];
            max_pos = i;
        }
        if(arr[i] <= minimum){
            minimum = arr[i];
            min_pos = i;
        }
    }
    if(max_pos > min_pos){
        cout << max_pos+((n-2)-min_pos) << endl;
    }else{
        cout << max_pos+((n-1)-min_pos) << endl;
    }
    return 0;
}