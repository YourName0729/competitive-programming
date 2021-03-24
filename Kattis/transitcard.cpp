// https://open.kattis.com/problems/transitcard
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
 
#define For(i, n) for (int i = 0; i < n; ++i)
#define Forcase int __t = 0; cin >> __t; while (__t--)
#define ll long long
#define ar array
 
using namespace std;
using namespace __gnu_pbds;
 
template<class Type> using indexed_set=tree<Type,null_type,less<Type>,rb_tree_tag,tree_order_statistics_node_update>;
 
const int MOD = 1e9 + 7;
const int INF = 2147483647;
const ll IINF = 1e18;
const double eps = 1e-12;

int l, t, n;
int p[110], d[110];
ar<int, 2> a[5010];
ll dp[5010];
int cdp[1000010];


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> l;
    For (i, l) cin >> p[i];
    For (i, l - 1) cin >> d[i];

    cin >> t >> n;
    a[0][0] = 1, a[n][1] = t;
    For (i, n) {
        cin >> a[i][1] >> a[i + 1][0];
        a[i][1]--;
        a[i + 1][0]++;
    }   
    n++;

    int cnt = d[0];
    int idx = 0;
    cdp[0] = 0;
    for (int i = 1; i < 1000010; i++) {
        cdp[i] = cdp[i - 1] + p[idx];
        cnt--;
        if (cnt == 0) {
            idx++;
            if (idx == l - 1) cnt = MOD;
            else cnt = d[idx];
        }
    }

    // For (i, t + 1) {
    //     cout << cdp[i] << ' ';
    // }
    // cout << '\n';
    // For (i, n) {
    //     cout << a[i][0] << ' ' << a[i][1] << '\n';
    // }

    dp[0] = cdp[a[0][1] - a[0][0] + 1];
    for (int i = 1; i < n; i++) {
        dp[i] = cdp[a[i][1]];
        for (int j = i; j >= 1; j--) {
            dp[i] = min(dp[i], dp[j - 1] + cdp[a[i][1] - a[j][0] + 1]);
        }
    }
    cout << dp[n - 1] << '\n';

    return 0;
}
