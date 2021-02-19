// BFS
// https://open.kattis.com/problems/grid
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
int tb[510][510];
int dist[510][510];

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

void bfs(int sx, int sy) {
    queue<ar<int, 3>> que;
    que.push({0, sx, sy});
    while (!que.empty()) {
        ar<int, 3> cur = que.front();
        que.pop();
        int x = cur[1], y = cur[2], w = cur[0];
        if (w >= dist[x][y])    continue;
        dist[x][y] = w;
        For (i, 4) {
            int nx = x + dx[i] * tb[x][y], ny = y + dy[i] * tb[x][y];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                que.push({w + 1, nx, ny});
            }
        }   
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    For (i, n) For (j, m) {
        char c;
        cin >> c;
        tb[i][j] = c - '0';
    }
    For (i, n) For (j, m)   dist[i][j] = MOD;
    
    bfs(0, 0);

    if (dist[n - 1][m - 1] == MOD) {
        cout << -1 << '\n';
    }
    else {
        cout << dist[n - 1][m - 1] << '\n';
    }
     

    return 0;
}