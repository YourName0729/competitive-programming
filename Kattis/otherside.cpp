// case_considering
// https://open.kattis.com/problems/otherside
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
const double eps = 1e-9;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (d == 0) {
        cout << "NO\n";
        return 0;
    }
    if (a + b == 0 || b + c == 0 || b == 0 || a + c == 0) {
        cout << "YES\n";
        return 0;
    }
    if (a == 0) {
        a = b, b = c, c = 0;
    }
    if (c == 0) {
        if (min(a, b) <= d - 1 || (a == d && b <= 2 * d) || (a <= 2 * d && b == d)) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
        return 0;
    }
    if (max(a, max(b, c)) <= d) {
        cout << "YES\n";
        return 0;
    }
    if (b <= d - 1 || a + c <= d - 1) {
        cout << "YES\n";
        return 0;
    }
    if (b == d && a + c <= 2 * d) {
        cout << "YES\n";
        return 0;
    }
    if (b <= 2 * d && a + c <= d) {
        cout << "YES\n";
        return 0;
    }
    cout << "NO\n";


    return 0;
}
