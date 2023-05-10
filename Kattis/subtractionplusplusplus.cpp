// https://open.kattis.com/problems/subtractionplusplusplus
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

int n = 200;
bool dp[1010][1010];

int main() {
    // ios_base::sync_with_stdio(false); cin.tie(0);

    // For (i, n) {
    //     for (int j = i; j < n; ++j) {
    //         dp[i][j] = 1;
    //     }
    // }

    // for (int i = 1; i < n; ++i) {
    //     for (int j = i - 1; j > 0; --j) {
    //         // i: stone, j: round
    //         for (int k = 1; k <= j; ++k) {
    //             if (!dp[i - k][j + 1]) {
    //                 dp[i][j] = 1;
    //                 break;
    //             }
    //         }
    //     }
    // }

    // for (int i = 1; i < 100; ++i) {
    //     if (dp[i][1]) cout << i << '\n';
    // }

    cin >> n;

    for (int i = 1; i < 1000; ++i) {
        if (i * i <= n && (i + 1) * (i + 1) > n) {
            cout << (n - i * i < i? "YES\n" : "NO\n");
            return 0;
        }
    }

    return 0;
}