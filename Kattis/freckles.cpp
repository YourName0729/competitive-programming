// MST Disjoint_set
// https://open.kattis.com/problems/freckles
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

int n;
ar<double, 2> a[1010];
//priority_queue<ar<double, 3>, vector<ar<double, 3>>, greater<ar<double, 3>>> pq;
vector<tuple<double, int, int>> vec;

double dist(int i, int j) {
    double dx = a[i][0] - a[j][0];
    double dy = a[i][1] - a[j][1];
    return sqrt(dx * dx + dy * dy);
}

// bool cmp(tuple<double, int, int> a, tuple<double, int, int> b) {
//     return get<0>(a) < get<0>(b);
// }

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    bool flg = 0;
    Forcase {
        if (flg)    cout << '\n';
        flg = 1;
        //while (!pq.empty()) pq.pop();
        vec.clear();
        cin >> n;
        DisjoitSet dst(n);
        For (i, n)  cin >> a[i][0] >> a[i][1];
        if (n == 0) {
            cout << "0\n";
        }
        else {
            For (i, n) {
                for (int j = i + 1; j < n; j++) {
                    //pq.push({dist(i, j), i, j});
                    vec.push_back({dist(i, j), i, j});
                }
            }
            sort(vec.begin(), vec.end());

            double ans = 0;
            int idx = 0;
            For (i, n - 1) {
                int u, v;
                double d;
                do {
                    //ar<double, 3> cur = pq.top();
                    //pq.pop();
                    //u = cur[1], v = cur[2], d = cur[0];
                    u = get<1>(vec[idx]), v = get<2>(vec[idx]), d = get<0>(vec[idx]);
                    idx++;
                } while (dst.InSameUnion(u, v));
                dst.Union(u, v);
                ans += d;
            }

            //cout << fixed << setprecision(2) << ans << '\n';
            //ans = (int)(ans * 100) / 100.0;
            cout << fixed << setprecision(2) << ans << '\n';
        }
    }

    return 0;
}