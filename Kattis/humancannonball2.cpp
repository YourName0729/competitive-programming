//
// https://open.kattis.com/problems/humancannonball2
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
    cin >> n;
    while (n--) {
        double v, theta, x, h1, h2;
        cin >> v >> theta >> x >> h1 >> h2;

        double ang = theta * 3.14159265 / 180.0;
        double t = x / v / cos(ang);
        double y = v * t * sin(ang) - 0.5 * 9.81 * t * t;

        if (h1 + 1 <= y && y <= h2 - 1) {
            cout << "Safe\n";
        } else {
            cout << "Not Safe\n";
        }
    }

    return 0;
}
