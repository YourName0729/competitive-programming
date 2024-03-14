// https://open.kattis.com/problems/listentoyourboss
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

int n, m;
vector<int> g[100010];
int tin[100010], tout[100010];
int t = 0;

void dfs(int u) {
    tin[u] = t++;
    for (auto v : g[u]) dfs(v);
    tout[u] = t++;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    cin >> n >> m;
    for (int i = 0, x; i < n - 1; ++i) {
        cin >> x;
        g[x].push_back(i + 2);
    }

    dfs(1);

    for (int i = 0, u, v; i < m; ++i) {
        cin >> u >> v;
        cout << (tin[v] < tin[u] && tout[v] > tout[u]? "NO" : "YES") << '\n';
    }

    return 0;
}