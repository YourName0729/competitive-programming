//
// https://open.kattis.com/problems/spavanac
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
    int m, s;
    cin >> m >> s;

    int all = m * 60 + s - 45 + 1440;
    all %= 1440;

    cout << all / 60 << ' ' << all % 60 << '\n';

    return 0;
}
