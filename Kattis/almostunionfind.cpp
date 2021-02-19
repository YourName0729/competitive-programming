// disjoint_set
// https://open.kattis.com/problems/almostunionfind
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
const ll INF = 1e18;

int n, m;
int rt[200010], rnk[200010], mp[200010];
ll sum[200010];

int root(int x) {
    if (rt[x] == x) return x;
    return rt[x] = root(rt[x]);
}

void joint(int a, int b) {
    if (root(a) == root(b)) return;
    a = root(a), b = root(b);
    if (rnk[a] < rnk[b])    swap(a, b);
    sum[a] += sum[b];
    rnk[a] += rnk[b];
    rt[b] = a;
    sum[b] = rnk[b] = 0;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    while(cin >> n >> m) {
        for (int i = 1; i <= n; i++) {
            rt[i] = sum[i] = i;
            rnk[i] = 1;
            mp[i] = i;
        }

        for (int i = 1; i <= m; i++) {
            int op, a, b;
            cin >> op >> a;
            if (op == 1) {
                cin >> b;
                joint(root(mp[a]), root(mp[b]));
            }
            else if (op == 2) {
                cin >> b;
                int ra = root(mp[a]), rb = root(mp[b]);
                if (ra == rb)   continue;
                sum[ra] -= a, rnk[ra]--;
                mp[a] = ++n;
                sum[mp[a]] = a, rnk[mp[a]] = 1, rt[mp[a]] = mp[a];
                joint(mp[a], rb);
            }
            else {
                int ra = root(mp[a]);
                cout << rnk[ra] << ' ' << sum[ra] << '\n';
            }

            // for (int j = 1; j <= 2 * n; j++) {
            //     cout << rt[i] << ' ' << rnk[i] << ' ' << mp[i] << ' ' << sum[i] << '\n';
            // }
        }    
    }
    

    return 0;
}
