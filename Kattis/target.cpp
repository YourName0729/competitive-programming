// https://open.kattis.com/problems/target
#include <bits/stdc++.h>
//#include <ext/pb_ds/tree_policy.hpp>
//#include <ext/pb_ds/assoc_container.hpp>

#define For(i, n) for (int i = 0; i < n; ++i)
#define Forcase int __t = 0; cin >> __t; while (__t--)
#define ll long long
#define ull unsigned long long
#define ar array

using namespace std;
//using namespace __gnu_pbds;

//template<class Type> using indexed_set=tree<Type,null_type,less<Type>,rb_tree_tag,tree_order_statistics_node_update>;

const int MOD = 1e9 + 7;
const int INF = 2147483647;
const ll IINF = 1e18;
const double eps = 1e-12;

int operator^(ar<int, 2> x, ar<int, 2> y) {
    return x[0] * y[1] - x[1] * y[0];
}
int operator*(ar<int, 2> x, ar<int, 2> y) {
    return x[0] * y[0] + x[1] * y[1];
}
ar<int, 2> operator+(ar<int, 2> x, ar<int, 2> y) {
    return {x[0] + y[0], x[1] + y[1]};
}
ar<int, 2> operator-(ar<int, 2> x, ar<int, 2> y) {
    return {x[0] - y[0], x[1] - y[1]};
}
int d2(ar<int, 2> x) {
    return x[0] * x[0] + x[1] * x[1];
}
int sign(int d) {
    if (d < 0)  return -1;
    return bool(d);
}

int n;
ar<int, 2> a[1010];

bool on(ar<int, 2> p) {
    For (i, n) {
        ar<int, 2> v1 = a[i] - p, v2 = a[i + 1] - p;
        if ((v1 ^ v2) == 0 && (v1 * v2) <= 0)   return 1;
    }
    return 0;
}

int ori(ar<int, 2> v, ar<int, 2> v1, ar<int, 2> v2) {
    return sign(v ^ v1) * sign(v ^ v2);
}

bool in(ar<int, 2> p) {
    int cnt = 0;
    ar<int, 2> v = {20011, 20021}, q = p + v;
    For (i, n) {
        ar<int, 2> v1 = a[i] - p, v2 = a[i + 1] - p;
        int A = ori(v, v1, v2);
        int B = ori(a[i + 1] - a[i], p - a[i], q - a[i]);
        if (A == -1 && B == -1) {
            cnt++;
        }
    }
    return cnt % 2;
}

double dist_p2l(ar<int, 2> p, ar<int, 2> p1, ar<int, 2> p2) {
    ar<int, 2> u = p - p1, v = p2 - p1;
    if (u * v < 0)  return sqrt(d2(u));
    if (((p - p2) * (p1 - p2)) < 0) return sqrt(d2(p - p2));
    return abs(u ^ v) / sqrt(d2(v));
}

double solve(ar<int, 2> p) {
    double ans = dist_p2l(p, a[0], a[1]);
    For (i, n) {
        ans = min(ans, dist_p2l(p, a[i], a[i + 1]));
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int cases = 0;
    while (cin >> n && n) {
        cout << "Case " << ++cases << '\n';
        For (i, n)  cin >> a[i][0] >> a[i][1];
        a[n] = a[0];

        int q;
        cin >> q;
        while (q--) {
            ar<int, 2> p;
            cin >> p[0] >> p[1];
            if (on(p)) {
                cout << "Winged!\n";
            }
            else if (!in(p)) {
                cout << "Miss! " << fixed << solve(p) << '\n';
            }
            else {
                cout << "Hit! " << fixed << solve(p) << '\n';
            }
        }
    }
    

    return 0;
}
