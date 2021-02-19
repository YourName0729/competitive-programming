// dp
// https://open.kattis.com/problems/batmanacci
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

ull dp[90];

char f(ull k, int n) {
    //cout << k << ' ' << n << '\n';
    if (n <= 2) return "AN"[n % 2];
    return (k <= dp[n - 2])? f(k, n - 2) : f(k - dp[n - 2], n - 1);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    ull k;
    int n;
    dp[0] = 0, dp[1] = 1;
    for (int i = 2; i < 88; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    cin >> n >> k;
    n = min(89, n);
    cout << f(k, n) << '\n';

    return 0;
}