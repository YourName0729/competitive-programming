//
// https://open.kattis.com/problems/closingtheloop
#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <iomanip>
#include <sstream>
#include <vector>
#include <iomanip>

using namespace std;

int n;
vector<int> b, r;

int Sum(vector<int>::iterator begin, vector<int>::iterator end) {
    int re = 0;
    for (vector<int>::iterator it = begin; it != end; it++) {
        re += *it;
    }
    return re;
}

int main() {
    int T, len;
    char clr;
    cin >> T;
    for (int t = 1; t <= T; t++) {

        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> len >> clr;
            if (clr == 'B') {
                b.push_back(len);
            } else {
                r.push_back(len);
            }
        }

        sort(b.begin(), b.end());
        reverse(b.begin(), b.end());

        sort(r.begin(), r.end());
        reverse(r.begin(), r.end());

        if (b.size() > r.size()) {
            int ans = Sum(b.begin(), b.begin() + r.size()) + Sum(r.begin(), r.end()) - r.size() * 2;
            cout << "Case #" << t << ": " << ans << '\n';
        } else {
            int ans = Sum(b.begin(), b.end()) + Sum(r.begin(), r.begin() + b.size()) - b.size() * 2;
            cout << "Case #" << t << ": " << ans << '\n';
        }

        b.clear();
        r.clear();
    }

    return 0;
}
