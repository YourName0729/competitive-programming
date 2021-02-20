//
// https://open.kattis.com/problems/sevenwonders
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
    
    int a[3] = {0};
    string s;

    cin >> s;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'T') {
            a[0]++;
        } else if (s[i] == 'C') {
            a[1]++;
        } else {
            a[2]++;
        }
    }

    //cout << a[0] << ' ' << a[1] << ' ' << a[2] << '\n';
    int ans = a[0] * a[0] + a[1] * a[1] + a[2] * a[2] + min(a[0], min(a[1], a[2])) * 7;
    cout << ans << '\n';

    return 0;
}
