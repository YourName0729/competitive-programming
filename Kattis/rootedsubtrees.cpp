// https://open.kattis.com/problems/rootedsubtrees
#include <bits/stdc++.h>
//#include <ext/pb_ds/tree_policy.hpp>
//#include <ext/pb_ds/assoc_container.hpp>

#define For(i, n) for (int i = 0; i < n; ++i)
#define Forcase int __t = 0; cin >> __t; while (__t--)
#define ll long long
#define ull unsigned long long
#define ar array

using namespace std;
//using namespace __gnu_pbds;

//template<class Type> using indexed_set=tree<Type,null_type,less<Type>,rb_tree_tag,tree_order_statistics_node_update>;

const int MOD = 1e9 + 7;
const int INF = 2147483647;
const ll IINF = 1e18;
const double eps = 1e-12;

int n;
vector<int> g[200010];
int tin[200010], tout[200010], timer = 0;
int alog[200010][20];

void dfs(int u, int p) {
    tin[u] = timer++;

    alog[u][0] = p;
    for (int i = 1; i < 20; i++) {
        alog[u][i] = alog[alog[u][i - 1]][i - 1];
    }

    for (auto v : g[u]) {
        if (v != p) dfs(v, u);
    }
    tout[u] = timer++;
}

bool ancestor(int cur, int anc) {
    return tin[anc] <= tin[cur] && tout[cur] <= tout[anc];
}

int LCA(int x, int y) {
    if (ancestor(x, y)) return y;
    if (ancestor(y, x)) return x;

    for (int i = 19; i >= 0; i--) {
        if (!ancestor(y, alog[x][i])) x = alog[x][i];
    }
    return alog[x][0];
}

int Pow(int a, int m) {
    if (m == 0) return 1;
    int re = Pow(a, m / 2);
    if (m % 2 == 0) return re * re;
    return re * re * a;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int q;
    cin >> n >> q;
    For (i, n - 1) {
        int u, v;
        cin >> u >> v, u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(0, 0);

    while (q--) {
        int u, v;
        cin >> u >> v, u--, v--;
        if (u == v) {
            cout << n << '\n';
            continue;
        }
        int p = LCA(u, v);
        ll l = 0;
        for (int i = 19; i >= 0; i--) {
            if (ancestor(alog[u][i], p) && !ancestor(p, alog[u][i])) {
                l += Pow(2, i);
                u = alog[u][i];
            }
        }
        if (u != p) l++;
        for (int i = 19; i >= 0; i--) {
            if (ancestor(alog[v][i], p) && !ancestor(p, alog[v][i])) {
                l += Pow(2, i);
                v = alog[v][i];
            }
        }
        if (v != p) l++;
        cout << n + l * (l + 1) / 2 << '\n';
    }
    

    return 0;
}
