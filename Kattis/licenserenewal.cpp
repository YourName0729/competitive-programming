// https://open.kattis.com/problems/licenserenewal
// only pass visible 1
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

int n, S, T;
int a[1010];
int dp[1010];
int pfx[1010];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> S >> T;
    For (i, n) cin >> a[i];
    pfx[0] = a[0];
    for (int i = 1; i < n; i++) {
        pfx[i] = a[i] + pfx[i - 1];
    }

    dp[0] = (a[0] <= S)? a[0] : 0;
    for (int i = 1; i < n; i++) {
        dp[i] = dp[i - 1];
        for (int j = 0; j < i; j++) {
            if (dp[j] + a[i] <= S) {
                dp[i] = max(dp[i], dp[j] + a[i]);
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (pfx[i] - dp[i] <= T) {
            ans++;
        }
        else {
            break;
        }
    }
    cout << ans << '\n';

    return 0;
}
