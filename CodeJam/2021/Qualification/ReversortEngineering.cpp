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

int n, c;
bool rev[110];
int a[110];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int cases = 0;
    Forcase {
        cases++;
        cin >> n >> c;
        if (c < n - 1 || c >= n * (n + 1) / 2) {
            cout << "Case #" << cases << ": " << "IMPOSSIBLE\n";
            continue;
        }

        for (int i = 0; i < n - 1; i++) {
            if (c - (n - i - 2) >= n - i) {
                rev[i] = 1;
                c -= n - i;
            }
            else {
                rev[i] = 0;
                c--;
            }
        }

        a[n - 1] = n;
        for (int i = n - 2; i >= 0; i--) {
            a[i] = i + 1;
            if (rev[i]) {
                reverse(a + i, a + n);
            }
        }

        cout << "Case #" << cases << ": ";
        For (i, n) {
            cout << a[i] << ' ';
        }
        cout << '\n';
    }

    return 0;
}
