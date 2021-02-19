// DFS
// https://open.kattis.com/problems/amanda
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

int n, m;
vector<ar<int, 2>> g[200010];
bool vst[200010];
bool vst2[200010];
bool clr[200010];
bool clr2[200010];

void dfs(int u, int c) {
    if (vst[u]) {
        if (clr[u] != c)    throw 1;
        return;
    }
    vst[u] = 1;
    clr[u] = c;
    for (auto p : g[u]) {
        int v = p[0], w = p[1];
        if ((c == 0 && w == 2) || (c == 1 && w == 0))   throw 1;
        if (c == w) dfs(v, 0);
        else    dfs(v, 1);
    }
}

ar<int, 2> dfs2(int u, int c) {
    if (vst2[u]) {
        if (clr2[u] != c)    throw 1;
        return {0, 0};
    }
    vst2[u] = 1;
    clr2[u] = c;
    ar<int, 2> re = {0, 0};
    re[c]++;
    for (auto p : g[u]) {
        int v = p[0], w = p[1];
        if (vst[v]) continue;
        ar<int, 2> cur = dfs2(v, (c + 1) % 2);
        re[0] += cur[0], re[1] += cur[1];
    }
    return re;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);


    cin >> n >> m;
    For (i, m) {
        int u, v, w;
        cin >> u >> v >> w, u--, v--;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    int ans = 0;

    try {
        For (i, n) {
            for (ar<int, 2> p : g[i]) {
                if (p[1] == 2) {
                    dfs(i, 1);
                }
                else if (p[1] == 0) {
                    dfs(i, 0);
                }
            }
        }
        For (i, n) {
            if (!vst[i] && !vst2[i]) {
                ar<int, 2> cur = dfs2(i, 1);
                ans += min(cur[0], cur[1]);
            }
        }
    }
    catch (int d) {
        cout << "impossible\n";
        return 0;
    }
    
    For (i, n) {
        if (vst[i] && clr[i])   ans++;
    }
    cout << ans << '\n';

    return 0;
}
