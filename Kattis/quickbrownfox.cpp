//
// https://open.kattis.com/problems/quickbrownfox
#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <iomanip>
#include <sstream>
#include <vector>
#include <iomanip>
#include <map>

using namespace std;

bool has[26];

void parse(char c) {
    if ('a' <= c && c <= 'z')   has[c - 'a'] = true;
    if ('A' <= c && c <= 'Z')   has[c - 'A'] = true;
}

bool all() {
    for (int i = 0; i < 26; i++) {
        if (!has[i])    return false;
    }
    return true;
}

int main() {
    
    int t;
    cin >> t;
    getchar();
    while (t--) {
        string s;
        getline(cin, s);

        for (int i = 0; i < 26; i++) {
            has[i] = false;
        }

        for (int i = 0; i < s.length(); i++) {
            parse(s[i]);
        }

        if (all()) {
            cout << "pangram\n";
        } else {
            cout << "missing ";
            for (int i = 0; i < 26; i++) {
                if (!has[i]) {
                    cout << char(i + 'a');
                }
            }
            cout << '\n';
        }

    }

    return 0;
}
