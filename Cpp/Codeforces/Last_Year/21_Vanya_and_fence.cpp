#include <iostream>
using namespace std;
int main(){
    int n, h; // number of people, height of wall;
    cin >> n >> h;
    int people[n], width = n;
    for(int i=0; i<n; i++){
        cin >> people[i];
        if(people[i] > h){
            width++;
        }
    } cout << width << endl;
    return 0;
}