#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> LPS(const string& P){
    int m = P.size();
    vector<int> lps(m, 0);
    int len = 0, i = 1;
    while(i < m){
        if(P[i] == P[len]){
            len++;
            lps[i] = len;
            i++;
        }else{
            if(len != 0){
                len = lps[len - 1];
            }else{
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

vector<int> search(const string& L, const string& P){
    int n = L.size(), m = P.size();

    vector<int> result;

    if(m == 0 || m > n){
        return result;
    }
    vector<int> lps = LPS(P);
    int i = 0, j = 0;
    while(i < n){
        if(L[i] == P[j]){
            i++; j++;
        }

        if(j == m){
            result.push_back(i - m);
            j = lps[j - 1];
        }else if(i < n && L[i] != P[j]){
            if(j != 0){
                j = lps[j - 1];
            }else{
                i++;
            }
        }
    }
    return result;
}

int main(){
    string line, pattern;
    getline(cin, line); getline(cin, pattern);
    
    vector<int>matches = search(line, pattern);
    if(matches.empty()){
        cout << "No matches found..." << endl;
    }else{
        cout << "Matches found at indices: ";
        bool first = true;
        for(int index : matches){
            if(first == false){
                cout << ", ";
            }
            cout << index;
            first = false;
        }
    }
    return 0;
}