// dp
// https://open.kattis.com/problems/exactchange2
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

int n, c;
int dp[110][20010];
int a[110];

int f(int nn, int w) {
    if (dp[nn][w] != -1)    return dp[nn][w];
   int ans = f(nn - 1, w);
   if (a[nn] <= w) ans = min(ans, 1 + f(nn - 1, w - a[nn]));
   return dp[nn][w] = ans; 
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    Forcase {
        cin >> c >> n;
        For (i, n)  cin >> a[i + 1];
        For (i, n + 1) For (j, 20001)   dp[i][j] = -1;
        For (i, 20001)  dp[0][i] = MOD;
        dp[0][0] = 0;

        for (int i = c; i <= 20000; i++) {
            if (f(n, i) != MOD) {
                cout << i << ' ' << f(n, i) << '\n';
                break;
            }
        }
    }
    

    return 0;
}