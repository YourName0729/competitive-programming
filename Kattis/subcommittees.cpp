// https://open.kattis.com/problems/subcommittees
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

int main() {
    //ios_base::sync_with_stdio(false); cin.tie(0);

    ll n;
    cin >> n;
    int ans = 1;
    for (ll i = 2; i * i <= n; ++i) {
        while (n % i == 0) {
            ++ans;
            n /= i;
        }
    }
    ans += n != 1;
    cout << ans << '\n';

    return 0;
}