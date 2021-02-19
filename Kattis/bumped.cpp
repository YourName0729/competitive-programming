// Dijkstra
// https://open.kattis.com/problems/bumped
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
vector<ar<ll, 2>> g[100010];
ll dist[100010];

void dijk(int s) {
    For (i, 2 * n) {
        dist[i] = IINF;
    }
    priority_queue<ar<ll, 2>, vector<ar<ll, 2>>, greater<ar<ll, 2>>> pq;
    pq.push({0, s});
    dist[s] = 0;

    while (!pq.empty()) {
        ar<ll, 2> cur = pq.top();
        pq.pop();
        ll u = cur[1], d = cur[0];
        if (dist[u] < d)   continue;
        //cout << "dist[" << u << "] = " << d << '\n';
        //dist[u] = d;
        for (ar<ll, 2> p : g[u]) {
            ll v = p[1], w = p[0];
            //cout << "v w " << v << ' ' << w << '\n';
            //cout << dist[v] << '\n';
            if (d + w < dist[v]) {
                dist[v] = d + w;
                //cout << "push " << d + w << ' ' << v << '\n';
                pq.push({d + w, v});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int s, t, f;
    cin >> n >> m >> f >> s >> t;
    For (i, m) {
        int u, v, c;
        cin >> u >> v >> c;
        g[u].push_back({c, v});
        g[v].push_back({c, u});
        g[u + n].push_back({c, v + n});
        g[v + n].push_back({c, u + n});
    }
    For (i, f) {
        int u, v;
        cin >> u >> v;
        g[u].push_back({0, v + n});
    }

    dijk(s);
    
    cout << min(dist[t], dist[t + n]) << '\n';

    return 0;
}