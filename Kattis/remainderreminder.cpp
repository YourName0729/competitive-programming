// Chinese_reminder_theorem
// https://open.kattis.com/problems/remainderreminder
#include <bits/stdc++.h>

#define For(i, n) for (int i = 0; i < n; i++)
#define Forcase int __t = 0; cin >> __t; while (__t--)
#define Show(a,n) For(i,n) cout << a[i] << ' ';cout << '\n';
#define pb push_back
#define ll long long
#define ar array

using namespace std;

const int MOD = 1e9 + 7;
const ll INF = 1e18;

ll a, b, c, d, e, f, g;
vector<ll> vol;

ll extended_euclidean(ll x, ll y, ll& a, ll& b) {
    //struct EX_GCD ex_gcd;
    if (y == 0) { 
        //ex_gcd.s = 1;
        //ex_gcd.t = 0;
        //ex_gcd.gcd = 0;
        a = 1, b = 0;
        return 0;
    }
    ll old_r = x, r = y;
    ll old_s = 1, s = 0;
    ll old_t = 0, t = 1;
    while (r != 0) { 
        ll q = old_r / r;
        ll temp = old_r;
        old_r = r;
        r = temp - q * r;
        temp = old_s;
        old_s = s;
        s = temp - q * s;
        temp = old_t;
        old_t = t;
        t = temp - q * t;
    }
    a = old_s, b = old_t;
    return old_r;
}

ll CRT(vector<ll> a, vector<ll> m) {
    ll s, t;
    ll a1 = a[0], m1 = m[0];
    for (int i = 1; i < a.size(); i++) {
        ll a2 = a[i], m2 = m[i];

        ll g = extended_euclidean(m1, m2, s, t);
        if (a1 % g != a2 % g) {
            throw "unsolvable";
        }

        extended_euclidean(m1 / g, m2 / g, s, t);

        ll mod = m1 / g * m2;
        ll x = (a1 * (m2 / g) * t + a2 * (m1 / g) * s) % mod;

        a1 = x, m1 = mod;
        if (a1 < 0) a1 += mod;
    }
    return a1;
}

ll LCM(vector<ll> m) {
    ll m1 = m[0];
    for (int i = 1; i < m.size(); i++) {
        ll s, t;
        ll g = extended_euclidean(m1, m[i], s, t);
        m1 = m1 / g * m[i];
    }
    return m1;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    cin >> a >> b >> c >> d >> e >> f >> g;
    for (int i = 1; i < min(a, b) / 2 + (min(a, b) % 2); i++) {
        vol.pb((a - 2 * i) * (b - 2 * i) * i);
    }

    sort(vol.begin(), vol.end());
    reverse(vol.begin(), vol.end());

    //Show(vol, vol.size());

    ll mod = LCM({vol[0], vol[1], vol[2]});
    ll x = CRT({c, d, e}, vector<ll>(vol.begin(), vol.begin() + 3));
    while (x < f)   x += mod;
    cout << x << '\n';

    return 0;
}