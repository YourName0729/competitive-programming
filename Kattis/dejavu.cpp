// sorting_and_searching
// https://open.kattis.com/problems/dejavu
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
ar<int, 2> a[100010];
map<int, ll> xs, ys;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    For (i, n) {
        cin >> a[i][0] >> a[i][1];
        xs[a[i][0]]++, ys[a[i][1]]++;
    }
    ll ans = 0;
    For (i, n) {
        ans += (xs[a[i][0]] - 1) * (ys[a[i][1]] - 1);
    }
    cout << ans << '\n';

    return 0;
}