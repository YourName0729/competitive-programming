//
// https://open.kattis.com/problems/alphabetspam
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

    int a[4] = {0};
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '_') {
            a[0]++;
        } else if ('a' <= s[i] && s[i] <= 'z') {
            a[1]++;
        } else if ('A' <= s[i] && s[i] <= 'Z') {
            a[2]++;
        } else {
            a[3]++;
        }
    }

    for (int i = 0; i < 4; i++) {
        cout << fixed << double(a[i])/s.length() << '\n';
    }

    return 0;
}
