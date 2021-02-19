//
// https://open.kattis.com/problems/spellingbee
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


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    string s, del;
    char c;
    cin >> c >> del;
    del += c;
    while (cin >> s) {
        if (s.length() < 4) continue;
        set<char> st;
        For (i, s.length()) {
            st.insert(s[i]);
        }
        if (!st.count(c)) continue;
        For (i, del.size()) {
            if (st.count(del[i]))   st.erase(del[i]);
        }
        if (st.empty()) cout << s << '\n';
    }

    return 0;
}