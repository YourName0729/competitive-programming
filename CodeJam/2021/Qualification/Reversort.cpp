// .
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

int n;
int a[110];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int cases = 0;
    Forcase {
        cases++;
        cin >> n;
        For (i, n)  cin >> a[i];

        int ans = 0;
        For (i, n - 1) {
            int j = i;
            for (int k = i; k < n; k++) {
                if (a[k] < a[j]) j = k;
            }
            ans += j - i + 1;

            reverse(a + i, a + j + 1);

            //For (j, n)  cout << a[j] << ' ';
            //cout << '\n';
        }

        

        cout << "Case #" << cases << ": " << ans << '\n';
    }

    return 0;
}
