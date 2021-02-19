// dp
// https://open.kattis.com/problems/pavers
#include <bits/stdc++.h>

#define For(i, n) for (int i = 0; i < n; i++)
#define Forcase int __t = 0; cin >> __t; while (__t--)
#define pb push_back
#define ll long long
#define ull unsigned long long
#define ar array

using namespace std;

const int MOD = 1e9 + 7;
const ll INF = 1e18;

int n;
ar<ll, 4> dp[100010][2];

ar<ll, 4> f(int i, int h) {
    if (i == 0) return {1, 0, 0, 0};
    if (dp[i][h][0] != 0)   return dp[i][h];

    auto h1 = f(i - 1, 0);
    auto f1 = f(i - 1, 1);
    auto f2 = f(i - 2, 1);

    if (h == 1) {
        For (j, 4) {
            dp[i][h][j] = 4 * h1[j] + 2 * f1[j] + 3 * f2[j];
        }
        dp[i][h][1] += 2 * f1[0] + 2 * f2[0] + 2 * h1[0];
        dp[i][h][2] += f1[0] + 2 * f2[0] + 2 * h1[0];
        dp[i][h][3] += 2 * h1[0] + 2 * f2[0];
    }
    else {
        For (j, 4) {
            dp[i][h][j] = f2[j] + f1[j] + h1[j];
        }
        dp[i][h][1] += f1[0];
        dp[i][h][2] += h1[0];
        dp[i][h][3] += f2[0];
    }
    return dp[i][h];
}

int main() {
    //ios_base::sync_with_stdio(false); cin.tie(0);
    
    cin >> n;

    dp[1][0] = {1, 1, 0, 0};
    dp[1][1] = {2, 2, 1, 0};
    //dp[2][0] = {4, 5, 2, 1};
    //dp[2][1] = {11, 16, 8, 4};

    auto ans = f(n, 1);

    For (i, 4) {
        cout << ans[i] << ' ';
    }

    return 0;
}
