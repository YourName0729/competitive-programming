//
// https://open.kattis.com/problems/knightjump
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
int dist[110][110];
bool wall[110][110];
int dx[] = {1, 2, 1, 2, -1, -2, -1, -2};
int dy[] = {2, 1, -2, -1, 2, 1, -2, -1};



int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    int x, y;
    For (i, n) {
        For (j, n) {
            char c;
            cin >> c;
            if (c == '#') wall[i][j] = 1;
            else if (c == 'K')  x = i, y = j;
            dist[i][j] = MOD;
        }
    }

    queue<ar<int, 2>> que;
    dist[x][y] = 0;
    que.push({x, y});
    while (!que.empty()) {
        x = que.front()[0], y = que.front()[1];
        que.pop();
        For (i, 8) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n || wall[nx][ny]) continue;
            if (dist[nx][ny] == MOD) {
                dist[nx][ny] = dist[x][y] + 1;
                que.push({nx, ny});
            }
        }
    }

    if (dist[0][0] == MOD) {
        cout << "-1\n";
    }
    else {
        cout << dist[0][0] << '\n';
    }
    

    return 0;
}