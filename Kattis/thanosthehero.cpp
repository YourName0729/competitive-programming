// 
// https://open.kattis.com/problems/thanosthehero
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

int n, m;
int a[50010];

int main() {
    //ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    For (i, n)  cin >> a[i];
    int prv = a[n - 1];
    ll ans = 0;
    for (int i = n - 2; i >= 0; i--) {
        if (a[i] >= prv) {
            ans += a[i] - prv + 1;
            prv = prv - 1;
        }
        else {
            prv = a[i];
        }
    }

    if (prv < 0) {
        cout << "1\n";
    }
    else {
        cout << ans << '\n';
    }
    


    return 0;
}