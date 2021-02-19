// brute_force
// https://open.kattis.com/problems/connectn
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

#define For(i, n) for (int i = 0; i < n; ++i)
#define Forcase int __t = 0; cin >> __t; while (__t--)
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

int n, m, k;
char tb[110][110];

int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

bool win(int x, int y) {
    For (i, 8) {
        int cx = x, cy = y, cnt = 1;
        while (1) {
            int nx = cx + dx[i], ny = cy + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) break;
            if (tb[nx][ny] != tb[cx][cy])   break;
            cnt++, cx = nx, cy = ny;
        }
        if (cnt >= k)   return 1;
    }
    return 0;
}

int main() {
    //ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m >> k;
    For (i, n) For (j, m) cin >> tb[i][j];

    For (i, n) {
        For (j, m) {
            if (tb[i][j] != 'O' && win(i, j)) {
                if (tb[i][j] == 'B')    cout << "BLUE WINS\n";
                else cout << "RED WINS\n";
                return 0;
            }
        }
    }
    cout << "NONE\n";

    return 0;
}