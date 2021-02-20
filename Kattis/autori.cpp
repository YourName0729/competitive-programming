//
// https://open.kattis.com/problems/autori
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

int main() {
    string s;
    getline(cin, s);

    string ans;
    ans += s[0];
    for (int i = 0; i < s.length() - 1; i++) {
        if (s[i] == '-') {
            ans += s[i + 1];
        }
    }
    cout << ans << '\n';

    return 0;
}
