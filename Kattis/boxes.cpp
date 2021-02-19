// tree ancestor
// https://open.kattis.com/problems/boxes
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
int f[200010];
vector<int> g[200010];
int tin[200010], tout[200010], chcnt[200010];
int timer = 0;

void build(int u) {
    tin[u] = timer++;
    chcnt[u] = 1;
    for (auto v : g[u]) {
        build(v);
        chcnt[u] += chcnt[v];
    }
    tout[u] = timer++;
}

bool back(int a, int b) {
    return tin[b] <= tin[a] && tout[b] >= tout[a];
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    vector<int> rts;
    For (i, n) {
        int d;
        cin >> d, d--;
        if (d != -1) {
            g[d].push_back(i);
            f[i] = d;
        }
        else {
            rts.push_back(i);
        }
    }

    for (auto root : rts) {
        build(root);
    }

    Forcase {
        int m;
        cin >> m;
        set<int> st;
        stack<int> era;
        For (i, m) {
            int u;
            bool flg = 1;
            cin >> u, u--;
            for (auto v : st) {
                if (back(u, v)) {
                    flg = 0;
                }
                else if (back(v, u)) {
                    //st.erase(v);
                    era.push(v);
                }
            }
            while (era.size()) {
                st.erase(era.top());
                era.pop();
            }
            if (flg) {
                st.insert(u);
            }
        }

        int ans = 0;
        for (auto u : st) {
            ans += chcnt[u];
        }
        cout << ans << '\n';
    }

    return 0;
}