// MST disjoint_set
// https://open.kattis.com/problems/minspantree
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
priority_queue<ar<int, 3>, vector<ar<int, 3>>, greater<ar<int, 3>>> pq;

bool cmp(ar<int, 2> a, ar<int, 2> b) {
    if (a[0] == b[0])   return a[1] < b[1];
    return a[0] < b[0];
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    while (cin >> n >> m && !(n == 0 && m == 0)) {
        DisjoitSet ds(n);
        For (i, m) {
            int u, v, w;
            cin >> u >> v >> w;
            pq.push({w, u, v});
        }
        ll sum = 0;
        vector<ar<int, 2>> ans;
        while (!pq.empty()) {
            ar<int, 3> cur = pq.top();
            pq.pop();
            int u = cur[1], v = cur[2], w = cur[0];
            if (!ds.InSameUnion(u, v)) {
                ds.Union(u, v);
                sum += w;
                if (u > v)  swap(u, v);
                ans.push_back({u, v});
            }
        }
        // cout << "cur\n";
        // for (ar<int, 2> p : ans) {
        //     cout << p[0] << ' ' << p[1] << '\n';
        // }

        if (ans.size() != n - 1) {
            cout << "Impossible\n";
            continue;
        }

        sort(ans.begin(), ans.end(), cmp);
        cout << sum << '\n';
        for (ar<int, 2> p : ans) {
            cout << p[0] << ' ' << p[1] << '\n';
        }
    }

    return 0;
}