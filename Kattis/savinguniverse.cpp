// https://open.kattis.com/problems/savinguniverse
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
const unsigned ll IINF = 1e18;
const double eps = 1e-12;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    For (tt, t) {
        int n, m;
        cout << "Case #" << tt + 1 << ": ";
        cin >> n;
        string s;
        getline(cin, s);
        For (i, n) getline(cin, s);
        cin >> m;
        set<string> st;
        int ans = 0;
        getline(cin, s);
        For (i, m) {
            getline(cin, s);
            st.insert(s);
            if (st.size() == n) {
                ++ans;
                st.clear();
                st.insert(s);
            }
        }
        cout << ans << '\n';
    }

    return 0;
}
