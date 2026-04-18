#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;
int main()
{
    string str1, str2, line;
    char a;
    int size1 = 0, size2 = 0;
    cin >> line;
    for (int i = 0; i < line.size(); i++)
    {
        a = line[i];
        a = tolower(a);
        str1 += a;
    }
    cin >> line;
    for (int i = 0; i < line.size(); i++)
    {
        a = line[i];
        a = tolower(a);
        str2 += a;
    }
    while (!str1.empty() || !str2.empty())
    {
        int sizes = (str1 > str2) ? str1.size() : str2.size();
        for (int i = 0; i < sizes; i++)
        {
            if (str1[i] > str2[i])
            {
                cout << "1" << endl;
                return 0;
            }
            else if (str1[i] < str2[i])
            {
                cout << "-1" << endl;
                return 0;
            }
        }
        if (str1.size() == str2.size())
        {
            cout << "0" << endl;
            return 0;
        }
    }
    return 0;
}