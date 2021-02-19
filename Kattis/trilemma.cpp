// computational_geometry
// https://open.kattis.com/problems/trilemma
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
const ll INF = 1e18;
const double eps = 1e-9;

int x[3], y[3], r2[3];

bool parall() {
    int vx = x[1] - x[0], vy = y[1] - y[0];
    int ux = x[2] - x[0], uy = y[2] - y[0];
    return vx * uy - vy * ux == 0;
}

int main() {
    //ios_base::sync_with_stdio(0); cin.tie(0);

    int t;
    cin >> t;
    For (tt, t) {
        cout << "Case #" << tt + 1 << ": ";

        For (i, 3) {
            cin >> x[i] >> y[i];
        }
        For (i, 3) {
            int j = (i + 1) % 3;
            int dx = x[i] - x[j], dy = y[i] - y[j];
            r2[i] = dx * dx + dy * dy;
        }
        sort(r2, r2 + 3);

        if (parall()) {
            cout << "not a triangle\n";
            continue;
        }
        
        if (r2[0] == r2[1] || r2[1] == r2[2]) {
            cout << "isosceles ";
        }
        else {
            cout << "scalene ";
        }

        if (r2[0] + r2[1] > r2[2]) {
            cout << "acute ";
        }
        else if (r2[0] + r2[1] < r2[2]) {
            cout << "obtuse ";
        }
        else {
            cout << "right ";
        }

        cout << "triangle\n";
    }

    return 0;
}