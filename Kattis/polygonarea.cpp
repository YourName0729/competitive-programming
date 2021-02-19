//
// https://open.kattis.com/problems/polygonarea
#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <stack>
#include <cmath>
#include <map>
#include <utility>
#include <queue>
#include <iomanip>

#define Forcase int __t;cin>>__t;getchar();for(int ___t=1;___t<=__t;___t++)
#define For(i, n) for(int i=0;i<n;i++)
#define Fore(e, arr) for(auto e:arr)

#define INF 1e9

using ull = unsigned long long;
using ll = long long;
using namespace std;

struct Point {
    Point() : x(0), y(0) {}
    Point(double a, double b) : x(a), y(b) {}

    double x, y;
};

Point operator-(const Point& p1, const Point& p2) {
    return Point(p1.x - p2.x, p1.y - p2.y);
}
double operator*(const Point& p1, const Point& p2) {
    return p1.x * p2.x + p1.y * p2.y;
}
double operator^(const Point& p1, const Point& p2) {
    return p1.x * p2.y - p1.y * p2.x;
}

int n;
Point ps[1010];

double area() {
    double re = ps[n - 1] ^ ps[0];
    For (i, n - 1) {
        re += ps[i] ^ ps[i + 1];
    }
    return re / 2;
}

int main() {

    while (cin >> n && n != 0) {
        For (i, n) {
            cin >> ps[i].x >> ps[i].y;
        }

        double a = area();
        if (a > 0) {
            cout << fixed << setprecision(1) << "CCW " << a << '\n';
        } else {
            cout << fixed << setprecision(1) << "CW " << -a << '\n';
        }
    }

    return 0;
}