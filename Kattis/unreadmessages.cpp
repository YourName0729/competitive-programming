// https://open.kattis.com/problems/unreadmessages
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

int n, m;
map<int, int> mp;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    
    ll tst = 0;
    ll sum = 0;
    For (i, m) {
        int d;
        cin >> d;
        sum += n - 1;
        if (mp.count(d)) {
            sum -= tst - mp[d] - 1;
        }
        else {
            sum -= tst;
        }
        mp[d] = tst;
        tst++;
        cout << sum << '\n';
    }

    return 0;
}
