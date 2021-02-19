// Dijkstra Binary_searching
// https://open.kattis.com/problems/arachnophobia
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
const double eps = 1e-12;

int n, m, T, s, t;
vector<ar<int, 2>> g[100010];
int ds[100010], dt[100010];

bool ok(int mx) {
    For (i, n) dt[i] = MOD;
    priority_queue<ar<int, 2>, vector<ar<int, 2>>, greater<ar<int, 2>>> pq;
    dt[s] = 0;
    pq.push({0, s});
    while (pq.size()) {
        int d = pq.top()[0], u = pq.top()[1];
        pq.pop();
        if (d > dt[u])  continue;
        for (ar<int, 2> p : g[u]) {
            int v = p[1], w = p[0];
            if (ds[v] < mx) continue;
            if (d + w < dt[v]) {
                dt[v] = d + w;
                pq.push({d + w, v});
            }
        }
    }
    return dt[t] <= T;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m >> T;
    For (i, m) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({w, v});
        g[v].push_back({w, u});
    }
    cin >> s >> t;

    int k;
    vector<int> spd;
    cin >> k;
    For (i, k) {
        int d;
        cin >> d;
        spd.push_back(d);
    }

    For (i, n)  ds[i] = MOD;
    priority_queue<ar<int, 2>, vector<ar<int, 2>>, greater<ar<int, 2>>> pq;
    for (auto u : spd) {
        ds[u] = 0;
        pq.push({0, u});
    }
    while (pq.size()) {
        int d = pq.top()[0], u = pq.top()[1];
        pq.pop();
        if (d > ds[u])  continue;
        for (ar<int, 2> p : g[u]) {
            int v = p[1], w = p[0];
            if (d + w < ds[v]) {
                ds[v] = d + w;
                pq.push({d + w, v});
            }
        }
    }

    int l = 0, r = min(ds[s], ds[t]);
    while (l < r) {
        int mid = (l + r) / 2 + (l + r) % 2;
        if (ok(mid)) {
            l = mid;
        }
        else {
            r = mid - 1;
        }
    }
    cout << l << '\n';

    return 0;
}
