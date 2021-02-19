//
// https://open.kattis.com/problems/piglatin
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

char cs[] = {'a', 'e', 'i', 'o', 'u', 'y'};

bool vol(char c) {
    For (i, 6)  if (cs[i] == c) return 1;
    return 0;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    string s;
    while (getline(cin, s)) {
        stringstream ss;
        ss << s;
        while (ss >> s) {
            int f = 0;
            while (f < s.length() && !vol(s[f])) f++;
            for (int i = f; i < s.length(); i++) {
                cout << s[i];
            }
            For (i, f)  cout << s[i];
            if (f == 0) cout << 'y';
            cout << "ay ";
        }
        cout << '\n';
    }
    
    return 0;
}