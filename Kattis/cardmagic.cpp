// https://open.kattis.com/problems/cardmagic
#include <bits/stdc++.h>

#define For(i, n) for (int i = 0; i < n; i++)
#define Forcase int __t = 0; cin >> __t; while (__t--)
#define pb push_back
#define ll long long
#define ull unsigned long long
#define ar array

using namespace std;

const int MOD = 1e9 + 9;
const int INF = 2147483647;

int n, k;
ll t;

ll dp[110][5010];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    cin >> n >> k >> t;

    For (i, k) dp[0][i + 1] = 1;

    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < 5010; ++j) {
            for (int l = 1; l <= min(k, j); ++l) {
                dp[i][j] += dp[i - 1][j - l];
                dp[i][j] %= MOD;
            }
        }
    }

    cout << dp[n - 1][t] << '\n';

    return 0;
}