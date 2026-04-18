#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int arr[4];
    int count = 0;
    cin >> arr[0] >> arr[1] >> arr[2] >> arr[3];
    for(int i=0; i<4; i++){
        for(int j=i+1; j<4; j++){
            if(arr[i] == arr[j]){
                    count++;
                    break;
            }
        }
    } cout << count << endl;
    return 0;
}