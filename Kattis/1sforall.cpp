// https://open.kattis.com/problems/1sforall
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

int n;
int dp[100010];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    cin >> n;
    dp[0] = 0, dp[1] = 1;

    for (int i = 2; i <= n; ++i) {
        dp[i] = MOD;
        for (int j = 1; j <= i / 2; ++j) {
            dp[i] = min(dp[i], dp[j] + dp[i - j]);
        }
        for (int j = 2; j * j <= i; ++j) {
            if (i % j == 0) dp[i] = min(dp[i], dp[j] + dp[i / j]);
        }

        int v = 10;
        while (1) {
            int pfx = i / v, sfx = i % v;
            v *= 10;

            if (pfx == 0) break;
            if (sfx * 100 < v) continue;
            dp[i] = min(dp[i], dp[pfx] + dp[sfx]);
        }
    }

    cout << dp[n] << '\n';

    return 0;
}