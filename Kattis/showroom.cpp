// Dijkstra
// https://open.kattis.com/problems/showroom
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
char tb[410][410];
int dist[410][410];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int main() {
    //ios_base::sync_with_stdio(0); cin.tie(0);

    int sx, sy;
    cin >> n >> m;
    For (i, n) {
        For (j, m) {
            cin >> tb[i][j];
            dist[i][j] = MOD;
        }
    }
    cin >> sx >> sy, sx--, sy--;

    priority_queue<ar<int, 3>, vector<ar<int, 3>>, greater<ar<int, 3>>> pq;
    dist[sx][sy] = 1;
    pq.push({0, sx, sy});
    while (pq.size()) {
        int x = pq.top()[1], y = pq.top()[2], d = pq.top()[0];
        pq.pop();
        if (d > dist[x][y])   continue;
        if ((x == 0 || x == n - 1) || (y == 0 || y == m - 1)) continue;
        For (i, 4) {
            int nx = x + dx[i], ny = y + dy[i];
            if (tb[nx][ny] == '#')  continue;
            
            int nd = dist[x][y] + (tb[nx][ny] == 'c');
            if (nd < dist[nx][ny]) {
                dist[nx][ny] = nd;
                pq.push({nd, nx, ny});
            }
        }
    }

    int ans = MOD;
    For (i, n) {
        ans = min(ans, min(dist[i][0], dist[i][m - 1]));
    }
    For (i, m) {
        ans = min(ans, min(dist[0][i], dist[n - 1][i]));
    }
    cout << ans << '\n';

    return 0;
}