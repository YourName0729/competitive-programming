//
// https://open.kattis.com/problems/luhnchecksum
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

    Forcase {
        string s;
        cin >> s;
        int ans = 0;
        for (int i = s.length() - 1; i >= 0; i--) {
            if ((s.length() - i) % 2 == 0) {
                int d = 2 * (s[i] - '0');
                d = d / 10 + d % 10;
                ans += d;    
            }
            else {
                ans += s[i] - '0';
            }
        }
        //cout << ans << '\n';
        if (ans % 10) {
            cout << "FAIL\n";
        }
        else {
            cout << "PASS\n";
        }
    }

    return 0;
}
