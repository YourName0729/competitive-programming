//
// https://open.kattis.com/problems/differentdistances
#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <iomanip>
#include <sstream>

using namespace std;

int main() {
    
    string s;
    double x1, y1, x2, y2, p;
    while (getline(cin, s) && s != "0") {
        stringstream ss;
        ss << s;
        ss >> x1 >> y1 >> x2 >> y2 >> p;

        double dx = abs(x1 - x2);
        double dy = abs(y1 - y2);

        cout << fixed << pow(pow(dx, p) + pow(dy, p), 1 / p) << '\n';
    }

    return 0;
}
