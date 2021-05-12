// https://open.kattis.com/problems/reactivity
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

#define For(i, n) for (int i = 0; i < n; ++i)
#define Forcase int __t = 0; cin >> __t; while (__t--)
#define ll long long
#define ar array

using namespace std;
using namespace __gnu_pbds;

template<class Type> using indexed_set=tree<Type,null_type,less<Type>,rb_tree_tag,tree_order_statistics_node_update>;

const int MOD = 1e9 + 7;
const int INF = 2147483647;
const ll IINF = 1e18;
const double eps = 1e-12;

int n, m;
vector<int> g[1010];
int ideg[1010];
bool vst[1010];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    For (i, m) {
        int u, v;
        cin >> u >> v;
        ideg[v]++;
        g[u].push_back(v);
    }

    vector<int> ans;
    vector<int> s;
    do {
        For (i, n) {
            if (!vst[i] && ideg[i] == 0) s.push_back(i);
        }
        if (s.size() == 0)  break;
        if (s.size() != 1) {
            cout << "back to the lab\n";
            return 0;
        }
        
        int u = s.front();
        s.clear();
        ans.push_back(u);
        vst[u] = 1;
        for (auto v : g[u]) {
            ideg[v]--;
        }
    } while (1);

    For (i, n) {
        if (!vst[i]) {
            cout << "back to the lab\n";
            return 0;
        }
    }

    For (i, n) {
        cout << ans[i] << ' ';
    }
    cout << '\n';

    return 0;
}
