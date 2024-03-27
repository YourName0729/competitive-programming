// https://open.kattis.com/problems/dualdivisibility
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

map<ll, int> f(ll u) {
    map<ll, int> mp;
    for (ll i = 2; i * i <= u; ++i) {
        while (u % i == 0) {
            ++mp[i];
            u /= i;
        }
    }
    if (u != 1) mp[u]++;

    // for (auto [k, v] : mp) cout << k << ' ' << v << '\n';
    // cout << '\n';

    return mp;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    ll a, b;
    cin >> a >> b;
    if (a % b != 0) {
        cout << "0\n";
        return 0;
    }

    a /= b;
    
    map<ll, int> mpa = f(a);

    ll ans = 1;
    for (auto& [k, v] : mpa) if (v != 0) ans *= v + 1;
    cout << ans << '\n';

    return 0;
}