// https://open.kattis.com/problems/anthony
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

int n, m;
double a[2010];
double dp[2010][2010];

double f(int x, int y) {
    if (y > x)  return 0;
    if (dp[x][y] >= 0)  return dp[x][y];
    if (y == 0) return dp[x][y] = (1 - a[x - 1]) * f(x - 1, 0);
    return dp[x][y] = a[x - 1] * f(x - 1, y - 1) + (1 - a[x - 1]) * f(x - 1, y);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    For (i, n + m - 1) {
        cin >> a[i];
    }
    For (i, n + m) {
        For (j, n + m) {
            dp[i][j] = -1;
        }
    }
    dp[0][0] = 1;

    double ans = 0;
    for (int i = m; i <= n + m - 1; i++) {
        //cout << "win " << i << "-th, win " << m - 1 << " in " << i - 1 << " is ";
        ans += a[i - 1] * f(i - 1, m - 1);
        //cout << a[i - 1] << ' ' << f(m - 1 + i, m - 1) << ' ' << a[i - 1] * f(m - 1 + i, m - 1) << '\n';
    }
    cout << ans << '\n';
    
    return 0;
}
