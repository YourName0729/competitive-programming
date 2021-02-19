// cycle
// https://open.kattis.com/problems/importspaghetti
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
map<string, int> s2i;
string i2s[510];
vector<int> g[510];
int prv[510];

vector<string> input_split() {
    string s;
    vector<string> re;
    stringstream ss;
    getline(cin, s);
    ss << s;
    while (ss >> s) {
        re.push_back(s);
    }
    return re;
}

int bfs(int s) {
    For (i, n)  prv[i] = -1;
    queue<int> que;
    que.push(s);
    while (que.size()) {
        int u = que.front();
        que.pop();
        for (auto v : g[u]) {
            if (v == s) return u;
            if (prv[v] == -1) {
                prv[v] = u;
                que.push(v);
            }
        }
    }
    return -1;
}

int main() {
    //ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    For (i, n) {
        string s;
        cin >> i2s[i];
        s2i[i2s[i]] = i;
    }
    For (i, n) {
        string su;
        int m, u, v;
        cin >> su >> m;
        u = s2i[su];
        getline(cin, su);
        For (j, m) {
            vector<string> vec = input_split();
            for (int k = 1; k < vec.size(); k++) {
                if (k != vec.size() - 1) vec[k].pop_back();
                v = s2i[vec[k]];
                //g[u].push_back(v);
                //cout << v << " -> " << u << '\n';
                //g[v].push_back(u);
                g[u].push_back(v);
                // if (v == u) {
                //     cout << i2s[v];
                //     return 0;
                // }
            }
        }
    }

    vector<int> ans;
    
    For (i, n) {
        int p = bfs(i);
        if (p != -1) {
            vector<int> cur;
            //cout << "end " << p << '\n';
            while (p != -1) {
                cur.push_back(p);
                p = prv[p];
            }
            if (ans.size() == 0 || cur.size() < ans.size()) {
                ans = cur;
            }
            // cout << "root " << i << '\n';
            // For (i, n) {
            //     cout << prv[i] << ' ';
            // }
            // cout << '\n';
        }

    }

    if (ans.size() == 0) {
        cout << "SHIP IT\n";
    }
    else {
        for (int i = ans.size() - 1; i >= 0; i--) {
            cout << i2s[ans[i]] << ' ';
        }
    }

    return 0;
}