// https://open.kattis.com/problems/destinationunknown
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

int n, m, t;
int s, g, h, ghl;
vector<ar<int, 2>> adj[2010];
vector<int> des;

int dis1[2010];
int dis2[2010];
int dis3[2010];

void dijk(int s, int dis[]) {   
    fill(dis, dis + n, 1e9 + 7);
    dis[s] = 0;
    priority_queue<array<int, 2>, vector<array<int, 2>>, greater<array<int, 2>>> pq;
    pq.push({0, s});
    while (pq.size()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (dis[u] < d) continue;
        for (auto& [v, w] : adj[u]) {
            if (d + w < dis[v]) {
                dis[v] = d + w;
                pq.push({dis[v], v});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int tc;
    cin >> tc;
    while (tc--) {
        // cout << "---------\n";
        cin >> n >> m >> t;
        cin >> s >> g >> h, --s, --g, --h;

        des.clear();
        For (i, n) adj[i].clear();

        int a, b, d;
        For (i, m) {
            cin >> a >> b >> d, --a, --b;
            if ((a == g && b == h) || (a == h && b == g)) ghl = d;
            adj[a].push_back({b, d});
            adj[b].push_back({a, d});
        }

        For (i, t) {
            int x;
            cin >> x, --x;
            des.push_back(x);
        }
        sort(des.begin(), des.end());

        dijk(s, dis1);
        dijk(g, dis2);
        dijk(h, dis3);

        for (auto d : des) {
            // cout << dis1[d] << ' ' << dis2[d] << '\n';
            if (   (dis1[d] == dis1[g] + ghl + dis3[d]) 
                || (dis1[d] == dis1[h] + ghl + dis2[d])) 
                cout << d + 1 << ' ';
        }
        cout << '\n';
    }

    return 0;
}