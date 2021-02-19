// simulation
// https://open.kattis.com/problems/slidingtiles
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


int x[26], y[26];
int tb[150][150];
int cx = 50, cy = 50;

void move(int c, int dx, int dy) {
    //cout << (char)(c + 'A') << ' ' << dx << ' ' << dy << '\n';
    x[c] += dx, y[c] += dy;
    if (tb[x[c]][y[c]] != -1) {
        move(tb[x[c]][y[c]], dx, dy);
    }
    tb[x[c]][y[c]] = c;
    tb[x[c] - dx][y[c] - dy] = -1;
        
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n;
    while (cin >> n && n != -1) {
        For (i, 150) For (j, 150) tb[i][j] = -1;
        For (i, 5) {
            For (j, 5) {
                x[i * 5 + j] = cx + i;
                y[i * 5 + j] = cx + j;
                tb[cx + i][cy + j] = i * 5 + j;
            }
        }

        For (i, n) {
            char c;
            string s;
            cin >> c >> s;
            if (s == "up") {
                move(c - 'A', -1, 0);
            }
            else if (s == "down") {
                move(c - 'A', 1, 0);
            }
            else if (s == "right") {
                move(c - 'A', 0, 1);
            }
            else {
                move(c - 'A', 0, -1);
            }
        }

        int xl = 150, xr = 0, yl = 150, yr = 0;
        For (i, 25) {
            xl = min(xl, x[i]);
            xr = max(xr, x[i]);
            yl = min(yl, y[i]);
            yr = max(yr, y[i]);
        }


        int d = 0;
        for (int i = xl; i <= xr; i++) {
            for (int j = yl; j <= yr; j++) {
                bool flg = 0;
                For (k, 25) {
                    if (x[k] == i && y[k] == j) {
                        For (l, d)  cout << ' ';
                        d = 0;
                        cout << (char)(k + 'A');
                        flg = 1;
                    }
                }
                if (!flg)   d++;
            }
            cout << '\n';
            d = 0;
        }
        cout << '\n';
    }

    return 0;
}