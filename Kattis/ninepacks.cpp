// dp
// https://open.kattis.com/problems/ninepacks
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

int n, m;
int a[110], b[110];
int dp1[100010], dp2[100010];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    For (i, 100001) dp1[i] = dp2[i] = MOD;
    dp1[0] = dp2[0] = 0;
    cin >> n;
    For (i, n)  cin >> a[i];
    cin >> m;
    For (i, m)  cin >> b[i];

    For (i, n) {
        for (int j = 100000 - a[i]; j >= 0; j--) {
            dp1[j + a[i]] = min(dp1[j + a[i]], dp1[j] + 1);
        }
    }
    For (i, m) {
        for (int j = 100000 - b[i]; j >= 0; j--) {
            dp2[j + b[i]] = min(dp2[j + b[i]], dp2[j] + 1);
        }
    }

    int ans = MOD;
    for (int i = 1; i <= 100000; i++) {
        ans = min(ans, dp1[i] + dp2[i]);
    }
    if (ans == MOD) {
        cout << "impossible\n";
    }
    else {
        cout << ans << '\n';
    }

    return 0;
}