//
// https://open.kattis.com/problems/qaly
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
    int n;
    double ans = 0;
    double a, b;

    cin >> n;
    while (n--) {
        cin >> a >> b;
        ans += a * b;
    }
    cout << fixed << ans << '\n';

    return 0;
}
