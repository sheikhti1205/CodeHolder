#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int n, j;
    cin >> n >> j;
    string str;
    cin >> str;
    while(j--){
        for(int i=0; i<n; i++){
            if(i!=0){
                if(str[i] == 'G' && str[i-1] == 'B'){
                    swap(str[i], str[i-1]);
                    i++;
                }
            }
        }
    } cout << str << endl;
    return 0;
}