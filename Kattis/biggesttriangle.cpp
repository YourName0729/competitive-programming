// computational_geometry brute_force
// https://open.kattis.com/problems/biggesttriangle
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

int n;
ar<int, 4> a[110];

bool para(int i, int j) {
    int ux = a[i][2] - a[i][0], uy = a[i][3] - a[i][1];
    int vx = a[j][2] - a[j][0], vy = a[j][3] - a[j][1];
    return ux * vy == uy * vx;
}

double dist(ar<double, 2> p, ar<double, 2> q) {
    double dx = p[0] - q[0], dy = p[1] - q[1];
    return sqrt(dx * dx + dy * dy);
}

ar<double, 2> intc(int i, int j) {
    double A = a[i][1] - a[i][3];
    double B = a[i][2] - a[i][0];
    double C = A * a[i][0] + B * a[i][1];
    double D = a[j][1] - a[j][3];
    double E = a[j][2] - a[j][0];
    double F = D * a[j][0] + E * a[j][1];

    double Base = A * E - B * D;
    double X = C * E - B * F, Y = A * F - C * D;
    return {X / Base, Y / Base};
}

double peri(int i, int j, int k) {
    ar<double, 2> p = intc(i, j), q = intc(j, k), r = intc(k, i);
    return dist(p, q) + dist(q, r) + dist(r, p);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    For (i, n) {
        For (j, 4)  cin >> a[i][j];
    }

    double ans = -1;
    For (i, n) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                if (para(i, j) || para(j, k) || para(i, k))  continue;
                ans = max(ans, peri(i, j, k));
            }
        }
    }

    if (ans < 1) {
        cout << "no triangle\n";
    }
    else {
        cout << fixed << ans << '\n';
    }

    return 0;
}