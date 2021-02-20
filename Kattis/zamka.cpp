//
// https://open.kattis.com/problems/zamka
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

int sd(int d) {
    int re = 0;
    while (d) {
        re += d % 10;
        d /= 10;
    }
    return re;
}

int main() {
    
    int l, r, x;
    cin >> l >>  r >> x;

    for (int i = l; i <= r; i++) {
        if (sd(i) == x) {
            cout << i << '\n';
            break;
        }
    }
    for (int i = r; i >= l; i--) {
        if (sd(i) == x) {
            cout << i << '\n';
            break;
        }
    }



    return 0;
}
