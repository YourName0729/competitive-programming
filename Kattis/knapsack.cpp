// dp
// https://open.kattis.com/problems/knapsack
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

int c, n;
int val[2010], wei[2010];
int dp[2010][2010];

int f(int i, int w) {
    if (i == -1)    return 0;
    if (dp[i][w] != -1) return dp[i][w];
    int ans = f(i - 1, w);
    if (wei[i] <= w) {
        ans = max(ans, val[i] + f(i - 1, w - wei[i]));
    }
    return dp[i][w] = ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    while (cin >> c >> n) {
        For (i, n) {
            For (j, c + 1) {
                dp[i][j] = -1;
            }
        }

        For (i, n) {
            cin >> val[i] >> wei[i];
        }

        f(n - 1, c);

        // For (i, n) {
        //     For (j, c + 1) {
        //         cout << dp[i][j] << ' ';
        //     }
        //     cout << '\n';
        // }

        int i = n - 1, w = c;
        vector<int> ans;
        while (i != -1) {
            if (f(i - 1, w) == f(i, w)) {
                i--;
            } 
            else {
                ans.push_back(i);
                w -= wei[i];
                i--;
            }
        }

        cout << ans.size() << '\n';
        for (int i = ans.size() - 1; i >= 0; i--) {
            cout << ans[i] << ' ';
        }
        cout << '\n';    
    }

    return 0;
}