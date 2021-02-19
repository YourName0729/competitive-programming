// dijkstra
// https://open.kattis.com/problems/invasion
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

int n, m;
vector<ar<int, 2>> g[10010];
int dist[10010];


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int A, K;
    while (cin >> n >> m >> A >> K && n + m + A + K) {
        For (i, n)  g[i].clear();
        For (i, m) {
            int u, v, w;
            cin >> u >> v >> w, u--, v--;
            g[u].push_back({w, v});
            g[v].push_back({w, u});
        }

        int ans = n;
        For (i, n)  dist[i] = MOD;
        priority_queue<ar<int, 2>, vector<ar<int, 2>>, greater<ar<int, 2>>> pq;
        For (i, A) {
            int d;
            cin >> d, d--;
            pq.push({0, d});
            if (dist[d] >= K)   ans--;
            dist[d] = 0;

            while (pq.size()) {
                int d = pq.top()[0], u = pq.top()[1];
                pq.pop();
                if (dist[u] < d)    continue;
                for (ar<int, 2> p : g[u]) {
                    int v = p[1], w = p[0];
                    if (d + w < dist[v]) {
                        if (d + w < K && dist[v] >= K)  ans--;
                        dist[v] = d + w;
                        pq.push({d + w, v});
                    }
                }
            }

            cout << ans << '\n';
        }
        cout << '\n';
    }

    return 0;
}
