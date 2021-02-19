// Fenwick_tree
// https://open.kattis.com/problems/fenwick
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

int n;
ll a[5000010];

int lowbit(int x) {
    return x & -x;
}

void modify(int pos, ll val) {
    for (int i = pos; i <= n; i += lowbit(i)) {
        a[i] += val;
    }
}

ll query(int pos) {
    ll ans = 0;
    for (int i = pos; i; i -= lowbit(i)) {
        ans += a[i];
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int q;
    cin >> n >> q;
    For (i, q) {
        char c;
        cin >> c;
        if (c == '+') {
            int pos, val;
            cin >> pos >> val;
            modify(pos + 1, val);
        }
        else {
            int pos;
            cin >> pos;
            cout << query(pos) << '\n';
        }
    }

    return 0;
}