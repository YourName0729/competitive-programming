// https://open.kattis.com/problems/polymul1
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

int a[1010], b[1010], c[1010];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    Forcase {
        int n, m;
        cin >> n;
        For (i, n + 1) cin >> a[i];
        cin >> m;
        For (i, m + 1) cin >> b[i];

        For (i, n + m + 1) c[i] = 0;
        For (i, n + 1) {
            For (j, m + 1) {
                c[i + j] += a[i] * b[j];
            }
        }

        cout << n + m << '\n';
        For (i, n + m + 1) {
            cout << c[i] << ' ';
        }
        cout << '\n';
    }
    

    return 0;
}
