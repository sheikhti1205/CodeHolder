#include <iostream>
#include <string>
using namespace std;
int main(){
    int t, n; cin >> t;
    while(t--){
        cin >> n;
        string s, copy; cin >> s;
        copy = s;
        for(int i = 1; i < n; i++){
            int temp = s[i], j = i - 1;
            while(j >= 0 && s[j] > temp){
                s[j + 1] = s[j];
                j--;
            }
            s[j + 1] = temp;
        }
        int count = 0;
        for(int i = 0; i < n; i++){
            if(s[i] != copy[i]){
                count++;
            }
        }
        cout << count << endl;
    }
    return 0;
}