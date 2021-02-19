//
// https://open.kattis.com/problems/countingstars
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <cmath>
#include <queue>
#include <algorithm>
#include <stack>
#include <deque>

#define forcase int __t;cin>>__t;getchar();for(int ___t=1;___t<=__t;___t++)
#define For(i, n) for(int i=0;i<n;i++)

using ll = long long;
using namespace std;
const ll INF = 1000000010;
const ll MOD = 1000000007;

const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1};
const int dy[8] = {0, 1, 0, -1, 1, -1, 1, -1};

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int r, c;
char tb[110][110];
bool vst[110][110];

void gogo(int x, int y) {
    if (x < 0 || x >= r || y < 0 || y >= c) return;

    vst[x][y] = true;

    For (i, 4) {
        int nx = x + dx[i], ny = y + dy[i];
        if (tb[nx][ny] == '-' && !vst[nx][ny]) {
            gogo(nx, ny);
        }
    }
}

int count() {
    For (i, r) {
        For(j, c) {
            vst[i][j] = false;
        }
    }

    int cnt = 0;
    For (i, r) {
        For (j, c) {
            if (tb[i][j] == '-' && !vst[i][j]) {
                gogo(i, j);
                cnt++;
            }
        }
    }

    return cnt;
}

int main() {
    //fast();
    
    int t = 1;
    while (cin >> r >> c) {
        For (i, r) {
            For (j, c) {
                cin >> tb[i][j];
            }
        }

        int ans = count();
        cout << "Case " << t << ": " << ans << '\n';
        t++;
    }

    return 0;
}