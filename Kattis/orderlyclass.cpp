// https://open.kattis.com/problems/orderlyclass
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

string a, b;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> a >> b;
    int l = 0, r = a.length() - 1;
    while (l < a.length() && a[l] == b[l]) ++l;
    while (r >= 0 && a[r] == b[r]) --r;

    for (int i = 0; i < r - l + 1; ++i) {
        if (a[l + i] != b[r - i]) {
            cout << "0";
            return 0;
        }
    }

    int i = 1;
    for (; l - i >= 0 && r + i < a.length(); ++i) {
        if (a[l - i] != a[r + i]) {
            cout << i << '\n';
            return 0;
        }
    }
    cout << i << '\n';

    return 0;
}
