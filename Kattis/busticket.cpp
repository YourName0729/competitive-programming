// https://open.kattis.com/problems/busticket
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

ll s, p, m, n;
ll a[1000010];
ll dp[1000010];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> s >> p >> m >> n;
    s = min(s, p);
    For (i, n) cin >> a[i];

    dp[0] = s;
    for (int i = 1; i < n; i++) {
        dp[i] = dp[i - 1] + s;
        if (a[0] >= a[i] - m + 1) {
            dp[i] = min(dp[i], p);
            continue;
        }

        int l = 0, r = i - 1;
        while (l < r) {
            int mid = (l + r) / 2 + (l + r) % 2;
            if (a[mid] >= a[i] - m + 1) {
                r = mid - 1;
            }
            else {
                l = mid;
            }
        }
        dp[i] = min(dp[i], p + dp[l]);
    }
    // For (i, n) {
    //     cout << a[i] << ' ' << dp[i] << '\n';
    // }
    // cout << '\n';

    cout << dp[n - 1] << '\n';

    return 0;
}
