// simulation
// https://open.kattis.com/problems/rockscissorspaper
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
const ll INF = 1e18;

int r, c, n;
char tb[110][110], tmp[110][110];

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

void go() {
    For (i, r) {
        For (j, c) {
            bool flg = 0;
            char v;
            if (tb[i][j] == 'R')    v = 'P';
            if (tb[i][j] == 'P')    v = 'S';
            if (tb[i][j] == 'S')    v = 'R';
            For (k, 4) {
                int nx = i + dx[k], ny = j + dy[k];
                if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
                if (tb[nx][ny] == v)    flg = 1;
            }
            if (flg)    tmp[i][j] = v;
            else    tmp[i][j] = tb[i][j];
        }
    }
    For (i, r)  For (j, c)  tb[i][j] = tmp[i][j];
}

int main() {
    //ios_base::sync_with_stdio(0); cin.tie(0);

    Forcase {
        cin >> r >> c >> n;
        For (i, r) For (j, c)   cin >> tb[i][j];

        For (i, n) go();
        For (i, r) {
            For (j, c) {
                cout << tb[i][j];
            }
            cout << '\n';
        }
    }


    return 0;
}
