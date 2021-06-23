// https://open.kattis.com/problems/elementarymath
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

int nx, ny = 0;
int mx[2510], my[7510];
bool vst[7510];
vector<ll> g[2510];

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

int bm() {
    memset(mx, -1, sizeof(mx));
    memset(my, -1, sizeof(my));

    int re = 0;
    For (i, nx) {
        memset(vst, 0, sizeof(vst));
        if (dfs(i)) re++;
    }
    return re;
}

ar<ll, 2> a[2500];
map<ll, int> l2i;
ll i2l[7510];

int req(ll l) {
    if (l2i.count(l))   return l2i[l];
    i2l[ny] = l;
    l2i[l] = ny;
    ny++;
    return ny - 1;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> nx;
    For (i, nx) cin >> a[i][0] >> a[i][1];
    For (i, nx) {
        g[i].push_back(req(a[i][0] + a[i][1]));
        g[i].push_back(req(a[i][0] - a[i][1]));
        g[i].push_back(req(a[i][0] * a[i][1]));
    }

    if (bm() != nx) {
        cout << "impossible\n";
    } 
    else {
        For (i, nx) {
            ll v = i2l[mx[i]];
            cout << a[i][0] << ' ';
            if (a[i][0] + a[i][1] == v) {
                cout << '+';
            }
            else if (a[i][0] - a[i][1] == v) {
                cout << "-";
            }
            else {
                cout << '*';
            }
            cout << ' ' << a[i][1] << " = " << v << '\n';
        }
    }

    return 0;
}
