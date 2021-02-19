// simulation
// https://open.kattis.com/problems/imperfectgps
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

int n, t;
vector<ar<double, 3>> a;

double dist(vector<ar<double, 3>>& vec) {
    double re = 0;
    For (i, vec.size() - 1) {
        double dx = vec[i][0] - vec[i + 1][0];
        double dy = vec[i][1] - vec[i + 1][1];
        re += sqrt(dx * dx + dy * dy);
    }
    return re;
}   

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> t;
    a.resize(n);

    For (i, n)  cin >> a[i][0] >> a[i][1] >> a[i][2];
    int i = 0, cur = 0;
    vector<ar<double, 3>> vec;
    while (i < n) {
        while (i < n && a[i][2] < cur)  i++;
        if (i == n) break;
        if (a[i][2] == cur) {
            vec.push_back({a[i][0], a[i][1], (double)cur});
        }
        else {
            double dt = a[i][2] - a[i - 1][2];
            double f1 = (a[i][2] - cur) / dt;
            double f2 = (cur - a[i - 1][2]) / dt;
            double x = f1 * a[i - 1][0] + f2 * a[i][0];
            double y = f1 * a[i - 1][1] + f2 * a[i][1];
            vec.push_back({x, y, (double)cur});
        }
        cur += t;
    }
    if (cur > a[n - 1][2]) vec.push_back({a[n - 1][0], a[n - 1][1], a[n - 1][2]});

    double d1 = dist(a), d2 = dist(vec);

    cout << fixed << setprecision(12) << abs(d1 - d2) / d1 * 100 << '\n';

    return 0;
}