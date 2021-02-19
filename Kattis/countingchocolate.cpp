// dp
// https://open.kattis.com/problems/countingchocolate
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

bool par[100010];
int a[1010];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    par[0] = 1;
    int n, sum = 0;
    cin >> n;
    For (i, n) cin >> a[i], sum += a[i];

    For (i, n) {
        for (int j = 100000; j >= a[i]; j--) {
            if (par[j - a[i]])  par[j] = 1;
        }
    }

    if (sum % 2 == 0 && par[sum / 2]) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }
    
    return 0;
}