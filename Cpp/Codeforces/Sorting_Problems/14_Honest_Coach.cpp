#include <iostream>
#include <vector>
using namespace std;
int main(){
    int t, n; cin >> t;
    while(t--){
        cin >> n;
        vector<int> s(n);
        for(int i = 0; i < n; i++){
            cin >> s[i];
        }
        for(int i = 1; i < n; i++){
            int temp = s[i], j = i - 1;
            while(j >= 0 && s[j] > temp){
                s[j+1] = s[j];
                j--;
            }
            s[j+1] = temp;
        }
        int min = s[1] - s[0];
        for(int i = 2; i < n; i++){
            if(min > (s[i] - s[i - 1])){
                min = s[i] - s[i - 1];
            }
        }
        cout << min << endl;
    }
    return 0;
}