// MST disjoint_set
// https://open.kattis.com/problems/communicationssatellite
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

struct D {
    double d;
    int i, j;
};

bool cmp(D a, D b) {
    return a.d < b.d;
}

int n;
ar<int, 3> a[2010];


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    For (i, n) For (j, 3)   cin >> a[i][j];

    vector<D> vec;
    For (i, n) {
        for (int j = i + 1; j < n; j++) {
            int dx = a[i][0] - a[j][0];
            int dy = a[i][1] - a[j][1];
            double d = sqrt(dx * dx + dy * dy);
            vec.push_back({d - a[i][2] - a[j][2], i, j});
        }
    }

    sort(vec.begin(), vec.end(), cmp);

    DisjoitSet dst(n);
    double ans = 0;
    int cur = 0;
    For (i, n - 1) {
        int u, v;
        double s;
        do {
            u = vec[cur].i, v = vec[cur].j;
            s = vec[cur].d;
            cur++;
        } while (dst.InSameUnion(u, v));
        dst.Union(u, v);
        ans += s;
    }
    
    cout << fixed << ans << '\n';

    return 0;
}