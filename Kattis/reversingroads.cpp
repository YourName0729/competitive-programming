// scc
// https://open.kattis.com/problems/reversingroads
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

int n, m;
bool g[60][60];
vector<ar<int, 2>> g2;
bool vst[60];
vector<int> order;

void dfs1(int u) {
    vst[u] = 1;
    For (v, n) {
        if (g[u][v] && !vst[v]) dfs1(v);
    }
    order.push_back(u);
}

void dfs2(int u) {
    vst[u] = 1;
    For (v, n) {
        if (g[v][u] && !vst[v]) dfs2(v);
    }
}

bool scc1() {
    order.clear();
    For (i, n)  vst[i] = 0;
    For (i, n) if (!vst[i]) dfs1(i);
 
    For (i, n) vst[i] = 0;
    dfs2(order[n - 1]);
    For (i, n) if (!vst[i]) return 0;
    return 1;
}

void solve() {
    if (scc1()) {
        cout << "valid\n";
        return;
    }

    for (ar<int, 2> p : g2) {
        int u = p[0], v = p[1];
        swap(g[u][v], g[v][u]);
        if (scc1()) {
            cout << u << ' ' << v << '\n';
            return;
        }
        swap(g[u][v], g[v][u]);
    }

    cout << "invalid\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t = 1;
    while (cin >> n >> m) {  
        For (i, n) For (j, n) g[i][j] = 0;
        g2.clear();
        For (i, m) {
            int u, v;
            cin >> u >> v;
            g[u][v] = 1;
            g2.push_back({u, v});
        }

        cout << "Case " << t++ << ": ";
        solve();
    }

    return 0;
}