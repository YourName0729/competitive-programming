// case_considering
// https://open.kattis.com/problems/robotopia
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

    Forcase {
        ll l1, r1, l2, r2, l, r;
        cin >> l1 >> r1 >> l2 >> r2 >> l >> r;
        ll ansx = -1, ansy = -1;
        for (ll x = 1; l1 * x < l; x++) {
            if ((l - l1 * x) % l2 == 0) {
                ll y = (l - l1 * x) / l2;
                if (x * r1 + y * r2 == r) {
                    if (ansx > 0) {
                        ansx = ansy = -2;
                    }
                    else if (ansx == -1) {
                        ansx = x, ansy = y;
                    }
                }
            }
        }

        if (ansx == -1 || ansx == -2) {
            cout << "?\n";
        }
        else {
            cout << ansx << ' ' << ansy << '\n';
        }
    }
    

    return 0;
}
