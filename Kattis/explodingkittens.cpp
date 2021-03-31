// https://open.kattis.com/contests/ubwxs6/problems/explodingkittens
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

struct Eve {
    Eve(int d, bool b) {
        v = d, exp = b;
    }

    int v;
    bool exp;
};

int n;
int prv[1010], nxt[1010];
int h[1010];
vector<Eve> vec;

bool cmp(Eve x, Eve y) {
    return x.v < y.v;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int E, D;
    cin >> n >> E >> D;
    For (i, n) {
        nxt[i] = (i + 1) % n;
        prv[i] = (i - 1 + n) % n;
    }

    For (i, E) {
        int d;
        cin >> d;
        vec.push_back(Eve(d, 1));
    }
    For (i, D) {
        int d;
        cin >> d;
        vec.push_back(Eve(d, 0));
    }

    sort(vec.begin(), vec.end(), cmp);

    int prvv = -1;
    int cur = 0;
    int nn = n;
    bool flg = 0;
    for (Eve e : vec) {
        //cout << prvv << ' ' << cur << ' ' << e.v << '\n';

        int dist = (e.v - prvv - 1) % nn;
        while (dist--) cur = nxt[cur];
        prvv = e.v;
        //cout << cur << " catch " << e.v << ' ' << e.exp << '\n';
        if (e.exp) {
            if (h[cur]) h[cur]--;
            else {
                nn--;
                nxt[prv[cur]] = nxt[cur];
                prv[nxt[cur]] = prv[cur];
                //cout << "kill " << cur << '\n';
                if (nn == 1) {
                    cout << nxt[cur] << '\n';
                    flg = 1;
                    break;
                }
            }
        }
        else {
            h[cur] = min(5, h[cur] + 1);
        }
        cur = nxt[cur];
    }

    if (!flg) {
        cout << "-1\n";
    }

    return 0;
}
