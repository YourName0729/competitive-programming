// https://open.kattis.com/problems/walkway
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

#define For(i, n) for (int i = 0; i < n; ++i)
#define Forcase int __t = 0; cin >> __t; while (__t--)
#define ll long long
#define ar array

using namespace std;
using namespace __gnu_pbds;

template<class Type> using indexed_set=tree<Type,null_type,less<Type>,rb_tree_tag,tree_order_statistics_node_update>;

const int MOD = 1e9 + 7;
const int INF = 2147483647;
const ll IINF = 1e18;
const double eps = 1e-12;

int n;
vector<ar<ll, 2>> g[1010];
ar<ll, 3> a[1010];
ll dist[1010];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    while (cin >> n && n) {
        For (i, 1001)   g[i].clear();

        For (i, n) {
            For (j, 3) {
                cin >> a[i][j];
                
            }
            g[a[i][0]].push_back({(a[i][0] + a[i][1]) * a[i][2], a[i][1]});
            g[a[i][1]].push_back({(a[i][0] + a[i][1]) * a[i][2], a[i][0]});
        }

        int s, t;
        cin >> s >> t;

        For (i, 1001) {
            dist[i] = IINF;
        }
        priority_queue<ar<ll, 2>, vector<ar<ll, 2>>, greater<ar<ll, 2>>> pq;
        dist[s] = 0;
        pq.push({0, s}); 
        while (pq.size()) {
            ll d = pq.top()[0], u = pq.top()[1];
            pq.pop();
            if (dist[u] < d) continue;
            for (ar<ll, 2> p : g[u]) {
                ll v = p[1], w = p[0];
                if (d + w < dist[v]) {
                    dist[v] = d + w;
                    pq.push({d + w, v});
                }
            }
        }

        cout << fixed << setprecision(2) << dist[t] / 100.0 << '\n';
    }

    return 0;
}
