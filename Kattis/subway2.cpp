// https://open.kattis.com/problems/subway2
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

struct D {
    int v;
    double w;
};

int n = 0;
ar<ll, 2> a[300];
map<ar<ll, 2>, int> mp;

double g[300][300];
vector<vector<ar<ll, 2>>> ls;
double dp[300];

int newn(ar<ll, 2> p) {
    if (mp.count(p))    return mp[p];
    mp[p] = n;
    a[n] = p;
    n++;
    return n - 1;
}

double dist(ar<ll, 2> p, ar<ll, 2> q) {
    ll dx = p[0] - q[0];
    ll dy = p[1] - q[1];
    return sqrt(dx * dx + dy * dy);
}

void add(int u, int v, bool sub) {
    double d = dist(a[u], a[v]);
    if (sub) {
        d = d * 3 / 1000 / 2;
    }
    else {
        d = d * 6 / 1000;
    }
    g[u][v] = g[v][u] = d;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    ar<ll, 2> s, t;
    
    cin >> s[0] >> s[1] >> t[0] >> t[1];
    newn(s);
    newn(t);

    ar<ll, 2> prv;
    while (cin >> prv[0] >> prv[1]) {
        vector<ar<ll, 2>> curl;
        curl.push_back(prv);
        newn(prv);
        ar<ll, 2> cur;
        while (cin >> cur[0] >> cur[1] && !(cur[0] == -1 && cur[1] == -1)) {
            prv = cur;
            curl.push_back(cur);
            newn(cur);   
        }
        ls.push_back(curl);
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            add(i, j, 0);
        }
    }

    for (vector<ar<ll, 2>>& vec : ls) {
        for (int i = 0; i < vec.size() - 1; i++) {
            add(mp[vec[i]], mp[vec[i + 1]], 1);
        }
    }
    
    // For (i, n) {
    //     For (j, n) {
    //         cout << g[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    For (i, n) {
        dp[i] = IINF;
    }

    priority_queue<ar<double, 2>, vector<ar<double, 2>>, greater<ar<double, 2>>> pq;
    pq.push({0, 0});
    dp[0] = 0;

    while (pq.size()) {
        int u = pq.top()[1];
        double d = pq.top()[0];
        pq.pop();
        if (d > dp[u]) continue;
        For (v, n) {
            double w = g[u][v];
            if (d + w < dp[v]) {
                dp[v] = d + w;
                pq.push({d + w, (double)v});
            }
        }
    }

    cout << (int)round(dp[1]) << '\n';

    return 0;
}
