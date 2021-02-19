// dicision_tree DFS
// https://open.kattis.com/problems/knightsfen
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

#define For(i, n) for (int i = 0; i < n; ++i)
#define Forcase int __t = 0; cin >> __t; while (__t--)
#define pb push_back
#define ll long long
#define ull unsigned long long
#define ar array

using namespace std;
using namespace __gnu_pbds;

template<class Type> using indexed_set=tree<Type,null_type,less<Type>,rb_tree_tag,tree_order_statistics_node_update>;

const int MOD = 1e9 + 7;
const int INF = 2147483647;
const ll IINF = 1e18;
const double eps = 1e-12;

string s;
int tb[5][5];
int dx[] = {1, 2, 1, 2, -1, -2, -1, -2};
int dy[] = {2, 1, -2, -1, 2, 1, -2, -1};

string F[] = {
    "22222",
    "12222",
    "11022",
    "11112",
    "11111"
};

bool same() {
    For (i, 5)  For (j, 5) if (F[i][j] - '0' != tb[i][j]) return 0;
    return 1;
}

int dfs(int x, int y, int step) {
    if (step == 11) return MOD;
    if (same()) {
        return step;
    }
    int re = MOD;
    For (i, 8) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5) continue;
        swap(tb[x][y], tb[nx][ny]);
        re = min(re, dfs(nx, ny, step + 1));
        swap(tb[x][y], tb[nx][ny]);
    }
    return re;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t;
    cin >> t;
    getline(cin, s);
    while (t--) {
        int cx, cy;
        For (i, 5) {
            getline(cin, s);
            For (j, 5) {
                if (s[j] != ' ') {
                    tb[i][j] = s[j] - '0' + 1;
                }
                else {
                    tb[i][j] = 0;
                    cx = i, cy = j;
                }
            }    
        }
        
        int ans = dfs(cx, cy, 0);
        if (ans == MOD) {
            cout << "Unsolvable in less than 11 move(s).\n";
        }
        else {
            cout << "Solvable in " << ans << " move(s).\n";
        }
    }

    return 0;
}