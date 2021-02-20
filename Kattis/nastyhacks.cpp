//
// https://open.kattis.com/problems/nastyhacks
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
    int n, a, b, c;
    cin >> n;
    while (n--) {
        cin >> a >> b >> c;
        if (b > a + c) {
            cout << "advertise\n";
        } else if (b == a + c) {
            cout << "does not matter\n";
        } else {
            cout << "do not advertise\n";
        }
    }

    return 0;
}
