//
// https://open.kattis.com/problems/conundrum
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
    int ans = 0;
    cin >> s;
    char c[] = {'P', 'E', 'R'};

    for (int i = 0; i < s.length(); i++) {
        if (s[i] != c[i % 3]) {
            ans++;
        }
    }
    cout << ans << '\n';

    return 0;
}
