//
// https://open.kattis.com/problems/maptiles2
#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <iomanip>
#include <sstream>
#include <vector>
#include <iomanip>

using namespace std;


struct Point {
    int x, y;
    Point(int a, int b) : x(a), y(b) {}
    Point() : x(0), y(0) {}

    int LenPow() const {
        return x * x + y * y;
    }
    double Len() const {
        return pow(LenPow(), 0.5);
    }

    friend Point operator*(int d, const Point& p) {
        return Point(d * p.x, d * p.y);
    }

    friend Point operator+(const Point& p1, const Point& p2) {
        return Point(p1.x + p2.x, p1.y + p2.y);
    }
    friend Point operator-(const Point& p1, const Point& p2) {
        return Point(p1.x - p2.x, p1.y - p2.y);
    }
    friend double Dis(const Point& p1, const Point& p2) {
        return (p1 - p2).Len();
    }
};

int Pow(int d) {
    if (d == 0) return 1;
    return 2 * Pow(d - 1);
}

string s;

Point go(int idx) {
    if (idx >= s.length())    return Point();

    int d = Pow(s.length() - idx - 1);
    if (s[idx] == '0') {
        return go(idx + 1);
    } else if (s[idx] == '1') {
        return go(idx + 1) + Point(d, 0);
    } else if (s[idx] == '2') {
        return go(idx + 1) + Point(0, d);
    } else {
        return go(idx + 1) + Point(d, d);
    }
}

int main() {
    cin >> s;
    cout << s.length() << ' ';

    Point ans = go(0);
    cout << ans.x << ' ' << ans.y << '\n';

    return 0;
}
