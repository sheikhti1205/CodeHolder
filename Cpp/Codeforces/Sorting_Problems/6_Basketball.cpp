#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int n, d;
    cin >> n >> d;
    int p[n];
    for(int i = 0; i < n; i++){
        cin >> p[i];
    }
    sort(p, p + n, greater<int>());
    int count = 0, i = 0, j = 0;
    while(i < n){
        int num_p_need = d / p[j] + 1; // note that i = 0 thus we need an extra 1 to start the count
        if(i + num_p_need <= n){
            count++;
            i += num_p_need;
        }else{
            break;
        } j++;
    } cout << count << endl;
    return 0;
}