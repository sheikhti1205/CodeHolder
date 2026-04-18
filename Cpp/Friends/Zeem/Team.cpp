#include<iostream>
using namespace std;
int main(){
    int n,count=0,sum=0;
    cin >> n;
    int arr[3];
    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++){
            cin >> arr[j];
            sum += arr[j];
        }
        if(sum>=2){
        count++;
        } sum = 0;
    }
    cout << count;
    return 0;
}