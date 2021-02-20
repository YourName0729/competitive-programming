//
// https://open.kattis.com/problems/unlockpattern
#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <iomanip>
#include <sstream>
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

int main() {
    
    Point arr[10];

    int in;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> in;
            arr[in] = Point(i, j);
        }
    }

    double sum = 0;
    for (int i = 1; i < 9; i++) {
        sum += Dis(arr[i], arr[i + 1]);
    }
    cout << fixed << sum << '\n';
    

    return 0;
}
