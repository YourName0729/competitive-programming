// https://open.kattis.com/problems/arrivingontime
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

#define For(i, n) for (int i = 0; i < n; ++i)
#define Forcase int __t = 0; cin >> __t; while (__t--)
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

int n, m, T;
vector<ar<ll, 4>> g[100010];
ll dist[100010];

ll dijk(ll st) {
    For (i, n) dist[i] = IINF;

    priority_queue<ar<ll, 2>, vector<ar<ll, 2>>, greater<ar<ll, 2>>> pq;
    dist[0] = st;
    pq.push({st, 0});
    while (pq.size()) {
        ll u = pq.top()[1], d = pq.top()[0];
        pq.pop();
        if (d > dist[u])    continue;
        for (ar<ll, 4> pr : g[u]) {
            ll v = pr[0], t0 = pr[1], p = pr[2], w = pr[3], t;
            if (d < t0) t = t0;
            else {
                t = (d - t0 + p - 1) / p * p + t0;
            }
            t += w;
            if (t < dist[v]) {
                dist[v] = t;
                pq.push({t, v});
            }
        }
    }

    return dist[n - 1];
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m >> T;
    For (i, m) {
        ll u, v, t0, p, d;
        cin >> u >> v >> t0 >> p >> d;
        g[u].push_back({v, t0, p, d});
    }

    ll l = 0, r = IINF;
    if (T < dijk(0)) {
        cout << "impossible";
        return 0;
    }

    while (l < r) {
        ll mid = (l + r) / 2 + (l + r) % 2;
        if (T < dijk(mid)) {
            r = mid - 1;
        }
        else {
            l = mid;
        }
    }

    cout << l;
    
    return 0;
}
