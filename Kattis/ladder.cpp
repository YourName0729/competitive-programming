//
// https://open.kattis.com/problems/ladder
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

int rnd(double d) {
    if (int(d) == d)    return int(d);
    return int(d) + 1;
}

int main() {
    double h, v;
    cin >> h >> v;
    cout << ceil(h / sin(v * 3.1415926 / 180)) << '\n';

    return 0;
}
