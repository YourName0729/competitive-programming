// dp
// https://open.kattis.com/users/yourname0729/submissions/runningroutes
#include <bits/stdc++.h>

#define For(i, n) for (int i = 0; i < n; i++)
#define Forcase int __t = 0; cin >> __t; while (__t--)
#define ll long long
#define ar array

using namespace std;

const int MOD = 1e9 + 7;

int n;
bool adj[510][510];
int dp[510][510];

int f(int bot, int top) {
    //cout << "find " << cur << " to " << top << '\n';
    if (top - bot <= 0)  return 0;
    if (dp[bot][top] != -1)  return dp[bot][top];

    int mx = 0;
    for (int i = bot + 1; i <= top; i++) {
        if (adj[bot][i]) {
            int d = f(bot + 1, i - 1) + f(i + 1, top) + 1;
            mx = max(mx, d);
        }
    }
    //cout << cur << " to " << top << " = " << mx << '\n';
    return dp[bot][top] = max(mx, f(bot + 1, top));
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    cin >> n;
    For (i, n) {
        For (j, n) {
            dp[i][j] = -1;
        }
    }

    For (i, n) {
        For (j, n) {
            int d;
            cin >> d;
            adj[i][j] = (d == 1);
        }
    }

    // For (i, n) {
    //     For (j, n) {
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    // cout << '\n';

    cout << f(0, n - 1) << '\n';

    return 0;
}
 rss fe