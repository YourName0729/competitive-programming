//
// https://open.kattis.com/problems/heirsdilemma
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

set<pair<int, int>> st1, st2;

bool ok(int d) {
    set<int> st;
    int dd = d;
    while (dd) {
        st.insert(dd % 10);
        dd /= 10;
    }
    if (st.count(0)) return 0;
    if (st.size() != 6) return 0;
    for (auto e : st)   if (d % e != 0) return 0;
    return 1;
}

int main() {
    //ios_base::sync_with_stdio(0); cin.tie(0);

    int l, r;
    cin >> l >> r;
    int ans = 0;
    for (int i = l; i <= r; i++) {
        if (ok(i))  ans++;
    }
    cout << ans << '\n';


    return 0;
}
