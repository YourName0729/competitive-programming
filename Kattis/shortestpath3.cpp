// Bellman-Ford DFS
// https://open.kattis.com/problems/shortestpath3
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
vector<ar<int, 2>> g[1010];
int dist[1010];
int dist2[1010];
bool vst[1010];

void dfs(int u) {
    vst[u] = 1;
    for (ar<int, 2> p : g[u]) {
        if (!vst[p[0]]) dfs(p[0]);
    }
}

void bf(int s) {
    For (i, n) {
        dist[i] = MOD;
    }

    dist[s] = 0;
    For (i, n - 1) {
        For (u, n) {
            for (ar<int, 2> p : g[u]) {
                int v = p[0], w = p[1];
                if (dist[u] != MOD)
                    dist[v] = min(dist[v], dist[u] + w);    
            }
        }
    }

    For (i, n)  dist2[i] = dist[i];
    For (u, n) {
        for (ar<int, 2> p : g[u]) {
            int v = p[0], w = p[1];
            //cout << dist[u] << ' ' << dist[v] << ' ' << w << '\n';
            if (dist2[u] != MOD)
                dist2[v] = min(dist2[v], dist2[u] + w);
        }
    }

    For (i, n) {
        //cout << dist2[i] << ' ' << dist[i] << '\n';
        if (dist2[i] != dist[i] && !vst[i]) {
            dfs(i);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int q, s, t;
    while (cin >> n >> m >> q >> s && !(!n && !m && !q && !s)) {
        For (i, n)  g[i].clear();
        For (i, n)  vst[i] = 0;
        For (i, m) {
            int u, v, w;
            cin >> u >> v >> w;
            g[u].push_back({v, w});
        }

        bf(s);

        For (i, q) {
            cin >> t;
            if (dist[t] == MOD) {
                cout << "Impossible\n";
            }
            else if (vst[t]) {
                cout << "-Infinity\n";
            }   
            else {
                cout << dist[t] << '\n';
            }
        }
        //cout << '\n';
    }
    


    return 0;
}