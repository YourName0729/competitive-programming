// https://open.kattis.com/problems/pleasegofirst
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

int n;
string s;
map<char, int> mp, cnt;
vector<int> odr;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    Forcase {
        mp.clear();
        cnt.clear();
        odr.clear();
        cin >> n >> s;
        For (i, n) {
            mp[s[i]] = i;
            ++cnt[s[i]];
        }

        set<char> st;
        for (int i = n - 1; i >= 0; --i) {
            if (!st.count(s[i])) {
                st.insert(s[i]);
                odr.push_back(s[i]);
            }
        }

        ll org = 0, aft = 0;
        for (auto c : st) {
            org += mp[c] * cnt[c];
        }
        int acc = 0;
        for (int i = 0; i < odr.size(); ++i) {
            int idx = n - 1 - acc;
            aft += idx * cnt[odr[i]];
            acc += cnt[odr[i]];
        }
        cout << (org - aft) * 5 << '\n';
    }


    return 0;
}
