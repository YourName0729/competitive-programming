// string_processing
// https://open.kattis.com/problems/knightsearch
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

int n;
string str = "ICPCASIASG";
char tb[110][110];
int dx[] = {1, 2, 1, 2, -1, -2, -1, -2};
int dy[] = {2, 1, -2, -1, 2, 1, -2, -1};

void dfs(int x, int y, int step) {
    if (step == str.length())   throw 1;
    For (i, 8) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
        if (tb[nx][ny] == str[step]) {
            dfs(nx, ny, step + 1);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    For (i, n) {
        For (j, n) {
            cin >> tb[i][j];
        }
    }

    try {
        For (i, n) {
            For (j, n) {
                if (tb[i][j] == 'I') {
                    dfs(i, j, 1);
                }
            }
        }
    }
    catch (int d) {
        cout << "YES\n";
        return 0;
    }
    cout << "NO\n";
    
    return 0;
}