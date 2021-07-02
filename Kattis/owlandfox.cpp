// https://open.kattis.com/problems/owlandfox
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

multiset<int> org;

int f(int d) {
    int re = 0;
    while (d) {
        re += d % 10;
        d /= 10;
    }
    return re;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int d;
    
    Forcase {
        cin >> d;
        
        bool flg = 0;
        for (int i = d - 1; i >= 0; --i) {
            if (f(i) + 1 == f(d)) {
                cout << i << '\n';
                flg = 1;
                break;
            }
        }
        if (!flg) cout << 0 << '\n';
    }
    

    return 0;
}
