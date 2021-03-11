// https://open.kattis.com/problems/draughts
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

int n = 10, m = 10;
char tb[11][11];
int dx[] = {1, 1, -1, -1};
int dy[] = {1, -1, 1, -1};

int dfs(int x, int y) {
    int re = 0;
    For (i, 4) {
        int nx = x + 2 * dx[i], ny = y + 2 * dy[i];
        int bx = x + dx[i], by = y + dy[i];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        if (tb[bx][by] != 'B' || tb[nx][ny] != '#')  continue;
        tb[bx][by] = '#';
        re = max(re, dfs(nx, ny) + 1);
        tb[bx][by] = 'B';
    }
    return re;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
 
    Forcase {
        For (i, n) For (j, m) cin >> tb[i][j];
        int ans = 0;
        For (i, n) {
            For (j, m) {
                if (tb[i][j] == 'W') {
                    tb[i][j] = '#';
                    ans = max(ans, dfs(i, j));
                    tb[i][j] = 'W';
                }
            }
        }

        cout << ans << '\n';
    }


    return 0;
}
