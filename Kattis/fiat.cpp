// discrete_mathematics Catalan_number number_theory
// https://open.kattis.com/problems/fiat
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

#define For(i, n) for (int i = 0; i < n; ++i)
#define Forcase int __t = 0; cin >> __t; while (__t--)
#define pb push_back
#define ll long long
#define ull unsigned long long
#define ar array

using namespace std;
using namespace __gnu_pbds;

template<class Type> using indexed_set=tree<Type,null_type,less<Type>,rb_tree_tag,tree_order_statistics_node_update>;

const int MOD = 1e9 + 7;
const int INF = 2147483647;
const ll IINF = 1e18;
const double eps = 1e-9;

ll pow(ll a, ll p) {
    if (p == 0) return 1;
    ll re = pow(a, p / 2);
    if (p % 2) {
        return re * re % MOD * a % MOD;
    }
    return re * re % MOD;
}

ll mod_inv(ll a, ll m) {
    return pow(a, m - 2);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n;
    cin >> n;
    ll a = 1;
    For (i, n) {
        a = a * (4 * i + 2) % MOD * mod_inv(i + 2, MOD) % MOD;
    }
    cout << a << '\n';

    return 0;
}
