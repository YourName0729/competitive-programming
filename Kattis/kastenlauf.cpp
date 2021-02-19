// DFS
// https://open.kattis.com/problems/kastenlauf
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
const double eps = 1e-9;

int n;
ar<int, 2> a[110];
vector<int> g[110];
bool vst[110];

void dfs(int u) {
    vst[u] = 1;
    for (auto v : g[u]) {
        if (!vst[v])    dfs(v);
    }
}

int dist(int i, int j) {
    return abs(a[i][0] - a[j][0]) + abs(a[i][1] - a[j][1]);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    Forcase {
        cin >> n;
        n += 2;
        For (i, n) {
            cin >> a[i][0] >> a[i][1];
            g[i].clear();
            vst[i] = 0;
        }
        For (i, n) {
            for (int j = i + 1; j < n; j++) {
                if (dist(i, j) <= 1000) {
                    g[i].push_back(j);
                    g[j].push_back(i);
                }
            }
        }
        dfs(0);
        if (vst[n - 1]) {
            cout << "happy\n";
        }
        else {
            cout << "sad\n";
        }
    }

    return 0;
}