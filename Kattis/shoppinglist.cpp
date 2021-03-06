// sorting_and_searching
// https://open.kattis.com/submissions/6766335
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

int n, m;
map<string, int> mp;
set<string> st;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;

    For (i, n) {
        For (j, m) {
            string s;
            cin >> s;
            st.insert(s);
            //mp[s]++;
        }
        for (auto s : st)    mp[s]++;
        st.clear();
    }
    
    vector<string> ans;
    for (auto p : mp) if (p.second == n)    ans.push_back(p.first);
    cout << ans.size() << '\n';
    for (string& s : ans) cout << s << '\n';

    return 0;
}