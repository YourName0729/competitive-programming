// DFS
// https://open.kattis.com/problems/10kindsofpeople
#include <bits/stdc++.h>

#define fast ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define forcase int __t;cin>>__t;for(int ___t=1;___t<=__t;___t++)
#define For(i, n) for(int i=0;i<n;i++)

using ll = long long;

using namespace std;

int R, C, n;
bool mp[1010][1010];
int id[1010][1010];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void gogo(int x, int y, int r) {
    id[x][y] = r;
    For (i, 4) {
        int nx = x + dx[i], ny = y + dy[i];
        if (0 <= nx && nx < R && 0 <= ny && ny < C) {
            if (id[nx][ny] != -1) continue;
            if (mp[x][y] != mp[nx][ny]) continue;

            gogo(nx, ny, r);
        }
    }
}

void go() {
    memset(id, -1, sizeof(id[0][0]) * 1010 * 1010);

    int round = 0;
    For (i, R) {
        For (j, C) {
            if (id[i][j] != -1) continue;

            gogo(i, j, round);
            round++;
        }
    }
}

int main() {
    fast;

    cin >> R >> C;
    For (i, R) {
        For (j, C) {
            char cc;
            cin >> cc;
            mp[i][j] = (cc == '1');
        }
    }

    go();
    
    cin >> n;
    For (i, n) {
        int sx, sy, dx, dy;
        cin >> sx >> sy >> dx >> dy;
        sx--;
        sy--;
        dx--;
        dy--;

        if (id[sx][sy] == id[dx][dy] && mp[sx][sy]) {
            cout << "decimal\n";
        } else if (id[sx][sy] == id[dx][dy]) {
            cout << "binary\n";
        } else {
            cout << "neither\n";
        }
    }
    
    return 0;
}