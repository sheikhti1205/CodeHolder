#include<iostream>
#include<cctype>
#include<string>
#include<algorithm>
using namespace std;
int main(){
    int n;
    string str1,str2;
    cin >> str1;
    cin >> str2;
    transform(str1.begin(),str1.end(),str1.begin(),::tolower);
    transform(str2.begin(),str2.end(),str2.begin(),::tolower);
    int sizes = (str1 > str2) ? str1.size() : str2.size();
        for (int i = 0; i < sizes; i++){
            if (str1[i] > str2[i]){
                cout << "1" << endl;
                return 0;
            }
            else if (str1[i] < str2[i]){
                cout << "-1" << endl;
                return 0;
            }
        }
        if (str1.size() == str2.size()) {
            cout << "0" << endl;
            return 0;
        }
    return 0;
}