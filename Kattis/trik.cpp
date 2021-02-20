//
// https://open.kattis.com/problems/trik
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
    bool b[] = {true, false, false};

    cin >> s;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'A') {
            swap(b[0], b[1]);
        } else if (s[i] == 'B') {
            swap(b[1], b[2]);
        } else {
            swap(b[0], b[2]);
        }
    }

    for (int i = 0; i < 3; i++) {
        if (b[i]) {
            cout << i + 1 << '\n';
        }
    }

    return 0;
}
