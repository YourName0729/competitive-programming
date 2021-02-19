//
// https://open.kattis.com/problems/ninetynine
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

int dp[100];

int f(int cur) {
    if (dp[cur] != -1)    return dp[cur];
    if (f(cur + 1) == 0)    return dp[cur] = 1;
    if (f(cur + 2) == 0)    return dp[cur] = 2;
    return dp[cur] = 0;
}

int main() {
    //ios_base::sync_with_stdio(0); cin.tie(0);

    For (i, 100)    dp[i] = -1;
    dp[99] = 0;
    dp[98] = 1, dp[97] = 2; 

    cout << 1 << endl;
    int n;
    while (cin >> n) {
        int d = f(n)? f(n) : rand() % 2 + 1;
        cout << n + d << endl;
        if (n + d == 99)    return 0;
    }

    return 0;
}