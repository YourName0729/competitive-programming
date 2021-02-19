// DAG
// https://open.kattis.com/problems/pickupsticks
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
vector<int> g[1000010];
int ideg[1000010];
bool vst[1000010];
vector<int> ans;

void dfs(int u) {
    vst[u] = 1;
    ans.push_back(u);
    for (auto v : g[u]) {
        ideg[v]--;
        if (!vst[v] && ideg[v] == 0) {
            dfs(v);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    For (i, m) {
        int u, v;
        cin >> u >> v, u--, v--;
        g[u].push_back(v);
        ideg[v]++;
    }

    For (i, n) {
        if (ideg[i] == 0 && !vst[i])   dfs(i);
    }

    For (i, n) {
        if (!vst[i]) {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
    }

    for (auto e : ans) {
        cout << e + 1 << '\n';
    }


    return 0;
}
