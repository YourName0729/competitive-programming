//
// https://open.kattis.com/problems/rationalsequence3
#include <bits/stdc++.h>

#define fast ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define forcase int __t;cin>>__t;while(__t--)
#define For(i, n) for(int i=0;i<n;i++)

using ll = long long;

using namespace std;

struct Point {
    ll x, y;
    Point(ll a, ll b) : x(a), y(b) {}
};

Point rec(ll n) {
    if (n == 1)     return Point(1, 1);

    Point f = rec(n / 2);
    if (n % 2 == 0) {
        return Point(f.x, f.x + f.y);
    } else {
        return Point(f.x + f.y, f.y);
    }
}

int main() {
    fast;

    forcase {
        ll k, n;

        cin >> k >> n;
        Point p = rec(n);
        cout << k << ' ' << p.x << '/' << p.y << '\n';
    }

    return 0;
}