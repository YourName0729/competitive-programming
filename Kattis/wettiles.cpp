// BFS
// https://open.kattis.com/problems/wettiles
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

int n, m, t;
bool wall[1010][1010];
int dst[1010][1010];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

void build(int x1, int y1, int x2, int y2) {
    if (x1 == x2) {
        if (y1 > y2)    swap(y1, y2);
        for (int i = y1; i <= y2; i++)  wall[x1][i] = 1;
    }
    else if (y1 == y2) {
        if (x1 > x2)    swap(x1, x2);
        for (int i = x1; i <= x2; i++)  wall[i][y1] = 1;
    }
    else {
        if (x1 > x2) {
            swap(x1, x2);
            swap(y1, y2);
        }
        if (x1 - x2 == y1 - y2) {
            for (int i = 0; i <= x2 - x1; i++) wall[x1 + i][y1 + i] = 1;
        }
        else {
            for (int i = 0; i <= x2 - x1; i++) wall[x1 + i][y1 - i] = 1;
        }
    }
}

int main() {
    //ios_base::sync_with_stdio(0); cin.tie(0);

    while (cin >> n && n != -1) {
        int l, w, x, y, a, b;
        queue<ar<int, 2>> que;
        cin >> m >> t >> l >> w, t -= 2;
        For (i, n + 2)  For (j, m + 2) {
            wall[i][j] = 0;
            dst[i][j] = -1;
        }
        For (i, l) {
            cin >> x >> y;
            que.push({x, y});
            dst[x][y] = 0;
        }
        For (i, w) {
            cin >> x >> y >> a >> b;
            build(x, y, a, b);
        }
        build(0, 0, 0, m + 1);
        build(0, m + 1, n + 1, m + 1);
        build(n + 1, m + 1, n + 1, 0);
        build(n + 1, 0, 0, 0);

        while (!que.empty()) {
            ar<int, 2> cur = que.front();
            que.pop();
            int x = cur[0], y = cur[1];
            For (i, 4) {
                int nx = x + dx[i], ny = y + dy[i];
                if (!wall[nx][ny] && dst[nx][ny] == -1) {
                    dst[nx][ny] = dst[x][y] + 1;
                    if (dst[nx][ny] <= t) {
                        que.push({nx, ny});
                    }
                }
            }
        }

        // For (i, n + 2) {
        //     For (j, m + 2) {
        //         if (wall[i][j]) cout << 'X';
        //         else if (dst[i][j] != -1) cout << dst[i][j];
        //         else cout << '.';
        //     }
        //     cout << '\n';
        // }

        int ans = 0;
        For (i, n + 2) For (j, m + 2) {
            if (dst[i][j] != -1)    ans++;
        }
        cout << ans << '\n';
    }

    return 0;
}