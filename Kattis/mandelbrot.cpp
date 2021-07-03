// https://open.kattis.com/problems/mandelbrot
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
const unsigned ll IINF = 1e18;
const double eps = 1e-12;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    double dx, dy, x, y;
    int r, t = 0;
    while (cin >> dx >> dy >> r) {
        ++t;
        cout << "Case " << t << ": ";
        bool flg = 0;
        x = y = 0;
        For (i, r) {
            x += dx, y += dy;
            if (x * x + y * y > 4) {
                flg = 1;
                cout << "OUT\n";
                break;
            }
            double nx = x * x - y * y, ny = 2 * x * y;
            x = nx, y = ny;
        }
        if (!flg) cout << "IN\n";
    }


    return 0;
}
