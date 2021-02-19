// 
// https://open.kattis.com/problems/pathtracing
#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <stack>
#include <cmath>
#include <map>
#include <utility>
#include <queue>
#include <iomanip>
#include <deque>
#include <set>
#include <functional>

#define Forcase int __t;cin>>__t;for(int cases=1;cases<=__t;cases++)
#define For(i, n) for(int i=0;i<n;i++)
#define Fore(e, arr) for(auto e:arr)

#define INF 1e9
#define LINF 1e18
#define EPS 1e-9

using ull = unsigned long long;
using ll = long long;
using namespace std;

int xb, xt, yb, yt;
char tb[510][510];

int n = 0;
int arrx[510], arry[510];

int main() {
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    // cout.tie(NULL);

    For (i, 510) {
        For (j, 510) {
            tb[i][j] = ' ';
        }
    }

    string s;
    while (cin >> s && s != "0") {
        arrx[n] = arry[n] = 0;
        if (s == "down") {
            arry[n] = 1;
        } else if (s == "up") {
            arry[n] = -1;
        } else if (s == "left") {
            arrx[n] = -1;
        } else if (s == "right") {
            arrx[n] = 1;
        }
        n++;
    }

    xb = xt = yb = yt = 0;
    int nx = 0, ny = 0;
    For (i, n) {
        nx += arrx[i];
        ny += arry[i];
        xb = min(xb, nx);
        xt = max(xt, nx);
        yb = min(yb, ny);
        yt = max(yt, ny);
    }

    nx = -xb;
    ny = -yb;
    tb[nx][ny] = 'S';
    For (i, n) {
        nx += arrx[i];
        ny += arry[i];
        if (tb[nx][ny] != 'S') tb[nx][ny] = '*';
    }
    tb[nx][ny] = 'E';

    int xs = xt - xb + 1, ys = yt - yb + 1;

    For (i, xs + 2) {
        cout << '#';
    }
    cout << '\n';
    For (j, ys) {
        cout << '#';
        For (i, xs) {
            cout << tb[i][j];
        }
        cout << "#\n";
    }
    For (i, xs + 2) {
        cout << '#';
    }
    cout << '\n';
    

    return 0;
}