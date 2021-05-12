// https://open.kattis.com/problems/iks
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

#define For(i, n) for (int i = 0; i < n; ++i)
#define Forcase int __t = 0; cin >> __t; while (__t--)
#define ll long long
#define ar array

using namespace std;
using namespace __gnu_pbds;

template<class Type> using indexed_set=tree<Type,null_type,less<Type>,rb_tree_tag,tree_order_statistics_node_update>;

const int MOD = 1e9 + 7;
const int INF = 2147483647;
const ll IINF = 1e18;
const double eps = 1e-12;

vector<ar<ll, 2>> prime_factor(ll n) {
    vector<ar<ll, 2>> re;
    for (ll i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            int cnt = 0;
            while (n % i == 0) {
                cnt++;
                n /= i;
            }
            re.push_back({i, cnt});
        }
    }
    if (n != 1) {
        re.push_back({n, 1});
    }
    return re;
}

int n;
ll a[1010];
vector<ar<ll, 2>> pf[1010];
map<ll, ll> pf2[1010];

ll Pow(ll a, ll m) {
    if (m == 0) return 1;
    ll tmp = Pow(a, m / 2);
    if (m % 2 == 0) {
        return tmp * tmp;
    }
    else {
        return tmp * tmp * a;
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    For (i, n) {
        cin >> a[i];
        pf[i] = prime_factor(a[i]);
        for (ar<ll, 2> p : pf[i]) {
            pf2[i][p[0]] = p[1];
        }
    }

    map<ll, ll> mp;
    For (i, n) {
        for (ar<ll, 2> p : pf[i]) {
            mp[p[0]] += p[1];
        }
    }

    map<ll, ll> ans;
    ll gcd = 1;
    for (auto p : mp) {
        if (p.second >= n) {
            ans[p.first] = p.second / n;
            gcd *= Pow(p.first, p.second / n);
        }
    }

    // For (i, n) {
    //     cout << a[i] << ":\n";
    //     for (ar<ll, 2> p : pf[i]) {
    //         cout << p[0] << ' ' << p[1] << '\n';
    //     }
    // }

    // cout << "ans\n";
    // for (auto p : ans) {
    //     cout << p.first << ' ' << p.second << '\n';
    // }
    
    ll cnt = 0;
    For (i, n) {
        for (auto p : ans) {
            if (!pf2[i].count(p.first)) {
                cnt += p.second;
            }
            else if (pf2[i][p.first] < p.second) {
                cnt += p.second - pf2[i][p.first];
            }
        }
    }

    cout << gcd << ' ' << cnt << '\n';

    return 0;
}
