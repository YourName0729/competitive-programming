// computational_geometry
// https://open.kattis.com/problems/pointinpolygon
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

#define For(i, n) for (int i = 0; i < n; ++i)
#define Forcase int __t = 0; cin >> __t; while (__t--)
#define pb push_back
#define ll long long
#define ull unsigned long long
#define ar array

using namespace std;
using namespace __gnu_pbds;

template<class Type> using indexed_set=tree<Type,null_type,less<Type>,rb_tree_tag,tree_order_statistics_node_update>;

const int MOD = 1e9 + 7;
const int INF = 2147483647;
const ll IINF = 1e18;
const double eps = 1e-9;

int n;
ar<int, 2> a[1010];

bool on(ar<int, 2> p, ar<int, 2> p1, ar<int, 2> p2) {
    ar<int, 2> v1 = {p[0] - p1[0], p[1] - p1[1]};
    ar<int, 2> v2 = {p[0] - p2[0], p[1] - p2[1]};
    if (v1[0] * v2[1] - v1[1] * v2[0] != 0) {
        return 0;
    }
    return v1[0] * v2[0] + v1[1] * v2[1] <= 0;
}

bool ok(ar<int, 2> p, ar<int, 2> v, ar<int, 2> p1, ar<int, 2> p2) {
    ar<int, 2> v1 = {p1[0] - p[0], p1[1] - p[1]};
    ar<int, 2> v2 = {p2[0] - p[0], p2[1] - p[1]};
    int d1 = v[0] * v1[1] - v[1] * v1[0];
    int d2 = v[0] * v2[1] - v[1] * v2[0];
    if ((d1 < 0 && d2 < 0) || (d1 > 0 && d2 > 0)) return 0;
    ar<int, 2> q = {p[0] + v[0], p[1] + v[1]};
    v1 = {p[0] - p1[0], p[1] - p1[1]};
    v2 = {q[0] - p1[0], q[1] - p1[1]};
    v = {p2[0] - p1[0], p2[1] - p1[1]};
    d1 = v[0] * v1[1] - v[1] * v1[0];
    d2 = v[0] * v2[1] - v[1] * v2[0];
    return (d1 < 0 && d2 > 0) || (d1 > 0 && d2 < 0);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    ar<int, 2> v = {20011, 20021};

    while (cin >> n && n) {
        For (i, n)  cin >> a[i][0] >> a[i][1];
        a[n][0] = a[0][0], a[n][1] = a[0][1];
        
        int q;
        cin >> q;
        For (i, q) {
            int x, y;
            cin >> x >> y;
            
            bool flg = 0;
            For (i, n) {
                if (on({x, y}, a[i], a[i + 1])) {
                    cout << "on\n";
                    flg = 1;
                    break;
                }
            }
            if (flg)    continue;

            int cnt = 0;
            For (i, n) {
                if (ok({x, y}, v, a[i], a[i + 1])) {
                    cnt++;
                }
            }
            if (cnt % 2 == 0) {
                cout << "out\n";
            }
            else {
                cout << "in\n";
            }
        }
    }

    return 0;
}
