// sorting_and_searching
// https://open.kattis.com/problems/kattissquest
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

set<tuple<int, int, int>> st;

int main() {
    //ios_base::sync_with_stdio(0); cin.tie(0);

    int q;
    cin >> q;
    while (q--) {
        string s;
        cin >> s;
        if (s == "add") {
            int e, g;
            cin >> e >> g;
            st.insert({-e, -g, q});
        }
        else {
            int x;
            cin >> x;
            ll ans = 0;
            while (!st.empty()) {
                auto cur = st.lower_bound({-x, -1e6, 0});
                if (cur == st.end())    break;
                ans += -get<1>(*cur);
                x -= -get<0>(*cur);
                st.erase(cur);
            }
            cout << ans << '\n';
        }
    }

    return 0;
}