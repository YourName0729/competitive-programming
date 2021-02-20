//
// https://open.kattis.com/problems/cetvrta
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
    friend bool operator==(const Point& p1, const Point& p2) {
        return p1.x == p2.x && p1.y == p2.y;
    }

    friend double Dis(const Point& p1, const Point& p2) {
        return (p1 - p2).Len();
    }

    friend istream& operator>>(istream& in, Point& p) {
        in >> p.x >> p.y;
        return in;
    }
    friend ostream& operator<<(ostream& out, Point& p) {
        out << p.x << ' ' << p.y;
        return out;
    }
};

bool cmp(Point& p1, Point& p2) {
    if (p1.x == p2.x)   return p1.y < p2.y;
    return p1.x < p2.x;
}

bool isRec(vector<Point> p) {
    sort(p.begin(), p.end(), cmp);

    // cout << p[0] << ' ' << p[1] << ' ' << p[2] << ' ' << p[3] << '\n';

    return (p[0] + p[3]) == (p[1] + p[2]);
}

int main() {
    Point tmp;
    vector<Point> p;
    for (int i = 0; i < 3; i++) {
        cin >> tmp;
        p.push_back(tmp);
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            Point cur(p[i].x, p[j].y);
            // cout << "cur = " << cur << '\n';
            p.push_back(cur);
            if (isRec(p)) {
                cout << cur << '\n';
                return 0;
            } else {
                p.pop_back();
            }
        }
    }


    return 0;
}
