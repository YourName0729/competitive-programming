// dp
// https://open.kattis.com/problems/countcircuits
#include <bits/stdc++.h>

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
#define forcase int __t;cin >> __t;while (__t--)
#define For(i, n) for(int i = 0; i < n; i++)

using namespace std;

class Point {
public:
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}

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

int n;
vector<Point> ps1, ps2;
map<Point, long long> m1, m2;

void build() {
    for(int i = 1; i < (1 << ps1.size()); i++) {
        Point sum;
        For (j, ps1.size()) {
            if ((1 << j) & i) {
                sum = sum + ps1[j];
            }
        }
        m1[sum]++;
    }

    for(int i = 1; i < (1 << ps2.size()); i++) {
        Point sum;
        For (j, ps2.size()) {
            if ((1 << j) & i) {
                sum = sum + ps2[j];
            }
        }
        m2[sum]++;
    }
}

int main() {
    fast;

    cin >> n;
    For (i, n) {
        Point tmp;
        cin >> tmp;
        if (i % 2 == 0) {
            ps1.push_back(tmp);
        } else {
            ps2.push_back(tmp);
        }
    }

    build();

    /*for (auto e : ps1) {
        cout << e.x << ' ' << e.y << '\n';
    }
    for (auto e : ps2) {
        cout << e.x << ' ' << e.y << '\n';
    }

    for (auto e : m1) {
        cout << e.first.x << ' ' << e.first.y << ' ' << e.second << '\n';
    }
    for (auto e : m2) {
        cout << e.first.x << ' ' << e.first.y << ' ' << e.second << '\n';
    }*/

    Point zero(0, 0);
    long long ans = m1[zero] + m2[zero];
    for (auto e : m1) {
        if (m2.count(-e.first)) {
            ans += m1[e.first] * m2[-e.first];
        }
    }

    cout << ans << '\n';
    
    return 0;
}
