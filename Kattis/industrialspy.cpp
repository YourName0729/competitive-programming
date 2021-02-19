//
// https://open.kattis.com/problems/industrialspy
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

set<int> st;

bool prime(int n) {
    if (n <= 1) return 0;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int main() {
    //ios_base::sync_with_stdio(0); cin.tie(0);

    Forcase {
        st.clear();
        string s;
        cin >> s;
        vector<int> p;
        For (i, s.length()) p.push_back(i);
        do {
            // cout << "p: ";
            // For (i, s.length()) cout << p[i] << ' ';
            // cout << '\n';
            int cur = 0;
            For (i, s.length()) {
                cur *= 10;
                cur += s[p[i]] - '0';
                st.insert(cur);
            } 
            //st.insert(cur);
        } while (next_permutation(p.begin(), p.end()));

        int ans = 0;
        for (auto u : st) {
            //cout << u << ' ';
            if (prime(u)) {
                ans++;
                //cout << "y";
            }
            //cout << '\n';
        }
        cout << ans << '\n';
    }

    return 0;
}