// DFS
// https://open.kattis.com/problems/brexit
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
vector<int> g[200010];
int deg[200010], mdeg[200010];
bool vst[200010];

void dfs(int u) {
    vst[u] = 1;
    for (auto v : g[u]) {
        deg[v]--;
        if (2 * deg[v] <= mdeg[v] && !vst[v]) {
            dfs(v);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int s, l;
    cin >> n >> m >> s >> l;
    For (i, m) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
        deg[u]++, mdeg[u]++, deg[v]++, mdeg[v]++;
    }

    dfs(l);

    if (vst[s]) {
        cout << "leave\n";
    }
    else {
        cout << "stay\n";
    }

    return 0;
}