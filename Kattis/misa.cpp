//
// https://open.kattis.com/problems/misa
#include <bits/stdc++.h>

#define fast ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define forcase int __t;cin >> __t;while (__t--)
#define For(i, n) for(int i = 0; i < n; i++)

using ll = long long;

using namespace std;

class Point {
public:
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}

    bool in(int X, int Y) const {
        return 0 <= x && x < X && 0 <= y && y < Y;
    }

    friend Point operator+(const Point& p1, const Point& p2) {
        return Point(p1.x + p2.x, p1.y + p2.y);
    }
    friend bool operator==(const Point& p1, const Point& p2) {
        return p1.x == p2.x && p1.y == p2.y;
    }
    friend bool operator!=(const Point& p1, const Point& p2) {
        return !(p1 == p2);
    }
    friend Point operator-(const Point& p) {
        return Point(-p.x, -p.y);
    }
    friend istream& operator>>(istream& in, Point& p) {
        in >> p.x >> p.y;
        return in;
    }
    friend bool operator<(const Point& p1, const Point& p2) {
        if (p1.x == p2.x)   return p1.y < p2.y;
        return p1.x < p2.x;
    }

    int x, y;
};

int n, m;
char arr[60][60];

Point drct[8] = {Point(1, 1), Point(1, 0), Point(1, -1), Point(0, -1), Point(-1, -1), Point(-1, 0), Point(-1, 1), Point(0, 1)};
int near(Point p) {
    int re = 0;
    For (i, 8) {
        Point go = p + drct[i];
        if (go.in(n, m) && arr[go.x][go.y] == 'o') {
            re++;
        }
    }
    return re;
}

int main() {
    fast;

    cin >> n >> m;
    For (i, n) {
        For (j, m) {
            cin >> arr[i][j];
        }
    }

    bool ok = false;
    Point mx(0, 0);
    For (i, n) {
        For (j, m) {
            if (arr[i][j] == '.' && (!ok || near(Point(i, j)) > near(mx))) {
                mx = Point(i, j);
                ok = true;
            }
        }
    }

    if (ok) {
        arr[mx.x][mx.y] = 'o';
    }

    int sum = 0;
    For (i, n) {
        For (j, m) {
            if (arr[i][j] == 'o') {
                sum += near(Point(i, j));
            }
        }
    }

    cout << sum / 2 << '\n';

    
    return 0;
}