#include <iostream>
#include <vector>
using namespace std;

vector<int> person;

int Josephus(int k, int idx){
    // Recursive simulation: remove every k-th person in a circle.
    if(person.size() == 1){
        return person[0];
    }
    // Move k steps from current index (0-based), wrap around with modulo.
    idx = (k + idx) % person.size();
    person.erase(person.begin() + idx);
    return Josephus(k, idx);
}

int main(){
    int n, k; cout << "Enter the number of people and the kth person to be killed till the last person survives: " << endl;
    cin >> n >> k;
    // Example: n=7, k=2 -> survivor is 3 (using 0-based step here).
    for(int i = 1; i <= n; i++){
        person.push_back(i);
    }
    cout << Josephus(k, 0);
    return 0;
}
