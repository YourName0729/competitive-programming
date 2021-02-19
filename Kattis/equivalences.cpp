// scc DAG
// https://open.kattis.com/problems/equivalences
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
vector<int> g[20010], tg[20010];
vector<int> order;
bool vst[20010];
int scc[20010];
bool ideg[20010], odeg[20010];

void dfs(int u) {
    vst[u] = 1;
    for (auto v : g[u]) if (!vst[v]) dfs(v);
    order.push_back(u);
}

void dfs2(int u, int c) {
    vst[u] = 1;
    scc[u] = c;
    for (auto v : tg[u]) if (!vst[v]) dfs2(v, c);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    Forcase {
        cin >> n >> m;
        For (i, n)  g[i].clear(), tg[i].clear();
        For (i, m) {
            int u, v;
            cin >> u >> v, u--, v--;
            g[u].push_back(v);
            tg[v].push_back(u);
        }

        order.clear();
        For (i, n)  vst[i] = 0;
        For (i, n)  if (!vst[i]) dfs(i);

        int C = 0;
        For (i, n)  vst[i] = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (!vst[order[i]]) dfs2(order[i], C++);
        }

        For (i, C)  odeg[i] = ideg[i] = 0;
        For (u, n) {
            for (auto v : g[u]) {
                if (scc[u] != scc[v]) {
                    ideg[scc[v]] = odeg[scc[u]] = 1;
                }
            }
        }

        int cnti = 0, cnto = 0;
        For (i, C) {
            if (ideg[i]) cnti++;
            if (odeg[i]) cnto++;
        }

        if (C == 1) {
            cout << "0\n";
        }
        else {
            cout << max(C - cnti, C - cnto) << '\n';    
        }
        
    }   

    return 0;
}