// mathematics
// https://open.kattis.com/problems/cropeasy
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
#include <deque>
#include <set>

#define Forcase int __t;cin>>__t;getchar();for(int ___t=1;___t<=__t;___t++)
#define For(i, n) for(int i=0;i<n;i++)
#define Fore(e, arr) for(auto e:arr)

#define INF 1e9
#define EPS 1e-9

using ull = unsigned long long;
using ll = long long;
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
    friend bool operator<(const Point& p1, const Point& p2) {
        if (p1.x == p2.x)   return p1.y < p2.y;
        return p1.x < p2.x;
    }
};

set<Point> ps;
ll dp[3][3];

ll C(ll n) {
    if (n < 3)  return 0;
    return n * (n - 1) / 2 * (n - 2) / 3;
}

ll ans() {
    For (i, 3) {
        For (j, 3) {
            dp[i][j] = 0;
        }
    }

    Fore (p, ps) {
        dp[p.x % 3][p.y % 3]++;
    }
    // For (i, 3) {
    //     For (j, 3) {
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    // cout << '\n';

    ll re = 0;
    
    For (i, 3) {
        For (j, 3) {
            re += C(dp[i][j]);
        }
    }
    re += dp[0][0] * dp[0][1] * dp[0][2];
    re += dp[1][0] * dp[1][1] * dp[1][2];
    re += dp[2][0] * dp[2][1] * dp[2][2];

    re += dp[0][0] * dp[1][0] * dp[2][0];
    re += dp[0][1] * dp[1][1] * dp[2][1];
    re += dp[0][2] * dp[1][2] * dp[2][2];

    re += dp[0][0] * dp[1][1] * dp[2][2];
    re += dp[0][1] * dp[1][2] * dp[2][0];
    re += dp[0][2] * dp[1][0] * dp[2][1];

    re += dp[0][2] * dp[1][1] * dp[2][0];
    re += dp[0][1] * dp[1][0] * dp[2][2];
    re += dp[0][0] * dp[1][2] * dp[2][1];

    return re;
}

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);

    int t;
    cin >> t;
    for (int cases = 1; cases <= t; cases++) {
        ps.clear();

        ll n, A, B, C, D, x0, y0, M;
        cin >> n >> A >> B >> C >> D >> x0 >> y0 >> M;

        ll x = x0, y = y0;
        ps.insert(Point(x, y));
        for (int i = 1; i < n; i++) {
            x = ((A * x) % M + B) % M;
            y = ((C * y % M) + D) % M;
            ps.insert(Point(x, y));
        }

        cout << "Case #" << cases << ": " << ans() << '\n';
    }

    return 0;
}