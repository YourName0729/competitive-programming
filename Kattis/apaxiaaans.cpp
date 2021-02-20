//
// https://open.kattis.com/problems/apaxiaaans
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
    cin >> s;

    char prev = ' ';
    for (int i = 0; i < s.length(); i++) {
        if (s[i] != prev || i == 0) {
            cout << s[i];
            prev = s[i];
        }
    }
    cout << '\n';

    return 0;
}
