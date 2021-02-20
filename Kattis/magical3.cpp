// https://open.kattis.com/problems/magical3
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

ll solve(ll n) {
    for (ll i = 4; i * i <= n; i++) {
        if (n % i == 0) {
            return i;
        }
    }
    return n;
}

int main() {
    //ios_base::sync_with_stdio(0); cin.tie(0);

    ll n;
    while (cin >> n && n) {
        if (n <= 2 || n == 5 || n == 4 || n == 6) {
            cout << "No such base\n";
            continue;
        }
        if (n == 3) {
            cout << "4\n";
            continue;
        }
        n -= 3;

        ll ans = solve(n);
        if (ans % 2 == 0 && n / 2 >= 4) {
            ans = min(ans, n / 2);
        }
        if (ans % 3 == 0 && n / 3 >= 4) {
            ans = min(ans, n / 3);
        }
        cout << ans << '\n';
    }

    return 0;
}
