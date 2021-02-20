//
// https://open.kattis.com/problems/quadrant
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
    int x, y;
    cin >> x >> y;
    if (x > 0 && y > 0) {
        cout << "1\n";
    } else if (x > 0 && y < 0) {
        cout << "4\n";
    } else if (x < 0 && y > 0) {
        cout << "2\n";
    } else {
        cout << "3\n";
    }

    return 0;
}
