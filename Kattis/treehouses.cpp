// MST disjoint_set
// https://open.kattis.com/problems/treehouses
#include <bits/stdc++.h>
 
#define For(i, n) for (int i = 0; i < n; ++i)
#define Forcase int __t = 0; cin >> __t; while (__t--)
#define pb push_back
#define ll long long
#define ull unsigned long long
#define ar array
 
using namespace std;
 
const int MOD = 1e9;//1e9 + 7;
const ll INF = 1e18;

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

int n, e, p;
double x[1010], y[1010];

double dist(int i, int j) {
    double dx = x[i] - x[j], dy = y[i] - y[j];
    return (dx * dx + dy * dy);
}

bool cmp(ar<int, 2> a, ar<int, 2> b) {
    return dist(a[0], a[1]) < dist(b[0], b[1]);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    

    cin >> n >> e >> p;

    DisjoitSet ds(n);

    For (i, n) {
        cin >> x[i] >> y[i];
    }

    For (i, e) {
        For (j, e) {
            ds.Union(i, j);
        }
    }

    For (i, p) {
        int a, b;
        cin >> a >> b, a--, b--;
        ds.Union(a, b);
    }

    vector<ar<int, 2>> ps;
    For (i, n) {
        for (int j = i + 1; j < n; j++) {
            ps.push_back({i, j});
        }
    }
    sort(ps.begin(), ps.end(), cmp);

    double ans = 0;
    for (ar<int, 2> p : ps) {
        if (!ds.InSameUnion(p[0], p[1])) {
            ans += sqrt(dist(p[0], p[1]));
            ds.Union(p[0], p[1]);
        }
    }
    cout << fixed << ans << '\n';

    return 0;
}