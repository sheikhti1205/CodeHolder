#include <iostream>
using namespace std;

void Hanoi(int n, char from, char to, char aux){
    // Move n disks from "from" peg to "to" peg using "aux" as temporary.
    if(n == 1){
        cout << "Moved disk " << n << "from " << from << " to " << to << endl;
        return;
    }
    // Step 1: move top n-1 disks to auxiliary peg.
    Hanoi(n - 1, from, aux, to);
    // Step 2: move largest disk to destination.
    cout << "Moved disk " << n << "from " << from << " to " << to << endl;
    // Step 3: move the n-1 disks from auxiliary to destination.
    Hanoi(n - 1, aux, to, from);
}

int main(){
    int n; cout << "Enter the number of disks: " << endl;
    cin >> n;
    // Example: n = 3 -> total moves should be 7 (2^3 - 1)
    Hanoi(n, 'A', 'C', 'B');
    // Intended formula: total moves = 2^n - 1 (note: ^ is XOR in C++).
    cout << "Total moves: " << (2 ^ n) + 1 << endl;
    return 0;
}
