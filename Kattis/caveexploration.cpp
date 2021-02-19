// scc
// https://open.kattis.com/problems/caveexploration
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
vector<int> g[10010];
bool vst[10010];
int tin[10010], low[10010];
bool fld[10010];
int timer = 0;

void dfs2(int u, int f) {
    fld[u] = 1;
    for (auto v : g[u]) {
        if (v == f) continue;
        if (!fld[v])    dfs2(v, u);
    }
}

void dfs(int u, int f) {
    low[u] = tin[u] = timer++;
    vst[u] = 1;
    for (auto v : g[u]) {
        if (v == f) continue;
        if (vst[v]) {
            low[u] = min(low[u], tin[v]);
        }
        else {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] > tin[u]) {
                dfs2(v, u);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    For (i, m) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(0, -1);

    int ans = 0;
    For (i, n)  if (!fld[i]) ans++;
    cout << ans << '\n';

    return 0;
}