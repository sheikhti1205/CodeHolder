#include <iostream>
#include <algorithm> 
#include <vector>
using namespace std;
int main(){
    int s, n;
    cin >> s >> n;
    vector<int> x(n), y(n), temp(n);
    for(int i = 0; i < n; i++){
        cin >> x[i] >> y[i];
        temp[i] = x[i];
    }
    sort(temp.begin(), temp.end());
    for(int i = 0; i < n; i++){
        if(s <= temp[i]){
            cout << "NO" << endl;
            return 0;
        }else{
            for(int j = 0; j < n; j++){
                if(x[j] == temp[i]){
                    s += y[j];
                    break;
                }
            }
        }
    }
    
}