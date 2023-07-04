// https://open.kattis.com/problems/fleaonachessboard
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

bool vst[2010][2010];
ll s, sx, sy, dx, dy;

bool iswhile(ll x, ll y) {
    x = x % (2 * s), y = y % (2 * s);
    if (s < x && x < 2 * s && 0 < y && y < s) return 1;
    if (s < y && y < 2 * s && 0 < x && x < s) return 1;
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    while (cin >> s >> sx >> sy >> dx >> dy && s + sx + sy + dx + dy) {
        memset(vst, false, 2010 * 2010);
        int ans = 0;
        bool flg = 0;
        while (!iswhile(sx, sy)) {
            if (vst[sx % (2 * s)][sy % (2 * s)]) {
                flg = 1;
                break;
            }
            vst[sx % (2 * s)][sy % (2 * s)] = 1;
            ++ans;
            sx += dx, sy += dy;
        }

        if (flg) cout << "The flea cannot escape from black squares.\n";
        else cout << "After " << ans << " jumps the flea lands at (" << sx << ", " << sy << ").\n";
    }

    return 0;
}