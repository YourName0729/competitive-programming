// Dijkstra
// https://open.kattis.com/problems/shortestpath2
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
vector<ar<int, 4>> g[20010];
int dist[20010];

void dijk(int s) {
    For (i, n)  dist[i] = MOD;
    
    priority_queue<ar<ll, 2>, vector<ar<ll, 2>>, greater<ar<ll, 2>>> pq;
    dist[s] = 0;
    pq.push({0, s});
    while (!pq.empty()) {
        ar<ll, 2> cur = pq.top();
        pq.pop();
        ll u = cur[1], d = cur[0];
        if (dist[u] < d)    continue;
        for (ar<int, 4> p : g[u]) {
            int v = p[0], t0 = p[1], P = p[2], w = p[3];
            int nd = MOD;
            if (d <= t0) {
                if (t0 + w < dist[v]) {
                    dist[v] = t0 + w;
                    pq.push({t0 + w, v});
                }
            }
            else if (P != 0) {
                int t = t0 + (d - t0 + P - 1) / P * P + w;
                if (t < dist[v]) {
                    dist[v] = t;
                    pq.push({t, v});
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int q, s;
    while (cin >> n >> m >> q >> s && n + m + q + s) {
        For (i, n) g[i].clear();
        For (i, m) {
            int u, v, t0, p, d;
            cin >> u >> v >> t0 >> p >> d;
            g[u].push_back({v, t0, p, d});
        }

        dijk(s);

        For (i, q) {
            int d;
            cin >> d;
            if (dist[d] == MOD) {
                cout << "Impossible\n";
            }
            else {
                cout << dist[d] << '\n';
            }
        }
        cout << '\n';
    }

    return 0;
}