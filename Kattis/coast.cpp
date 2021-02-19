// DFS
// https://open.kattis.com/problems/coast
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
bool tb[1010][1010];
bool vst[1010][1010];

bool legal(int x, int y) {
    return 0 <= x && x < r && 0 <= y && y < c;
}

void gogo(int x, int y) {
    if (tb[x][y])   return;
    
    vst[x][y] = true;
    For (i, 4) {
        int nx = x + dx[i], ny = y + dy[i];
        if (legal(nx, ny) && !vst[nx][ny] && !tb[nx][ny]) {
            gogo(nx, ny);
        }
    }
}

int count() {
    int cnt = 0;
    For (i, r) {
        For (j, c) {
            if (vst[i][j])  continue;

            For (k, 4) {
                int nx = i + dx[k], ny = j + dy[k];
                if (!legal(nx, ny) || (legal(nx, ny) && vst[nx][ny])) {
                    cnt++;
                }
            }
        }
    }
    return cnt++;
}

int main() {
    //fast();
    
    cin >> r >> c;

    For (i, r) {
        For (j, c) {
            char c;
            cin >> c;
            tb[i][j] = (c == '1');
        }
    }

    For (i, r) {
        gogo(i, 0);
        gogo(i, c - 1);
    }
    For (i, c) {
        gogo(0, i);
        gogo(r - 1, i);
    }

    cout << count() << '\n';


    return 0;
}