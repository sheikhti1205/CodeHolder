#include <iostream>
#include <string>
using namespace std;
int main(){
    string line, pattern;
    cin >> line >> pattern; //if there's space use getline(cin, line); getline(cin, pattern);

    int n = line.size(), m = pattern.size(), j; //storing the size in variable makes it easier to comprehend ig...

    bool found = false; // this is for - if there's no match...

    if(m<=n && m!=0 && n!=0){   
        for(int i=0; i<=n-m; i++){ 
        // i <= n-m...take example ababababab (line, here size is 10), and ab (pattern, here size is 2), 
        // so there's matches at index 0, 2, 4, 6, 8 = total 5 matches
        // now take the total amount of times it actually runs...that's - for index 0, 1, 2, 3, 4, 5, 6, 7, 8 = 9 times
        // because naive approach iterates by one each step...it's naive and time consuming....
            j=0; // I declared j before...you can declare here too...
            while(j<m && line[i+j]==pattern[j]){ 
                // first check if j which will count the number of matches if is less than m
                // if it's equal (can't normally be greater) the while loop stops...
                // second condition is if line at i+j index is eqaul to pattern at j index. If it fails the while loop stops
                // you might need to think a bit here ig?
                j++;
            }
            if(j==m){
                cout << "Pattern matched at index: " << i << endl;
                found=1;
            }
        }
    }
        if(!found){
            cout << "No match...." << endl;
        }
    return 0;
}