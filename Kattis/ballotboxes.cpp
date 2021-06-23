// https://open.kattis.com/problems/ballotboxes
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
const ll IINF = 1e18;
const double eps = 1e-12;

int n, b;
int a[500010];

bool ok(int mid) {
    int cnt = 0;
    For (i, n) {
        cnt += (a[i] - 1) / mid + 1;
    }
    return cnt <= b;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    while (cin >> n >> b && n != -1) {
        int l = 1, r = 0;
        For (i, n) cin >> a[i], r = max(r, a[i]);

        while (l < r) {
            int mid = (l + r) / 2;
            if (ok(mid)) {
                r = mid;
            }
            else {
                l = mid + 1;
            }
        }    
        cout << l << '\n';
    }

    return 0;
}
