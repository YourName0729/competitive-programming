// DFS
// https://open.kattis.com/problems/dominoes2
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
vector<int> g[10010];
bool vst[10010];

void dfs(int u) {
    if (vst[u]) return;
    vst[u] = 1;
    for (auto v : g[u]) dfs(v);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    Forcase {
        int l;
        cin >> n >> m >> l;
        For (i, n + 1)  g[i].clear();
        For (i, n + 1)  vst[i] = 0;

        For (i, m) {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
        }
        For (i, l) {
            int u;
            cin >> u;
            dfs(u);
        }

        int ans = 0;
        For (i, n + 1) {
            if (vst[i]) ans++;
        }

        cout << ans << '\n';
    }
    

    return 0;
}