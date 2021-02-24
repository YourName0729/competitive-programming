// https://open.kattis.com/problems/landlocked
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

int n, m;
char tb[1010][1010];
int dist[1010][1010];

int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    For (i, n) For (j, m) {
        cin >> tb[i][j];
    }

    For (i, n) For (j, m) dist[i][j] = MOD;
    priority_queue<ar<int, 3>, vector<ar<int, 3>>, greater<ar<int, 3>>> pq;
    For (i, n) For (j, m) {
        if (tb[i][j] == 'W') {
            dist[i][j] = 0;
            pq.push({0, i, j});
        }
    }
    while (pq.size()) {
        int d = pq.top()[0], x = pq.top()[1], y = pq.top()[2];
        pq.pop();
        if (dist[x][y] < d)    continue;
        For (i, 8) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            int w = (tb[x][y] != tb[nx][ny]);
            if (d + w < dist[nx][ny]) {
                dist[nx][ny] = d + w;
                pq.push({d + w, nx, ny});
            }
        }
    }

    vector<int> ans(26, MOD);
    For (i, n) For (j, m) {
        int cur = tb[i][j] - 'A';
        ans[cur] = min(ans[cur], dist[i][j]);
    }

    For (i, 26) {
        if (ans[i] != 0 && ans[i] != MOD) {
            cout << (char)(i + 'A') << ' ' << ans[i] - 1 << '\n';
        }
    }


    return 0;
}
