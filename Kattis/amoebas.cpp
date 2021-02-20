//
// https://open.kattis.com/problems/amoebas
#include <bits/stdc++.h>

#define For(i, n) for (int i = 0; i < n; i++)
#define Forcase int __t = 0; cin >> __t; while (__t--)
#define pb push_back
#define ll long long
#define ull unsigned long long
#define ar array

using namespace std;

const int MOD = 1e9 + 7;
const int INF = 2147483647;

int n, m;
bool cell[110][110];
bool vst[110][110];

int dx[] = {1, 1, 1, 0, -1, -1, -1, 0};
int dy[] = {1, 0, -1, -1, -1, 0, 1, 1};

void dfs(int x, int y) {
    vst[x][y] = 1;
    For (i, 8) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (0 <= nx && nx < n && 0 <= ny && ny < m && !vst[nx][ny] && cell[nx][ny]) {
            dfs(nx, ny);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    cin >> n >> m;
    For (i, n) {
        For (j, m) {
            char c;
            cin >> c;
            cell[i][j] = (c == '#');
        }
    }

    int cnt = 0;
    For (i, n) {
        For (j, m) {
            if (cell[i][j] && !vst[i][j]) {
                dfs(i, j);
                cnt++;
            }
        }
    }

    cout << cnt << '\n';

    return 0;
}