//
// https://open.kattis.com/problems/boatparts
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
const ll INF = 1e18;



int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int p, n;
    cin >> p >> n;
    set<string> st;
    For (i, n) {
        string s;
        cin >> s;
        st.insert(s);
        if (st.size() == p) {
            cout << i + 1;
            return 0;
        }
    }
    cout << "paradox avoided\n";
    
    return 0;
}
