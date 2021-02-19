//
// https://open.kattis.com/problems/perket
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

int n;
int a[10], b[10];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    For (i, n) {
        cin >> a[i] >> b[i];
    }

    int ans = MOD;
    for (int i = 1; i < (1 << n); i++) {
        int A = 1, B = 0;
        For (j, n) {
            if (i & (1 << j)) {
                A *= a[j], B += b[j];
            }
        }
        ans = min(ans, abs(A - B));
    }

    cout << ans << '\n';
    

    return 0;
}