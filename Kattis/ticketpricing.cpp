// https://open.kattis.com/problems/ticketpricing
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

int n, W;
vector<ar<int, 2>> a[60];
int dp[310][60];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> W;
    For (i, W + 1) {
        int k;
        cin >> k;
        For (j, k) {
            int d;
            cin >> d;
            a[i].push_back({d, 0});
        }
        For (j, k) {
            int d;
            cin >> d;
            a[i][j][1] = d;
        }
    }

    For (i, n + 1) {
        int mx = 0;
        For (j, a[W].size()) {
            mx = max(mx, a[W][j][0] * min(i, a[W][j][1]));
        }
        dp[i][W] = mx;
    }

    for (int i = W - 1; i >= 1; i--) {
        For (j, n + 1) {
            int mx = 0;
            For (k, a[i].size()) {
                int cur = a[i][k][0] * min(j, a[i][k][1]);
                if (j >= a[i][k][1]) {
                    cur += dp[j - a[i][k][1]][i + 1];
                }
                mx = max(mx, cur);
            }
            dp[j][i] = mx;
        }
    }

    int ans = 0, ansv = 0;
    For (i, a[0].size()) {
        int cur = a[0][i][0] * min(n, a[0][i][1]);
        if (n >= a[0][i][1]) {
            cur += dp[n - a[0][i][1]][1];
        }
        if (cur > ans) {
            ans = cur, ansv = a[0][i][0];
        }
        else if (cur == ans) {
            ansv = min(ansv, a[0][i][0]);
        }
    }

    cout << ans << '\n' << ansv << '\n';

    return 0;
}
