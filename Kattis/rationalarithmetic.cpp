// gcd
// https://open.kattis.com/problems/rationalarithmetic
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

void trim(ll& x, ll& y) {
    bool neg = (x < 0 && y >= 0) || (x >= 0 && y < 0);
    x = abs(x), y = abs(y);
    if (x == 0) {
        y = 1;
        return;
    }
    ll g = __gcd(x, y);
    x /= g, y /= g;
    if (neg)    x *= -1;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    Forcase {
        ll x1, y1, x2, y2, xa, ya;
        char op;
        cin >> x1 >> y1 >> op >> x2 >> y2;
        if (op == '+') {
            xa = x1 * y2 + x2 * y1;
            ya = y1 * y2;
        }
        else if (op == '-') {
            xa = x1 * y2 - x2 * y1;
            ya = y1 * y2;
        }
        else if (op == '*') {
            xa = x1 * x2;
            ya = y1 * y2;
        }
        else {
            xa = x1 * y2;
            ya = y1 * x2;
        }
        trim(xa, ya);
        cout << xa << " / " << ya << '\n';
    }

    return 0;
}