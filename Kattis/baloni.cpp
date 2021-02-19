// greedy
// https://open.kattis.com/problems/baloni
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

int n;
int a[1000010];
int h[1000010];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    int mx = 0;
    For (i, n)  cin >> a[i];
    for (int i = n - 1; i >= 0; i--) {
        int d = a[i];
        mx = max(d, mx);
        h[d]++;
        if (h[d - 1])   h[d - 1]--;
    }

    int ans = 0;
    For (i, mx + 1) {
        ans += h[i];
    }
    
    cout << ans << '\n';

    return 0;
}