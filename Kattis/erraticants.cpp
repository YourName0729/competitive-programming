// https://open.kattis.com/problems/erraticants
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
const unsigned ll IINF = 1e18;
const double eps = 1e-12;

map<char, int> mp = {{'S', 0}, {'N', 2}, {'E', 1}, {'W', 3}};
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
vector<int> g[200][200];
int dis[200][200];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    Forcase {
        int n;
        cin >> n;
        For (i, 200) {
            For (j, 200) {
                g[i][j].clear();
                dis[i][j] = MOD;
            }
        }
        int x = 100, y = 100;
        For (i, n) {
            char c;
            cin >> c;
            int k = mp[c];
            int nx = x + dx[k], ny = y + dy[k];
            g[x][y].push_back(k);
            g[nx][ny].push_back((k + 2) % 4);
            x = nx, y = ny;
        }

        int ex = x, ey = y;
        dis[100][100] = 0;
        queue<ar<int, 2>> que;
        que.push({100, 100});
        while (que.size()) {
            int x = que.front()[0], y = que.front()[1];
            que.pop();
            if (x == ex && y == ey) break;
            for (auto k : g[x][y]) {
                int nx = x + dx[k], ny = y + dy[k];
                if (dis[x][y] + 1 < dis[nx][ny]) {
                    dis[nx][ny] = dis[x][y] + 1;
                    que.push({nx, ny});
                }
            }
        }

        cout << dis[ex][ey] << '\n';
    }
    
    return 0;
}
