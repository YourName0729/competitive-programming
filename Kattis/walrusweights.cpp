// dp
// https://open.kattis.com/problems/walrusweights
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
bool dp[1010][2010];
int a[1010];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    For (i, n)  cin >> a[i];
    For (i, 2001)   dp[0][i] = 0;
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        dp[i][0] = 1;
        for (int j = 1; j <= 2000; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j >= a[i - 1]) {
                dp[i][j] = dp[i][j] || dp[i - 1][j - a[i - 1]];
            }
            // if (dp[i][j]) {
            //     cout << "ok " << i << ' ' << j << '\n';
            // }
        }
    }

    for (int i = 0; i <= 1000; i++) {
        if (dp[n][1000 + i]) {
            cout << 1000 + i << '\n';
            break;
        }
        if (dp[n][1000 - i]) {
            cout << 1000 - i << '\n';
            break;
        }
    }

    return 0;
}