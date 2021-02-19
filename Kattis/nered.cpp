//
// https://open.kattis.com/problems/nered
#include <bits/stdc++.h>
 
#define For(i, n) for (int i = 0; i < n; i++)
#define FOR1(i, n) for (int i = 1; i <= n; i++)
#define Forcase int __t = 0; cin >> __t; while (__t--)
#define pb push_back
#define ll long long
#define ull unsigned long long
#define ar array
 
using namespace std;
 
const int MOD = 1e9 + 7;
const int INF = 2147483647;

int n, m;
int arr[110][110];
int dp[110][110];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    cin >> n >> m;
    For (i, m) {
        int r, c;
        cin >> r >> c;
        arr[r][c]++;
    }

    FOR1 (i, n) {
        FOR1 (j, n) {
            dp[i][j] = bool(arr[i][j]) + dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
        }
    }

    // For (i, n + 1) {
    //     For (j, n + 1) {
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    int ans = 0;

    FOR1 (w, m) {
        if (m % w != 0) continue;
        if (m / w > n)  continue;
        int r = m / w;
        FOR1 (x, n - w + 1) {
            FOR1 (y, n - r + 1) {
                int d = dp[x + w - 1][y + r - 1] - dp[x + w - 1][y - 1] - dp[x - 1][y + r - 1] + dp[x - 1][y - 1];
                ans = max(ans, d);
                // if (ans == d) {
                //     cout << ans << ' ' << x << ' ' << y << ' ' << x + w << ' ' << y + r << '\n';
                // }
            }
        }
    }

    cout << m - ans << '\n';

    return 0;
}