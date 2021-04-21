// https://open.kattis.com/problems/soyoulikeyourfoodhot
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

ll n, a, b;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int x, y, z, u, v, w;
    char cc;
    cin >> x >> cc >> u >> y >> cc >> v >> z >> cc >> w;
    n = 100 * x + u, a = 100 * y + v, b = 100 * z + w;;

    int c = 0;
    bool flg = 0;
    while (c * a <= n) {
        if ((n - a * c) % b == 0) {
            cout << c << ' ' << (n - a * c) / b << '\n';
            flg = 1;  
        }
        c++;
    }
    if (!flg) {
        cout << "none\n";
    }
    

    return 0;
}
