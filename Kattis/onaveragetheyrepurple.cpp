// BFS
// https://open.kattis.com/problems/onaveragetheyrepurple
#include <bits/stdc++.h>

#define For(i, n) for (int i = 0; i < n; i++)
#define Forcase int __t = 0; cin >> __t; while (__t--)
#define ll long long
#define ar array

using namespace std;

const int MOD = 1e9 + 7;

int n, m;
vector<int> adj[100010];
int dp[100010];


int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    cin >> n >> m;
    For (i, m) {
        int a, b;
        cin >> a >> b, a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    memset(dp, MOD, sizeof(dp[0]) * n);

    queue<ar<int, 2>> que;
    que.push({0, 0});

    while (!que.empty()) {
        ar<int, 2> cur = que.front();
        que.pop();
        int u = cur[0], d = cur[1];
        if (d < dp[u]) {
            dp[u] = d;
            for (auto v : adj[u]) {
                if (d + 1 < dp[v]) {
                    que.push({v, d + 1});
                }
            }
        }    
    }

    cout << dp[n - 1] - 1 << '\n';

    return 0;
}