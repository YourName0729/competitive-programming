// https://open.kattis.com/problems/quantumsuperposition
#include <bits/stdc++.h>

#define For(i, n) for (int i = 0; i < n; i++)
#define Forcase int __t = 0; cin >> __t; while (__t--)
#define pb push_back
#define ll long long
#define ull unsigned long long
#define ar array

using namespace std;

const int MOD = 1e9 + 7;
const int INF = 2147483647;

int n, n2, m1, m2;
vector<int> g[2010];

vector<int> topo;

ar<bool, 2010> r[2010];
bool vst[2010];

void dfs(int u) {
    vst[u] = 1;
    for (auto v : g[u]) {
        if (!vst[v]) dfs(v);

        For (i, 2009) {
            if (r[v][i]) r[u][i + 1] = 1;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    auto add_edge = [&](int u, int v) {
        g[u].push_back(v);
    };

    cin >> n >> n2 >> m1 >> m2;
    int u, v;
    For (i, m1) {
        cin >> u >> v, --u, --v;
        add_edge(u, v);
    }
    add_edge(n - 1, n);
    For (i, m2) {
        cin >> u >> v, --u, --v;
        add_edge(u + n, v + n);
    }

    r[n + n2 - 1][0] = 1;
    dfs(0);

    // For (i, 10) {
    //     cout << r[0][i] << ' ';
    // }
    // cout << '\n';
    
    int q;
    cin >> q;
    while (q--) {
        int k;
        cin >> k;
        cout << (r[0][k + 1]? "Yes\n" : "No\n");
    }

    return 0;
}