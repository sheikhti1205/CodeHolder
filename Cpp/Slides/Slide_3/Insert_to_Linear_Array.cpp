#include <iostream>
#include <vector>
using namespace std;
int main(){
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << "Enter the element and position at which you want to insert it to: " << endl;
    int e, p; cin >> e >> p;
    arr.resize(arr.size() + 1);
    for(int i = arr.size() - 1; i > p; i--){
        arr[i] = arr[i - 1];
    }
    arr[p] = e; bool first = true;
    for(int i = 0; i < arr.size(); i++){
        if(first == false){
            cout << ", ";
        }
        cout << arr[i];
        first = false;
    }
    return 0;
}