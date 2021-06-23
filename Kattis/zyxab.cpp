// https://open.kattis.com/problems/zyxab
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
vector<string> vec;

bool cmp(string& a, string& b) {
    if (a.length() != b.length()) return a.length() > b.length();
    return a < b;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> n;
    For (i, n) {
        string s;
        cin >> s;
        if (s.length() <= 4) continue;
        set<char> st;
        bool flg = 0;
        for (auto c : s) {
            if (st.count(c)) {
                flg = 1;
                break;
            } 
            st.insert(c);
        }
        if (flg) continue;
        vec.push_back(s); 
    }

    if (vec.empty()) {
        cout << "neibb!\n";
    }
    else {
        sort(vec.begin(), vec.end(), cmp);
        cout << vec.back() << '\n';
    }

    

    return 0;
}
