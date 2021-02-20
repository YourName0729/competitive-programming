//
// https://open.kattis.com/problems/judgingmoose
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
    int a, b;
    cin >> a >> b;

    if (a == b && a == 0) {
        cout << "Not a moose\n";
    } else if (a == b) {
        cout << "Even " << max(a, b) * 2 << '\n';
    } else {
        cout << "Odd " << max(a, b) * 2 << '\n';
    }

    return 0;
}
