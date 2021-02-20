// 
// https://open.kattis.com/problems/hidingplaces
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


int n, m;
int dist[8][8];
int dx[] = {1, 2, 1, 2, -1, -2, -1, -2};
int dy[] = {2, 1, -2, -1, 2, 1, -2, -1};

bool cmp(ar<int, 2> a, ar<int, 2> b) {
    if (a[1] == b[1])   return a[0] < b[0];
    return a[1] > b[1];
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    Forcase {
        int x, y;
        char c;
        cin >> c >> y;
        x = c - 'a', y--;
        For (i, 8) For (j, 8)   dist[i][j] = MOD;
        queue<ar<int, 2>> que;
        dist[x][y] = 0;
        que.push({x, y});
        int mx = 0;
        while (!que.empty()) {
            x = que.front()[0], y = que.front()[1];
            que.pop();
            For (i, 8) {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx < 0 || nx >= 8 || ny < 0 || ny >= 8) continue;
                if (dist[nx][ny] == MOD) {
                    dist[nx][ny] = dist[x][y] + 1;
                    mx = max(mx, dist[nx][ny]);
                    que.push({nx, ny});
                }
            }
        }

        // For (i, 8) {
        //     For (j, 8) {
        //         cout << dist[i][j] << ' ';
        //     }
        //     cout << '\n';
        // }

        vector<ar<int, 2>> ans;
        
        For (i, 8) For (j, 8) {
            if (dist[i][j] == mx) {
                ans.push_back({i, j});
            }
        }
        sort(ans.begin(), ans.end(), cmp);

        cout << mx << ' ';
        for (ar<int, 2> p : ans) {
            cout << (char)(p[0] + 'a') << p[1] + 1 << ' ';
        }
        cout << '\n';
    }
    

    return 0;
}