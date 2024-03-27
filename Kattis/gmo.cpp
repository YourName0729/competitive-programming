// https://open.kattis.com/problems/gmo
#include <bits/stdc++.h>

#define For(i, n) for (int i = 0; i < n; i++)
#define Forcase int __t = 0; cin >> __t; while (__t--)
#define pb push_back
#define ll long long
#define ull unsigned long long
#define ar array

using namespace std;

const int MOD = 1e9 + 7;
const int INF = 2147483647;

int n, m;
string s1, s2;
int dp[10010][5010];

int c[300];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    cin >> s1 >> s2;
    cin >> c['A'] >> c['C'] >> c['G'] >> c['T'];

    n = s1.length(), m = s2.length();

    // cout << 0 << ' ';
    for (int i = 1, sm = 0; i <= m; ++i) {
        sm += c[s2[i]];
        dp[0][i] = sm;
        // cout << sm << ' ';
    } 
    // cout << '\n';

    for (int i = 1; i <= n; ++i) {
        // cout << dp[i][0] << ' ';
        for (int j = 1; j <= m; ++j) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else dp[i][j] = dp[i][j - 1] + c[s2[j - 1]];
            // cout << dp[i][j] << ' ';
        }
        // cout << '\n';
    }

    int ans = MOD;
    for (int i = 0; i < n; ++i) {
        if (s1[i] == s2.back()) ans = min(ans, dp[i][m - 1]);
        else ans = min(ans, dp[i + 1][m - 1] + c[s2.back()]);
    }

    cout << ans << '\n';

    return 0;
}