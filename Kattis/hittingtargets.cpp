//
// https://open.kattis.com/problems/hittingtargets
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

#define For(i, n) for (int i = 0; i < n; ++i)
#define Forcase int __t = 0; cin >> __t; while (__t--)
#define ll long long
#define ull unsigned long long
#define ar array

using namespace std;
using namespace __gnu_pbds;

template<class Type> using indexed_set=tree<Type,null_type,less<Type>,rb_tree_tag,tree_order_statistics_node_update>;

const int MOD = 1e9 + 7;
const int INF = 2147483647;
const ll IINF = 1e18;
const double eps = 1e-12;

vector<ar<int, 4>> rec;
vector<ar<int, 3>> cir;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    Forcase {
        string s;
        cin >> s;
        if (s == "rectangle") {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            rec.push_back({x1, y1, x2, y2});
        }
        else {
            int x, y, r;
            cin >> x >> y >> r;
            cir.push_back({x, y, r});
        }
    }

    int q;
    cin >> q;
    while (q--) {
        int x, y;
        cin >> x >> y;
        int ans = 0;
        for (ar<int, 4> p : rec) {
            if (p[0] <= x && x <= p[2] && p[1] <= y && y <= p[3]) ans++;
        }
        for (ar<int, 3> p : cir) {
            int dx = x - p[0], dy = y - p[1];
            if (dx * dx + dy * dy <= p[2] * p[2]) ans++;
        }
        cout << ans << '\n';
    }

    return 0;
}
