//
// https://open.kattis.com/problems/drmmessages
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


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    string s;
    cin >> s;
    int sum = 0;
    For (i, s.length() / 2) {
        sum += s[i] - 'A';
    }
    For (i, s.length() / 2) {
        s[i] = (s[i] + sum - 'A') % 26 + 'A';
    }
    sum = 0;
    for (int i = s.length() / 2; i < s.length(); i++) {
        sum += s[i] - 'A';
    }
    for (int i = s.length() / 2; i < s.length(); i++) {
        s[i] = (s[i] + sum - 'A') % 26 + 'A';
    }
    For (i, s.length() / 2) {
        s[i] = (s[i] + s[i + s.length() / 2] - 'A' - 'A') % 26 + 'A';
        cout << s[i];
    }
    cout << '\n';

    return 0;
}
