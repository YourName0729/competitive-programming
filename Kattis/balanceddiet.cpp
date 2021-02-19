// dp
// https://open.kattis.com/problems/balanceddiet
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
int a[30];
bool dp[12010];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    while (cin >> n && n) {
        For (i, 12001)  dp[i] = 0;
        dp[0] = 1;
        int all = 0;
        For (i, n) {
            cin >> a[i];
            all += a[i];
            for (int j = 12000; j >= 0; j--) {
                if (dp[j])  dp[j + a[i]] = 1;
            }
        }
        int ans = 0;
        For (i, 12001) {
            if (dp[i]) ans = max(ans, min(i, all - i));
        }
        cout << all - ans << ' ' << ans << '\n';
    }

    return 0;
}