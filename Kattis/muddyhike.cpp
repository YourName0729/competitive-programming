// DFS binary_searching
// https://open.kattis.com/problems/muddyhike
#include <bits/stdc++.h>
 
#define For(i, n) for (int i = 0; i < n; ++i)
#define Forcase int __t = 0; cin >> __t; while (__t--)
#define pb push_back
#define ll long long
#define ull unsigned long long
#define ar array
 
using namespace std;
 
const int MOD = 1e9;//1e9 + 7;
const ll INF = 1e18;

int n, m;
int tb[1010][1010];
bool vst[1010][1010];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

void dfs(int x, int y, int d) {
    vst[x][y] = 1;
    For (i, 4) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        if (tb[nx][ny] <= d && !vst[nx][ny]) {
            dfs(nx, ny, d);
        }
    }
}

bool ok(int d) {
    For (i, n)  For (j, m)  vst[i][j] = 0;
    For (i, n)  if (tb[i][0] <= d)  dfs(i, 0, d);
    For (i, n)  if (vst[i][m - 1])  return 1;
    return 0;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    For (i, n)  For (j, m)  cin >> tb[i][j];
    int l = 0, r = 1000000;
    while (l < r) {
        int mid = (l + r) / 2;
        if (ok(mid)) {
            r = mid;
        }
        else {
            l = mid + 1;
        }
    }
    cout << l << '\n';

    return 0;
}