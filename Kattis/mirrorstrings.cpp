// https://open.kattis.com/problems/mirrorstrings
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

ll _exp(ll b, ll m) {
    if (m == 0) return 1ull;
    ll tmp = _exp(b, m / 2);
    if (m % 2 == 0) return (tmp * tmp) % MOD;
    return (tmp * tmp % MOD * b) % MOD;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int l, r;
    cin >> l >> r;

    ll ans = 0;
    for (int i = l; i <= r; ++i) {
        ans = (ans + _exp(5, (i + 1) / 2) + _exp(2, (i + 1) / 2)) % MOD;
    }
    cout << ans << '\n';

    return 0;
}