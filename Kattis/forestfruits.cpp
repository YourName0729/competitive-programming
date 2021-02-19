// Dijkstra
// https://open.kattis.com/problems/forestfruits
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

int n, m, c;
ll k, M;
vector<ar<ll, 2>> g[20010];
ll dist[20010];
bool fui[20010];

void dijk(int s) {
    For (i, n + 1)  dist[i] = IINF;
    
    priority_queue<ar<ll, 2>, vector<ar<ll, 2>>, greater<ar<ll, 2>>> pq;
    dist[s] = 0;
    pq.push({0, s});
    while (!pq.empty()) {
        ar<ll, 2> cur = pq.top();
        pq.pop();
        ll u = cur[1], d = cur[0];
        if (dist[u] < d)    continue;
        for (ar<ll, 2> p : g[u]) {
            ll v = p[1], w = p[0];
            if (d + w < dist[v]) {
                dist[v] = d + w;
                pq.push({d + w, v});
            }
        }
    }
}

bool ok(ll d) {
    int cnt = 0;
    for (int i = 1; i <= n ; i++) {
        if (fui[i] && dist[i] <= d) cnt++;
    }
    return (cnt >= k || cnt >= M);
}   

ll bs(ll l, ll r) {
    if (!ok(r)) return -1;
    while (l < r) {
        ll mid = (l + r) / 2;
        if (ok(mid)) {
            r = mid;
        }
        else {
            l = mid + 1;
        }
    }
    return 2 * l;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    ll sum = 0;
    cin >> n >> m >> c >> k >> M;
    For (i, m) {
        int u, v, w;
        cin >> u >> v >> w;
        sum += w;
        g[u].push_back({w, v});
        g[v].push_back({w, u});
    }
    For (i, c) {
        int d;
        cin >> d;
        fui[d] = 1;
    }

    dijk(1);

    cout << bs(0, sum) << '\n';

    return 0;
}