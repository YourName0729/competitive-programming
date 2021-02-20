//
// https://open.kattis.com/problems/greedypolygons
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
    ios_base::sync_with_stdio(0); cin.tie(0);

    double pi = acos(-1);

    Forcase {
        int n, l, d, g;
        cin >> n >> l >> d >> g;
        double theta = pi * (0.5 - 1 / (double)n);
        double a1 = n * l * l  * tan(theta) / 4;
        double a2 = g * l * n * d;
        double a3 = g * g * d * d * pi;
        // cout << theta << '\n';
        //cout << a1 << ' ' << a2 << ' ' << a3 << '\n';
        cout << fixed << a1 + a2 + a3 << '\n';
    }

    return 0;
}
