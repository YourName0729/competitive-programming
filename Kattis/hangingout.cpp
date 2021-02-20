//
// https://open.kattis.com/problems/hangingout
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
    
    int l, n;
    int amt = 0, ans = 0;

    cin >> l >> n;
    while (n--) {
        string s;
        int d;
        cin >> s >> d;
        if (s == "enter") {
            if (amt + d > l) {
                ans++;
            } else {
                amt += d;
            }
        } else {
            amt -= d;
        }
    }

    cout << ans << '\n';

    return 0;
}
