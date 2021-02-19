// minimum_spanning_tree mst
// https://open.kattis.com/problems/landline
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

class DisjoitSet {
public:
    DisjoitSet(int N) {
        rt.resize(N);
        rnk.resize(N, 1);
        for (int i = 0; i < N; ++i) rt[i] = i;
        n = N;
    }

    size_t Size() const {
        return n;
    }

    void Union(int a, int b) {
        int fa = root(a), fb = root(b);
        if (fa == fb)   return;

        n--;
        if (rnk[fa] > rnk[fb]) rt[fb] = rt[fa];
        else if (rnk[fa] < rnk[fb]) rt[fa] = rt[fb];
        else {
            rt[fa] = fb;
            rnk[fb]++;
        }
    }

    bool InSameUnion(int a, int b) {
        return root(a) == root(b);
    }

protected:
    int root(int i) {
        if (rt[i] == i) return i;
        return rt[i] = root(rt[i]);
    }

    int n;
    vector<int> rt, rnk;
};

int n, m;
vector<ar<int, 2>> g[1010];
bool oth[10010];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int p;
    cin >> n >> m >> p;
    if (n == 1) {
        cout << "0\n";
        return 0;
    }
    if (n == 2) {
        int d;
        For (i, p) cin >> d;
        if (m == 0) {
            cout << "impossible\n";
        }
        else {
            cin >> d >> d >> d;
            cout << d << '\n';
        }
        return 0;
    }

    For (i, p) {
        int d;
        cin >> d, d--;
        oth[d] = 1;
    }

    priority_queue<ar<int, 3>, vector<ar<int, 3>>, greater<ar<int, 3>>> pq;
    For (i, m) {
        int u, v, w;
        cin >> u >> v >> w, u--, v--;
        if (!oth[v]) g[u].push_back({w, v});
        if (!oth[u]) g[v].push_back({w, u});
        if (!oth[u] && !oth[v]) pq.push({w, u, v});
    }
    
    DisjoitSet dst(n);
    ll ans = 0;
    try {
        For (i, n - p - 1) {
            int u, v, w;
            do {
                if (pq.empty()) throw 1;
                u = pq.top()[1], v = pq.top()[2], w = pq.top()[0];
                pq.pop();
            } while (dst.InSameUnion(u, v));
            dst.Union(u, v);
            ans += w;
        }
        For (i, n) {
            if (oth[i]) {
                int mn = MOD;
                for (ar<int, 2> p : g[i]) mn = min(mn, p[0]);
                if (mn == MOD)  throw 1;
                ans += mn;
            }
        }
    }
    catch (int d) {
        cout << "impossible\n";
        return 0;
    }
    cout << ans << '\n';
    

    return 0;
}
