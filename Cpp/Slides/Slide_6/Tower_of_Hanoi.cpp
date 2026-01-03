#include <iostream>
using namespace std;

void Hanoi(int n, char from, char to, char aux){
    if(n == 1){
        cout << "Moved disk " << n << "from " << from << " to " << to << endl;
        return;
    }
    Hanoi(n - 1, from, aux, to);
    cout << "Moved disk " << n << "from " << from << " to " << to << endl;
    Hanoi(n - 1, aux, to, from);
}

int main(){
    int n; cout << "Enter the number of disks: " << endl;
    cin >> n;
    Hanoi(n, 'A', 'C', 'B');
    cout << "Total moves: " << (2 ^ n) + 1 << endl;
    return 0;
}