// dp
// https://open.kattis.com/problems/marypartitions
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
const double eps = 1e-12;

ll dp[10010][10];
int m;

ll f(int n, int a) {
    if (dp[n][a] != -1)    return dp[n][a];
    if (pow(m, a) > n)  return dp[n][a] = f(n, a - 1);
    ll re = 0;
    for (int i = 0; i <= n; i += pow(m, a)) {
        re += f(n - i, a - 1);
    }   
    return dp[n][a] = re;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    Forcase {
        int t, n;
        cin >> t >> m >> n;
        For (i, n + 1) For (j, 10) dp[i][j] = -1;
        For (i, 10) dp[0][i] = 1;
        For (i, n + 1)  dp[i][0] = 1;
        cout << t << ' ' << f(n, 9) << '\n';
    }

    return 0;
}