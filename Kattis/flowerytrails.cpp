// https://open.kattis.com/problems/flowerytrails
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
vector<ar<int, 2>> g[10010];
bool vst[10010];
int dis[10010];

bool mnv[10010];

int dijk(int s, int e) {
    For (i, n) dis[i] = MOD;
    dis[s] = 0;
    priority_queue<ar<int, 2>, vector<ar<int, 2>>, greater<ar<int, 2>>> pq;
    pq.push({0, s});
    while (pq.size()) {
        auto [_, u] = pq.top();
        pq.pop();
        vst[u] = 1;
        for (auto [v, d] : g[u]) {
            if (!vst[v] && dis[u] + d < dis[v]) {
                pq.push({dis[u] + d, v});
                dis[v] = dis[u] + d;
            }
        }
    }
    return dis[e];
}

void dfs(int u) {
    mnv[u] = 1;
    for (auto [v, w] : g[u]) {
        if (!mnv[v] && dis[v] + w == dis[u]) dfs(v);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    cin >> n >> m;
    For (i, m) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    dijk(0, n - 1);

    dfs(n - 1);

    int ans = 0;
    For (u, n) {
        for (auto [v, w] : g[u]) {
            if (mnv[u] && mnv[v] && dis[v] + w == dis[u]) ans += w;
        }
    }

    cout << 2 * ans << '\n';

    return 0;
}