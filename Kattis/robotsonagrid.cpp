// https://open.kattis.com/problems/robotsonagrid
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
const unsigned ll IINF = 1e18;
const double eps = 1e-12;

int n;
bool path[1010][1010];
bool vst[1010][1010];
ll dp[1010][1010];


int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

void dfs(int x, int y) {
    vst[x][y] = 1;
    For (i, 4) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx < n && nx >= 0 && ny < n && ny >= 0 && !vst[nx][ny] && path[nx][ny]) {
            dfs(nx, ny);
        }
    }
}

int main() {
    //ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> n;
    For (i, n) {
        For (j, n) {
            char c;
            cin >> c;
            path[i][j] = c == '.';
        }
    }

    dfs(0, 0);
    if (!vst[n - 1][n - 1]) {
        cout << "INCONCEIVABLE\n";
        return 0;
    }

    dp[0][0] = 1;
    for (int i = 1; i < n; ++i) {
        dp[i][0] = dp[i - 1][0] && path[i][0];
        dp[0][i] = dp[0][i - 1] && path[0][i];
    }

    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < n; ++j) {
            if (!path[i][j]) continue;
            dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % INF;
        }
    }

    if (dp[n - 1][n - 1] == 0) {
        cout << "THE GAME IS A LIE\n";
    }
    else {
        cout << dp[n - 1][n - 1] << '\n';
    }

    return 0;
}
