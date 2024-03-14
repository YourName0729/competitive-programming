// https://open.kattis.com/problems/efficientexchange
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
string s;
int arr[1010];
int dp[1010] = {0};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    cin >> s;
    n = s.length();
    for (int i = 0; i < n; ++i) arr[i] = s[n - i - 1] - '0';

    dp[0] = 0;

    for (int i = 0; i < n; ++i) {
        dp[i + 1] = dp[i] + arr[i];
        int sm = 2;
        for (int j = 0; j <= i; ++j) {
            sm += 9 - arr[i - j];
            dp[i + 1] = min(dp[i + 1], dp[i - j] + sm);
        }
        // cout << dp[i + 1] << ' ';
    }
    // cout << '\n';

    cout << dp[n] << '\n';

    return 0;
}