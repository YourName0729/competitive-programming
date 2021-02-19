// graph_traversal DFS
// https://open.kattis.com/problems/amazing
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

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
string drct[] = {"right", "down", "left", "up"};
int g[210][210][4];
bool vst[210][210];

void dfs(int x, int y) {
   //cout << "at " << x << ' ' << y << '\n';
    vst[x][y] = 1;
    For (i, 4) {
        int nx = x + dx[i], ny = y + dy[i];
        if (vst[nx][ny])    continue;
        if (g[x][y][i] == -1) {
            cout << drct[i] << '\n';
            string in;
            cin >> in;
            if (in == "wall") {
                g[x][y][i] = g[nx][ny][(i + 2) % 4] = 0;
            }
            else if (in == "ok") {
                g[x][y][i] = g[nx][ny][(i + 2) % 4] = 1;
                //cout << "go " << nx << ' ' << ny << '\n';
                dfs(nx, ny);
                //cout << "back to " << x << ' ' << y << '\n';
                cout << drct[(i + 2) % 4] << '\n';
                cin >> in;
            }
            else if (in == "solved")    throw 1;
        }
    }
}

int main() {
    //ios_base::sync_with_stdio(0); cin.tie(0);

    For (i, 210) {
        For (j, 210) {
            For (k, 4) {
                g[i][j][k] = -1;
            }
        }
    }

    try {
        dfs(105, 105);
        cout << "no way out\n";
    }
    catch (int d) {

    }

    return 0;
}
