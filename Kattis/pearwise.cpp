// https://open.kattis.com/problems/pearwise
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

int n, m;
int wei[2010];
int loc[2010][26];

bool g[26][26];
bool vst[26];

bool win(int a, int b) {
    int va = 0, vb = 0;
    For (i, m) {
        if (loc[i][a] > loc[i][b]) {
            vb += wei[i];
        }
        else {
            va += wei[i];
        }
    }
    return va > vb;
}

void dfs(int u) {
    vst[u] = 1;
    For (v, n) {
        if (g[u][v] && !vst[v]) {
            dfs(v);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> n >> m;
    For (i, m) {
        string s;
        cin >> wei[i] >> s;
        For (j, s.length()) {
            loc[i][s[j] - 'A'] = j;
        }
    }

    For (i, n) {
        for (int j = i + 1; j < n; ++j) {
            if (win(i, j)) {
                g[i][j] = 1;
            }
            else {
                g[j][i] = 1;
            }
        }
    }

    For (i, n) {
        For (j, n) vst[j] = 0;
        dfs(i);
        bool flg = 0;
        For (j, n) if (!vst[j]) {
            flg = 1;
            break;
        }
        if (flg) {
            cout << (char)(i + 'A') << ": can't win\n";
        }
        else {
            cout << (char)(i + 'A') << ": can win\n";
        }
    }

    return 0;
}
