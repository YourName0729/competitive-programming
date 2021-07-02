// https://open.kattis.com/problems/veci
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

multiset<int> org;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int d;
    cin >> d;
    int d2 = d;
    while (d2) {
        org.insert(d2 % 10);
        d2 /= 10;
    }

    int cur = d + 1;
    while (1) {
        multiset<int> st;
        int cur2 = cur;
        while (cur2) {
            st.insert(cur2 % 10);
            cur2 /= 10;
        }
        if (st.size() != org.size()) {
            cout << 0 << '\n';
            return 0;
        }
        if (st == org) {
            cout << cur << '\n';
            return 0;
        }
        ++cur;
    }

    return 0;
}
