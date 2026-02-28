#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> LPS(const string& P){
    // Build the LPS (longest prefix which is also suffix) table for pattern P.
    // Example: P = "ABABC" -> LPS = [0,0,1,2,0]
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
    // Use LPS to skip comparisons when a mismatch happens.
    vector<int> lps = LPS(P);
    int i = 0, j = 0;
    while(i < n){
        if(L[i] == P[j]){
            i++; j++;
        }

        if(j == m){
            // Full match of pattern ends at i-1 -> start index is i-m.
            result.push_back(i - m);
            j = lps[j - 1];
    // Do NOTICE that L[i] != P[j] PART!!! -_-
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
    
    // Example input:
    // line = "ababcabcabababd"
    // pattern = "ababd"
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
