// scc
// https://open.kattis.com/problems/runningmom
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

int n = 0, m;
vector<int> g[5010], gt[5010];
bool vst[5010];
int scc[5010], sccn[5010];

map<string, int> s2i;
string i2s[5010];

int reqID(string& s) {
    if (s2i.count(s))   return s2i[s];
    s2i[s] = n;
    i2s[n] = s;
    n++;
    return n - 1;
}

vector<int> order;
void dfs1(int u) {
    vst[u] = 1;
    for (auto v : g[u]) if (!vst[v]) dfs1(v);
    order.push_back(u);
}

int dfs2(int u, int c) {
    int re = 1;
    scc[u] = c;
    vst[u] = 1;
    for (auto v : gt[u])    if (!vst[v]) re += dfs2(v, c);
    return re;
}

void dfs(int u) {
    if (sccn[scc[u]] >= 2)    throw 1;
    vst[u] = 1;
    for (auto v : g[u]) if (!vst[v]) dfs(v);
}

int main() {
    //ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> m;
    For (i, m) {
        string a, b;
        cin >> a >> b;
        int u = reqID(a), v = reqID(b);
        g[u].push_back(v);
        gt[v].push_back(u);
    }

    For (i, n) if (!vst[i]) dfs1(i);

    For (i, n) vst[i] = 0;
    for (int i = n - 1; i >= 0; i--) {
        int c = order[i];
        if (!vst[c]) sccn[c] = dfs2(c, c);
    }

    // For (i, n) {
    //     cout << i2s[i] << " : " << i2s[scc[i]] << '\n'; 
    // }

    string str;
    while (cin >> str) {
        int s = reqID(str);
        For (i, n)  vst[i] = 0;
        try {
            dfs(s);
        }
        catch(int d) {
            cout << str << " safe\n";
            continue;
        }
        cout << str << " trapped\n";
    }

    
    
    return 0;
}