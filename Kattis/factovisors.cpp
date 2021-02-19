// number_theory
// https://open.kattis.com/problems/factovisors
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

#define For(i, n) for (int i = 0; i < n; ++i)
#define Forcase int __t = 0; cin >> __t; while (__t--)
#define ll long long
#define ull unsigned long long
#define ar array

using namespace std;
using namespace __gnu_pbds;

template<class Type> using indexed_set=tree<Type,null_type,less<Type>,rb_tree_tag,tree_order_statistics_node_update>;

const int MOD = 1e9 + 7;
const int INF = 2147483647;
const ll IINF = 1e18;
const double eps = 1e-12;

vector<pair<ll, ll>> prime_factor(ll d) {
    vector<pair<ll, ll>> re;
    for (ll i = 2; i * i <= d; i++) {
        if (d % i == 0) {
            int cnt = 0;
            while (d % i == 0) {
                cnt++;
                d /= i;
            }
            re.push_back({i, cnt});
        }
    }
    if (d != 1) re.push_back({d, 1});
    return re;
}

int cnt(ll n, ll p) {
    if (n <= 1) return 0; 
    ll cur = p;
    int re = 0;
    while (cur <= n) {
        re += n / cur;
        cur *= p;
    }
    return re;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    ll n, m;
    while (cin >> n >> m) {
        if (m == 0) {
            cout << "0 does not divide " << n << "!\n";
            continue;
        }

        auto vec = prime_factor(m);
        bool flg = 0;
        for (auto p : vec) {
            int c = cnt(n, p.first);
            if (c < p.second) {
                flg = 1;
                break;
            }
        }
        cout << m;
        if (flg) {
            cout << " does not divide ";
        }
        else {
            cout << " divides ";
        }
        cout << n << "!\n";
    }
    
    return 0;
}