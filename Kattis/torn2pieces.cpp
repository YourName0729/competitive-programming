// DFS
// https://open.kattis.com/problems/torn2pieces
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

int n;
vector<int> g[10000];
int prv[10000];

map<string, int> s2i;
string i2s[10000];

int timer = 0;
int reqID(string& s) {
    if (s2i.count(s))   return s2i[s];
    i2s[timer] = s;
    s2i[s] = timer;
    timer++;
    return timer - 1;
}

void dfs(int u, int p) {
    prv[u] = p;
    for (auto v : g[u]) {
        if (prv[v] == -1) {
            dfs(v, u);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    string sa, sb;
    getline(cin, sa);
    For (i, n) {
        getline(cin, sa);
        stringstream ss;
        ss << sa;
        ss >> sa;
        int u = reqID(sa);
        while (ss >> sb) {
            int v = reqID(sb);
            g[u].push_back(v);
            g[v].push_back(u);
        }
    }

    For (i, timer + 2)  prv[i] = -1;

    cin >> sa >> sb;
    int s = reqID(sa), t = reqID(sb);
    dfs(s, -2);
    
    if (prv[t] == -1) {
        cout << "no route found\n";
    }
    else {
        vector<int> ans;
        ans.push_back(t);
        int p = prv[t];
        while (p != -2) {
            ans.push_back(p);
            p = prv[p];
        }
        for (int i = ans.size() - 1; i >= 0; i--) {
            cout << i2s[ans[i]] << ' ';
        }
    }

    return 0;
}