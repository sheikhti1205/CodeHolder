#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n, k, s = 0, d = 0; cin >> n;
    vector<int> data;
    for(int i=0; i<n; i++){
        cin >> k;
        data.push_back(k);
    }
    int left = 0, right = n-1;
    bool turn = 0;
    for(int i=0; i<n; i++){
        if(turn == 0){
            if(data[left] > data[right]){
                s += data[left];
                left++;
            }else{
                s += data[right];
                right--;
            }
            turn = 1;
        }else{
            if(data[left] > data[right]){
                d += data[left];
                left++;
            }else{
                d += data[right];
                right--;
            }
            turn = 0;
        }
        
    }
    cout << s << " " << d << endl;
    return 0;
}