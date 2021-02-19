// segment_tree
// https://open.kattis.com/problems/justforsidekicks
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

int n, q;
ar<int, 6> seg[800010];
ll cost[6];

void update(int i, int l, int r, int tar, int val) {
    if (l == r) {
        For (j, 6) {
            seg[i][j] = 0;
        }
        seg[i][val] = 1;
        return;
    }

    int mid = (l + r) / 2, cl = 2 * i, cr = cl + 1;
    if (tar <= mid) {
        update(cl, l, mid, tar, val);
    }
    else {
        update(cr, mid + 1, r, tar, val);
    }
    
    For (j, 6) {
        seg[i][j] = seg[cl][j] + seg[cr][j];
    }
}

ar<int, 6> query(int i, int bot, int top, int l, int r) {
    if (bot == l && r == top) {
        return seg[i];
    }

    int mid = (bot + top) / 2, cl = 2 * i, cr = cl + 1;
    if (r <= mid)   return query(cl, bot, mid, l, r);
    else if (mid + 1 <= l)  return query(cr, mid + 1, top, l, r);

    ar<int, 6> a, b;
    a = query(cl, bot, mid, l, mid);
    b = query(cr, mid + 1, top, mid + 1, r);
    For (j, 6) {
        a[j] += b[j];
    } 
    return a;
}

int main() {
    //ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> q;
    For (i, 6) {
        cin >> cost[i];
    }
    For (i, n) {
        char c;
        cin >> c;
        update(1, 1, n, i + 1, c - '1');
    }
    For (i, q) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 1) {
            update(1, 1, n, b, c - 1);
        }
        else if (a == 2) {
            cost[b - 1] = c;
        }
        else {
            ar<int, 6> arr = query(1, 1, n, b, c);
            ll ans = 0;
            For (i, 6) {
                ans += cost[i] * arr[i];
            }
            cout << ans << '\n';
        }
    }

    return 0;
}