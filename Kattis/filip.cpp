//
// https://open.kattis.com/problems/filip
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

int rev(int d) {
    int re = 0;
    while (d) {
        re *= 10;
        re += d % 10;
        d /= 10;
    }
    return re;
}

int main() {
    int a, b;
    cin >> a >> b;
    cout << max(rev(a), rev(b)) << '\n';


    return 0;
}
