//
// https://open.kattis.com/problems/everywhere
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
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            m[s] = true;
        }

        cout << m.size() << '\n';
        m.clear();
    }

    return 0;
}
