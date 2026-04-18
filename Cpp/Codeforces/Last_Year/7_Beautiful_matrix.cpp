#include <iostream>
using namespace std;

int main(){
    int mat[5][5], a, a1, a2;
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++)
        {
            cin >> a;
            if(a == 1){
                a1 = i; a2 = j;
            }
            mat[i][j] = a;
        }
    } int count = 0;
    while(a1 != 2 || a2 != 2){
        if(a1>2){
            count++;
            a1--;
        }else if(a1<2){
            count++;
            a1++;
        }
        if(a2>2){
            count++;
            a2--;
        }else if(a2<2){
            count++;
            a2++;
        }
    } cout << count << endl;
    return 0;
}