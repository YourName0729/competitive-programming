// BFS
// https://open.kattis.com/problems/fire2
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
bool wall[1010][1010];
int fdp[1010][1010];
int sdp[1010][1010];

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

void bfs(vector<ar<int, 2>>& s, int dp[][1010]) {
    queue<ar<int, 2>> que;
    For (i, s.size()) {
        que.push(s[i]);
        dp[s[i][0]][s[i][1]] = 0;
    }
    while (!que.empty()) {
        ar<int, 2> cur = que.front();
        que.pop();
        int x = cur[0], y = cur[1];
        For (i, 4) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx == n || ny < 0 || ny == m) continue;
            if (wall[nx][ny])   continue;
            if (dp[nx][ny] > dp[x][y] + 1) {
                dp[nx][ny] = dp[x][y] + 1;
                que.push({nx, ny});
            }
        }
    }
}

void show(int dp[][1010]) {
    For (i, n) {
        For (j, m) {
            if (dp[i][j] == MOD) {
                cout << 'X';
            }
            else {
                cout << dp[i][j];
            }
            cout << ' ';
        }
        cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    Forcase {
        vector<ar<int, 2>> fire;
        vector<ar<int, 2>> s;

        cin >> n >> m;
        swap(n, m);
        For (i, n) {
            For (j, m) {
                wall[i][j] = 0;
                fdp[i][j] = sdp[i][j] = MOD;
                char c;
                cin >> c;
                if (c == '#') {
                    wall[i][j] = 1;
                }
                else if (c == '*') {
                    fire.push_back({i, j});
                }
                else if (c == '@') {
                    s.push_back({i, j});
                }
            }
        }

        bfs(fire, fdp);
        bfs(s, sdp);

        // show(fdp);
        // cout << '\n';
        // show(sdp);

        int ans = MOD;
        For (i, n) {
            if (sdp[i][0] < fdp[i][0]) {
                ans = min(ans, sdp[i][0]);
            }
            if (sdp[i][m - 1] < fdp[i][m - 1]) {
                ans = min(ans, sdp[i][m - 1]);
            }
        }
        For (i, m) {
            if (sdp[0][i] < fdp[0][i]) {
                ans = min(ans, sdp[0][i]);
            }
            if (sdp[n - 1][i] < fdp[n - 1][i]) {
                ans = min(ans, sdp[n - 1][i]);
            }
        }
        if (ans == MOD) {
            cout << "IMPOSSIBLE\n";
        }
        else {
            cout << ans + 1 << '\n';
        }
    }

    return 0;
}