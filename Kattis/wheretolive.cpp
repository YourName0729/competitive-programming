// optimization
// https://open.kattis.com/problems/wheretolive
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
int ax[1010], ay[1010];
int ansx, ansy;

double dist(int x, int y) {
    double re = 0;
    For (i, n) {
        int dx = x - ax[i], dy = y - ay[i];
        re += sqrt(dx * dx + dy * dy);
    }
    return re;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    while (cin >> n && n) {
        For (i, n)  cin >> ax[i] >> ay[i];
        int sx = 0, sy = 0;
        For (i, n)  sx += ax[i], sy += ay[i];
        double cx = sx / (double)n, cy = sy / (double)n;
        ansx = cx, ansy = cy;
        if (cx - (int)cx > 0.5) ansx++;
        if (cy - (int)cy > 0.5) ansy++;
        cout << ansx << ' ' << ansy << '\n';
    }

    return 0;
}