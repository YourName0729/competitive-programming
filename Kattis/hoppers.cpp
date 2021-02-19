// DFS
// https://open.kattis.com/problems/hoppers
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
vector<int> g[500010];
bool vst[500010], vst2[500010];

void dfs(int u) {
    vst[u] = 1;
    for (auto v : g[u]) {
        if (!vst[v])    dfs(v);
    }
}

void dfs3(int);

void dfs2(int u) {
    vst[u] = 1;
    for (auto v : g[u]) {
        if (!vst2[v]) dfs3(v);
    }
}

void dfs3(int u) {
    vst2[u] = 1;
    for (auto v : g[u]) {
        if (!vst[v]) dfs2(v);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    For (i, m) {
        int u, v;
        cin >> u >> v, u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> vec;
    int cpn = 0;
    For (i, n) {
        if (!vst[i]) {
            dfs(i);
            vec.push_back(i);
            cpn++;
        }
    }

    for (int i = 1; i < vec.size(); i++) {
        g[vec[0]].push_back(vec[i]);
        g[vec[i]].push_back(vec[0]);
    }
    For (i, n)  vst[i] = 0;

    dfs2(0);
    
    For (i, n) {
        if (!vst[i]) {
            cout << cpn << '\n';
            return 0;
        }
    }
    cout << cpn - 1 << '\n';

    return 0;
}