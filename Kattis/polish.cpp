// string_processing
// https://open.kattis.com/problems/polish
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

stringstream ss;

int exp() {
    string s;
    ss >> s;
    if (s.length() == 1) {
        char c = s[0];
        if (c == '+' || c == '-' || c == '*') {
            int a, b;
            string sa, sb;
            bool va = 1, vb = 1;
            try {
                a = exp();
            }
            catch (string e) {
                sa = e;
                va = 0;
            }
            try {
                b = exp();
            }
            catch (string e) {
                sb = e;
                vb = 0;
            }
            if (va && vb) {
                if (c == '+')   return a + b;
                if (c == '-')   return a - b;
                if (c == '*')   return a * b;
            }
            if (va) {
                s += ' ' + to_string(a);
            }
            else {
                s += ' ' + sa;
            }
            if (vb) {
                s += ' ' + to_string(b);
            }
            else {
                s += ' ' + sb;
            }
            throw s;
        }
        else if ('a' <= c && c <= 'z') {
            throw s;
        }
    }
    return stoi(s);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    string s;
    int cnt = 1;
    while (getline(cin, s)) {
        cout << "Case " << cnt++ << ": ";
        ss.clear();
        ss << s;
        int ans;
        try {
            ans = exp();
            cout << ans << '\n';
        }
        catch (string s) {
            cout << s << '\n';
        }
    }
    
    return 0;
}