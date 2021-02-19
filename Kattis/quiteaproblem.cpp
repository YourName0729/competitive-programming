//
// https://open.kattis.com/problems/quiteaproblem
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

string s, t = "problem";

bool ok(int idx) {
    for (int i = 0; i < t.length(); i++) {
        if (idx + i >= s.length())  return 0;
        char cur = s[idx + i];
        if (cur != t[i] && cur != t[i] + 'A' - 'a')  return 0;
    }
    return 1;
}

int main() {
    //ios_base::sync_with_stdio(0); cin.tie(0);

    while (getline(cin, s)) {
        bool flg = 0;
        for (int i = 0; i < s.length(); i++) {
            if (ok(i)) {
                flg = 1;
                break;
            }
        }
        if (flg) cout << "yes\n";
        else cout << "no\n";
    }

    return 0;
}