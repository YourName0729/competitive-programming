//
// https://open.kattis.com/problems/piperotation
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
const double eps = 1e-12;

int n, m;
char tb[110][110];
bool up[110];

bool ok() {
    For (i, n) {
        bool left = 0;
        For (j, m) {
            char cur = tb[i][j];
            if (cur == 'A') {
                if (up[j] || left)  return 0;
                up[j] = left = 0;
            }
            else if (cur == 'B') {
                if (up[j] && left)  return 0;
            }
            else if (cur == 'C') {
                left = !left, up[j] = !up[j];
            }
            else if (cur == 'D') {
                if (!up[j] || !left) return 0;
                up[j] = left = 1;
            }
        }
        if (left)   return 0;
    }
    For (i, m)  if (up[i])  return 0;
    return 1;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    For (i, n)  For (j, m)  cin >> tb[i][j];
    
    if (ok()) {
        cout << "Possible\n";
    }
    else {
        cout << "Impossible\n";
    }

    return 0;
}