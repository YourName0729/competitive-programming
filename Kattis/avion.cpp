//
// https://open.kattis.com/problems/avion
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

bool has(string& s, string& tar) {
    for (int i = 0; i < s.length() - tar.length() + 1; i++) {
        bool re = true;
        for (int j = 0; j < tar.length(); j++) {
            if (s[i + j] != tar[j]) {
                re = false;
            }
        }
        if (re) return true;
    }
    return false;
}

int main() {
    string s[5];
    for (int i = 0; i < 5; i++) {
        cin >> s[i];
    }

    vector<int> ans;
    string tar = "FBI";
    for (int i = 0; i < 5; i++) {
        if (has(s[i], tar)) {
            ans.push_back(i + 1);
        }
    }

    if (ans.empty()) {
        cout << "HE GOT AWAY!\n";
    } else {
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << ' ';
        }
        cout << '\n';
    }

    return 0;
}
