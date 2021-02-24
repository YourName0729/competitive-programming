// https://open.kattis.com/problems/askmarilyn
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

int main() {
    //ios_base::sync_with_stdio(0); cin.tie(0);

    ll cur = 1, x = 100003, y = 10009;
    int a = 0;
    For (i, 1000) {
        //cout << "A\n";
        cout << (char)(a + 'A') << '\n';
        cur = (x * cur + y) % MOD;
        
        char c;
        int d;
        cin >> c >> d;
        if (d == 1) {
            cout << c << '\n';
            cin >> d >> c;
        }
        else {
            //cout << ":" << c - 'A' << ' ' << a << '\n';
            char oth = 3 - (c - 'A') - a + 'A';
            cout << oth << '\n';
            cin >> d >> c; 
        }
        a = cur % 3;
    }

    return 0;
}
