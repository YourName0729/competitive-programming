//
// https://open.kattis.com/problems/deathknight
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

bool ok(string& s) {
    for (int i = 0; i < s.length() - 1; i++) {
        if (s[i] == 'C' && s[i + 1] == 'D') return false;
    }
    return true;
}

int main() {
    
    int n, ans = 0;
    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        if (ok(s)) {
            ans++;
        }
    }
    cout << ans << '\n';

    return 0;
}