#include <iostream>
using namespace std;
int main(){
    int n, count = 0; string str;
    cin >> n;
    while(n--){
        cin >> str;
        if(str == "Tetrahedron"){
            count += 4;
        }
        if(str == "Cube"){
            count += 6;
        }
        if(str == "Octahedron"){
            count += 8;
        }
        if(str == "Dodecahedron"){
            count += 12;
        }
        if(str == "Icosahedron"){
            count += 20;
        }
    } cout << count << endl;
    return 0;
}