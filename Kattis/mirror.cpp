//
// https://open.kattis.com/problems/mirror
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

int n, m;
char c[20][20];


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t;
    cin >> t;
    For (k, t) {
        cin >> n >> m;
        cout << "Test " << k + 1 << '\n';
        For (i, n)  For (j, m)  cin >> c[i][j];
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                cout << c[i][j];
            }
            cout << '\n';
        }
    }
    
    return 0;
}
