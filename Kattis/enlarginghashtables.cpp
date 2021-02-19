// prime_factor
// https://open.kattis.com/problems/enlarginghashtables
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
const double eps = 1e-12;

bool np(ll n) {
    for (ll i = 2; i * i <= n; i++) {
        if (n % i == 0) return 1;
    }
    return 0;
}

int main() {
    //ios_base::sync_with_stdio(0); cin.tie(0);

    ll n;
    while (cin >> n && n) {
        ll cur = 2 * n + 1;
        while (np(cur)) cur++;
        cout << cur;
        if (np(n)) {
            cout << " (" << n << " is not prime)";
        }
        cout << '\n';
    }
    
    return 0;
}