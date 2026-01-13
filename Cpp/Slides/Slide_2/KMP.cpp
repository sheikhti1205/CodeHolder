#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> LPS(const string& P){
    // LPS table: lps[i] = length of longest proper prefix of P[0..i] that is also a suffix.
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

vector<int> KMPSearch(const string& L, const string &P){
    int n = L.size(), m = P.size();

    vector<int> result;

    if(m == 0 || m > n) return result;

    vector<int> lps = LPS(P);

    int i = 0, j = 0;

    while(i < n){
        if(L[i] == P[j]){
            i++; j++;
        }

        if(j == m){
            // Found a match; jump using LPS to continue searching for overlaps.
            result.push_back(i - m);
            j = lps[j - 1];
        }else if(i < n &&  L[i] != P[j]){
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
    // Example: line="aaaaa", pattern="aaa" -> matches at 0,1,2
    if(line.empty() || pattern.empty()){
        cout << "One or more input is empty" << endl;
    }else{
        vector<int> matches = KMPSearch(line, pattern);
        if(matches.empty()){
            cout << "No matches found" << endl;
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
    }
}
