// greedy
// https://open.kattis.com/problems/alicedigital
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

int n, m;
int a[100010];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    Forcase {
        cin >> n >> m;
        For (i, n)  cin >> a[i];

        int ans = 0;
        For (i, n) {
            if (a[i] == m) {
                int sum = m;
                for (int j = i + 1; j < n && a[j] > m; j++) {
                    sum += a[j];
                }
                for (int j = i - 1; j >= 0 && a[j] > m; j--) {
                    sum += a[j];
                }
                ans = max(ans, sum);
            }
        }


        cout << ans << '\n';
    }

    return 0;
}