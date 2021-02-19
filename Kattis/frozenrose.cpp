// graph_traversal DFS
// https://open.kattis.com/problems/frozenrose
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

int n;
vector<ar<int, 2>> g[1010];

int cost(int u, int p) {

    int re = 0;
    for (ar<int, 2> pr : g[u]) {
        if (pr[0] == p)  continue;
        if (g[pr[0]].size() > 1)    re += min(pr[1], cost(pr[0], u));
        else    re += pr[1];
    }
    return re;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int s;
    while (cin >> n >> s) {
        For (i, n + 1) {
            g[i].clear();
        }

        For (i, n - 1) {
            int u, v, w;
            cin >> u >> v >> w;
            g[u].push_back({v, w});
            g[v].push_back({u, w});
        }

        cout << cost(s, -1) << '\n';
    }



    return 0;
}
