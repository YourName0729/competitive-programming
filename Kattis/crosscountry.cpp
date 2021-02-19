//
// https://open.kattis.com/problems/crosscountry
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

int n;
int g[1010][1010];
int dist[1010];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int s, t;
    cin >> n >> s >> t;
    For (i, n) {
        For (j, n) {
            cin >> g[i][j];
        }
    }

    For (i, n)  dist[i] = MOD;
    priority_queue<ar<int, 2>, vector<ar<int, 2>>, greater<ar<int, 2>>> pq;
    dist[s] = 0;
    pq.push({0, s});
    while (pq.size()) {
        int d = pq.top()[0], u = pq.top()[1];
        pq.pop();
        if (dist[u] < d)    continue;
        For (v, n) {
            if (v == u) continue;
            int w = g[u][v];
            if (d + w < dist[v]) {
                dist[v] = d + w;
                pq.push({d + w, v});
            }
        }
    }

    // For (i, n)  cout << dist[i] << ' ';
    // cout << '\n';
    cout << dist[t] << '\n';

    return 0;
}