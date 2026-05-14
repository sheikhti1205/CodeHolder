#include <iostream>
#include <string>
using namespace std;

int main() {
    string text = "ABCDEFG";
    cout << "Length: " << text.length() << "\n";
    cout << "Substring: " << text.substr(2, 3) << "\n";
    cout << "Index of CD: " << text.find("CD") << "\n";

    string inserted = text;
    inserted.insert(3, "XYZ");
    cout << inserted << "\n";

    string deleted = text;
    deleted.erase(3, 2);
    cout << deleted << "\n";

    string replaced = text;
    size_t pos = replaced.find("CD");
    if (pos != string::npos) replaced.replace(pos, 2, "xx");
    cout << replaced << "\n";
    return 0;
}