// https://open.kattis.com/problems/proofs
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

int n;
set<string> st;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    string s;
    getline(cin, s);
    For (i, n) {
        getline(cin, s);
        stringstream ss;
        ss << s;
        vector<string> vec;
        while (ss >> s) vec.push_back(s);
        int at = 0;
        while (vec[at] != "->") at++;
        if (at == 0) {
            st.insert(vec[1]);
        }
        else {
            For (j, at) {
                if (!st.count(vec[j])) {
                    cout << i + 1 << '\n';
                    return 0;
                }
            }
            st.insert(vec[at + 1]);
        }
    }
    cout << "correct\n";

    return 0;
}
