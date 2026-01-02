#include <bits/stdc++.h>
using namespace std;

// Naive pattern matching: check for pattern at every possible shift
// Time complexity: O(n*m) where n = text length, m = pattern length

vector<int> naive_search(const string &text, const string &pattern) {
    vector<int> matches;
    int n = (int)text.size();
    int m = (int)pattern.size();
    if (m == 0) return matches;

    for (int i = 0; i + m <= n; ++i) {
        int j = 0;
        for (; j < m; ++j) {
            if (text[i + j] != pattern[j]) break;
        }
        if (j == m) matches.push_back(i); // pattern found at shift i
    }
    return matches;
}

int main(int argc, char **argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string text, pattern;

    // Accept input either as command-line args or from stdin.
    // Usage (CLI): NPM.exe "abracadabra" "abra"
    if (argc >= 3) {
        text = argv[1];
        pattern = argv[2];
    } else {
        if (!(cin >> text >> pattern)) {
            cerr << "Usage: provide text and pattern either as args or stdin\n";
            return 1;
        }
    }

    auto matches = naive_search(text, pattern);
    if (matches.empty()) {
        cout << "No match\n";
        return 0;
    }

    // Print all starting indices where pattern occurs in text
    cout << "Matches at indices:";
    for (int idx : matches) cout << ' ' << idx;
    cout << '\n';
    return 0;
}