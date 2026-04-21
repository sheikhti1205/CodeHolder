#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

/*
Input
The input file consists of three lines: the first line contains the guest's name, 
the second line contains the name of the residence host and the third line contains letters in a pile that were found at the door in the morning. 
All lines are not empty and contain only uppercase Latin letters. The length of each line does not exceed 100.

Output
Print "YES" without the quotes, if the letters in the pile could be permuted to make the names of the "New Year and Christmas Men". 
Otherwise, print "NO" without the quotes.
*/

int main(){
    string host, guest, str;
    cin >> host >> guest >> str;
    if(host.size() + guest.size() != str.size()){
        cout << "NO" << endl;
        return 0;
    }
    
    string combined = host + guest;

    sort(combined.begin(), combined.end());
    sort(str.begin(), str.end());

    if(combined != str){
        cout << "NO" << endl;
    }else{
        cout << "YES" << endl;
    }
    return 0;
}