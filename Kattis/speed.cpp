// binary_searching
// https://open.kattis.com/problems/speed
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
int d[1010], s[1010];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> t;
    For (i, n) {
        cin >> d[i] >> s[i];
    }
    double l = -s[0], r = 1e9;
    For (i, n) l = max(l, (double)-s[i]);
    while (r - l > 1e-9) {
        double mid = (l + r) / 2;
        double sum = 0;
        For (i, n)  sum += d[i] / (s[i] + mid);
        if (sum < t) {
            r = mid;
        }
        else {
            l = mid;
        }
    }

    cout << fixed << l << '\n';

    return 0;
}