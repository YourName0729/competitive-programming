// number_theory
// https://open.kattis.com/problems/rationalratio
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

int main() {
    //ios_base::sync_with_stdio(0); cin.tie(0);

    ll a, m;
    char c;
    string b;
    cin >> a >> c >> b >> m;

    ll x = stoll(b), y = 0;
    if (b.length() != m) {
        x -= stoll(b.substr(0, b.length() - m));
    }
    For (i, m) {
        y *= 10;
        y += 9;
    }
    For (i, b.length() - m) {
        y *= 10;
    }

    ll g = __gcd(x, y);
    x /= g;
    y /= g;
    cout << a * y + x << '/' << y << '\n';

    return 0;
}