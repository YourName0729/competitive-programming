// DFS
// https://open.kattis.com/problems/breakingbad
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
map<string, int> s2i;
string i2s[100010];
vector<int> g[100010];
int clr[100010];

void dfs(int u, int c) {
    if (clr[u]) {
        if (clr[u] == c)    return;
        else    throw 1;
    }
    clr[u] = c;
    for (auto v : g[u]) {
        dfs(v, c % 2 + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    For (i, n) {
        cin >> i2s[i];
        s2i[i2s[i]] = i;
    }

    cin >> m;
    For (i, m) {
        string a, b;
        cin >> a >> b;
        int u = s2i[a], v = s2i[b];
        g[u].push_back(v);
        g[v].push_back(u);
    }

    try {
        For (i, n) {
            if (!clr[i])    dfs(i, 1);
        }
    }
    catch (int d) {
        cout << "impossible\n";
        return 0;
    }
    
    For (i, n) {
        if (clr[i] == 1) cout << i2s[i] << ' ';
    }
    cout << '\n';
    For (i, n) {
        if (clr[i] == 2) cout << i2s[i] << ' ';
    }
    cout << '\n';

    return 0;
}