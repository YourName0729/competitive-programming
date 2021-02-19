// DAG Graph_traversal
// https://open.kattis.com/problems/builddeps
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
const ll INF = 1e18;
const double eps = 1e-9;

int n;
vector<int> g[100010];
bool vst[100010];
int ideg[100010];
string i2s[100010];
map<string, int> s2i;

int reqID(string& s) {
    static int timer = 0;
    if (s2i.count(s)) {
        return s2i[s];
    }
    i2s[timer] = s;
    s2i[s] = timer;
    timer++;
    return timer - 1;
}

void dfs(int u) {
    vst[u] = 1;
    for (auto v : g[u]) {
        if (!vst[v]) dfs(v);
    }
}

void dfs2(int u) {
    cout << i2s[u] << '\n';
    for (auto v : g[u]) {
        ideg[v]--;
        if (ideg[v] == 0)   dfs2(v);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    string s;
    stringstream ss;
    getline(cin, s);
    For (i, n) {
        getline(cin, s);
        ss.clear();
        ss << s;
        ss >> s;
        s.pop_back();
        int u = reqID(s);
        while (ss >> s) {
            int v = reqID(s);
            g[v].push_back(u);
            ideg[u]++;
        }
    }

    string tar;
    cin >> tar;
    int tarid = reqID(tar);
    dfs(tarid);
    For (i, n) {
        if (!vst[i]) {
            for (auto v : g[i]) {
                ideg[v]--;
            } 
        }
    }

    dfs2(tarid);


    return 0;
}