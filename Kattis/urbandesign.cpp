// computational_geometry
// https://open.kattis.com/problems/urbandesign
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

int n, q;
ar<int, 4> str[10010];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    For (i, n) {
        For (j, 4) {
            cin >> str[i][j];
        }
    }

    cin >> q;
    For (i, q) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int cnt = 0;
        for (ar<int, 4> s : str) {
            ll ux = x1 - s[0], uy = y1 - s[1], vx = x2 - s[0], vy = y2 - s[1];
            ll wx = s[2] - s[0], wy = s[3] - s[1];
            ll du = wx * uy - wy * ux, dv = wx * vy - wy * vx;
            if (du * dv < 0) {
                cnt++;
            }
        }
        if (cnt % 2 == 0) {
            cout << "same\n";
        }
        else {
            cout << "different\n";
        }
    }

    return 0;
}