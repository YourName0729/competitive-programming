// https://open.kattis.com/problems/paludarium
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

#define For(i, n) for (int i = 0; i < n; ++i)
#define Forcase int __t = 0; cin >> __t; while (__t--)
#define ll long long
#define ar array

using namespace std;
using namespace __gnu_pbds;

template<class Type> using indexed_set=tree<Type,null_type,less<Type>,rb_tree_tag,tree_order_statistics_node_update>;

const int MOD = 1e9 + 7;
const int INF = 2147483647;
const ll IINF = 1e18;
const double eps = 1e-12;

int h, w;
ll a[500010];

ar<ll, 2> diff(ll lev) {
    ll air = 0, wt = 0;
    For (i, w) {
        if (a[i] <= lev) {
            wt += lev - a[i];
            air += h - lev;
        }
        else {
            air += h - a[i];
        }
    }
    return {abs(air - wt), wt};
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> h >> w;
    ll mn = MOD;
    For (i, w) {
        cin >> a[i];
        mn = min(mn, a[i]);
    }

    if (mn == h - 1) {
        cout << "0 0\n";
        return 0;
    }

    ll l = mn + 1, r = h;
    while (l + 10 < r) {
        ll m1 = (2 * l + r) / 3, m2 = (l + 2 * r) / 3;
        if (diff(m1) <= diff(m2)) {
            r = m2;
        }
        else {
            l = m1;
        }
    }

    ar<ll, 2> ans = diff(l);
    int lev = l;
    for (int i = l + 1; i <= r; i++) {
        ar<ll, 2> cur = diff(i);
        //cout << cur[0] << ' ' << cur[1] << '\n';
        if (cur[0] < ans[0]) ans = cur, lev = i;
    }
    cout << lev << ' ' << ans[1] << '\n';

    return 0;
}
