// dp
// https://open.kattis.com/problems/cycleseasy
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

int dp[1024][11];
int n, k;
bool g[11][11];

int f(int cur, int prv) {
    if (dp[cur][prv] != -1) return dp[cur][prv];
    if (cur == (1 << n) - 1) {
        return dp[cur][prv] = (g[prv][0]);
    }
    int re = 0;
    For (i, n) {
        if ((cur & (1 << i)) == 0 && g[prv][i]) {
            re = (re + f(cur | (1 << i), i)) % 9901;
        }
    }
    return dp[cur][prv] = re;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t;
    cin >> t;
    For (tt, t) {
        cin >> n >> k;
        For (i, (1 << n)) For (j, n)    dp[i][j] = -1;
        For (i, n) For (j, n)   g[i][j] = 1;
        For (i, n)  g[i][i] = 0;
        For (i, k) {
            int u, v;
            cin >> u >> v, u--, v--;
            g[u][v] = g[v][u] = 0;
        }

        cout << "Case #" << tt + 1 << ": " << f(1, 0) * 4951 % 9901 << '\n';
    }


    return 0;
}