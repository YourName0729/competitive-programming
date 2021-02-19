// dp
// https://open.kattis.com/problems/kingswalk
#include <bits/stdc++.h>

#define For(i, n) for (int i = 0; i < n; i++)
#define Forcase int __t = 0; cin >> __t; while (__t--)
#define ll long long
#define ar array

using namespace std;

const int MOD = 5318008; //1e9 + 7;

//int step[5010][5010];
int way[5010][5010];
int rnd[5010][5010];
int crnd = 0;
//bool vst[5010][5010];
//int dx[] = {1, 1, 1, 0, -1, -1, -1, 0};
//int dy[] = {1, 0, -1, -1, -1, 0, 1, 1};

int n;
ar<int, 2> s, e;

bool legal(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < n;
}

int f(int x, int y) {
    if (!legal(x, y))   return 0;
    if (rnd[x][y] == crnd) return way[x][y];
    int dx = x - s[0], dy = y - s[1];
    way[x][y] = 0;
    if (abs(dx) != dy)  way[x][y] = f(x, y - 1);
    if (dx > 0 || dy + dx >= 2) {
        way[x][y] = (way[x][y] + f(x - 1, y - 1)) % MOD;
    }
    if (dx < 0 || dy - dx >= 2) {
        way[x][y] = (way[x][y] + f(x + 1, y - 1)) % MOD;
    }
    rnd[x][y] = crnd;
    return way[x][y];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    Forcase {
        crnd++;
        cin >> n;
        cin >> s[0] >> s[1] >> e[0] >> e[1], s[0]--, s[1]--, e[0]--, e[1]--;
        if (s[0] > e[0]) {
            s[0] = n - 1 - s[0];
            e[0] = n - 1 - e[0];
        }
        if (s[1] > e[1]) {
            s[1] = n - 1 - s[1];
            e[1] = n - 1 - e[1];
        }
        if (e[0] - s[0] > e[1] - s[1]) {
            swap(s[0], s[1]);
            swap(e[0], e[1]);
        }

        
        rnd[s[0]][s[1]] = crnd;
        way[s[0]][s[1]] = 1;
        cout << f(e[0], e[1]) << '\n';

        /*for (int i = 0; i < n; i++) {
            For (j, n) {
                cout << setw(3) << way[i][j] << ' ';
            }
            cout << '\n';
        }*/
    }

    return 0;
}