// BFS
// https://open.kattis.com/problems/rings2
#include <bits/stdc++.h>
 
#define For(i, n) for (int i = 0; i < n; ++i)
#define Forcase int __t = 0; cin >> __t; while (__t--)
#define pb push_back
#define ll long long
#define ull unsigned long long
#define ar array
 
using namespace std;
 
const int MOD = 1e9 + 7;
const ll INF = 1e18;

int n, m;
bool land[110][110];
int dp[110][110];

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

bool near(int x, int y) {
    For (i, 4) {
        int nx = x + dx[i], ny = y + dy[i];
        if (!land[nx][ny])  return 1;
    }
    return 0;
}

int main() {
    //ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            char c;
            cin >> c;
            land[i][j] = (c == 'T');
            dp[i][j] = MOD;
        }
    }

    queue<ar<int, 3>> que;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (land[i][j] && near(i, j)) {
                //cout << "near " << i << ' ' << j << '\n'; 
                que.push({i, j, 1});
            }
        }
    }

    while (!que.empty()) {
        ar<int, 3> cur = que.front();
        que.pop();
        int x = cur[0], y = cur[1], d = cur[2];
        if (dp[x][y] <= d)   continue;
        dp[x][y] = d;

        For (i, 4) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (land[nx][ny]) {
                que.push({nx, ny, d + 1});
            }
        }
    }

    int mx = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (land[i][j])
                mx = max(mx, dp[i][j]);
        }
    }

    if (mx < 10) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (land[i][j]) {
                    cout << '.' << dp[i][j];
                }
                else {
                    cout << "..";
                }
            }
            cout << '\n';
        }
    }
    else {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (land[i][j]) {
                    cout << setw(3) << setfill('.') << dp[i][j];
                }
                else {
                    cout << "...";
                }
            }
            cout << '\n';
        }
    }

    return 0;
}