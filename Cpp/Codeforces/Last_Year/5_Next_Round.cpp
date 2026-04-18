#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int n, k, s, place;
    vector<int> score;
    cin >> n >> k;
    for(int i=0; i<n; i++){
        cin >> s;
        score.push_back(s);
    }
    place = score[k-1];
    s = 0;
    for(int i=0; i<n; i++){
        if(score[i] >= place && score[i]>0){
            s++;
        }
    }
    cout << s << endl;

    return 0;
}