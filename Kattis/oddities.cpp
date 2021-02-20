//
// https://open.kattis.com/problems/oddities
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
    int n, d;
    cin >> n;
    while (n--) {
        cin >> d;
        if (d % 2 == 0) {
            cout << d << " is even\n";
        } else {
            cout << d << " is odd\n";
        }
    }

    return 0;
}
