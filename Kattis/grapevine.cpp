// https://open.kattis.com/problems/grapevine
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

int n, m, D;
vector<int> g[100010];
int dist[100010], hrd[100010], spr[100010];
bool vst[100010];

map<string, int> s2i;
string i2s[100010];

void dfs(int u, int d) {
    dist[u] = d;
    vst[u] = 1;
    if (d == D) return;
    for (auto v : g[u]) {
        if (!vst[v]) {
            hrd[v]++;
            if (hrd[v] >= spr[v]) {
                dfs(v, d + 1);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m >> D;
    For (i, n) {
        cin >> i2s[i] >> spr[i];
        s2i[i2s[i]] = i;
    }
    For (i, m) {
        string su, sv;
        cin >> su >> sv;
        int u = s2i[su], v = s2i[sv];
        g[u].push_back(v);
        g[v].push_back(u);
    }

    string ss;
    cin >> ss;
    int s = s2i[ss];
    
    queue<int> que;
    que.push(s);
    For (i, D) {
        int q = que.size();
        For (i, q) {
            int u = que.front();
            que.pop();
            vst[u] = 1;
            for (auto v : g[u]) {
                if (vst[v]) continue;
                hrd[v]++;
                if (hrd[v] >= spr[v]) {
                    que.push(v);
                }
            }
        }
    }

    
    //For (i, n) cout << dist[i] << ' ' << spr[i] << ' ' << hrd[i] << '\n';

    int ans = 0;
    For (i, n) {
        if (hrd[i]) {
            ans++;
        }  
    }
    cout << ans << '\n';

    return 0;
}
