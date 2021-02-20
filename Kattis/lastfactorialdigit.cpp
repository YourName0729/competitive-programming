//
// https://open.kattis.com/problems/lastfactorialdigit
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

int fac(int d) {
    if (d == 0) return 1;
    return d * fac(d - 1);
}

int main() {
    int n, d;
    cin >> n;
    while (n--) {
        cin >> d;
        cout << fac(d) % 10 << '\n';
    }


    return 0;
}
