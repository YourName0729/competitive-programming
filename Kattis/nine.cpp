// greedy
// https://open.kattis.com/problems/nine
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
const ll INF = 1e18;
const double eps = 1e-9;

ll Pow(ll d) {
    if (d == 0) return 1;
    ll re = Pow(d / 2);
    if (d % 2 == 0) {
        return re * re % MOD;
    }
    return (re * re % MOD) * 9 % MOD;
}

int main() {
    //ios_base::sync_with_stdio(0); cin.tie(0);

    Forcase {
        ll n;
        cin >> n;
        cout << Pow(n - 1) * 8 % MOD << '\n';    
    }

    

    return 0;
}