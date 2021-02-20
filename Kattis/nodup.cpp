//
// https://open.kattis.com/problems/nodup
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

map<string, bool> m;

int main() {
    bool ok = true;
    string s;
    while (cin >> s) {
        if (m[s]) {
            ok = false;
        }
        m[s] = true;
    }

    cout << (!ok? "no\n" : "yes\n");

    return 0;
}
