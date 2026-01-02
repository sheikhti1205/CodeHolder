#include <bits/stdc++.h>
#include <string>
#define Max_size 10001
using namespace std;

// 1. Length
int stringLength(const string &s) {
    int count = 0;
    for(int i=0; s[i] !='\0';i++){
        count++;
    }
   return count;
}

// 2. Substring
char *substring(char s[Max_size],int initial, int len) {
   
}

// 3. Indexing (find pattern in text)
 int indexOf(const string &text, const string &pattern) {
    size_t pos = text.find(pattern);
    if (pos != string::npos) return (int)pos; // 0-based index
    return -1; // not found
} 

// 4. Concatenation
string concat(const string &s1, const string &s2) {
    return s1 + s2;
}

// 5. Insertion
string insertString(const string &s, int pos, const string &toInsert) {
    if (pos < 0 || pos > (int)s.length()) return s;
    string result = s;
    result.insert(pos, toInsert);
    return result;
}

// 6. Deletion
string deleteString(const string &s, int pos, int len) {
    if (pos < 0 || pos >= (int)s.length()) return s;
    string result = s;
    result.erase(pos, len);
    return result;
}

// 7. Replacement
string replaceString(const string &s, const string &pattern, const string &replacement) {
    size_t pos = s.find(pattern);
    if (pos != string::npos) {
        string result = s;
        result.replace(pos, pattern.length(), replacement);
        return result;
    }
    return s; // no change if pattern not found
}

int main() {

    char text[] = "HIS FATHER IS THE PROFESSOR";
    cout << "Substring (start=4, len=7): " << substring(text, 4, 7) << endl;
  /*  string text = "HIS FATHER IS THE PROFESSOR";

    // Length
    cout << "Length: " << stringLength(text) << endl;

    // Substring
    cout << "Substring (start=4, len=7): " << substring(text, 4, 7) << endl;

    // Indexing
    cout << "Index of 'THE': " << indexOf(text, "THE") << endl;

    // Concatenation
    cout << "Concatenation: " << concat("MARK", "TWIN") << endl;

    // Insertion
    cout << "Insertion: " << insertString("ABCDEF", 3, "XYZ") << endl;

    // Deletion
    cout << "Deletion: " << deleteString("ABCDEFG", 4, 2) << endl;

    // Replacement
    cout << "Replacement: " << replaceString("ABXYEFGH", "XY", "CD") << endl;
    
    return 0;
    */
}