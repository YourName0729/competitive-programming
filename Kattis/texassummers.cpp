// Dijkstra
// https://open.kattis.com/problems/texassummers
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
ar<ll, 2> a[2510];
ll dist[2510];
int prv[2510];

ll Dist(int i, int j) {
    ll dx = a[i][0] - a[j][0];
    ll dy = a[i][1] - a[j][1];
    return dx * dx + dy * dy;
}

int main() {
    //ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    For (i, n) cin >> a[i][0] >> a[i][1];
    cin >> a[n][0] >> a[n][1];
    cin >> a[n + 1][0] >> a[n + 1][1];
    n += 2;
    For (i, n) dist[i] = IINF;

    priority_queue<ar<ll, 2>, vector<ar<ll, 2>>, greater<ar<ll, 2>>> pq;
    dist[n - 2] = 0;
    pq.push({0, n - 2});
    while (pq.size()) { 
        ll w = pq.top()[0], u = pq.top()[1];
        //cout << w << ' ' << u << '\n';
        pq.pop();
        if (dist[u] < w) continue;
        For (i, n) {
            ll d = Dist(i, u);
            if (w + d < dist[i]) {
                dist[i] = w + d;
                pq.push({w + d, i});
                prv[i] = u;
            }
        }
    }

    // For (i, n) {
    //     cout << prv[i] << ' ';
    // }
    // cout << '\n';

    vector<int> ans;
    int cur = n - 1;
    while (prv[cur] != n - 2) {
        //cout << cur << '\n';
        ans.push_back(prv[cur]);
        cur = prv[cur];
    }

    if (ans.size() == 0) {
        cout << "-\n";
    }
    else {
        for (int i = ans.size() - 1; i >= 0; i--) {
            cout << ans[i] << '\n';
        }
    }

    return 0;
}