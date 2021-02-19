//
// https://open.kattis.com/problems/platforme
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
ar<int, 3> a[110];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    For (i, n) For (j, 3) cin >> a[i][j];

    sort(a, a + n);

    ll ans = 0;
    For (i, n) {
        int l = a[i][1], r = a[i][2], y = a[i][0];
        int mxl = 0, mxr = 0;
        for (int j = 0; j < i; j++) {
            int cl = a[j][1], cr = a[j][2], cy = a[j][0];
            if (cl <= l && l < cr) {
                mxl = max(mxl, cy);
            }
            if (cl < r && r <= cr) {
                mxr = max(mxr, cy);
            }
        }
        ans += 2 * y - mxl - mxr;
    }

    cout << ans << '\n';
    
    return 0;
}