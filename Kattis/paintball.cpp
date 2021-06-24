// https://open.kattis.com/problems/paintball
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
vector<int> g[1010];
int mx[1010], my[1010];
bool vst[1010];

bool dfs(int u) {
    for (auto v : g[u]) {
        if (!vst[v]) {
            vst[v] = 1;
            if (my[v] == -1 || dfs(my[v])) {
                my[v] = u, mx[u] = v;
                return 1;
            }
        }
    }
    return 0;
}

int match() {
    memset(mx, -1, sizeof(mx));
    memset(my, -1, sizeof(my));

    int re = 0;
    For (i, n) {
        memset(vst, 0, sizeof(vst));
        if (dfs(i)) {
            ++re;
        }
    }
    return re;
}

int main() {
    //ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> n >> m;
    For (i, m) {
        int u, v;
        cin >> u >> v, --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    if (match() != n) {
        cout << "Impossible\n";
    }
    else {
        For (i, n) {
            cout << mx[i] + 1 << '\n';
        }
    }

    return 0;
}
